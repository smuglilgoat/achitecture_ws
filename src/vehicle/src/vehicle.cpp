#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

#include "project_s_msgs/Actuators.h"
#include "project_s_msgs/EgoDataReport.h"
#include "project_s_msgs/EgoDistanceCurviligne.h"
#include "std_msgs/Float64.h"

#include "project_s_msgs/Configurations.h"
#include "project_s_msgs/Tableau_Circuit.h"

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
//#define LATITUDE_ORIGIN	+48.80
//#define LONGITUDE_ORIGIN	+01.98
#define LATITUDE_ORIGIN		+48.7965
#define LONGITUDE_ORIGIN	+ 1.9872
#define RAYON_TERRE		6371000.0
#define X_ORIGIN		0.0
#define Y_ORIGIN		0.0

// coordonnées du véhicule & orientation
double x;
double y;			// y dans le sens positif à gauche, alors que la longitude est décroissante par l'ouest.
double th;			// theta en rad, sens positif trigo,
				// alors que le cap est en degré, sens positif anti-trigo.

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
nav_msgs::Odometry odom;
project_s_msgs::EgoDataReport egoDataVehicle;
project_s_msgs::EgoDistanceCurviligne Ego_Distance_Curviligne;

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::Actuators actuators;
std_msgs::Float64 Speed;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
void actuatorsCallback(const project_s_msgs::Actuators::ConstPtr& ptrActuators)
{
	actuators = *ptrActuators;
}

void Vehicle_Speed_Planning_Callback(const geometry_msgs::Twist::ConstPtr& buffer)
{
	Speed.data = buffer->linear.x;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv){
  ros::init(argc, argv, "vehicle");

  ros::NodeHandle n;

  ros::Subscriber subActuators = n.subscribe(std::string("/actuators_data"), 1, actuatorsCallback);
  ros::Subscriber sub_vehicle_speed_planning = n.subscribe(std::string("/cmd_vel"), 1, Vehicle_Speed_Planning_Callback);

  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("/odom", 1);
  ros::Publisher ego_data_pub = n.advertise<project_s_msgs::EgoDataReport>("/ego_data", 1);
  ros::Publisher ego_data_vehicle_pub = n.advertise<project_s_msgs::EgoData>("/ego_data_vehicle", 1);
  ros::Publisher pub_Distance_Curviligne_Ego = n.advertise<project_s_msgs::EgoDistanceCurviligne>(std::string("/Distance_Curviligne_Ego"), 1);

  tf::TransformBroadcaster odom_broadcaster;
  geometry_msgs::TransformStamped odom_trans;

#ifdef SIMULATION_CIRCUIT_LINE
  // placement du véhicule & orientation initials
  x = 20.0 + 3.5/2;	// placement dans la voie de droite suivant generation_route2
  y = 0.0;
  th = M_PI/2;
#endif

#ifdef SIMULATION_CIRCUIT_GPS
  // placement du véhicule & orientation initials : au début du circuit
  x  = (Tableau_circuit_GPS[0].latitude  - LATITUDE_ORIGIN)  / 180.0 * M_PI *  RAYON_TERRE;
  y  = (Tableau_circuit_GPS[0].longitude - LONGITUDE_ORIGIN) / 180.0 * M_PI * (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI));
  x += X_ORIGIN;
  y += Y_ORIGIN;
  y  = -y;
  //th = 10.0 / 180.0 * M_PI;	// cap de départ pour un Circuit_huit
  th = 45.0 / 180.0 * M_PI;	// cap de départ pour un Circuit_reduit
