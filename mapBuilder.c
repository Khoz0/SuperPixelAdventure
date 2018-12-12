#include "mapBuilder.h"

/*********************************************
This funtion fill a table with sprites values
comming from a .txt file
*********************************************/

Uint16** mapBuilder(int number){

    FILE* file;
    int tmp, i, j;

    // memory allocation
    Uint16 **map_builder = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
      map_builder[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }

    // we only load the necessary file
    if(number==1) {
      file = fopen("./maps/map_water.txt", "r");
    }else if(number==2) {
      file = fopen("./maps/map_no_water_spawn_old.txt", "r");
    }else if(number==3) {
      file = fopen("./maps/map_no_water_no_spawn_old.txt", "r");
    }else if(number==4) {
      file = fopen("./maps/map_no_water_no_spawn_no_old.txt", "r");
    }else{
      file = fopen("./maps/map_cave.txt", "r");
    }

    if(!file) {
      printf("Error : map didn't load\n");
      return 0;
    }

    for(i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
      for(j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
        fscanf(file, "%d", &tmp);
        map_builder[j][i] = tmp;
      }
    }

    fclose(file);
    return map_builder;

}
