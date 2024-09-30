#ifndef TRACKS_H			
#define TRACKS_H			
			
//-----------------------------			
// Structures			
//-----------------------------			
			
typedef struct {			
	double latitude;		
	double longitude;		
	float offset;		
}point_GPS;			
			
typedef struct {			
	float offset;		
	unsigned char effectiveSpeedLimit;		
}speed_limit;			
			
typedef struct {			
	float offset;		
	float value;		
}curvature;			
			
typedef struct {			
	float offset;		
	unsigned char Sign_Type;		
	unsigned char Value;		
	unsigned char Lane;		
	unsigned char Sign_Location;		
	double latitude;		
	double longitude;		
}traffic_sign;			
			
typedef struct str_circuit {			
// Longueurs de tableaux			
	int centreNb;		
	int gaucheNb;		
	int droiteNb;		
	int MEgaucheNb;		
	int MEdroiteNb;		
	int speedlimitNb;		
	int curvatureNb;		
	int trafficsignNb;		
// Pointeurs des tableaux			
	point_GPS* centre_tab;		
	point_GPS* gauche_tab;		
	point_GPS* droite_tab;		
	point_GPS* MEgauche_tab;		
	point_GPS* MEdroite_tab;		
	speed_limit* speed_limit_tab;		
	curvature* curvature_tab;		
	traffic_sign* traffic_sign_tab;		
} t_circuit;			
		

typedef struct {			
	unsigned int NbrSpot;
	float offset_debut;
	float offset_fin;	
}segmentME;


typedef struct str_circuit_ehSegmentAOEO {
// Longueurs de tableaux
	int AO_Nb;
	int EO_Nb;

// Pointeurs des tableaux
	segmentME* AO_tab;
	segmentME* EO_tab;

} t_circuit_ehSegmentAOEO;
	
// ---------------------			
// Include des circuits			
// ---------------------			
#include "Track_PA-PL1_11.h"			
#include "Track_PL1-PA_12.h"			
#include "Track_PA-PL2_13.h"			
#include "Track_PL2-PA_14.h"			
#include "Track_PA-PL3_15.h"			
#include "Track_PL3-PA_16.h"			
			
// -----------------------			
// structure des circuits			
// -----------------------			
const t_circuit tracks_tab[] = {			
	TRACK_PA_PL1_11,		
	TRACK_PL1_PA_12,		
	TRACK_PA_PL2_13,		
	TRACK_PL2_PA_14,		
	TRACK_PA_PL3_15,		
	TRACK_PL3_PA_16,		
};			
			

const t_circuit_ehSegmentAOEO ehSegmentAOEO_tab[] = {			
	TRACK_PA_PL1_11_ehSegmentAOEO,		
	TRACK_PL1_PA_12_ehSegmentAOEO,		
	TRACK_PA_PL2_13_ehSegmentAOEO,		
	TRACK_PL2_PA_14_ehSegmentAOEO,		
	TRACK_PA_PL3_15_ehSegmentAOEO,		
	TRACK_PL3_PA_16_ehSegmentAOEO,		
};	

#endif // TRACKS_H			
