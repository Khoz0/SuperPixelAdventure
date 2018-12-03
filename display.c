#include "display.h"

void display(Atlas* atlas, SDL_Surface *screen, Uint16** map_builder, int xscroll, int yscroll) {
  
  for(int i = 0 ; i < SIZE_ATLAS ; i++) {
    if(getIsPrinted(atlas, i)) {
      if(!getIsNeg(atlas, i)) {
        SDL_BlitSurface(getPicture(atlas, i)->surface, &getPicture(atlas, i)->src, screen, &getPicture(atlas, i)->dst);
      }else{
        SDL_BlitSurface(getPicture(atlas, i)->surface, &getPicture(atlas, i)->src, screen, &getPicture(atlas, i)->neg);
      }
    }
  }
  displayMap(map_builder, screen, xscroll, yscroll, atlas);
  
}