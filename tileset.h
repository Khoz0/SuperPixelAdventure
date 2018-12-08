#pragma once
#include "constants.h"

typedef struct Atlas Atlas;

typedef struct TileSet {

  SDL_Surface* tileset1;
  SDL_Surface* tileset2;
  SDL_Surface* tileset3;

} TileSet;

TileSet* createTileset();
SDL_Surface* getTileset(Atlas* atlas, int index);
void destroyTileset(TileSet* tileset);
