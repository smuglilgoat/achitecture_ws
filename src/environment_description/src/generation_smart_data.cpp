#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include "project_s_msgs/GenericSmartData.h"
#include "project_s_msgs/ObstacleReport.h"

#include <mobileye_560_660_msgs/Tsr.h>

#define LARGEUR_VOIE		3.50
#define RAYON_1			20.0
#define LONGUEUR_LIGNE_1	20.0
#define RAYON_2			5.0
#define LONGUEUR_LIGNE_2	17.0

int main(int argc, char** argv){
  ros::init(argc, argv, "data_generator");

  ros::NodeHandle n;
  ros::Publisher obstacle_pub = n.advertise<project_s_msgs::ObstacleReport>("/obstacles", 1);
//  tf::TransformBroadcaster odom_broadcaster;

  project_s_msgs::ObstacleReport tableauSmartData;
  std_msgs::UInt8 QtySmartData;

  // conditions initiales
  double x = (RAYON_1 - LARGEUR_VOIE/2.0);
  double y = 0.0;
  double th = -M_PI/2;
  //double v/* = 5.0*/;
  double T = 0;
  double Tangle = 0;

  double x2 = -(RAYON_1 - LARGEUR_VOIE/2.0);
  double y2 = - LONGUEUR_LIGNE_1;
  double th2 = M_PI/2;
  double T2 = 0;
  double Tangle2 = 0;

  double dt;

  int i;

  int ChgtVirage, ChgtVirage2;	// flag de chgt

  ros::Time current_time, last_time;
  last_time = ros::Time::now();

  ros::Rate r(1000.0);	// F = 1000Hz <=> 1ms

  while(n.ok()){

    ros::spinOnce();               // check for incoming messages
    current_time = ros::Time::now();

    QtySmartData.data = 0;

tableauSmartData.id.data = 11;
tableauSmartData.header.stamp = current_time;

    // objet fixe
    tableauSmartData.GenericSmartData[0].header.frame_id = "/odom";
    tableauSmartData.GenericSmartData[0].header.stamp = current_time;
    tableauSmartData.GenericSmartData[0].id.data = 1;
    tableauSmartData.GenericSmartData[0].obstaclePosition.position.x = 0;
    tableauSmartData.GenericSmartData[0].obstaclePosition.position.y = RAYON_1; 
    tableauSmartData.GenericSmartData[0].obstaclePosition.position.z = 0;
    tableauSmartData.GenericSmartData[0].obstacleVelocity.linear.x = 0;
    tableauSmartData.GenericSmartData[0].obstacleVelocity.linear.y = 0;
    tableauSmartData.GenericSmartData[0].obstacleVelocity.linear.z = 0;
    tableauSmartData.GenericSmartData[0].obstaclePosition.orientation = tf::createQuaternionMsgFromYaw(0);
    tableauSmartData.GenericSmartData[0].obstacleDimensions.x = 1;
    tableauSmartData.GenericSmartData[0].obstacleDimensions.y = 1;
    tableauSmartData.GenericSmartData[0].obstacleDimensions.z = 1;
    tableauSmartData.GenericSmartData[0].obstacleClass = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_PLOT;
    QtySmartData.data++;

    // objet fixe
    tableauSmartData.GenericSmartData[1].header.frame_id = "/odom";
    tableauSmartData.GenericSmartData[1].header.stamp = current_time;
    tableauSmartData.GenericSmartData[1].id.data = 2;
bool pieton;
if (n.hasParam("/pieton")) n.getParam("/pieton", pieton);
//if(pieton) tableauSmartData.GenericSmartData[1].obstaclePosition.position.x = -(RAYON_1 + LARGEUR_VOIE - LARGEUR_VOIE/2.0);
//else
    tableauSmartData.GenericSmartData[1].obstaclePosition.position.x = -(RAYON_1 + LARGEUR_VOIE);
    tableauSmartData.GenericSmartData[1].obstaclePosition.position.y = 0;
    tableauSmartData.GenericSmartData[1].obstaclePosition.position.z = 0;
    tableauSmartData.GenericSmartData[1].obstacleVelocity.linear.x = 0;
    tableauSmartData.GenericSmartData[1].obstacleVelocity.linear.y = 0;
    tableauSmartData.GenericSmartData[1].obstacleVelocity.linear.z = 0;
    tableauSmartData.GenericSmartData[1].obstaclePosition.orientation = tf::createQuaternionMsgFromYaw(0);
    tableauSmartData.GenericSmartData[1].obstacleDimensions.x = 1;
    tableauSmartData.GenericSmartData[1].obstacleDimensions.y = 1;
    tableauSmartData.GenericSmartData[1].obstacleDimensions.z = 1;
    tableauSmartData.GenericSmartData[1].obstacleClass = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN;
    tableauSmartData.GenericSmartData[1].vision_only_sign_type = mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_90;
    QtySmartData.data++;

    // objet fixe
    tableauSmartData.GenericSmartData[2].header.frame_id = "/odom";
    tableauSmartData.GenericSmartData[2].header.stamp = current_time;
    tableauSmartData.GenericSmartData[2].id.data = 3;
if(pieton) tableauSmartData.GenericSmartData[2].obstaclePosition.position.x = -(RAYON_1 + LARGEUR_VOIE/2.0);
else
    tableauSmartData.GenericSmartData[2].obstaclePosition.position.x = -(RAYON_1 - LARGEUR_VOIE);
    tableauSmartData.GenericSmartData[2].obstaclePosition.position.y = -LONGUEUR_LIGNE_1;
    tableauSmartData.GenericSmartData[2].obstaclePosition.position.z = 0;
    tableauSmartData.GenericSmartData[2].obstacleVelocity.linear.x = 0;
    tableauSmartData.GenericSmartData[2].obstacleVelocity.linear.y = 0;
    tableauSmartData.GenericSmartData[2].obstacleVelocity.linear.z = 0;
    tableauSmartData.GenericSmartData[2].obstaclePosition.orientation = tf::createQuaternionMsgFromYaw(0);
    tableauSmartData.GenericSmartData[2].obstacleDimensions.x = 1;
    tableauSmartData.GenericSmartData[2].obstacleDimensions.y = 1;
    tableauSmartData.GenericSmartData[2].obstacleDimensions.z = 1;
    tableauSmartData.GenericSmartData[2].obstacleClass = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN;
    tableauSmartData.GenericSmartData[2].vision_only_sign_type = mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_50;
    QtySmartData.data++;

    // objet fixe
    tableauSmartData.GenericSmartData[3].header.frame_id = "/odom";
    tableauSmartData.GenericSmartData[3].header.stamp = current_time;
    tableauSmartData.GenericSmartData[3].id.data = 4;
    tableauSmartData.GenericSmartData[3].obstaclePosition.position.x =  RAYON_1 + 1.5*LARGEUR_VOIE;
    tableauSmartData.GenericSmartData[3].obstaclePosition.position.y = -RAYON_1;
    tableauSmartData.GenericSmartData[3].obstaclePosition.position.z = 0;
    tableauSmartData.GenericSmartData[3].obstacleVelocity.linear.x = 0;
    tableauSmartData.GenericSmartData[3].obstacleVelocity.linear.y = 0;
    tableauSmartData.GenericSmartData[3].obstacleVelocity.linear.z = 0;
    tableauSmartData.GenericSmartData[3].obstaclePosition.orientation = tf::createQuaternionMsgFromYaw(0);
    tableauSmartData.GenericSmartData[3].obstacleDimensions.x = 1;
    tableauSmartData.GenericSmartData[3].obstacleDimensions.y = 1;
    tableauSmartData.GenericSmartData[3].obstacleDimensions.z = 1;
    tableauSmartData.GenericSmartData[3].obstacleClass = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN;
    tableauSmartData.GenericSmartData[3].vision_only_sign_type = mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_50;
    QtySmartData.data++;

    // objet fixe
    tableauSmartData.GenericSmartData[4].header.frame_id = "/odom";
    tableauSmartData.GenericSmartData[4].header.stamp = current_time;
    tableauSmartData.GenericSmartData[4].id.data = 5;
    tableauSmartData.GenericSmartData[4].obstaclePosition.position.x =  RAYON_1;
    tableauSmartData.GenericSmartData[4].obstaclePosition.position.y = -RAYON_1/2;
    tableauSmartData.GenericSmartData[4].obstaclePosition.position.z = 0;
    tableauSmartData.GenericSmartData[4].obstacleVelocity.linear.x = 0;
    tableauSmartData.GenericSmartData[4].obstacleVelocity.linear.y = 0;
    tableauSmartData.GenericSmartData[4].obstacleVelocity.linear.z = 0;
    tableauSmartData.GenericSmartData[4].obstaclePosition.orientation = tf::createQuaternionMsgFromYaw(0);
    tableauSmartData.GenericSmartData[4].obstacleDimensions.x = 1;
    tableauSmartData.GenericSmartData[4].obstacleDimensions.y = 1;
    tableauSmartData.GenericSmartData[4].obstacleDimensions.z = 1;
    tableauSmartData.GenericSmartData[4].obstacleClass = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_PLOT;

    QtySmartData.data++;

    // objet dynamique
    dt = (current_time - last_time).toSec();

  // calculs des durées de déplacement pour chaque tronçons
  double vx7 = 15.0;
  double duree_deplacement_7 = 25.6;
  duree_deplacement_7 /= vx7;
  //duree_deplacement_7 += 0;
  vx7 *= -1;

  double vx6 = 5.0;	// virage intérieur
  double duree_deplacement_6 = 2*M_PI*(RAYON_2 - LARGEUR_VOIE/2.0)/2.0*0.75;
  duree_deplacement_6 /= vx6;
  duree_deplacement_6 += duree_deplacement_7;
  vx6 *= -1;

  double vx5 = 15.0;
  double duree_deplacement_5 = LONGUEUR_LIGNE_2;
  duree_deplacement_5 /= vx5;
  duree_deplacement_5 += duree_deplacement_6;
  vx5 *= -1;

  double vx4 = 8.0;	// virage extérieur
  double duree_deplacement_4 = 2*M_PI*(RAYON_2 + LARGEUR_VOIE/2.0)/2.0*0.75;
  duree_deplacement_4 /= vx4;
  duree_deplacement_4 += duree_deplacement_5;
  vx4 *= -1;

  double vx3 = 5.0;	// virage intérieur
  double duree_deplacement_3 = 2*M_PI*(RAYON_2 - LARGEUR_VOIE/2.0)/2.0;
  duree_deplacement_3 /= vx3;
  duree_deplacement_3 += duree_deplacement_4;
  vx3 *= -1;

  double vx2 = 15.0;
  double duree_deplacement_2 = LONGUEUR_LIGNE_1;
  duree_deplacement_2 /= vx2;
  duree_deplacement_2 += duree_deplacement_3;
  vx2 *= -1;

  double vx1 = 10.0;
  double duree_deplacement_1 = 2*M_PI*(RAYON_1 - LARGEUR_VOIE/2.0)/2.0;
  duree_deplacement_1 /= vx1;
  duree_deplacement_1 += duree_deplacement_2;
  vx1 *= -1;

  T += dt;	// 40ms car 25 Hz
/*
// pour rendre le véhicule immobile
// et mettre en commentaires la màj tableauSmartData.GenericSmartData[5] plus bas
geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(-M_PI/2);

tableauSmartData.GenericSmartData[5].header.frame_id = "/odom";
tableauSmartData.GenericSmartData[5].header.stamp = current_time;
tableauSmartData.GenericSmartData[5].id.data = 6;
tableauSmartData.GenericSmartData[5].obstaclePosition.position.x = (RAYON_1 - LARGEUR_VOIE/2.0);
tableauSmartData.GenericSmartData[5].obstaclePosition.position.y = 0;
tableauSmartData.GenericSmartData[5].obstaclePosition.position.z = 0;
tableauSmartData.GenericSmartData[5].obstacleVelocity.linear.x = 0;
tableauSmartData.GenericSmartData[5].obstacleVelocity.linear.y = 0;
tableauSmartData.GenericSmartData[5].obstacleVelocity.linear.z = 0;
tableauSmartData.GenericSmartData[5].obstaclePosition.orientation = odom_quat;
tableauSmartData.GenericSmartData[5].obstacleDimensions.x = 4;
tableauSmartData.GenericSmartData[5].obstacleDimensions.y = 2;
tableauSmartData.GenericSmartData[5].obstacleDimensions.z = 1;
QtySmartData.data++;*/

  // ligne droite de x metre
  if(T < duree_deplacement_7)
  {
    x = (RAYON_1 - LARGEUR_VOIE/2.0);
    y += dt*vx7;
    th = -M_PI/2;
    Tangle = 0;
  }
  // 4ème virage
  else if(T < duree_deplacement_6)
  {
    x = (RAYON_2 - LARGEUR_VOIE/2.0) * cos(vx6*Tangle/(RAYON_2 - LARGEUR_VOIE/2.0)) + (RAYON_1 - RAYON_2);
    y = (RAYON_2 - LARGEUR_VOIE/2.0) * sin(vx6*Tangle/(RAYON_2 - LARGEUR_VOIE/2.0)) - 25.6;
    th = -M_PI/2 + vx6*Tangle/(RAYON_2 - LARGEUR_VOIE/2.0);
    Tangle += dt;
  }
  // ligne droite de LONGUEUR_LIGNE_2
  else if(T < duree_deplacement_5)
  {
    x += dt*vx5/1.4142;
    y += dt*(-vx5)/1.4142;
    th = 0.75*M_PI;
    Tangle = 0;
  }
  // 3ème virage
  else if(T < duree_deplacement_4)
  {
    x = (RAYON_2 + LARGEUR_VOIE/2.0) * cos(-vx4*Tangle/(RAYON_2 + LARGEUR_VOIE/2.0) + M_PI*0.25) - (RAYON_1 - RAYON_2 - 2*RAYON_2);
    y = (RAYON_2 + LARGEUR_VOIE/2.0) * sin(-vx4*Tangle/(RAYON_2 + LARGEUR_VOIE/2.0) + M_PI*0.25) - LONGUEUR_LIGNE_1;
    th = 0.75*M_PI - vx4*Tangle/(RAYON_2 + LARGEUR_VOIE/2.0);
    Tangle += dt;
    ChgtVirage = 1;	// flag de chgt, sert à clearer le Tangle
  }
  // 2ème virage
  else if(T < duree_deplacement_3)
  {
    if(ChgtVirage)
    {
      ChgtVirage=0;
      Tangle = 0;
    }
    x = (RAYON_2 - LARGEUR_VOIE/2.0) * cos(vx3*Tangle/(RAYON_2 - LARGEUR_VOIE/2.0)) - (RAYON_1 - RAYON_2);
    y = (RAYON_2 - LARGEUR_VOIE/2.0) * sin(vx3*Tangle/(RAYON_2 - LARGEUR_VOIE/2.0)) - LONGUEUR_LIGNE_1;
    th = -M_PI/2 + vx3*Tangle/(RAYON_2 - LARGEUR_VOIE/2.0);
    Tangle += dt;
  }
  // ligne droite de LONGUEUR_LIGNE_1
  else if(T < duree_deplacement_2)
  {
    x = -(RAYON_1 - LARGEUR_VOIE/2.0);
    y += dt*(-vx2);
    th = +M_PI/2;
    Tangle = 0;
  }
  // 1er virage
  else if(T < duree_deplacement_1)
  {
    x = (RAYON_1 - LARGEUR_VOIE/2.0) * cos(vx1*Tangle/(RAYON_1 - LARGEUR_VOIE/2.0) + M_PI);
    y = (RAYON_1 - LARGEUR_VOIE/2.0) * sin(vx1*Tangle/(RAYON_1 - LARGEUR_VOIE/2.0) + M_PI);
    th = +M_PI/2 + vx1*Tangle/(RAYON_1 - LARGEUR_VOIE/2.0);
    Tangle += dt;
  }
  else
  {
    T = 0;	// clear du temps, pour refaire une boucle
    y = 0;
  }

    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

    tableauSmartData.GenericSmartData[5].header.frame_id = "/odom";
    tableauSmartData.GenericSmartData[5].header.stamp = current_time;
    tableauSmartData.GenericSmartData[5].id.data = 6;
    tableauSmartData.GenericSmartData[5].obstaclePosition.position.x = x;
    tableauSmartData.GenericSmartData[5].obstaclePosition.position.y = y;
    tableauSmartData.GenericSmartData[5].obstaclePosition.position.z = 0;
    tableauSmartData.GenericSmartData[5].obstaclePosition.orientation = odom_quat;
    tableauSmartData.GenericSmartData[5].obstacleDimensions.x = 4;
    tableauSmartData.GenericSmartData[5].obstacleDimensions.y = 2;
    tableauSmartData.GenericSmartData[5].obstacleDimensions.z = 1;
    QtySmartData.data++;

  // 2ème véhicule
  // calculs des durées de déplacement pour chaque tronçons
  vx2 = 15.0;
  double duree2_deplacement_2 = LONGUEUR_LIGNE_1;
  duree2_deplacement_2 /= vx2;
  //duree2_deplacement_2 += 0;
  vx2 *= -1;

  vx1 = 10.0;
  double duree2_deplacement_1 = 2*M_PI*(RAYON_1 - LARGEUR_VOIE/2.0)/2.0;
  duree2_deplacement_1 /= vx1;
  duree2_deplacement_1 += duree2_deplacement_2;
  vx1 *= -1;

  vx7 = 15.0;
  double duree2_deplacement_7 = 25.6;
  duree2_deplacement_7 /= vx7;
  duree2_deplacement_7 += duree2_deplacement_1;
  vx7 *= -1;

  vx6 = 5.0;	// virage intérieur
  double duree2_deplacement_6 = 2*M_PI*(RAYON_2 - LARGEUR_VOIE/2.0)/2.0*0.75;
  duree2_deplacement_6 /= vx6;
  duree2_deplacement_6 += duree2_deplacement_7;
  vx6 *= -1;

  vx5 = 15.0;
  double duree2_deplacement_5 = LONGUEUR_LIGNE_2;
  duree2_deplacement_5 /= vx5;
  duree2_deplacement_5 += duree2_deplacement_6;
  vx5 *= -1;

  vx4 = 8.0;	// virage extérieur
  double duree2_deplacement_4 = 2*M_PI*(RAYON_2 + LARGEUR_VOIE/2.0)/2.0*0.75;
  duree2_deplacement_4 /= vx4;
  duree2_deplacement_4 += duree2_deplacement_5;
  vx4 *= -1;

  vx3 = 5.0;	// virage intérieur
  double duree2_deplacement_3 = 2*M_PI*(RAYON_2 - LARGEUR_VOIE/2.0)/2.0;
  duree2_deplacement_3 /= vx3;
  duree2_deplacement_3 += duree2_deplacement_4;
  vx3 *= -1;

/*
// pour rendre le véhicule immobile
// et mettre en commentaires la màj tableauSmartData.GenericSmartData[6] plus bas
geometry_msgs::Quaternion odom_quat2 = tf::createQuaternionMsgFromYaw(+M_PI/2);

tableauSmartData.GenericSmartData[6].header.frame_id = "/odom";
tableauSmartData.GenericSmartData[6].header.stamp = current_time;
tableauSmartData.GenericSmartData[6].id.data = 7;
tableauSmartData.GenericSmartData[6].obstaclePosition.position.x = -(RAYON_1 - LARGEUR_VOIE/2.0);
tableauSmartData.GenericSmartData[6].obstaclePosition.position.y = 0;
tableauSmartData.GenericSmartData[6].obstaclePosition.position.z = 0;
tableauSmartData.GenericSmartData[0].obstacleVelocity.linear.x = 0;
tableauSmartData.GenericSmartData[0].obstacleVelocity.linear.y = 0;
tableauSmartData.GenericSmartData[0].obstacleVelocity.linear.z = 0;
tableauSmartData.GenericSmartData[6].obstaclePosition.orientation = odom_quat2;
tableauSmartData.GenericSmartData[6].obstacleDimensions.x = 4;
tableauSmartData.GenericSmartData[6].obstacleDimensions.y = 2;
tableauSmartData.GenericSmartData[6].obstacleDimensions.z = 1;
QtySmartData.data++;*/

  // ligne droite de x metre
  // ligne droite de LONGUEUR_LIGNE_1
  if(T < duree2_deplacement_2)
  {
    x2 = -(RAYON_1 - LARGEUR_VOIE/2.0);
    y2 += dt*(-vx2);
    th2 = +M_PI/2;
    Tangle2 = 0;
  }
  // 1er virage
  else if(T < duree2_deplacement_1)
  {
    x2 = (RAYON_1 - LARGEUR_VOIE/2.0) * cos(vx1*Tangle2/(RAYON_1 - LARGEUR_VOIE/2.0) + M_PI);
    y2 = (RAYON_1 - LARGEUR_VOIE/2.0) * sin(vx1*Tangle2/(RAYON_1 - LARGEUR_VOIE/2.0) + M_PI);
    th2 = +M_PI/2 + vx1*Tangle2/(RAYON_1 - LARGEUR_VOIE/2.0);
    Tangle2 += dt;
  }
  else if(T < duree2_deplacement_7)
  {
    x2 = (RAYON_1 - LARGEUR_VOIE/2.0);
    y2 += dt*vx7;
    th2 = -M_PI/2;
    Tangle2 = 0;
  }
  // 4ème virage
  else if(T < duree2_deplacement_6)
  {
    x2 = (RAYON_2 - LARGEUR_VOIE/2.0) * cos(vx6*Tangle2/(RAYON_2 - LARGEUR_VOIE/2.0)) + (RAYON_1 - RAYON_2);
    y2 = (RAYON_2 - LARGEUR_VOIE/2.0) * sin(vx6*Tangle2/(RAYON_2 - LARGEUR_VOIE/2.0)) - 25.6;
    th2 = -M_PI/2 + vx6*Tangle2/(RAYON_2 - LARGEUR_VOIE/2.0);
    Tangle2 += dt;
  }
  // ligne droite de LONGUEUR_LIGNE_2
  else if(T < duree2_deplacement_5)
  {
    x2 += dt*vx5/1.4142;
    y2 += dt*(-vx5)/1.4142;
    th2 = 0.75*M_PI;
    Tangle2 = 0;
  }
  // 3ème virage
  else if(T < duree2_deplacement_4)
  {
    x2 = (RAYON_2 + LARGEUR_VOIE/2.0) * cos(-vx4*Tangle2/(RAYON_2 + LARGEUR_VOIE/2.0) + M_PI*0.25) - (RAYON_1 - RAYON_2 - 2*RAYON_2);
    y2 = (RAYON_2 + LARGEUR_VOIE/2.0) * sin(-vx4*Tangle2/(RAYON_2 + LARGEUR_VOIE/2.0) + M_PI*0.25) - LONGUEUR_LIGNE_1;
    th2 = 0.75*M_PI - vx4*Tangle2/(RAYON_2 + LARGEUR_VOIE/2.0);
    Tangle2 += dt;
    ChgtVirage2 = 1;	// flag de chgt, sert à clearer le Tangle2
  }
  // 2ème virage
  else if(T < duree2_deplacement_3)
  {
    if(ChgtVirage2)
    {
      ChgtVirage2=0;
      Tangle2 = 0;
    }
    x2 = (RAYON_2 - LARGEUR_VOIE/2.0) * cos(vx3*Tangle2/(RAYON_2 - LARGEUR_VOIE/2.0)) - (RAYON_1 - RAYON_2);
    y2 = (RAYON_2 - LARGEUR_VOIE/2.0) * sin(vx3*Tangle2/(RAYON_2 - LARGEUR_VOIE/2.0)) - LONGUEUR_LIGNE_1;
    th2 = -M_PI/2 + vx3*Tangle2/(RAYON_2 - LARGEUR_VOIE/2.0);
    Tangle2 += dt;
  }
  else
  {
    T = 0;	// clear du temps, pour refaire une boucle
    y2 = - LONGUEUR_LIGNE_1;
  }

    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat2 = tf::createQuaternionMsgFromYaw(th2);

    tableauSmartData.GenericSmartData[6].header.frame_id = "/odom";
    tableauSmartData.GenericSmartData[6].header.stamp = current_time;
    tableauSmartData.GenericSmartData[6].id.data = 7;
    tableauSmartData.GenericSmartData[6].obstaclePosition.position.x = x2;
    tableauSmartData.GenericSmartData[6].obstaclePosition.position.y = y2;
    tableauSmartData.GenericSmartData[6].obstaclePosition.position.z = 0;
    tableauSmartData.GenericSmartData[6].obstaclePosition.orientation = odom_quat2;
    tableauSmartData.GenericSmartData[6].obstacleDimensions.x = 4;
    tableauSmartData.GenericSmartData[6].obstacleDimensions.y = 2;
    tableauSmartData.GenericSmartData[6].obstacleDimensions.z = 1;
    QtySmartData.data++;

    tableauSmartData.QtySmartData = QtySmartData;

    //publish the message
    obstacle_pub.publish(tableauSmartData);

    last_time = current_time;
    r.sleep();
  }
}
