#include "destroyTab.h"

void destroyTab(Uint16** tab) {

  for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
     free(tab[j]);
  }
  free(tab);

}
