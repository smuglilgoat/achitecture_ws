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
//#include <iostream>
//#include <string>
//#include <vector>

#include "ros/ros.h"

#include "project_s_msgs/ObstacleReport.h"
#include "project_s_msgs/ObstacleAlignmentReport.h"
#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/LaneAlignment.h"

#include <can_msgs/Frame.h>

#include <mobileye_560_660_msgs/Lane.h>
#include <mobileye_560_660_msgs/LkaLane.h>
#include <mobileye_560_660_msgs/LkaReferencePoints.h>
#include <mobileye_560_660_msgs/AftermarketLane.h>
#include <mobileye_560_660_msgs/LkaNumOfNextLaneMarkersReported.h>

#include <mobileye_560_660_msgs/ObstacleData.h>
#include <mobileye_560_660_msgs/ObstacleStatus.h>

#include <mobileye_560_660_msgs/Ahbc.h>
#include <mobileye_560_660_msgs/AhbcGradual.h>
#include <mobileye_560_660_msgs/AwsDisplay.h>
#include <mobileye_560_660_msgs/FixedFoe.h>

#include <mobileye_560_660_msgs/Tsr.h>
#include <mobileye_560_660_msgs/TsrVisionOnly.h>

#include <visualization_msgs/Marker.h>
//#include <perception_msgs/LaneModels.h>
//#include <perception_msgs/ObjectWithCovariance.h>
#include <derived_object_msgs/LaneModels.h>
#include <derived_object_msgs/ObjectWithCovariance.h>

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport extractedObstacle;
project_s_msgs::RouteLine      extractedLine;

can_msgs::Frame can_tx;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport reportObstacle;
project_s_msgs::RouteLine      reportLine;

can_msgs::Frame can_rx;

mobileye_560_660_msgs::Lane Lane;
mobileye_560_660_msgs::LkaLane left_lka_lane, right_lka_lane, next_lka_lane;
mobileye_560_660_msgs::LkaReferencePoints lka_reference_points;
mobileye_560_660_msgs::AftermarketLane aftermarket_lane;
mobileye_560_660_msgs::LkaNumOfNextLaneMarkersReported lka_num_of_next_lane;

mobileye_560_660_msgs::ObstacleData obstacle_data;
mobileye_560_660_msgs::ObstacleStatus obstacle_status;

mobileye_560_660_msgs::Ahbc ahbc;
mobileye_560_660_msgs::AhbcGradual ahbc_gradual;
mobileye_560_660_msgs::AwsDisplay aws_display;
mobileye_560_660_msgs::FixedFoe fixed_foe;

mobileye_560_660_msgs::Tsr tsr;
mobileye_560_660_msgs::TsrVisionOnly tsr_vision_only;

visualization_msgs::Marker lane_markers, object_markers;
//perception_msgs::LaneModels lane_models;
//perception_msgs::ObjectWithCovariance object_detected;
derived_object_msgs::LaneModels lane_models;
derived_object_msgs::ObjectWithCovariance object_detected;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool obstacleReceived = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& ObstacleArray)
{
	extractedObstacle = *ObstacleArray;

	obstacleReceived = true;
}

bool routeLineReceived = false;
void linesDataCallback(const project_s_msgs::RouteLine::ConstPtr& routeLine)
{
	extractedLine = *routeLine;

	routeLineReceived = true;
}

bool can_tx_Received = false;
void cantxCallback(const can_msgs::Frame::ConstPtr& buffer)
{
	can_tx = *buffer;

	can_tx_Received = true;
}

