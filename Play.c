#include "libgame.h"

void Play(){
	
	PrintOcean(OCEAN_LEFT,OCEAN_SIZE);
	PrintOcean(OCEAN_RIGHT,OCEAN_SIZE);
	
	PutVessels(OCEAN_LEFT);
}
