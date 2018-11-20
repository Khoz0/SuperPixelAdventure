#include "mapBoolean.h"
#include "isFull.h"

/********************************************
This funtion fill a table with boolean values
0 = empty (everything is empty my default)
1 = full
********************************************/

Uint16** mapBoolean(Uint16** map_builder){

    int tmp1, tmp2, i, j;

    // memory allocation
    Uint16 **map_boolean = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
      map_boolean[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }

    // only define full blocs
    for(i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
      for(j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
        if(map_builder[j][i] == 77){
          map_boolean[j][i] = 2;
        }else{
          map_boolean[j][i] = isFull(map_builder[j][i]);
        }
      }
    }
    
    // definitions of the special interactions blocs (like pannel, door,...)

    return map_boolean;

}
