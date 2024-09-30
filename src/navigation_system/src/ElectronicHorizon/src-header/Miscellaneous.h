#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#include "Header.h"

//----------
// Constant
//----------
const double PI(3.1415926535);

//-------------------------
// Intermediate structures
//-------------------------

struct GpsCoord
{
	double lat;
	double lon;
};

struct CartoCoord
{
	double x;
	double y;
};

//-----------
// Functions
//-----------

::google::protobuf::uint32 getTileIDfromLatLon(double latitude, double longitude);

CartoCoord convLatLonToXY(GpsCoord gps);

GpsCoord twoDToLatLon(::google::protobuf::int64 coordinate);

double pointTOpointDistance(GpsCoord point1, GpsCoord point2);

#endif // !MISCELLANEOUS_H
