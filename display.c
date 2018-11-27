#include "display.h"

void display(Uint16** map_builder, SDL_Surface *screen, int xscroll, int yscroll, SDL_Surface *tileset1, SDL_Surface *tileset2, SDL_Surface *tileset3) {

  SDL_Rect Rect_dest;
  SDL_Rect Rect_source;
  Rect_source.w = WIDTH_TILE;
  Rect_source.h = HEIGHT_TILE;
  
  // printing tiles, the file depend on the number of the tile
  for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
    for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
      if((i*WIDTH_TILE > xscroll - WIDTH_TILE) && (i*WIDTH_TILE < xscroll + SCREEN_WIDTH + WIDTH_TILE)
        && (j*WIDTH_TILE > yscroll - WIDTH_TILE) && (j*WIDTH_TILE < yscroll + SCREEN_HEIGHT + WIDTH_TILE)){
        if(map_builder[i][j]<171){
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (map_builder[i][j])*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(tileset1,&Rect_source,screen,&Rect_dest);
        }else if((map_builder[i][j]<341) && (map_builder[i][j]>170)){
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (map_builder[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(tileset2,&Rect_source,screen,&Rect_dest);
        }else{
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (map_builder[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(tileset3,&Rect_source,screen,&Rect_dest);
        }
      }
    }
  }
  SDL_FreeSurface(screen);
  
//   return 0;
}