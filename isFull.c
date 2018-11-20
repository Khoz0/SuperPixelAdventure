#include "isFull.h"

#define SIZE_TAB_FULL 29

int isFull(int tile_number){
  
  // this table contain the number of full tiles
  int tab_full[SIZE_TAB_FULL] = {6};
  
  for(int i = 0 ; i < SIZE_TAB_FULL ; i++){
    if(tab_full[i] == tile_number){
      return 0;
    }
  }
  return 1;
}