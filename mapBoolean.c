#include "mapBoolean.h"

Uint16** mapBoolean(Uint16** map_builder){

    int tmp;
    
    // allocation mémoire
    Uint16 **map_boolean = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
      map_boolean[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }
    
    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
	    for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
 		    tmp = map_builder[j][i];
		    switch (tmp){
		      case 5:
			map_boolean[j][i] = 0;
			break;
		      case 1:
			map_boolean[j][i] = 1;
			break;
		      case 17:
			map_boolean[j][i] = 1;
			break;
		      case 44:
			map_boolean[j][i] = 1;
			break;
		      case 36:
			map_boolean[j][i] = 1;
			break;
		      case 50:
			map_boolean[j][i] = 1;
			break;
		      case 49:
			map_boolean[j][i] = 1;
			break;
		      case 48:
			map_boolean[j][i] = 1;
			break;
		      case 32:
			map_boolean[j][i] = 1;
			break;
		      case 35:
			map_boolean[j][i] = 1;
			break;
		      case 37:
			map_boolean[j][i] = 1;
			break;
		      case 65:
			map_boolean[j][i] = 1;
			break;
		      case 34:
			map_boolean[j][i] = 1;
			break;
		      case 33:
			map_boolean[j][i] = 1;
			break;
		      case 19:
			map_boolean[j][i] = 1;
			break;
		      case 52:
			map_boolean[j][i] = 1;
			break;
		    }
	    }
    }
    
    return map_boolean;
    
}
