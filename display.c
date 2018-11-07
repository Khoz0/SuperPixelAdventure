#include "display.h"

Uint16** Display(){
  
    FILE* file;
    int tmp;
    Uint16 **map_builder = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
      map_builder[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }
    
    // ouverture du fichier .txt de la map 
    file = fopen("level.txt", "r");
    // vérification que le fichier est bien ouvert
    if(!file) {
      printf("Erreur d'ouverture du fichier level.txt\n");
      return 0;
    } else {	
      printf("Fichier level.txt ouvert correctement\n");
    }
    
    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
	    for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
		    fscanf(file, "%d", &tmp);
 		    map_builder[j][i] = tmp;
	    }
    }
    
    fclose(file);
    
    return map_builder;
  
}
