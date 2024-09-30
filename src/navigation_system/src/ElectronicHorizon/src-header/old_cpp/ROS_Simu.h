#ifndef ROS_SIMU_H
#define ROS_SIMU_H

#include <vector>

//--------------------------------------------------------------------------------------------------------
// ROS ElectronicHorizon/MapMatching/RoutePlanning Messages Type Definition (for simulation purpose only)
//--------------------------------------------------------------------------------------------------------

namespace std_msgs
{
	typedef unsigned int time;

	struct Header
	{
		unsigned int seq;
		time stamp;
		std::string frame_id;
	};

	struct UInt8
	{
		unsigned char data;
	};

	struct UInt32
	{
		unsigned int data;
	};

	struct UInt16
	{
		unsigned short data;
	};

	struct Float32
	{
		float data;
	};

	struct Bool
	{
		bool data;
	};
}

namespace geometry_msgs
{
	struct Vector3
	{
		double x;
		double y;
		double z;
	};

	struct Twist
	{
		Vector3  linear;
		Vector3  angular;
	};

	struct Quaternion
	{
		double x;
		double y;
		double z;
		double w;
	};

	struct Point
	{
		double x;
		double y;
		double z;
	};

	struct Pose
	{
		Point position;
		Quaternion orientation;
	};

	struct PoseWithCovariance
	{
		Pose pose;
		double covariance[36];
	};

	struct TwistWithCovariance
	{
		Twist twist;
		double covariance[36];
	};
}

namespace nav_msgs
{
	struct Odometry
	{
		std_msgs::Header header;
		std::string child_frame_id;
		geometry_msgs::PoseWithCovariance pose;
		geometry_msgs::TwistWithCovariance twist;
	};
}

namespace project_s_msgs
{
	struct ehSegment
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std_msgs::Float32 offset;
		std_msgs::UInt8 functionRoadClass;
		std_msgs::UInt8 wayForm;
		std_msgs::UInt8 effectiveSpeedLimit;
		std_msgs::UInt8 nbLanesDrivingDirection;
		std_msgs::UInt8 nbLanesOppositeDirection;
	};

	struct ehStub
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std_msgs::Float32 offset;
		std_msgs::UInt8 indexSubPath;
		std_msgs::Float32 turnAngle;
		std_msgs::UInt8 functionRoadClass;
		std_msgs::UInt8 wayForm;
		std_msgs::UInt8 nbLanesDrivingDirection;
		std_msgs::UInt8 nbLanesOppositeDirection;
	};

	struct ehSpotCurvature
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std_msgs::Float32 offset;
		std_msgs::Float32 Value_0;
		std_msgs::Float32 Distance_1;
		std_msgs::Float32 Value_1;
	};

	struct ehSpotCoordGeo
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std_msgs::Float32 offset;
		double latitude;
		double longitude;
	};

	struct ehLineCoordGeo
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		ehSpotCoordGeo ehSpotCoordGeo[100];
		std_msgs::UInt8 NbrSpotCoordGeo;
	};

	struct ehNbrLineCoordGeo
	{
		std_msgs::UInt8 Nbr;
		std_msgs::Float32 offset;
	};

	struct ehSpotTrafficSign
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std_msgs::Float32 offset;
		unsigned char Sign_Type;
		unsigned char Value;
		unsigned char Lane;
		unsigned char Sign_Location;
	};

	struct ehPosition
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std_msgs::Float32 offset;
		std_msgs::Float32 latitude;
		std_msgs::Float32 longitude;
		std_msgs::Float32 cap;
		std_msgs::UInt16 agePosition;
		std_msgs::Float32 speed;
		std_msgs::Float32 relativeHeading;
		std_msgs::UInt8 currentLane;
	};

	struct ElectronicHorizon
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std_msgs::UInt8 indexPath;

		ehSegment ehSegment[10];
		std_msgs::UInt8 NbrSegment;

		ehStub ehStub[10];
		std_msgs::UInt8 NbrStub;

		ehSpotCurvature ehSpotCurvature[50];
		std_msgs::UInt8 NbrSpotCurvature;

		ehSpotCoordGeo ehSpotCoordGeoRight[250];
		std_msgs::UInt8 NbrSpotCoordGeoRight;
		ehSpotCoordGeo ehSpotCoordGeoLeft[250];
		std_msgs::UInt8 NbrSpotCoordGeoLeft;

		ehLineCoordGeo ehLineCoordGeo[10];
		std_msgs::UInt8 QtyLineCoordGeo;

		ehNbrLineCoordGeo ehNbrLineCoordGeo[100];
		std_msgs::UInt8 QtyNbrLineCoordGeo;

		ehSpotTrafficSign ehSpotTrafficSign[10];
		std_msgs::UInt8 NbrSpotTrafficSign;

		ehPosition ehPosition;
	};

	struct ElectronicHorizonArray
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		ElectronicHorizon PathsArray[5];
		std_msgs::UInt8 NbrPath;
		std_msgs::UInt8 indexMPP;

		nav_msgs::Odometry odom;
	};

	struct Segment
	{
		std_msgs::Float32 length;
		std_msgs::Float32 angle;
		geometry_msgs::Point position;
		geometry_msgs::Twist Velocity;

		double latitude;
		double longitude;
		float offset;
	};

	struct point_GPS	// !!!
	{
		float latitude;
		float longitude;
		float offset;
	};

	struct speed_limit	// !!!
	{
		float offset;
		unsigned char effectiveSpeedLimit;
	};

	struct curvature	// !!!
	{
		float offset;
		float value;
	};

	struct traffic_sign	// !!!
	{
		float offset;
		unsigned char Sign_Type;
		unsigned char Value;
		unsigned char Lane;
		unsigned char Sign_Location;
	};

	struct RoutePlanning	// !!!
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std::vector<Segment> roadSegment;
		std_msgs::UInt8 nbrLane;
		std_msgs::UInt8 intersection;

		std::vector<unsigned int> list_Links_ID;
		std::vector<unsigned int> list_Links_HEREtile_ID;
		std::vector<unsigned int> list_Nodes_ID;
		std::vector<unsigned int> list_Nodes_HEREtile_ID;
		std::vector<bool> list_Links_vs_Route_direction;
		unsigned int LIST_LINKS_SIZE;

		unsigned char NBRE_POINT_CIRCUIT_GPS;
		unsigned char NBRE_POINT_TABLEAU_GPS;

		std::vector<point_GPS> Tableau_circuit_GPS;
		std::vector<point_GPS> Tableau_circuit_GPS_gauche;
		std::vector<point_GPS> Tableau_circuit_GPS_droite;
		std::vector<speed_limit> Tableau_circuit_speedlimit;
		std::vector<curvature> Tableau_circuit_curvature;
		std::vector<traffic_sign> Tableau_circuit_trafficsign;
	};

	struct MapMatching	// !!!
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		std_msgs::UInt32 link_ID;
		std_msgs::UInt32 link_HEREtile_ID;
		std_msgs::Float32 Distance_Curviligne_Ego;
		std_msgs::Float32 latitude;
		std_msgs::Float32 longitude;
		std_msgs::Float32 cap;
	};

	struct EgoData	// !!!
	{
		std_msgs::time stamp;

		double latitude;
		double longitude;
		double cap;
	};

	struct EgoDataReport	// !!!
	{
		std_msgs::Header header;
		std_msgs::UInt8 id;

		EgoData EgoData[10];
	};
}

#endif // !ROS_SIMU_H