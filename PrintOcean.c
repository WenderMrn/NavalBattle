#include "libgame.h"

void PrintOcean(int pos,int size){
	/*
		this function prints a square representing the ocean
	*/
	int i=0,j=0,x=0,y=0,initx=0,inity=0;
	
	if(pos == OCEAN_LEFT){
		x = initx = XA;
		y = inity = YA;	
	}else if(pos == OCEAN_RIGHT){
		x = initx = XB;
		y = inity =YB;
	}
	
	textcolor(OCEAN_CHARACTER_COLOR); 
	textbackground(OCEAN_BACKGROUND_COLOR);
	
	for(i=0;i < size;i++){
		for(j=0;j< size ;j++){
			gotoxy(x+=1,y);printf("%c",OCEAN_CHARACTER_CODE);
		}
		x = initx;
		y += 1;
	}
}