#endif

  // dynamique du véhicule
  double Acceleration_x, Acceleration_y;
  double v;
  //double v = 8.3;			// vitesse initiale 30km/h
  //double v = 0.0;			// vitesse initiale nulle
  double vx;
  double vy;
  double vth;
  double vth_old;

  #define M 1700.0			// masse en kg
  #define PUISSANCE_MAX 120000.0	// Puissance max en W

  #define FREINAGE_MAX	9.81		// 1G de freinage max

  #define L	2.50			// empattement en m

  ros::Time current_time, last_time;
  last_time = ros::Time::now();

  std_msgs::Float32 SommeCurvi;

  ros::Rate r(100.0);	// F = 100Hz <=> 10ms

  while(n.ok()){

    ros::spinOnce();               // check for incoming messages
    current_time = ros::Time::now();

    //compute odometry in a typical way given the velocities of the robot
    double dt = (current_time - last_time).toSec();

    // calcul de la vitesse lacet
    v = Speed.data;
    //v=0;	//pour forcer le vehicule immobile
    double R;
    if(actuators.steeringAngle.data != 0)
    {
      R = L/tan(actuators.steeringAngle.data);
      vth = v/R;
    }
    else
    {
      R = 0;
      vth = 0;
    }

    // lissage de vth au 1er ordre
    double K = exp(-dt/0.001); 

    vth  = (1.0-K)*vth;
    vth +=      K *vth_old;
    vth_old = vth;

    // calcul de l'angle de cap
    double delta_th = vth * dt;
    th += delta_th;

    // calcul des forces de traction / freinage / trainée
    double Ftrack = 0;
    if (abs(v) < 8)
      Ftrack = actuators.Accelerator.data / 100 * PUISSANCE_MAX / 8;
    else
      Ftrack = actuators.Accelerator.data / 100 * PUISSANCE_MAX / v;

    double Fbrake = - actuators.brakePressure.data / 100 * FREINAGE_MAX * M;
    if(v< 0)
      Fbrake *= -1;

    #define rho 1.2		// masse volumique de l'air (kg/m3)
    #define S 3			// surface frontale (m2)
    //#define Cx 0.38		// coefficient de trainée (sans unité)
    #define Cx 0.0		// à 0 pour annuler les frottements
    double Fdrag = - 0.5 * rho * S * Cx * v * v;

    // calcul de la vitesse
    Acceleration_x = (Ftrack + Fbrake + Fdrag)/M;	// Acc_x et _y dans le repère ego véhicule : à changer _longi et _lat
    Acceleration_y = (v*v) / R;
    double delta_v = Acceleration_x * dt;
    v += delta_v;
    vx = v * cos(th);					// vx et vy dans le repère abslolu (RVIZ)
    vy = v * sin(th);
  
    // calcul de la position
    double delta_x = vx * dt;
    double delta_y = vy * dt;
    x += delta_x;
    y += delta_y;

#ifdef SIMULATION_CIRCUIT_LINE
    if((SommeCurvi.data > 70.0) && (y>0))						// sert à RAZ, à chaque boucle du circuit
#endif
#ifdef SIMULATION_CIRCUIT_GPS
    if(SommeCurvi.data > Tableau_circuit_GPS[NBRE_POINT_CIRCUIT_GPS-1].offset)	// sert à RAZ, à chaque boucle du circuit
#endif
      SommeCurvi.data = 0;

    SommeCurvi.data += std::sqrt(std::pow(delta_x,2) + std::pow(delta_y,2));

    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

    //first, we'll publish the transform over tf
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = x;
    odom_trans.transform.translation.y = y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    //send the transform
    odom_broadcaster.sendTransform(odom_trans);

    //next, we'll publish the odometry message over ROS
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_link";

    //set the position
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    //set the velocity
    odom.twist.twist.linear.x = vx;
    odom.twist.twist.linear.y = vy;
    odom.twist.twist.angular.z = vth;

    //publish the message
    odom_pub.publish(odom);

    // mis à jour des data de l'ego-véhicule
    egoDataVehicle.header.stamp = current_time;
    egoDataVehicle.header.frame_id = "odom";
    egoDataVehicle.id.data = 1;

    for(int i = project_s_msgs::EgoDataReport::NBR_MAX_EGO_DATA-1; i > 0; i--){
      //décalage des buffers
      egoDataVehicle.EgoData[i] = egoDataVehicle.EgoData[i-1];
    }
    // indice 0 -> NBR_MAX_EGO_DATA : du plus récent -> au plus ancien

    egoDataVehicle.EgoData[0].stamp = current_time;
    //egoDataVehicle.EgoData[0].velocity.linear.x = v; egoDataVehicle.EgoData[0].velocity.linear.y = 0;		// A VALIDER
    egoDataVehicle.EgoData[0].velocity.linear.x = vx; egoDataVehicle.EgoData[0].velocity.linear.y = vy;
    egoDataVehicle.EgoData[0].velocity.angular.z = vth;
    egoDataVehicle.EgoData[0].acceleration.linear.x = Acceleration_x; egoDataVehicle.EgoData[0].acceleration.linear.y = Acceleration_y;

    // calcul coord. géographiques
    double delta_latitude;
    double delta_longitude;

    delta_latitude  = + (x - X_ORIGIN) /  RAYON_TERRE                                  * 180.0 / M_PI;
    delta_longitude = - (y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
    egoDataVehicle.EgoData[0].latitude  = LATITUDE_ORIGIN  + delta_latitude;
    egoDataVehicle.EgoData[0].longitude = LONGITUDE_ORIGIN + delta_longitude;
    egoDataVehicle.EgoData[0].cap       = th;

    // calcul distance curviligne par rapport au début du path
    Ego_Distance_Curviligne.header.stamp   = current_time;
    Ego_Distance_Curviligne.distance       = SommeCurvi;
    Ego_Distance_Curviligne.odom           = odom;
    Ego_Distance_Curviligne.latitude.data  = LATITUDE_ORIGIN  + delta_latitude;
    Ego_Distance_Curviligne.longitude.data = LONGITUDE_ORIGIN + delta_longitude;
    Ego_Distance_Curviligne.cap.data       = th;

    //publish the message
    ego_data_pub.publish(egoDataVehicle);
    ego_data_vehicle_pub.publish(egoDataVehicle.EgoData[0]);
    pub_Distance_Curviligne_Ego.publish(Ego_Distance_Curviligne);

    last_time = current_time;
    r.sleep();
  }

 return 0;
}
