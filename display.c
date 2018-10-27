#include "display.h"

void Display(SDL_Surface* screen,SDL_Surface* tileset){
    
	int test;
	SDL_Rect Rect_dest;
	SDL_Rect Rect_source;
	Rect_source.w = WIDTH_TILE;
	Rect_source.h = HEIGHT_TILE;
    FILE* file;
    int* tmp;
    int map_builder[MAP_BLOCKS_WIDTH][MAP_BLOCKS_HEIGHT];
    
    // ouverture du fichier .txt de la map 
    file = fopen("level.txt", "r");
        
	for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
		for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
			fscanf(file, "%d",&tmp);
			map_builder[j][i] = tmp;
        }
	}
    
	for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
		for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
			Rect_dest.x = i*WIDTH_TILE;
			Rect_dest.y = j*HEIGHT_TILE;
			Rect_source.x = (map_builder[j][i])*WIDTH_TILE;
			Rect_source.y = 0;
			SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
		}
	}

}
