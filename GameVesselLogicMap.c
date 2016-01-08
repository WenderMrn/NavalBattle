#include "libgame.h"

void PutVesselLogicMap(int logicMap[][OCEAN_SIZE],int rotation,int vessel,int x, int y){
	VesselLogicMap vesselLogic = {};
	
		switch(rotation){
			case VESSELS_VERTICAL:
				/* first coordinate*/
				vesselLogic.coordinates[0].x = x+1; 
				vesselLogic.coordinates[0].y = y;
				/* second coordinate */
				vesselLogic.coordinates[1].x = x;
				vesselLogic.coordinates[1].y = y+1;
				/* third coordinate*/
				vesselLogic.coordinates[2].x = x+2;
				vesselLogic.coordinates[2].y = y+1;
			break;
			case VESSELS_REVERSE_VERTICAL:
							
			break;
		}
	
}

void removeVesselLogicMap(int logicMap[][OCEAN_SIZE],int rotation,int vessel,int x, int y){
	
}
