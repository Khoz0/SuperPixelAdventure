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

    if(number==1) file = fopen("level1.txt", "r");
    if(number==2) file = fopen("level2.txt", "r");

    if(!file) {
      printf("Error : level.txt didn't load correctly\n");
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
