#include <ros/ros.h>

#include "project_s_msgs/Configurations.h"
#include "project_s_msgs/Trajectory.h"
#include "project_s_msgs/VehicleGuidance.h"
#include "std_msgs/Float64.h"
#include "project_s_msgs/EgoDataReport.h"

#define L	2.50			// empattement en m

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::VehicleGuidance vehicleGuidance;
geometry_msgs::Twist cmd_vel;

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::Trajectory trajectory;
nav_msgs::Odometry odom_gps;
std_msgs::Float64 Speed;
project_s_msgs::EgoDataReport ego_data_report;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedTrajectory = false;
void trajectoryCallback(const project_s_msgs::Trajectory::ConstPtr& buffer)
{
	trajectory = *buffer;

	receivedTrajectory = true;
}

bool receivedOdomGPS = false;
void odomGPSCallback(const nav_msgs::Odometry::ConstPtr& buffer)
{
	odom_gps = *buffer;

	receivedOdomGPS = true;
}

bool receivedVehicleSpeedPlanning = false;
void Vehicle_Speed_Planning_Callback(const std_msgs::Float64::ConstPtr& buffer)
{
	Speed = *buffer;

	receivedVehicleSpeedPlanning = true;
}

bool receivedEgoDataReport = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& buffer)
{
	ego_data_report = *buffer;

	receivedEgoDataReport = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "vehicle_guidance");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher vehicleGuidance_pub = n.advertise<project_s_msgs::VehicleGuidance>("/vehicle_guidance_data", 1);

	// Sert à la commande de Twist_controller
	ros::Publisher pub_cmd_vel = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1);

	// Subscriber 
#ifdef SIMULATION_CIRCUIT_LINE
	ros::Subscriber trajectory_sub = n.subscribe(std::string("/trajectory_generation_data"), 1, trajectoryCallback);
#endif
#ifdef SIMULATION_CIRCUIT_GPS
	ros::Subscriber trajectory_GPS_sub = n.subscribe(std::string("/trajectory_GPS_generation_data"), 1, trajectoryCallback);
#endif
	ros::Subscriber sub_odom_gps   = n.subscribe(std::string("/odom_gps"), 1, odomGPSCallback);
	ros::Subscriber sub_vehicle_speed_planning = n.subscribe(std::string("/vehicle_speed_planning"), 1, Vehicle_Speed_Planning_Callback);
	ros::Subscriber subEgoData = n.subscribe(std::string("/ego_data"), 1, egoDataCallback);

	ros::Rate r(25);

	ros::Time current_time, last_time;
	last_time = ros::Time::now();

	float W_old = 0;

  	while(n.ok())
	{
		ros::spinOnce();

		current_time = ros::Time::now();


		if(receivedEgoDataReport){
			receivedEgoDataReport = false;
		}

		if(receivedOdomGPS){
			receivedOdomGPS = false;
		}

		if(receivedVehicleSpeedPlanning){
			receivedVehicleSpeedPlanning = false;

			cmd_vel.linear.x  = Speed.data;

			// calcul de la courbure :
			float C;
			C = std::pow(trajectory.setpointPosition.position.x,2) + std::pow(trajectory.setpointPosition.position.y,2);
			if(C != 0)
			C = 2 * trajectory.setpointPosition.position.y / C;

			// calcul du Yaw rate
#ifdef PROJECT_S_SIMULATION
			float W = odom_gps.twist.twist.linear.x * C;
#endif
#ifdef PROJECT_S_VEHICLE
			float W = ego_data_report.EgoData[0].velocity.linear.x * C;

			if(ego_data_report.EgoData[0].velocity.linear.x == 0)
				W = cmd_vel.angular.z;
#endif
			// lissage de vth au 1er ordre
			double dt = (current_time - last_time).toSec();
			last_time = current_time;

			double K = exp(-dt/0.1);
			W  = (1.0-K)*W;
			W +=      K *W_old;
			W_old = W;

			cmd_vel.angular.z = W;

			// publish du message systématiquement pour Twist_controller
			pub_cmd_vel.publish(cmd_vel);
		}

		if(receivedTrajectory){
			receivedTrajectory = false;

			// calcul de la courbure :
			float C;
			C = std::pow(trajectory.setpointPosition.position.x,2) + std::pow(trajectory.setpointPosition.position.y,2);
			if(C != 0)
			C = 2 * trajectory.setpointPosition.position.y / C;

			// calcul de l'angle de roue
			float alpha = atan(L*C);

			// MàJ de l'OUTPUT data
			vehicleGuidance.header = trajectory.header;

			vehicleGuidance.driveBrakingTorque.data = 0;		// équivalent à 0% d'accélération si pas de traitement par la suite
			vehicleGuidance.steeringWheelAngle.data = alpha;

			//publish the message
			vehicleGuidance_pub.publish(vehicleGuidance);
		}

		r.sleep();
	}

	return 0;
}
