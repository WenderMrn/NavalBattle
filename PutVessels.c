#include "libgame.h"

XYKey PutVessels(int ocean){
	
	XYKey xykey = {0,0,'/0'};
	int posX=0,posY=0,vessel = SEAPLANE,rotation=1;
	
	NumberMyVessels myvessel = {3,4,3,2,1};
		
	if(ocean == OCEAN_LEFT){
		posX=XA,posY=YA;	
	}else if(ocean == OCEAN_RIGHT){
		posX=XB,posY=YB;	
	}
	int maxX = posX + OCEAN_SIZE,minX = posX;
	int maxY = posY + OCEAN_SIZE,minY = posY;
	
	char tecla;
	
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
					if(myvessel.seaplane == 0){
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
					if(myvessel.submarine == 0){
						vessel++;
						break;	
					} 
					PrintSubmarine(posX-1,posY);		
				break;
				case CRUISERS:
						/* print rectification vessel */
					if(myvessel.cruisers == 0){
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
					if(myvessel.battleships == 0){
						vessel++;
						break;	
					} 
						/* print rectification vessel */
					if(rotation == VESSELS_HORIZONTAL && posX+2 == maxX){
						posX-=1;
					}
					if(rotation == VESSELS_VERTICAL && posY+3 == maxY){
						posY-=1;
					}
					PrintBattleships(posX,posY,rotation);		
				break;
				case AIRCRAFTARRIER:
					if(myvessel.aircraftarrier == 0){
						vessel++;
						break;	
					} 
						/* print rectification vessel */
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
			gotoxy(1,22);printf("%d ",myvessel.seaplane);
			gotoxy(2,22);printf("%d ",myvessel.battleships);
			gotoxy(3,22);printf("%d ",myvessel.cruisers);
			gotoxy(4,22);printf("%d ",myvessel.submarine);
			gotoxy(5,22);printf("%d ",myvessel.aircraftarrier);
			gotoxy(posX,posY);
			
			if(tecla == ENTER){
				
				switch(vessel){
					case SEAPLANE:
						if(myvessel.seaplane >= 1)
						myvessel.seaplane-=1; 
					;break;
					case SUBMARINE:
						if(myvessel.submarine >= 1)
						myvessel.submarine-=1; 
					;break;
					case CRUISERS:
						if(myvessel.cruisers >= 1)
						myvessel.cruisers-=1; 
					;break;
					case BATTLESHIPS:
						if(myvessel.battleships >= 1)
						myvessel.battleships-=1; 
					;break;
					case AIRCRAFTARRIER:
						if(myvessel.aircraftarrier >= 1)
						myvessel.aircraftarrier-=1; 
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

