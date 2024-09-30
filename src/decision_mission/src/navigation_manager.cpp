#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h> 
#include <sys/timeb.h>
#include <sys/time.h>  
#include <sstream>
#include <ros/callback_queue.h>
#include <iostream>
#include <string>
#include <vector>

#include "ros/ros.h"

#include "std_msgs/UInt32.h"
#include "project_s_msgs/Line.h"

#include <fstream>
using namespace std;

#define NBRE_POINT_HUIT	76
typedef struct{
	float x;
	float y;
}point;
point Tableau_circuit_huit[NBRE_POINT_HUIT] = {
{0,0},
{1.09,0},
{2.18,0},
{3.28,0},
{4.37,0},
{6.59,0.21},
{8.73,0.82},
{10.73,1.82},
{12.5,3.18},
{13.99,4.83},
{15.15,6.74},
{15.94,8.83},
{16.33,11.02},
{16.3,13.25},
{15.86,15.44},
{15.03,17.51},
{13.82,19.39},
{12.29,21.01},
{10.49,22.32},
{8.47,23.28},
{6.31,23.84},
{4.09,24},
{1.87,23.74},
{-0.26,23.07},
{-2.23,22.03},
{-3.97,20.63},
{-5.42,18.94},
{-6.54,17.01},
{-7.28,14.9},
{-7.61,12.7},
{-7.53,10.47},
{-7.05,8.29},
{-6.16,6.24},
{-4.91,4.39},
{-3.35,2.81},
{-2.51,2.11},
{-1.67,1.4},
{-0.84,0.7},
{0,0},
{0.84,-0.7},
{1.67,-1.4},
{2.51,-2.11},
{3.35,-2.81},
{4.91,-4.39},
{6.16,-6.24},
{7.05,-8.29},
{7.53,-10.47},
{7.61,-12.7},
{7.28,-14.9},
{6.54,-17.01},
{5.42,-18.94},
{3.97,-20.63},
{2.23,-22.03},
{0.26,-23.07},
{-1.87,-23.74},
{-4.09,-24},
{-6.31,-23.84},
{-8.47,-23.28},
{-10.49,-22.32},
{-12.29,-21.01},
{-13.82,-19.39},
{-15.03,-17.51},
{-15.86,-15.44},
{-16.3,-13.25},
{-16.33,-11.02},
{-15.94,-8.83},
{-15.15,-6.74},
{-13.99,-4.83},
{-12.5,-3.18},
{-10.73,-1.82},
{-8.73,-0.82},
{-6.59,-0.21},
{-4.37,0},
{-3.28,0},
{-2.18,0},
{-1.09,0},
};

#define NBRE_POINT_SQUARE	92
point Tableau_circuit_square[NBRE_POINT_SQUARE] = {
{0,0},
{1.333,0},
{2.666,0},
{3.999,0},
{5.332,0},
{6.665,0},
{7.998,0},
{9.331,0},
{10.664,0},
{11.997,0},
{13.33,0},
{14.663,0},
{15.996,0},
{17.329,0},
{18.662,0},
{19.995,0},
{20.975,0.1},
{21.905,0.38},
{22.775,0.84},
{23.535,1.46},
{24.155,2.22},
{24.615,3.09},
{24.895,4.02},
{24.995,5},
{24.995,6.333},
{24.995,7.666},
{24.995,8.999},
{24.995,10.332},
{24.995,11.665},
{24.995,12.998},
{24.995,14.331},
{24.995,15.664},
{24.995,16.997},
{24.995,18.33},
{24.995,19.663},
{24.995,20.996},
{24.995,22.329},
{24.995,23.662},
{24.995,24.995},
{24.895,25.975},
{24.615,26.905},
{24.155,27.775},
{23.535,28.535},
{22.775,29.155},
{21.905,29.615},
{20.975,29.895},
{19.995,29.995},
{18.662,29.995},
{17.329,29.995},
{15.996,29.995},
{14.663,29.995},
{13.33,29.995},
{11.997,29.995},
{10.664,29.995},
{9.331,29.995},
{7.998,29.995},
{6.665,29.995},
{5.332,29.995},
{3.999,29.995},
{2.666,29.995},
{1.333,29.995},
{0,29.995},
{-0.98,29.895},
{-1.91,29.615},
{-2.78,29.155},
{-3.54,28.535},
{-4.16,27.775},
{-4.62,26.905},
{-4.9,25.975},
{-5,24.995},
{-5,23.662},
{-5,22.329},
{-5,20.996},
{-5,19.663},
{-5,18.33},
{-5,16.997},
{-5,15.664},
{-5,14.331},
{-5,12.998},
{-5,11.665},
{-5,10.332},
{-5,8.999},
{-5,7.666},
{-5,6.333},
{-5,5},
{-4.9,4.02},
{-4.62,3.09},
{-4.16,2.22},
{-3.54,1.46},
{-2.78,0.84},
{-1.91,0.38},
{-0.98,0.1},
};
// Buffers
project_s_msgs::Line Circuit;
std_msgs::UInt32 mission_manager_nbr;

// Callback functions for receiving topics
bool receivedMissionManager = false;
void missionManagerCallback(const std_msgs::UInt32::ConstPtr& msg)
{
	mission_manager_nbr = *msg;

	receivedMissionManager = true;
}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("controle_circuit"));

	ros::NodeHandle n;

	ros::Publisher pub_navigation_manager = n.advertise<project_s_msgs::Line>(std::string("/navigation_manager"), 1);

	ros::Subscriber sub_mission_manager_nbr = n.subscribe(std::string("/mission_manager_nbr"), 1, missionManagerCallback);

	ros::Rate loop_rate(10);
/*
char a[80];
int i = 0;
ifstream myfile("file/carre_30m.csv");
while(!myfile.eof()){
	myfile >> a;
	cout << a << endl;
}
myfile.close();
*/

	while(n.ok())
	{
		ros::spinOnce();

		if(receivedMissionManager){
			receivedMissionManager = false;

			switch(mission_manager_nbr.data){
			case 1:
				Circuit.lineClass.data = NBRE_POINT_SQUARE;	// on se sert de lineClass pour renseigner sur le nbre de points du circuit
				for(int i = 0; i < NBRE_POINT_SQUARE; i++){
					Circuit.segment[i].position.x = Tableau_circuit_square[i].x;
					Circuit.segment[i].position.y = Tableau_circuit_square[i].y;
				}
				break;
			case 2:
				Circuit.lineClass.data = NBRE_POINT_HUIT;
				for(int i = 0; i < NBRE_POINT_HUIT; i++){
					Circuit.segment[i].position.x = Tableau_circuit_huit[i].x;
					Circuit.segment[i].position.y = Tableau_circuit_huit[i].y;
				}
				break;
			default :
				break;
			}

			pub_navigation_manager.publish(Circuit);
		}

		loop_rate.sleep();		
	}

	return 0;
}