//#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
//int polynomial_fit()
int polynomial_fit(int N, double x[], double y[], double coeff[3+1])
{
//    int i,j,k,n,N;
int i,j,k;
int n = 3;			// n is the degree of Polynomial 
    cout.precision(4);                        //set precision
    cout.setf(ios::fixed);
//    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays that will store x,y, and z values
//    cin>>N;
//    double x[N],y[N];
//    cout<<"\nEnter the x-axis values:\n";                //Input x-values
//    for (i=0;i<N;i++)
//        cin>>x[i];
//    cout<<"\nEnter the y-axis values:\n";                //Input y-values
//    for (i=0;i<N;i++)
//        cin>>y[i];
//    cout<<"\nWhat degree of Polynomial do you want to use for the fit?\n";
//    cin>>n;                                // n is the degree of Polynomial 
    double X[2*n+1];                        //Array that will store the values of sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
    for (i=0;i<2*n+1;i++)
    {
        X[i]=0;
        for (j=0;j<N;j++)
            X[i]=X[i]+pow(x[j],i);        //consecutive positions of the array will store N,sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
    }
    double B[n+1][n+2],a[n+1];            //B is the Normal matrix(augmented) that will store the equations, 'a' is for value of the final coefficients
    for (i=0;i<=n;i++)
        for (j=0;j<=n;j++)
            B[i][j]=X[i+j];            //Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix
    double Y[n+1];                    //Array to store the values of sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    for (i=0;i<n+1;i++)
    {    
        Y[i]=0;
        for (j=0;j<N;j++)
        Y[i]=Y[i]+pow(x[j],i)*y[j];        //consecutive positions will store sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    }
    for (i=0;i<=n;i++)
        B[i][n+1]=Y[i];                //load the values of Y as the last column of B(Normal Matrix but augmented)
    n=n+1;                //n is made n+1 because the Gaussian Elimination part below was for n equations, but here n is the degree of polynomial and for n degree we get n+1 equations
    cout<<"\nThe Normal(Augmented Matrix) is as follows:\n";    
    for (i=0;i<n;i++)            //print the Normal-augmented matrix
    {
        for (j=0;j<=n;j++)
            cout<<B[i][j]<<setw(16);
        cout<<"\n";
    }    
    for (i=0;i<n;i++)                    //From now Gaussian Elimination starts(can be ignored) to solve the set of linear equations (Pivotisation)
        for (k=i+1;k<n;k++)
            if (B[i][i]<B[k][i])
                for (j=0;j<=n;j++)
                {
                    double temp=B[i][j];
                    B[i][j]=B[k][j];
                    B[k][j]=temp;
                }
    
    for (i=0;i<n-1;i++)            //loop to perform the gauss elimination
        for (k=i+1;k<n;k++)
            {
                double t=B[k][i]/B[i][i];
                for (j=0;j<=n;j++)
                    B[k][j]=B[k][j]-t*B[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
            }
    for (i=n-1;i>=0;i--)                //back-substitution
    {                        //x is an array whose values correspond to the values of x,y,z..
        a[i]=B[i][n];                //make the variable to be calculated equal to the rhs of the last equation
        for (j=0;j<n;j++)
            if (j!=i)            //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                a[i]=a[i]-B[i][j]*a[j];
        a[i]=a[i]/B[i][i];            //now finally divide the rhs by the coefficient of the variable to be calculated
    }
    cout<<"\nThe values of the coefficients are as follows:\n";
    for (i=0;i<n;i++)
        cout<<"x^"<<i<<"="<<a[i]<<endl;            // Print the values of x^0,x^1,x^2,x^3,....    
    cout<<"\nHence the fitted Polynomial is given by:\ny=";
    for (i=0;i<n;i++)
        cout<<" + ("<<a[i]<<")"<<"x^"<<i;
    cout<<"\n";
for(i=0;i<n;i++)
coeff[i] = a[i];
    return 0;
}//output attached as .jpg

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "camera_me_data_extraction");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_obstacles   = n.advertise<project_s_msgs::ObstacleReport>(std::string("/camera_me_data_extraction_obstacle"),    1);	
	ros::Publisher pub_route_lines = n.advertise<project_s_msgs::RouteLine>     (std::string("/camera_me_data_extraction_route_lines"), 1);

	ros::Publisher pub_can_rx = n.advertise<can_msgs::Frame>(std::string("/can_rx"), 1);

	ros::Publisher pub_lane                 = n.advertise<mobileye_560_660_msgs::Lane>                           (std::string("/parsed_tx/lane"),                                  1);
	ros::Publisher pub_left_lka_lane        = n.advertise<mobileye_560_660_msgs::LkaLane>                        (std::string("/parsed_tx/left_lka_lane"),                         1);
	ros::Publisher pub_right_lka_lane       = n.advertise<mobileye_560_660_msgs::LkaLane>                        (std::string("/parsed_tx/right_lka_lane"),                        1);
	ros::Publisher pub_next_lka_lane        = n.advertise<mobileye_560_660_msgs::LkaLane>                        (std::string("/parsed_tx/next_lka_lane"),                         1);
	ros::Publisher pub_lka_reference_points = n.advertise<mobileye_560_660_msgs::LkaReferencePoints>             (std::string("/parsed_tx/lka_reference_points"),                  1);
	ros::Publisher pub_aftermarket_lane     = n.advertise<mobileye_560_660_msgs::AftermarketLane>                (std::string("/parsed_tx/aftermarket_lane"),                      1);
	ros::Publisher pub_lka_num_of_next_lane = n.advertise<mobileye_560_660_msgs::LkaNumOfNextLaneMarkersReported>(std::string("/parsed_tx/lka_num_of_next_lane_markers_reported"), 1);

	ros::Publisher pub_obstacle_data   = n.advertise<mobileye_560_660_msgs::ObstacleData>  (std::string("/parsed_tx/obstacle_data"),   1);
	ros::Publisher pub_obstacle_status = n.advertise<mobileye_560_660_msgs::ObstacleStatus>(std::string("/parsed_tx/obstacle_status"), 1);

	ros::Publisher pub_ahbc         = n.advertise<mobileye_560_660_msgs::Ahbc>       (std::string("/parsed_tx/ahbc"),         1);
	ros::Publisher pub_ahbc_gradual = n.advertise<mobileye_560_660_msgs::AhbcGradual>(std::string("/parsed_tx/ahbc_gradual"), 1);
	ros::Publisher pub_aws_display  = n.advertise<mobileye_560_660_msgs::AwsDisplay> (std::string("/parsed_tx/aws_display"),  1);
	ros::Publisher pub_fixed_foe    = n.advertise<mobileye_560_660_msgs::FixedFoe>   (std::string("/parsed_tx/fixed_foe"),    1);

	ros::Publisher pub_tsr             = n.advertise<mobileye_560_660_msgs::Tsr>          (std::string("/parsed_tx/pub_tsr"),             1);
	ros::Publisher pub_tsr_vision_only = n.advertise<mobileye_560_660_msgs::TsrVisionOnly>(std::string("/parsed_tx/pub_tsr_vision_only"), 1);

	ros::Publisher pub_lane_markers   = n.advertise<visualization_msgs::Marker>(std::string("/as_tx/lane_markers"),   1);
	ros::Publisher pub_object_markers = n.advertise<visualization_msgs::Marker>(std::string("/as_tx/object_markers"), 1);

//	ros::Publisher pub_lane_models = n.advertise<perception_msgs::LaneModels>(std::string("/as_tx/lane_models"), 1);
//	ros::Publisher pub_objects = n.advertise<perception_msgs::ObjectWithCovariance>(std::string("/as_tx/objects"), 1);
	ros::Publisher pub_lane_models = n.advertise<derived_object_msgs::LaneModels>(std::string("/as_tx/lane_models"), 1);
	ros::Publisher pub_objects = n.advertise<derived_object_msgs::ObjectWithCovariance>(std::string("/as_tx/objects"), 1);

	// Subscriber
	ros::Subscriber subData  = n.subscribe(std::string("/camera_me_obstacle"),    1, obstacleDataCallback);
	ros::Subscriber subLines = n.subscribe(std::string("/camera_me_route_lines"), 1, linesDataCallback);

	ros::Subscriber sub_can_tx = n.subscribe(std::string("/can_tx"), 1, cantxCallback);

	ros::Rate loop_rate(1000);
/*
int N;
cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays that will store x,y, and z values
cin>>N;
double x[N],y[N];
x[0]=0;x[1]=1;x[2]=2;x[3]=3;x[4]=4;
y[0]=1;y[1]=1.8;y[2]=1.3;y[3]=2.5;y[4]=6.3;
polynomial_fit(N, x, y);
*/
  	while(n.ok())
	{
		ros::spinOnce();

		if(obstacleReceived)
		{
			obstacleReceived = false;

			reportObstacle = extractedObstacle;

			pub_obstacles.publish(reportObstacle);
		}

		if(routeLineReceived)
		{
			routeLineReceived = false;

			reportLine = extractedLine;

			pub_route_lines.publish(reportLine);

Lane.lane_curvature = 0;
pub_lane.publish(Lane);

//-----
left_lka_lane = mobileye_560_660_msgs::LkaLane();
left_lka_lane.header = extractedLine.header;

int N;
N = extractedLine.line[1].QtySegment.data;
if(N >= 2){
double x[N],y[N];
for (int i=0;i<N;i++)
x[i] = extractedLine.line[1].segment[i].position.x;
for (int i=0;i<N;i++)
y[i] = extractedLine.line[1].segment[i].position.y;
double coeff[3+1];
polynomial_fit(N, x, y, coeff);

left_lka_lane.position_parameter_c0             = coeff[0];
left_lka_lane.heading_angle_parameter_c1        = coeff[1];
left_lka_lane.curvature_parameter_c2            = coeff[2];
left_lka_lane.curvature_derivative_parameter_c3 = coeff[3];
left_lka_lane.marking_width = x[0];	// A REVOIR
left_lka_lane.view_range = x[N-1];

//left_lka_lane.lane_type = mobileye_560_660_msgs::LkaLane::LANE_TYPE_DASHED;
pub_left_lka_lane.publish(left_lka_lane);
}

//-----
right_lka_lane = mobileye_560_660_msgs::LkaLane();
right_lka_lane.header = extractedLine.header;

//int N;
N = extractedLine.line[0].QtySegment.data;
if(N >= 2){
double x[N],y[N];
for (int i=0;i<N;i++)
x[i] = extractedLine.line[0].segment[i].position.x;
for (int i=0;i<N;i++)
y[i] = extractedLine.line[0].segment[i].position.y;
double coeff[3+1];
polynomial_fit(N, x, y, coeff);

right_lka_lane.position_parameter_c0             = coeff[0];
right_lka_lane.heading_angle_parameter_c1        = coeff[1];
right_lka_lane.curvature_parameter_c2            = coeff[2];
right_lka_lane.curvature_derivative_parameter_c3 = coeff[3];
right_lka_lane.marking_width = x[0];	// A REVOIR
right_lka_lane.view_range = x[N-1];

//right_lka_lane.lane_type = mobileye_560_660_msgs::LkaLane::LANE_TYPE_SOLID;
pub_right_lka_lane.publish(right_lka_lane);
}

//-----
next_lka_lane = mobileye_560_660_msgs::LkaLane();
next_lka_lane.header = extractedLine.header;

//int N;
N = extractedLine.line[2].QtySegment.data;
if(N >= 2){
double x[N],y[N];
for (int i=0;i<N;i++)
x[i] = extractedLine.line[2].segment[i].position.x;
for (int i=0;i<N;i++)
y[i] = extractedLine.line[2].segment[i].position.y;
double coeff[3+1];
polynomial_fit(N, x, y, coeff);

next_lka_lane.position_parameter_c0             = coeff[0];
next_lka_lane.heading_angle_parameter_c1        = coeff[1];
next_lka_lane.curvature_parameter_c2            = coeff[2];
next_lka_lane.curvature_derivative_parameter_c3 = coeff[3];
next_lka_lane.marking_width = x[0];	// A REVOIR
next_lka_lane.view_range = x[N-1];

//next_lka_lane.quality = mobileye_560_660_msgs::LkaLane::LANE_CONFIDENCE_HIGH;
pub_next_lka_lane.publish(next_lka_lane);
}

//-----

lka_reference_points.ref_point_1_position = 0;
pub_lka_reference_points.publish(lka_reference_points);

aftermarket_lane.lane_confidence_left = mobileye_560_660_msgs::AftermarketLane::LANE_CONFIDENCE_NONE;
pub_aftermarket_lane.publish(aftermarket_lane);

lka_num_of_next_lane.num_of_next_lane_markers_reported = 0;
pub_lka_num_of_next_lane.publish(lka_num_of_next_lane);

obstacle_data.blinker_info = mobileye_560_660_msgs::ObstacleData::BLINKER_INFO_BOTH;
pub_obstacle_data.publish(obstacle_data);

obstacle_status.right_close_range_cut_in = false;
pub_obstacle_status.publish(obstacle_status);

lane_markers.ns = "lane";
pub_lane_markers.publish(lane_markers);

object_markers.ns = "object";
pub_object_markers.publish(object_markers);

object_detected.pose.pose.position.x = 0;
pub_objects.publish(object_detected);

ahbc.high_low_beam_decision = mobileye_560_660_msgs::Ahbc::HIGH_LOW_BEAM_DECISION_NO_RECOMMENDATION;
pub_ahbc.publish(ahbc);

ahbc_gradual.object_distance_hlb = 0;
pub_ahbc_gradual.publish(ahbc_gradual);

aws_display.sound_type = mobileye_560_660_msgs::AwsDisplay::SOUND_SILENT;
pub_aws_display.publish(aws_display);

fixed_foe.fixed_yaw = 0;
pub_fixed_foe.publish(fixed_foe);

tsr.vision_only_sign_type = mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_10;
pub_tsr.publish(tsr);

tsr_vision_only.vision_only_sign_type_display1 = 0;
pub_tsr_vision_only.publish(tsr_vision_only);

pub_lane_models.publish(lane_models);
		}

		loop_rate.sleep();
	}

	return 0;
}
