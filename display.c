#include "display.h"
#include "createSDL.h"
#include "variables.h"
#include "game.h"

/*
each function used is a specifical print function, one to print the map,
one to print the character and PNJs, one to print the pannels & chats chatBox
*/

void display(Game* game) {
  displayMap(getGameTables(game), getScreen(getGameSdl(game)), getVariable(getGameVariables(game), XSCROLL), getVariable(getGameVariables(game), YSCROLL), getGameAtlas(game));
  displayPannel(getScreen(getGameSdl(game)), getGameAtlas(game), getGameVariables(game));
  displayChar(getScreen(getGameSdl(game)), getGameAtlas(game));
}

void displayMap(Tables* tables, SDL_Surface* screen, int xscroll, int yscroll, Atlas* atlas) {

  SDL_Rect Rect_dest;
  SDL_Rect Rect_source;
  Rect_source.w = WIDTH_TILE;
  Rect_source.h = HEIGHT_TILE;

  // printing tiles, the file depend on the number of the tile
  // we only print the blocks inside of the scroll window
  for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
    for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
      if((i*WIDTH_TILE > xscroll - WIDTH_TILE) && (i*WIDTH_TILE < xscroll + SCREEN_WIDTH + WIDTH_TILE)
        && (j*WIDTH_TILE > yscroll - WIDTH_TILE) && (j*WIDTH_TILE < yscroll + SCREEN_HEIGHT + WIDTH_TILE)){
        if(getTable(tables, MAP_BUILDER)[i][j]<171){
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(tables, MAP_BUILDER)[i][j])*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(atlas, TILESET1), &Rect_source, screen, &Rect_dest);
        }else if((getTable(tables, MAP_BUILDER)[i][j]<341) && (getTable(tables, MAP_BUILDER)[i][j]>170)){
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(tables, MAP_BUILDER)[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(atlas, TILESET2), &Rect_source, screen, &Rect_dest);
        }else{
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(tables, MAP_BUILDER)[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(atlas, TILESET3), &Rect_source, screen, &Rect_dest);
        }
      }
    }
  }
  SDL_FreeSurface(screen);
}

void displayPannel(SDL_Surface* screen, Atlas* atlas, Variables* variables) {
  if(getBoolean(variables, BOOL_PANNEL)) SDL_BlitSurface(getPicture(atlas, PANNEL)->surface, NULL, screen, &getPicture(atlas, PANNEL)->dst);
}

void displayChar(SDL_Surface* screen, Atlas* atlas) {

  if(!getIsNeg(atlas, 0)) {
    SDL_BlitSurface(getPicture(atlas, 0)->surface, &getPicture(atlas, 0)->src, screen, &getPicture(atlas, 0)->dst);
  }else{
    SDL_BlitSurface(getPicture(atlas, 0)->surface, &getPicture(atlas, 0)->src, screen, &getPicture(atlas, 0)->neg);
  }
}
