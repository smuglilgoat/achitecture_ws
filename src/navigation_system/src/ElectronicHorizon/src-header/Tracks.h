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
#include "Track_PA1_PF1_11.h"			
#include "Track_PF1_PA1_12.h"			
#include "Track_PA1_PF2_13.h"			
#include "Track_PF2_PA1_14.h"			
#include "Track_PA1_PF3_15.h"			
#include "Track_NOTVALID_16.h"			
#include "Track_NOTVALID_17.h"			
#include "Track_NOTVALID_18.h"			
#include "Track_PA2_PF1_19.h"			
#include "Track_PA2_PF2_20.h"			
#include "Track_PA2_PF3_21.h"			
#include "Track_PF3_PA2_22.h"		
#include "Track_PF1_PF2_23.h"			
#include "Track_PF2_PF1_24.h"			
#include "Track_PF1_PF3_25.h"			
#include "Track_PF3_PF1_26.h"			
#include "Track_PF2_PF3_27.h"			
#include "Track_PF3_PF2_28.h"			
#include "Track_TRP_BTA_29.h"
#include "Track_TRP_BTA_30.h"
			
// -----------------------			
// structure des circuits			
// -----------------------			
const t_circuit tracks_tab[] = {			
	TRACK_PA1_PF1_11,		
	TRACK_PF1_PA1_12,		
	TRACK_PA1_PF2_13,		
	TRACK_PF2_PA1_14,		
	TRACK_PA1_PF3_15,		
	TRACK_NOTVALID_16,		
	TRACK_NOTVALID_17,		
	TRACK_NOTVALID_18,		
	TRACK_PA2_PF1_19,		
	TRACK_PA2_PF2_20,		
	TRACK_PA2_PF3_21,		
	TRACK_PF3_PA2_22,		
	TRACK_PF1_PF2_23,		
	TRACK_PF2_PF1_24,		
	TRACK_PF1_PF3_25,		
	TRACK_PF3_PF1_26,		
	TRACK_PF2_PF3_27,		
	TRACK_PF3_PF2_28,
	TRACK_TRP_BTA_29,		
	TRACK_TRP_BTA_30,

};			
			
const t_circuit_ehSegmentAOEO ehSegmentAOEO_tab[] = {			
	TRACK_PA1_PF1_11_ehSegmentAOEO,		
	TRACK_PF1_PA1_12_ehSegmentAOEO,		
	TRACK_PA1_PF2_13_ehSegmentAOEO,			
	TRACK_PF2_PA1_14_ehSegmentAOEO,			
	TRACK_PA1_PF3_15_ehSegmentAOEO,		
	TRACK_NOTVALID_16_ehSegmentAOEO,		
	TRACK_NOTVALID_17_ehSegmentAOEO,			
	TRACK_NOTVALID_18_ehSegmentAOEO,		
	TRACK_PA2_PF1_19_ehSegmentAOEO,		
	TRACK_PA2_PF2_20_ehSegmentAOEO,		
	TRACK_PA2_PF3_21_ehSegmentAOEO,			
	TRACK_PF3_PA2_22_ehSegmentAOEO,		
	TRACK_PF1_PF2_23_ehSegmentAOEO,		
	TRACK_PF2_PF1_24_ehSegmentAOEO,		
	TRACK_PF1_PF3_25_ehSegmentAOEO,			
	TRACK_PF3_PF1_26_ehSegmentAOEO,
	TRACK_PF2_PF3_27_ehSegmentAOEO,		
	TRACK_PF3_PF2_28_ehSegmentAOEO,	
	TRACK_TRP_BTA_29_ehSegmentAOEO,	
	TRACK_TRP_BTA_30_ehSegmentAOEO,
};	


#endif // TRACKS_H			
