#include "load_level.h"

int** load_level(){
    
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
	
	return map_builder;
}
