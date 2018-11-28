#pragma once
#include "constants.h"

typedef struct TileSet {
  
  SDL_Surface *tileset1;
  SDL_Surface *tileset2;
  SDL_Surface *tileset3;
  
} TileSet;

TileSet* createTileset();

void destroyTileset(TileSet* tileset);