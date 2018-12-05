#include "display.h"
#include "createSDL.h"
#include "booleans.h"

void display(Atlas* atlas, Booleans* booleans, SDL* sdl, Uint16** map_builder, int xscroll, int yscroll) {

  displayMap(map_builder, getScreen(sdl), xscroll, yscroll, atlas);

  for(int i = 0 ; i < SIZE_ATLAS ; i++) {
    if(getIsPrinted(atlas, i)) {
      // theses conditions are used to make a difference between the last parameter of fonction SDL_BlitzSurface
      if(!getIsNeg(atlas, i)) {
        SDL_BlitSurface(getPicture(atlas, i)->surface, &getPicture(atlas, i)->src, getScreen(sdl), &getPicture(atlas, i)->dst);
      }else{
        if(i != 3){
          SDL_BlitSurface(getPicture(atlas, i)->surface, &getPicture(atlas, i)->src, getScreen(sdl), &getPicture(atlas, i)->neg);
        }
      }
      if(getBoolean(booleans, BOOL_PANNEL)) SDL_BlitSurface(getPicture(atlas, PANNEL)->surface, NULL, getScreen(sdl), &getPicture(atlas, PANNEL)->dst);
    }
  }

}
