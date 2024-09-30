#include "Miscellaneous.h"

using namespace std;

::google::protobuf::uint32 getTileIDfromLatLon(double latitude, double longitude)
{
	// Get the tile's id in which the input GPS coordinate lies
	// Method cf HERE doc

	::google::protobuf::uint16 x, y, m;
	::google::protobuf::uint32 z(0);
	x = floor((longitude + 180.0) * 16384.0 / 360.0);
	y = floor((latitude + 90.0) * 16384.0 / 360.0);

	x += 0x4000;
	for (int i(0), m = 0x8000; i < 16; i++)
	{
		z += y & m;
		z <<= 1;
		z += x & m;
		m /= 2;
	}

	return z;
}

CartoCoord convLatLonToXY(GpsCoord gps)
{
	// Lambert conformal conic 9 zones projection (CC49)
	// Transform GPS geographic coordinate system into cartographic projected flat coordinate system

	const double PHI0(49.0);
	const double LAMBDA0(3.0);
	const double PHI1(48.25);
	const double PHI2(49.75);
	const double X0(1700000.0);
	const double Y0(8200000.0);
	const double A(6378137.0);
	const double F = 1.0 / 298.257222101;
	const double B = A * (1 - F);
	const double E = sqrt((A * A - B * B) / (A * A));

	CartoCoord carto;

	const double n = (log(cos(PHI2 * PI / 180.0) / cos(PHI1 * PI / 180.0)) + 0.5 * log((1.0 - pow(E * sin(PHI1 * PI / 180.0), 2.0)) / (1.0 - pow(E * sin(PHI2 * PI / 180.0), 2.0)))) / log((tan((PHI1 * PI / 180.0) / 2.0 + PI / 4.0) * pow((1.0 - E * sin(PHI1 * PI / 180.0)) * (1.0 + E * sin(PHI2 * PI / 180.0)), E / 2.0)) / tan((PHI2 * PI / 180.0) / 2.0 + PI / 4.0) * pow((1.0 + E * sin(PHI1 * PI / 180.0)) * (1.0 - E * sin(PHI2 * PI / 180.0)), E / 2.0));
	const double rho0 = (A * cos(PHI1 * PI / 180.0) / n * pow(1.0 - pow(E * sin(PHI1 * PI / 180.0), 2.0), 0.5)) * pow(tan((PHI1 * PI / 180.0) / 2.0 + PI / 4.0) * pow((1.0 - E * sin(PHI1 * PI / 180.0)) / (1.0 + E * sin(PHI1 * PI / 180.0)), E / 2.0), n);
	const double rhophi0 = rho0 * pow((cos((PHI0 * PI / 180.0) / 2.0 + PI / 4.0) / sin((PHI0 * PI / 180.0) / 2.0 + PI / 4.0)) * pow((1.0 + E * sin(PHI0 * PI / 180.0)) / (1.0 - E * sin(PHI0 * PI / 180.0)), E / 2.0), n);

	double rhophi = rho0 * pow((cos((gps.lat * PI / 180.0) / 2.0 + PI / 4.0) / sin((gps.lat * PI / 180.0) / 2.0 + PI / 4.0)) * pow((1.0 + E * sin(gps.lat * PI / 180.0)) / (1.0 - E * sin(gps.lat * PI / 180.0)), E / 2.0), n);
	carto.x = X0 + rhophi * sin(n * ((gps.lon - LAMBDA0) * PI / 180.0));
	carto.y = Y0 + rhophi0 - rhophi * cos(n * ((gps.lon - LAMBDA0) * PI / 180.0));

	return carto;
}

GpsCoord twoDToLatLon(::google::protobuf::int64 coordinate)
{
	// Method cf HERE doc

	// Decoding Morton Codes

	::google::protobuf::int32 int_latitude(0), int_longitude(0);

	// Shift Mask
	::google::protobuf::int64 mask(0x1);
	::google::protobuf::int64 m(0x1);

	GpsCoord gps;

	// Doing the opposite of interleaving
	for (int i(0); i < 32; i++)
	{
		int_longitude += ((coordinate & mask) ? m : 0);
		mask <<= 1;

		int_latitude += ((coordinate & mask) ? m : 0);
		mask <<= 1;

		m <<= 1;
	}

	// Final conversion: integer segment unit to double
	gps.lat = int_latitude * (180.0 / 2147483648.0);
	gps.lon = int_longitude * (360.0 / 4294967296.0);

	return gps;
}

double pointTOpointDistance(GpsCoord point1, GpsCoord point2)
{
	// This function calculate the great-circle distance between two latitude/longitude points on the basis of a spherical earth

	double d;

	// Using Spherical Law of Cosines
	//d = acos(sin(point1.lat * PI / 180.0) * sin(point2.lat * PI / 180.0) + cos(point1.lat * PI / 180.0) * cos(point2.lat * PI / 180.0) * cos(point2.lon * PI / 180.0 - point1.lon * PI / 180.0)) * 6371000.0;
	
	// Using Haversine
	double R = 6371000.0;
	double phi1 = point1.lat * PI / 180.0;
	double phi2 = point2.lat * PI / 180.0;
	double dPhi = (point2.lat - point1.lat) * PI / 180.0;
	double dLambda = (point2.lon - point1.lon) * PI / 180.0;

	double a = sin(dPhi / 2.0) * sin(dPhi / 2.0) + cos(phi1) * cos(phi2) * sin(dLambda / 2.0) * sin(dLambda / 2.0);

	double c = 2 * atan2(sqrt(a), sqrt(1.0 - a));

	d = R * c;

	return d;
}
