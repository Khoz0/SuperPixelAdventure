#include "mapBoolean.h"
#include "isEmpty.h"

/********************************************
This funtion fill a table with boolean values
0 = empty (everything is empty my default)
1 = full
********************************************/

Uint16** mapBoolean(Uint16** map_builder){

    // memory allocation
    Uint16 **map_boolean = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
      map_boolean[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }

    // only define full blocs
    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
      for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
        if(map_builder[j][i]==77){
          map_boolean[j][i] = 2;
        }else if(map_builder[j][i]==399 || map_builder[j][i]==400) {
          map_boolean[j][i] = 3;
	      }else if(map_builder[j][i]==78) {
          map_boolean[j][i] = 4;
        }else if(map_builder[j][i]==53){
          map_boolean[j][i] = 5;
        }else if(map_builder[j][i]==347){
          map_boolean[j][i] = 6;
        }else if(map_builder[j][i]==346){
          map_boolean[j][i] = 7;
        }else if(map_builder[j][i]==345){
          map_boolean[j][i] = 8;
        }else if(map_builder[j][i]==344){
          map_boolean[j][i] = 9;
        }else if(map_builder[j][i]==287){
          map_boolean[j][i] = 10;
        }else if(map_builder[j][i]==284){
          map_boolean[j][i] = 11;
        }else if(map_builder[j][i]==265){
          map_boolean[j][i] = 12;
        }else if(map_builder[j][i]==262){
          map_boolean[j][i] = 13;
        }else{
          map_boolean[j][i] = isEmpty(map_builder[j][i]);
        }
      }
    }

    return map_boolean;

}
