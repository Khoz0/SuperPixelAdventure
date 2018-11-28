#include "tileset.h"

TileSet* createTileset() {

  TileSet* tileset = malloc(sizeof(TileSet));

  tileset->tileset1 = SDL_LoadBMP("./pictures/tileset/tileset1.bmp");
  tileset->tileset2 = SDL_LoadBMP("./pictures/tileset/tileset2.bmp");
  tileset->tileset3 = SDL_LoadBMP("./pictures/tileset/tileset3.bmp");

  return tileset;

}

void destroyTileset(TileSet* tileset) {

  SDL_FreeSurface(tileset->tileset1);
  SDL_FreeSurface(tileset->tileset2);
  SDL_FreeSurface(tileset->tileset3);

  free(tileset);
  tileset = NULL;

}
