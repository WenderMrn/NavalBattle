#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

/* CONFIG OCEAN */

#define OCEAN_BACKGROUND_COLOR BLACK
#define OCEAN_CHARACTER_COLOR CYAN
#define OCEAN_CHARACTER_CODE 254
#define OCEAN_SIZE 15

#define XA 18
#define YA 5

#define XB 41
#define YB 5  

#define OCEAN_LEFT 1
#define OCEAN_RIGHT 2

/* CONFIG VESSELS */  

#define VESSELS_CHARACTER_COLOR LIGHTGREEN 
#define VESSELS_CHARACTER_CODE 254

#define VESSELS_NORMAL_VERTICAL 1
#define VESSELS_RIGHT_HORIZONTAL 2
#define VESSELS_LEFT_HORIZONTAL 3
#define VESSELS_REVERSE_VERTICAL 4
#define VESSELS_VERTICAL 1
#define VESSELS_HORIZONTAL 2

#define SEAPLANE 1
#define SUBMARINE 2
#define CRUISERS 3
#define BATTLESHIPS 4
#define AIRCRAFTARRIER 5

/* CONFIG MOVEMENT */

#define RIGHT 77
#define LEFT  75
#define DOWN  80
#define UP    72
 
#define ENTER 13
#define ESC 27
#define SPC 32
#define BS 8

typedef struct{
	int x,y;
    char key;
}XYKey;

typedef struct{
	int seaplane,submarine,cruisers,battleships,aircraftarrier;
}NumberMyVessels;

XYKey PutVessels(int ocean);

void PrintOcean(int pos,int size);

void PrintSeaPlanes(int x,int y,int pos);

void PrintSubmarine(int x,int y);

void PrintCruisers(int x,int y,int pos);

void PrintBattleships(int x,int y,int pos);

void PrintAircraftarrier(int x,int y,int pos);
