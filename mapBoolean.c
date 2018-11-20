#include "mapBoolean.h"

#define SIZE_TAB_FULL 29

/********************************************
This funtion fill a table with boolean values
0 = empty (everything is empty my default)
1 = full
********************************************/

Uint16** mapBoolean(Uint16** map_builder){

    int tmp1, tmp2, i, j;

    // this table contain the number of full tiles
    int tab_full[SIZE_TAB_FULL] = {0, 1, 2, 3, 4, 5, 8, 9, 11, 12, 14, 15, 16, 17, 21, 22, 23, 24, 25, 26, 28, 29, 30, 31, 32, 33, 34, 35, 37};

    // memory allocation
    Uint16 **map_boolean = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
      map_boolean[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }

    // full 0 by default
    for(i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
        for(j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
            map_boolean[j][i] = 0;
        }
    }

    // only define full blocs
    for(i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
      for(j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
 		    tmp1 = map_builder[j][i];
        for(int k = 0 ; k < SIZE_TAB_FULL ; i++){
          tmp2 = tab_full[k];
        }
        switch (tmp1){
          case tmp2:
        map_boolean[j][i] = 1;
        break;
        default:
          break;
		    }
	    }
    }

    return map_boolean;

}
