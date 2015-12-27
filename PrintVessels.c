#include "libgame.h"

/* SeaPlanes(pt:Hidroaviões)*/
void PrintSeaPlanes(int x,int y,int pos){
	
	textcolor(VESSELS_CHARACTER_COLOR); 
	textbackground(OCEAN_BACKGROUND_COLOR);
	
	switch(pos){
		case VESSELS_NORMAL_VERTICAL:
			gotoxy(x+1,y);printf("%c",VESSELS_CHARACTER_CODE);
			gotoxy(x,y+1);printf("%c",VESSELS_CHARACTER_CODE);
			gotoxy(x+2,y+1);printf("%c",VESSELS_CHARACTER_CODE);
			
		;break;
		case VESSELS_RIGHT_HORIZONTAL:
			
			gotoxy(x,y);printf("%c",VESSELS_CHARACTER_CODE);
			gotoxy(x+1,y+1);printf("%c",VESSELS_CHARACTER_CODE);
			gotoxy(x,y+2);printf("%c",VESSELS_CHARACTER_CODE);

		;break;
		case VESSELS_LEFT_HORIZONTAL:
			
			gotoxy(x+1,y);printf("%c",VESSELS_CHARACTER_CODE);
			gotoxy(x,y+1);printf("%c",VESSELS_CHARACTER_CODE);
			gotoxy(x+1,y+2);printf("%c",VESSELS_CHARACTER_CODE);

		;break;
		case VESSELS_REVERSE_VERTICAL:
			
			gotoxy(x+1,y+1);printf("%c",VESSELS_CHARACTER_CODE);
			gotoxy(x,y);printf("%c",VESSELS_CHARACTER_CODE);
			gotoxy(x+2,y);printf("%c",VESSELS_CHARACTER_CODE);

		;break;
	}
}
/* Submarine(pt:Submarino)*/
void PrintSubmarine(int x,int y){
	
	textcolor(VESSELS_CHARACTER_COLOR); 
	textbackground(OCEAN_BACKGROUND_COLOR);
	
	gotoxy(x+1,y);printf("%c",VESSELS_CHARACTER_CODE);
}
/* Cruisers (pt:Cruzadores)*/
void PrintCruisers(int x,int y,int pos){
	
	textcolor(VESSELS_CHARACTER_COLOR); 
	textbackground(OCEAN_BACKGROUND_COLOR);
	
	if(pos == VESSELS_HORIZONTAL){
		gotoxy(x+1,y);printf("%c%c",VESSELS_CHARACTER_CODE,VESSELS_CHARACTER_CODE);	
	}else if(pos == VESSELS_VERTICAL){
		gotoxy(x+1,y);printf("%c",VESSELS_CHARACTER_CODE);
		gotoxy(x+1,y+1);printf("%c",VESSELS_CHARACTER_CODE);		
	}
		
}
/* Battleships (pt:Encouraçados)*/
void PrintBattleships(int x,int y,int pos){
	
	textcolor(VESSELS_CHARACTER_COLOR); 
	textbackground(OCEAN_BACKGROUND_COLOR);
	
	if(pos == VESSELS_HORIZONTAL){
		gotoxy(x,y);printf("%c%c%c%c",VESSELS_CHARACTER_CODE,VESSELS_CHARACTER_CODE,
		VESSELS_CHARACTER_CODE,VESSELS_CHARACTER_CODE);
	}else if(pos == VESSELS_VERTICAL){
		gotoxy(x,y);printf("%c",VESSELS_CHARACTER_CODE);
		gotoxy(x,y+1);printf("%c",VESSELS_CHARACTER_CODE);
		gotoxy(x,y+2);printf("%c",VESSELS_CHARACTER_CODE);
		gotoxy(x,y+3);printf("%c",VESSELS_CHARACTER_CODE);	
	}
}
/* Aircraftarrier (pt:Porta-Aviões)*/
void PrintAircraftarrier(int x,int y,int pos){
	
	textcolor(VESSELS_CHARACTER_COLOR); 
	textbackground(OCEAN_BACKGROUND_COLOR);
	
	if(pos == VESSELS_HORIZONTAL){
		gotoxy(x,y);printf("%c%c%c%c%c",VESSELS_CHARACTER_CODE,VESSELS_CHARACTER_CODE,
		VESSELS_CHARACTER_CODE,VESSELS_CHARACTER_CODE,VESSELS_CHARACTER_CODE);	
	}else if(pos == VESSELS_VERTICAL){
		gotoxy(x,y);printf("%c",VESSELS_CHARACTER_CODE);
		gotoxy(x,y+1);printf("%c",VESSELS_CHARACTER_CODE);
		gotoxy(x,y+2);printf("%c",VESSELS_CHARACTER_CODE);
		gotoxy(x,y+3);printf("%c",VESSELS_CHARACTER_CODE);
		gotoxy(x,y+4);printf("%c",VESSELS_CHARACTER_CODE);	
	}	
	
}
