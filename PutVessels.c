#include "libgame.h"

XYKey PutVessels(int ocean){
	
	XYKey xykey = {0,0,'/0'};
	int posX=0,posY=0,vessel = SEAPLANE,rotation=1;
	
	/* Default number of available vessel */
	NumberMyVessels myvesselavailable = {3,4,3,2,1};
	/* Available Oceans */	
	if(ocean == OCEAN_LEFT){
		posX=XA,posY=YA;	
	}else if(ocean == OCEAN_RIGHT){
		posX=XB,posY=YB;	
	}
	int maxX = posX + OCEAN_SIZE,minX = posX;
	int maxY = posY + OCEAN_SIZE,minY = posY;
	
	/* Mapping logic ocean*/
	int oceanLogicMap[OCEAN_SIZE][OCEAN_SIZE];

	char tecla;
	
	/* Cursor movement */
	gotoxy(posX+=1,posY);		
	  do{
	  	
	  
		do{
			gotoxy(posX,posY);tecla = getch();
			if( tecla == RIGHT && posX < maxX){
				gotoxy(posX+=1,posY);
			}
			else if(tecla == LEFT && posX > minX+1){
				gotoxy(posX-=1,posY);
			}
			else if(tecla == DOWN && posY < maxY-1){
				
				gotoxy(posX,posY+=1);
			}		
			else if (tecla == UP && posY > minY){
				gotoxy(posX,posY-=1);
			}
			/* chaneg vessel*/
			if(tecla == 'V' || tecla == 'v'){
				vessel = (vessel++ % 5);
				rotation = 1;
			}
			/* rotation vessel */
			if(tecla == 'R' || tecla == 'r'){
				
				switch(vessel){
					case SEAPLANE:
						rotation = (rotation++ % 4);
					break;
					case CRUISERS:				
						rotation = (rotation++ % 2);	
					break;
					case BATTLESHIPS:				
						rotation = (rotation++ % 2);	
					break;
					case AIRCRAFTARRIER:
						rotation = (rotation++ % 2);	
					break;
				}
			}
			
			/* updat ocean */
			PrintOcean(OCEAN_LEFT,OCEAN_SIZE);
			PrintOcean(OCEAN_RIGHT,OCEAN_SIZE);
			/* updat vessel */
			switch(vessel){
				case SEAPLANE:				
					/* print rectification vessel */
					if(myvesselavailable.seaplane == 0){
						vessel++;
						break;	
					} 
					
					if((rotation == VESSELS_NORMAL_VERTICAL
					 || rotation == VESSELS_REVERSE_VERTICAL)
					 && posX+1 == maxX){
						posX-=1;	
					}
					if((rotation == VESSELS_NORMAL_VERTICAL
					 || rotation == VESSELS_REVERSE_VERTICAL) 
					 && posY+1 == maxY){
						posY-=1;
					}
					if((rotation == VESSELS_RIGHT_HORIZONTAL
					 || rotation == VESSELS_LEFT_HORIZONTAL)
					 && posX == maxX){
						posX-=1;	
					}
					if((rotation == VESSELS_RIGHT_HORIZONTAL
					 || rotation == VESSELS_LEFT_HORIZONTAL)
					  && posY+2 == maxY){
						posY-=1;	
					}
					PrintSeaPlanes(posX,posY,rotation);												
				break;
				case SUBMARINE:
					if(myvesselavailable.submarine == 0){
						vessel++;
						break;	
					} 
					PrintSubmarine(posX-1,posY);		
				break;
				case CRUISERS:
						/* print rectification vessel */
					if(myvesselavailable.cruisers == 0){
						vessel++;
						break;	
					} 
						
					if(rotation == VESSELS_VERTICAL && posY+1 >= maxY){
						PrintCruisers(posX-1,posY-1,rotation);	
					}else if(rotation == VESSELS_HORIZONTAL &&  posX+1 >= maxX){
						PrintCruisers(posX-2,posY,rotation);	
					}else{
						PrintCruisers(posX-1,posY,rotation);	
					}									
				break;
				case BATTLESHIPS:
					if(myvesselavailable.battleships == 0){
						vessel++;
						break;	
					} 
						/* Print rectification vessel */
					if(rotation == VESSELS_HORIZONTAL && posX+2 == maxX){
						posX-=1;
					}
					if(rotation == VESSELS_VERTICAL && posY+3 == maxY){
						posY-=1;
					}
					PrintBattleships(posX,posY,rotation);		
				break;
				case AIRCRAFTARRIER:
					if(myvesselavailable.aircraftarrier == 0){
						vessel++;
						break;	
					} 
						/* Print rectification vessel */
					if(rotation == VESSELS_HORIZONTAL && posX+2 == maxX){
						posX-=1;
					}
					if(rotation == VESSELS_VERTICAL && posY+4 == maxY){
						posY-=1;
					}
					PrintAircraftarrier(posX,posY,rotation);	
				break;
			}
			
			gotoxy(5,24);printf("x: %d y: %d / MaxX: %d / Maxy: %d / MinX: %d / Miny: %d  vessel:%d Rotacao:%d",posX,posY,maxX,maxY,minX,minY,vessel,rotation);
			gotoxy(1,22);printf("%d ",myvesselavailable.seaplane);
			gotoxy(2,22);printf("%d ",myvesselavailable.battleships);
			gotoxy(3,22);printf("%d ",myvesselavailable.cruisers);
			gotoxy(4,22);printf("%d ",myvesselavailable.submarine);
			gotoxy(5,22);printf("%d ",myvesselavailable.aircraftarrier);
			gotoxy(posX,posY);
			
			/* Add vessel to game map and remove from my available vessel*/
			if(tecla == ENTER){
			
				switch(vessel){
					case SEAPLANE:
						if(myvesselavailable.seaplane >= 1)
						myvesselavailable.seaplane-=1;	
						/* Mapping the parts of the vessel */										
						PutVesselLogicMap(oceanLogicMap,rotation,vessel,posX,posY);			
		 	
					;break;
					case SUBMARINE:
						if(myvesselavailable.submarine >= 1)
						myvesselavailable.submarine-=1; 
					;break;
					case CRUISERS:
						if(myvesselavailable.cruisers >= 1)
						myvesselavailable.cruisers-=1; 
					;break;
					case BATTLESHIPS:
						if(myvesselavailable.battleships >= 1)
						myvesselavailable.battleships-=1; 
					;break;
					case AIRCRAFTARRIER:
						if(myvesselavailable.aircraftarrier >= 1)
						myvesselavailable.aircraftarrier-=1; 
					;break;
				}


			}
		
		}while(tecla != ESC);
			/*xykey.x=posX;
		 	xykey.y=posY;
		 	xykey.key = tecla;
		 	
			return xykey;*/	
	 }while(tecla != ESC);	
 
 	_setcursortype(_NOCURSOR);	
 	xykey.x=posX;
	xykey.y=posY;
	xykey.key = tecla;
	return xykey;		
}

