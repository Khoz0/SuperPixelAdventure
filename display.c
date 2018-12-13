#include "display.h"
#include "createSDL.h"
#include "variables.h"
#include "game.h"

void display(Game* game) {
  displayMap(game);
  displayWaterfall(game);
  displayChest(game);
  displayFog(game);
  displayHero(game);
  displayPannel(game);
  displayBars(game);
  updateScreen(game);
}

void displayMap(Game* game) {

  SDL_Rect Rect_dest;
  SDL_Rect Rect_source;
  int xscroll = getVariable(getGameVariables(game), XSCROLL);
  int yscroll = getVariable(getGameVariables(game), YSCROLL);
  Rect_source.w = WIDTH_TILE;
  Rect_source.h = HEIGHT_TILE;

  // printing tiles, the file depend on the number of the tile
  // we only print the blocks inside of the scroll window
  for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
    for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
      if((i*WIDTH_TILE > xscroll - WIDTH_TILE) && (i*WIDTH_TILE < xscroll + SCREEN_WIDTH + WIDTH_TILE)
        && (j*WIDTH_TILE > yscroll - WIDTH_TILE) && (j*WIDTH_TILE < yscroll + SCREEN_HEIGHT + WIDTH_TILE)){
        if(getTable(getGameTables(game), MAP_BUILDER)[i][j]<171){
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j])*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET1), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }else if((getTable(getGameTables(game), MAP_BUILDER)[i][j]<341) && (getTable(getGameTables(game), MAP_BUILDER)[i][j]>170)){
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET2), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }else{
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET3), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }
      }
    }
  }
}

void displayPannel(Game* game) {
  if(getBoolean(getGameVariables(game), BOOL_PANNEL)) SDL_BlitSurface(getPicture(getGameAtlas(game), PANNEL)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PANNEL)->dst);
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX)) SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  displayTextPannel(game);
}

void displayTextPannel(Game* game) {
  // print of text at the start of the game
  if(getBoolean(getGameVariables(game), BOOL_SPAWN)){
    setTextDst(getGameText(game), 370, 350);
    SDL_BlitSurface(getText(getGameText(game), TEXT_SPAWN_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 330, 410);
    SDL_BlitSurface(getText(getGameText(game), TEXT_SPAWN_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 580, 460);
    SDL_BlitSurface(getText(getGameText(game), TEXT_SPAWN_3), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text with the countryguard at the start of the game
  if(getBoolean(getGameVariables(game), BOOL_COUNTRYGUARD)) {
    setTextDst(getGameText(game), 370, 420);
    SDL_BlitSurface(getText(getGameText(game), TEXT_COUNTRYGUARD_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 400, 480);
    SDL_BlitSurface(getText(getGameText(game), TEXT_COUNTRYGUARD_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_START)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_START), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_START)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_START), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_ONE)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_ONE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_TWO)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_TWO), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_THREE)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_THREE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_FOUR)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_FOUR), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
}

void displayHero(Game* game) {
  SDL_BlitSurface(getPicture(getGameAtlas(game), HERO)->surface, &getPicture(getGameAtlas(game), HERO)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), HERO)->dst);
}

void displayWaterfall(Game* game) {
  if (getBoolean(getGameVariables(game), BOOL_WATERFALL)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), WATERFALL)->surface, &getPicture(getGameAtlas(game), WATERFALL)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), WATERFALL)->neg);
  }
}

void displayChest(Game* game){
  SDL_BlitSurface(getPicture(getGameAtlas(game), CHEST)->surface, &getPicture(getGameAtlas(game), CHEST)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHEST)->neg);
}

void displayFog(Game* game) {
  if(getBoolean(getGameVariables(game), BOOL_FOG))  SDL_BlitSurface(getPicture(getGameAtlas(game), FOG)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), FOG)->dst);
}

void displayBars(Game* game) {
  updateBars(game);
  SDL_BlitSurface(getStamina(getGameAtlas(game)), NULL, getScreen(getGameSdl(game)), getStaminaDst(getGameAtlas(game)));
  SDL_BlitSurface(getLifePoint(getGameAtlas(game)), NULL, getScreen(getGameSdl(game)), getLifePointDst(getGameAtlas(game)));
}

void updateScreen(Game* game) {
  SDL_UpdateRect(getScreen(getGameSdl(game)), 0, 0, 0, 0);
  SDL_Flip(getScreen(getGameSdl(game)));
}
