#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

void Display(SDL_Surface* screen,SDL_Surface* tileset,char** map_builder,int map_blocks_width,int map_blocks_height){
  
	int i,j;
	int test;
	SDL_Rect Rect_dest;
	SDL_Rect Rect_source;
	Rect_source.w = WIDTH_TILE;
	Rect_source.h = HEIGHT_TILE;
	for(i = 0 ; i < map_blocks_width ; i++){
		for(j = 0 ; j < map_blocks_height ; j++){
			if(map_builder[j][i] == 'A'){
			    test = 10;
			    Rect_dest.x = i*WIDTH_TILE;
			    Rect_dest.y = j*HEIGHT_TILE;
			    Rect_source.x = test*WIDTH_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else if(map_builder[j][i] == 'B'){
			    test = 11;
			    Rect_dest.x = i*WIDTH_TILE;
			    Rect_dest.y = j*HEIGHT_TILE;
			    Rect_source.x = test*WIDTH_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else if(map_builder[j][i] == 'C'){
			    test = 12;
			    Rect_dest.x = i*WIDTH_TILE;
			    Rect_dest.y = j*HEIGHT_TILE;
			    Rect_source.x = test*WIDTH_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else if(map_builder[j][i] == 'D'){
			    test = 13;
			    Rect_dest.x = i*WIDTH_TILE;
			    Rect_dest.y = j*HEIGHT_TILE;
			    Rect_source.x = test*WIDTH_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else if(map_builder[j][i] == 'E'){
			    test = 14;
			    Rect_dest.x = i*WIDTH_TILE;
			    Rect_dest.y = j*HEIGHT_TILE;
			    Rect_source.x = test*WIDTH_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else{
			    Rect_dest.x = i*WIDTH_TILE;
			    Rect_dest.y = j*HEIGHT_TILE;
			    Rect_source.x = (map_builder[j][i] - '0')*WIDTH_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}
		}
	}

}