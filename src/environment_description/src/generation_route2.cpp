#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <tf/transform_broadcaster.h>
#include "project_s_msgs/RouteLine.h"

#include "project_s_msgs/Tableau_Circuit.h"

#include <cmath>

#define LARGEUR_VOIE		3.50
#define RAYON_1			20.0
#define LONGUEUR_LIGNE_1	20.0
#define RAYON_2			5.0
#define LONGUEUR_LIGNE_2	13.0

//#define LATITUDE_ORIGIN	+48.80
//#define LONGITUDE_ORIGIN	+01.98
#define LATITUDE_ORIGIN		+48.7965
#define LONGITUDE_ORIGIN	+ 1.9872
#define RAYON_TERRE		6371000.0
#define X_ORIGIN		0.0
#define Y_ORIGIN		0.0

int main( int argc, char** argv )
{
  ros::init(argc, argv, "points_and_lines");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("/lines_marker", 3);	// affichage jusqu'à 3 lignes

  ros::Publisher line_pub = n.advertise<project_s_msgs::RouteLine>("/line_data", 1);

  // A FAIRE : pas de rafraichissement, envoi du topic en one shot 
  ros::Rate r(1);

  while (ros::ok())
  {

    visualization_msgs::Marker line_strip;
    line_strip.header.frame_id = "/odom";
    line_strip.header.stamp = ros::Time::now();
    line_strip.ns = "points_and_lines";
    line_strip.action = visualization_msgs::Marker::ADD;
    line_strip.pose.orientation = tf::createQuaternionMsgFromYaw(0);

    visualization_msgs::Marker line_strip_2;
    line_strip_2.header.frame_id = "/odom";
    line_strip_2.header.stamp = ros::Time::now();
    line_strip_2.ns = "points_and_lines";
    line_strip_2.action = visualization_msgs::Marker::ADD;
    line_strip_2.pose.orientation = tf::createQuaternionMsgFromYaw(0);

    visualization_msgs::Marker line_strip_3;
    line_strip_3.header.frame_id = "/odom";
    line_strip_3.header.stamp = ros::Time::now();
    line_strip_3.ns = "points_and_lines";
    line_strip_3.action = visualization_msgs::Marker::ADD;
    line_strip_3.pose.orientation = tf::createQuaternionMsgFromYaw(0);

    line_strip.id = 1;
    line_strip_2.id = 2;
    line_strip_3.id = 3;

    line_strip.type   = visualization_msgs::Marker::LINE_STRIP;
    line_strip_2.type = visualization_msgs::Marker::LINE_LIST;
    line_strip_3.type = visualization_msgs::Marker::LINE_STRIP;

    project_s_msgs::RouteLine line;
    uint32_t i_1 = 0;
    uint32_t i_2 = 0;
    uint32_t i_3 = 0;
    uint32_t i_4 = 0;

    // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
    line_strip.scale.x = 0.1;
    line_strip_2.scale.x = 0.1;
    line_strip_3.scale.x = 0.1;

    // Line strip is red //blue
    line_strip.color.r = 1.0;
    line_strip.color.g = 1.0;
    line_strip.color.b = 1.0;
    line_strip.color.a = 1.0;

    line_strip_2.color.r = 1.0;
    line_strip_2.color.g = 1.0;
    line_strip_2.color.b = 1.0;
    line_strip_2.color.a = 1.0;

    line_strip_3.color.r = 1.0;
    line_strip_3.color.g = 1.0;
    line_strip_3.color.b = 1.0;
    line_strip_3.color.a = 1.0;

    // Create the vertices for the points and lines
    geometry_msgs::Point precedent, derive;
    precedent.x = RAYON_1;
    precedent.y = 0;

double delta_latitude;
double delta_longitude;

float SommeCurvi = 0;

    // 1er virage
    for (uint32_t i = 0; i <= 50; ++i)
    {
      float x = RAYON_1 * cos(i / 100.0f * 2 * M_PI);
      float y = RAYON_1 * sin(i / 100.0f * 2 * M_PI);

      derive.x = x - precedent.x;
      derive.y = y - precedent.y;
      derive.z = sqrt(derive.x*derive.x + derive.y*derive.y); // on se sert de derive.z comme buffer
//SommeCurvi += derive.z;
SommeCurvi += (RAYON_1 + LARGEUR_VOIE/2.0)*2*M_PI / 100.0;
      if(derive.z == 0)
        derive.z = 1;
      derive.x /= derive.z;
      derive.y /= derive.z;

      geometry_msgs::Point p;
      // ligne red
      p.x = x - LARGEUR_VOIE*derive.y;
      p.y = y + LARGEUR_VOIE*derive.x;
      p.z = 0;
      if(i == 0)
      {
        p.x = RAYON_1 - LARGEUR_VOIE;
        p.y = 0.0;

SommeCurvi = 0;
      }

      line_strip.points.push_back(p);
      line.line[2].segment[i_1].position = p;
delta_latitude  = + (p.x - X_ORIGIN) /  RAYON_TERRE                                  * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[2].segment[i_1].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[2].segment[i_1].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[2].segment[i_1].offset    = SommeCurvi;
      i_1++;

      // ligne white (milieu)
      p.x = x;
      p.y = y;
      if(i == 0)
      {
        p.x = RAYON_1;
        p.y = 0.0;
      }

      line_strip_2.points.push_back(p);
      line.line[1].segment[i_2].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[1].segment[i_2].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[1].segment[i_2].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[1].segment[i_2].offset    = SommeCurvi;
      i_2++;

      // ligne blue
      p.x = x + LARGEUR_VOIE*derive.y;
      p.y = y - LARGEUR_VOIE*derive.x;
      if(i == 0)
      {
        p.x = RAYON_1 + LARGEUR_VOIE;
        p.y = 0.0;
      }

      line_strip_3.points.push_back(p);
      line.line[0].segment[i_3].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[0].segment[i_3].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[0].segment[i_3].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[0].segment[i_3].offset    = SommeCurvi;
      i_3++;

// ligne trajectoire GPS
p.x = x + LARGEUR_VOIE/2.0*derive.y;
p.y = y - LARGEUR_VOIE/2.0*derive.x;
if(i == 0)
{
p.x = RAYON_1 + LARGEUR_VOIE/2.0;
p.y = 0.0;
}

line.line[3].segment[i_4].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[3].segment[i_4].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[3].segment[i_4].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[3].segment[i_4].offset    = SommeCurvi;
i_4++;

      precedent.x = x;
      precedent.y = y;
    }

//SommeCurvi = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI;

    // ligne droite de LONGUEUR_LIGNE_1 metres, sur 10 pts
    for (uint32_t i = 0; i < 10; ++i)
    {
      float x = precedent.x;
      float y = precedent.y - (LONGUEUR_LIGNE_1 / 10);

      derive.x = x - precedent.x;
      derive.y = y - precedent.y;
      derive.z = sqrt(derive.x*derive.x + derive.y*derive.y); // on se sert de derive.z comme buffer
//SommeCurvi += derive.z;
SommeCurvi += LONGUEUR_LIGNE_1 / 10.0;
      if(derive.z == 0)
        derive.z = 1;
      derive.x /= derive.z;
      derive.y /= derive.z;

      // ligne red
      geometry_msgs::Point p;
      p.x = x - LARGEUR_VOIE*derive.y;
      p.y = y + LARGEUR_VOIE*derive.x;
      p.z = 0;

      line_strip.points.push_back(p);
      line.line[2].segment[i_1].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[2].segment[i_1].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[2].segment[i_1].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[2].segment[i_1].offset    = SommeCurvi;
      i_1++;

      // ligne white (milieu)
      p.x = x;
      p.y = y;

      line_strip_2.points.push_back(p);
      line.line[1].segment[i_2].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[1].segment[i_2].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[1].segment[i_2].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[1].segment[i_2].offset    = SommeCurvi;
      i_2++;

      // ligne blue
      p.x = x + LARGEUR_VOIE*derive.y;
      p.y = y - LARGEUR_VOIE*derive.x;

      line_strip_3.points.push_back(p);
      line.line[0].segment[i_3].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[0].segment[i_3].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[0].segment[i_3].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[0].segment[i_3].offset    = SommeCurvi;
      i_3++;

// ligne trajectoire GPS
p.x = x + LARGEUR_VOIE/2.0*derive.y;
p.y = y - LARGEUR_VOIE/2.0*derive.x;

line.line[3].segment[i_4].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[3].segment[i_4].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[3].segment[i_4].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[3].segment[i_4].offset    = SommeCurvi;
i_4++;

      precedent.x = x;
      precedent.y = y;
    }

//SommeCurvi = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1;

    // 2ème virage
    for (uint32_t i = 51; i <= 100; ++i)
    {
      float x = RAYON_2 * cos(i / 100.0f * 2 * M_PI) - (RAYON_1 - RAYON_2);
      float y = RAYON_2 * sin(i / 100.0f * 2 * M_PI) - LONGUEUR_LIGNE_1;

      derive.x = x - precedent.x;
      derive.y = y - precedent.y;
      derive.z = sqrt(derive.x*derive.x + derive.y*derive.y); // on se sert de derive.z comme buffer
//SommeCurvi += derive.z;
SommeCurvi += (RAYON_2 + LARGEUR_VOIE/2.0)*2*M_PI / 100.0;
      if(derive.z == 0)
        derive.z = 1;
      derive.x /= derive.z;
      derive.y /= derive.z;

      // ligne red
      geometry_msgs::Point p;
      p.x = x - LARGEUR_VOIE*derive.y;
      p.y = y + LARGEUR_VOIE*derive.x;
      p.z = 0;

      line_strip.points.push_back(p);
      line.line[2].segment[i_1].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[2].segment[i_1].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[2].segment[i_1].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[2].segment[i_1].offset    = SommeCurvi;
      i_1++;

      // ligne white (milieu)
      p.x = x;
      p.y = y;

      line_strip_2.points.push_back(p);
      line.line[1].segment[i_2].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[1].segment[i_2].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[1].segment[i_2].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[1].segment[i_2].offset    = SommeCurvi;
      i_2++;

      // ligne blue
      p.x = x + LARGEUR_VOIE*derive.y;
      p.y = y - LARGEUR_VOIE*derive.x;

      line_strip_3.points.push_back(p);
      line.line[0].segment[i_3].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[0].segment[i_3].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[0].segment[i_3].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[0].segment[i_3].offset    = SommeCurvi;
      i_3++;

// ligne trajectoire GPS
p.x = x + LARGEUR_VOIE/2.0*derive.y;
p.y = y - LARGEUR_VOIE/2.0*derive.x;

line.line[3].segment[i_4].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[3].segment[i_4].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[3].segment[i_4].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[3].segment[i_4].offset    = SommeCurvi;
i_4++;

      precedent.x = x;
      precedent.y = y;
    }

//SommeCurvi = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI;

    // 3ème virage
    for (uint32_t i = 49; i > 12; --i)
    {
      float x = RAYON_2 * cos(i / 100.0f * 2 * M_PI) - (RAYON_1 - RAYON_2 - 2* RAYON_2);
      float y = RAYON_2 * sin(i / 100.0f * 2 * M_PI) - LONGUEUR_LIGNE_1;

      derive.x = x - precedent.x;
      derive.y = y - precedent.y;
      derive.z = sqrt(derive.x*derive.x + derive.y*derive.y); // on se sert de derive.z comme buffer
//SommeCurvi += derive.z;
SommeCurvi += (RAYON_2 - LARGEUR_VOIE/2.0)*2*M_PI / 100.0;
      if(derive.z == 0)
        derive.z = 1;
      derive.x /= derive.z;
      derive.y /= derive.z;

      // ligne red
      geometry_msgs::Point p;
      p.x = x - LARGEUR_VOIE*derive.y;
      p.y = y + LARGEUR_VOIE*derive.x;
      p.z = 0;

      line_strip.points.push_back(p);
      line.line[2].segment[i_1].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[2].segment[i_1].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[2].segment[i_1].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[2].segment[i_1].offset    = SommeCurvi;
      i_1++;

      // ligne white (milieu)
      p.x = x;
      p.y = y;

      line_strip_2.points.push_back(p);
      line.line[1].segment[i_2].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[1].segment[i_2].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[1].segment[i_2].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[1].segment[i_2].offset    = SommeCurvi;
      i_2++;

      // ligne blue
      p.x = x + LARGEUR_VOIE*derive.y;
      p.y = y - LARGEUR_VOIE*derive.x;

      line_strip_3.points.push_back(p);
      line.line[0].segment[i_3].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[0].segment[i_3].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[0].segment[i_3].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[0].segment[i_3].offset    = SommeCurvi;
      i_3++;

// ligne trajectoire GPS
p.x = x + LARGEUR_VOIE/2.0*derive.y;
p.y = y - LARGEUR_VOIE/2.0*derive.x;

line.line[3].segment[i_4].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[3].segment[i_4].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[3].segment[i_4].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[3].segment[i_4].offset    = SommeCurvi;
i_4++;

      precedent.x = x;
      precedent.y = y;
    }

//SommeCurvi = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76;

    // ligne droite de LONGUEUR_LIGNE_2 metres, sur 10 pts
    for (uint32_t i = 0; i < 10; ++i)
    {
      float x = precedent.x + (LONGUEUR_LIGNE_2 / 10);
      float y = precedent.y - (LONGUEUR_LIGNE_2 / 10);

      derive.x = x - precedent.x;
      derive.y = y - precedent.y;
      derive.z = sqrt(derive.x*derive.x + derive.y*derive.y); // on se sert de derive.z comme buffer
//SommeCurvi += derive.z;
SommeCurvi += sqrt(2*LONGUEUR_LIGNE_2*LONGUEUR_LIGNE_2) / 10.0;
      if(derive.z == 0)
        derive.z = 1;
      derive.x /= derive.z;
      derive.y /= derive.z;

      // ligne red
      geometry_msgs::Point p;
      p.x = x - LARGEUR_VOIE*derive.y;
      p.y = y + LARGEUR_VOIE*derive.x;
      p.z = 0;

      line_strip.points.push_back(p);
      line.line[2].segment[i_1].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[2].segment[i_1].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[2].segment[i_1].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[2].segment[i_1].offset    = SommeCurvi;
      i_1++;

      // ligne white (milieu)
      p.x = x;
      p.y = y;

      line_strip_2.points.push_back(p);
      line.line[1].segment[i_2].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[1].segment[i_2].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[1].segment[i_2].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[1].segment[i_2].offset    = SommeCurvi;
      i_2++;

      // ligne blue
      p.x = x + LARGEUR_VOIE*derive.y;
      p.y = y - LARGEUR_VOIE*derive.x;

      line_strip_3.points.push_back(p);
      line.line[0].segment[i_3].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[0].segment[i_3].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[0].segment[i_3].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[0].segment[i_3].offset    = SommeCurvi;
      i_3++;

// ligne trajectoire GPS
p.x = x + LARGEUR_VOIE/2.0*derive.y;
p.y = y - LARGEUR_VOIE/2.0*derive.x;

line.line[3].segment[i_4].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[3].segment[i_4].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[3].segment[i_4].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[3].segment[i_4].offset    = SommeCurvi;
i_4++;

      precedent.x = x;
      precedent.y = y;
    }

//SommeCurvi = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 + sqrt(2*LONGUEUR_LIGNE_2*LONGUEUR_LIGNE_2);

    // 4ème virage
    float Xr = precedent.x - RAYON_2 * cos(62.0 / 100.0f * 2 * M_PI);
    float Yr = precedent.y - RAYON_2 * sin(62.0 / 100.0f * 2 * M_PI);
    for (uint32_t i = 63; i < 101; ++i)
    {
      float x = RAYON_2 * cos(i / 100.0f * 2 * M_PI) + Xr;
      float y = RAYON_2 * sin(i / 100.0f * 2 * M_PI) + Yr;

      derive.x = x - precedent.x;
      derive.y = y - precedent.y;
      derive.z = sqrt(derive.x*derive.x + derive.y*derive.y); // on se sert de derive.z comme buffer
//SommeCurvi += derive.z;
SommeCurvi += (RAYON_2 + LARGEUR_VOIE/2.0)*2*M_PI / 100.0;
      if(derive.z == 0)
        derive.z = 1;
      derive.x /= derive.z;
      derive.y /= derive.z;

      // ligne red
      geometry_msgs::Point p;
      p.x = x - LARGEUR_VOIE*derive.y;
      p.y = y + LARGEUR_VOIE*derive.x;
      p.z = 0;

      line_strip.points.push_back(p);
      line.line[2].segment[i_1].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[2].segment[i_1].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[2].segment[i_1].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[2].segment[i_1].offset    = SommeCurvi;
      i_1++;

      // ligne white (milieu)
      p.x = x;
      p.y = y;

      line_strip_2.points.push_back(p);
      line.line[1].segment[i_2].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[1].segment[i_2].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[1].segment[i_2].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[1].segment[i_2].offset    = SommeCurvi;
      i_2++;

      // ligne blue
      p.x = x + LARGEUR_VOIE*derive.y;
      p.y = y - LARGEUR_VOIE*derive.x;

      line_strip_3.points.push_back(p);
      line.line[0].segment[i_3].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[0].segment[i_3].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[0].segment[i_3].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[0].segment[i_3].offset    = SommeCurvi;
      i_3++;

// ligne trajectoire GPS
p.x = x + LARGEUR_VOIE/2.0*derive.y;
p.y = y - LARGEUR_VOIE/2.0*derive.x;

line.line[3].segment[i_4].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[3].segment[i_4].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[3].segment[i_4].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[3].segment[i_4].offset    = SommeCurvi;
i_4++;

      precedent.x = x;
      precedent.y = y;
    }

//SommeCurvi = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 + sqrt(2*LONGUEUR_LIGNE_2*LONGUEUR_LIGNE_2) + \
             (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76;

    Yr = 0 - precedent.y;
    // ligne droite de x metres, sur 10 pts
    for (uint32_t i = 0; i < 10; ++i)
    {
      float x = precedent.x;
      float y = precedent.y + (Yr / 10);

      derive.x = x - precedent.x;
      derive.y = y - precedent.y;
      derive.z = sqrt(derive.x*derive.x + derive.y*derive.y); // on se sert de derive.z comme buffer
//SommeCurvi += derive.z;
SommeCurvi += 26.6 / 10.0;
      if(derive.z == 0)
        derive.z = 1;
      derive.x /= derive.z;
      derive.y /= derive.z;

      // ligne red
      geometry_msgs::Point p;
      p.x = x - LARGEUR_VOIE*derive.y;
      p.y = y + LARGEUR_VOIE*derive.x;
      p.z = 0;

      line_strip.points.push_back(p);
      line.line[2].segment[i_1].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[2].segment[i_1].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[2].segment[i_1].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[2].segment[i_1].offset    = SommeCurvi;
      i_1++;

      // ligne white (milieu)
      p.x = x;
      p.y = y;

      line_strip_2.points.push_back(p);
      line.line[1].segment[i_2].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[1].segment[i_2].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[1].segment[i_2].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[1].segment[i_2].offset    = SommeCurvi;
      i_2++;

      // ligne blue
      p.x = x + LARGEUR_VOIE*derive.y;
      p.y = y - LARGEUR_VOIE*derive.x;

      line_strip_3.points.push_back(p);
      line.line[0].segment[i_3].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[0].segment[i_3].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[0].segment[i_3].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[0].segment[i_3].offset    = SommeCurvi;
      i_3++;

// ligne trajectoire GPS
p.x = x + LARGEUR_VOIE/2.0*derive.y;
p.y = y - LARGEUR_VOIE/2.0*derive.x;

line.line[3].segment[i_4].position = p;
delta_latitude  = + (p.x - X_ORIGIN) / RAYON_TERRE                                   * 180.0 / M_PI;
delta_longitude = - (p.y - Y_ORIGIN) / (RAYON_TERRE*cos(LATITUDE_ORIGIN/180.0*M_PI)) * 180.0 / M_PI;
line.line[3].segment[i_4].latitude  = LATITUDE_ORIGIN  + delta_latitude;
line.line[3].segment[i_4].longitude = LONGITUDE_ORIGIN + delta_longitude;
line.line[3].segment[i_4].offset    = SommeCurvi;
i_4++;

      precedent.x = x;
      precedent.y = y;
    }

// ajout Tableau_Circuit.h dans line.line[3]
for(uint i=0; i<NBRE_POINT_TABLEAU_GPS; i++){
line.line[3].segment[i].latitude  = Tableau_circuit_GPS[i].latitude;	// coord GPS
line.line[3].segment[i].longitude = Tableau_circuit_GPS[i].longitude;
line.line[3].segment[i].offset    = Tableau_circuit_GPS[i].offset;
}
line.line[3].QtySegment.data = NBRE_POINT_TABLEAU_GPS;

    marker_pub.publish(line_strip);
    marker_pub.publish(line_strip_2);
    marker_pub.publish(line_strip_3);

    line_pub.publish(line);

    r.sleep();
  }

  return 0;
}
