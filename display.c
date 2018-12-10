#include "display.h"
#include "createSDL.h"
#include "variables.h"
#include "game.h"

/*
each function used is a specifical print function, one to print the map,
one to print the character and PNJs, one to print the pannels & chats chatBox
*/

void display(Game* game) {
  displayMap(game);
  displayPannel(game);
  displayChar(game);
  displayWaterfall(game);
  displayBars(game);
}

void displayMap(Game* game) {

  SDL_Rect Rect_dest;
  SDL_Rect Rect_source;
  Rect_source.w = WIDTH_TILE;
  Rect_source.h = HEIGHT_TILE;

  // printing tiles, the file depend on the number of the tile
  // we only print the blocks inside of the scroll window
  for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
    for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
      if((i*WIDTH_TILE > getVariable(getGameVariables(game), XSCROLL) - WIDTH_TILE) && (i*WIDTH_TILE < getVariable(getGameVariables(game), XSCROLL) + SCREEN_WIDTH + WIDTH_TILE)
        && (j*WIDTH_TILE > getVariable(getGameVariables(game), YSCROLL) - WIDTH_TILE) && (j*WIDTH_TILE < getVariable(getGameVariables(game), YSCROLL) + SCREEN_HEIGHT + WIDTH_TILE)){
        if(getTable(getGameTables(game), MAP_BUILDER)[i][j]<171){
          Rect_dest.x = i*WIDTH_TILE - getVariable(getGameVariables(game), XSCROLL);
          Rect_dest.y = j*HEIGHT_TILE - getVariable(getGameVariables(game), YSCROLL);
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j])*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET1), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }else if((getTable(getGameTables(game), MAP_BUILDER)[i][j]<341) && (getTable(getGameTables(game), MAP_BUILDER)[i][j]>170)){
          Rect_dest.x = i*WIDTH_TILE - getVariable(getGameVariables(game), XSCROLL);
          Rect_dest.y = j*HEIGHT_TILE - getVariable(getGameVariables(game), YSCROLL);
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET2), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }else{
          Rect_dest.x = i*WIDTH_TILE - getVariable(getGameVariables(game), XSCROLL);
          Rect_dest.y = j*HEIGHT_TILE - getVariable(getGameVariables(game), YSCROLL);
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET3), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }
      }
    }
  }
  SDL_FreeSurface(getScreen(getGameSdl(game)));
}

void displayPannel(Game* game) {
  if(getBoolean(getGameVariables(game), BOOL_PANNEL)) SDL_BlitSurface(getPicture(getGameAtlas(game), PANNEL)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PANNEL)->dst);
  displayTextPannel(game);
}

void displayChar(Game* game) {

  for(int i = 0 ; i < SIZE_ATLAS ; i++) {
    if(getIsPrinted(getGameAtlas(game), i) && i!=3 && i!=12) {
      // we ignore i=3 and i=12 because it's the index of waterfall & pannel, special printings
      // theses conditions are used to make a difference between the last parameter of fonction SDL_BlitzSurface
      if(!getIsNeg(getGameAtlas(game), i)) {
        SDL_BlitSurface(getPicture(getGameAtlas(game), i)->surface, &getPicture(getGameAtlas(game), i)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), i)->dst);
      }else{
        SDL_BlitSurface(getPicture(getGameAtlas(game), i)->surface, &getPicture(getGameAtlas(game), i)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), i)->neg);
      }
    }
  }

}

void displayTextPannel(Game* game) {
  if(getBoolean(getGameVariables(game), BOOL_PANNEL)) SDL_BlitSurface(getPicture(getGameAtlas(game), PANNEL)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PANNEL)->dst);
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_START)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_START), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  if(getBoolean(getGameVariables(game), BOOL_FOG))  SDL_BlitSurface(getPicture(getGameAtlas(game), FOG)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), FOG)->dst);
}

void displayWaterfall(Game* game) {
  if (getBoolean(getGameVariables(game), BOOL_WATERFALL)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), WATERFALL)->surface, &getPicture(getGameAtlas(game), WATERFALL)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), WATERFALL)->neg);
  }
}

void displayBars(Game* game) {
  updateBar(getGameAtlas(game), getScreen(getGameSdl(game)));
  SDL_BlitSurface(getStamina(getGameAtlas(game)), NULL, getScreen(getGameSdl(game)), getStaminaDst(getGameAtlas(game)));
  SDL_BlitSurface(getLifePoint(getGameAtlas(game)), NULL, getScreen(getGameSdl(game)), getLifePointDst(getGameAtlas(game)));
}
