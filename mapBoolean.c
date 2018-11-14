#include "mapBoolean.h"

Uint16** mapBoolean(Uint16** map_builder){

    int tmp;
    
    // allocation mémoire
    Uint16 **map_boolean = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
      map_boolean[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }
    
    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
        for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
            map_boolean[j][i] = 0;
        }
    }
    
    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
	    for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
 		    tmp = map_builder[j][i];
		    switch (tmp){
		      case 0:
			map_boolean[j][i] = 1;
			break;
		      case 1:
			map_boolean[j][i] = 1;
			break;
		      case 2:
			map_boolean[j][i] = 1;
			break;
		      case 3:
			map_boolean[j][i] = 1;
			break;
		      case 4:
			map_boolean[j][i] = 1;
			break;
		      case 5:
			map_boolean[j][i] = 1;
			break;
		      case 8:
			map_boolean[j][i] = 1;
			break;
		      case 9:
			map_boolean[j][i] = 1;
			break;
		      case 11:
			map_boolean[j][i] = 1;
			break;
		      case 12:
			map_boolean[j][i] = 1;
			break;
		      case 13:
			map_boolean[j][i] = 1;
			break;
		      case 14:
			map_boolean[j][i] = 1;
			break;
		      case 15:
			map_boolean[j][i] = 1;
			break;
		      case 16:
			map_boolean[j][i] = 1;
			break;
		      case 17:
			map_boolean[j][i] = 1;
			break;
              case 21:
			map_boolean[j][i] = 1;
			break;
              case 22:
			map_boolean[j][i] = 1;
			break;
              case 23:
			map_boolean[j][i] = 1;
			break;
              case 24:
			map_boolean[j][i] = 1;
			break;
              case 25:
			map_boolean[j][i] = 1;
			break;
              case 26:
			map_boolean[j][i] = 1;
			break;
              case 28:
			map_boolean[j][i] = 1;
			break;
              case 29:
			map_boolean[j][i] = 1;
			break;
              case 30:
			map_boolean[j][i] = 1;
			break;
              case 31:
			map_boolean[j][i] = 1;
			break;
              case 32:
			map_boolean[j][i] = 1;
			break;
              case 33:
			map_boolean[j][i] = 1;
			break;
              case 34:
			map_boolean[j][i] = 1;
			break;
              case 35:
			map_boolean[j][i] = 1;
			break;
              case 37:
			map_boolean[j][i] = 1;
			break;
              case 38:
			map_boolean[j][i] = 1;
			break;
              case 39:
			map_boolean[j][i] = 1;
			break;
              case 40:
			map_boolean[j][i] = 1;
			break;
              case 42:
			map_boolean[j][i] = 1;
			break;
              case 47:
			map_boolean[j][i] = 1;
			break;
              case 48:
			map_boolean[j][i] = 1;
			break;
              case 49:
			map_boolean[j][i] = 1;
			break;
              case 50:
			map_boolean[j][i] = 1;
			break;
              case 51:
			map_boolean[j][i] = 1;
			break;
              case 52:
			map_boolean[j][i] = 1;
			break;
              case 53:
			map_boolean[j][i] = 1;
			break;
              case 54:
			map_boolean[j][i] = 1;
			break;
              case 55:
			map_boolean[j][i] = 1;
			break;
              case 56:
			map_boolean[j][i] = 1;
			break;
              case 59:
			map_boolean[j][i] = 1;
			break;
              case 61:
			map_boolean[j][i] = 1;
			break;
              case 62:
			map_boolean[j][i] = 1;
			break;
              case 63:
			map_boolean[j][i] = 1;
			break;
              case 64:
			map_boolean[j][i] = 1;
			break;
              case 65:
			map_boolean[j][i] = 1;
			break;
              case 66:
			map_boolean[j][i] = 1;
			break;
              case 67:
			map_boolean[j][i] = 1;
			break;
              case 68:
			map_boolean[j][i] = 1;
			break;
              case 69:
			map_boolean[j][i] = 1;
			break;
              case 70:
			map_boolean[j][i] = 1;
			break;
              case 71:
			map_boolean[j][i] = 1;
			break;
              case 72:
			map_boolean[j][i] = 1;
			break;
              case 73:
			map_boolean[j][i] = 1;
			break;
              case 74:
			map_boolean[j][i] = 1;
			break;
              case 75:
			map_boolean[j][i] = 1;
			break;
              case 77:
			map_boolean[j][i] = 1;
			break;
            
		    }
	    }
    }
    
    return map_boolean;
    
}
