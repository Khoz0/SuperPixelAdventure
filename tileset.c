#include "tileset.h"
#include "atlas.h"

TileSet* createTileset() {

  TileSet* tileset = malloc(sizeof(TileSet));

  tileset->tileset1 = SDL_LoadBMP("./pictures/tileset/tileset1.bmp");
  tileset->tileset2 = SDL_LoadBMP("./pictures/tileset/tileset2.bmp");
  tileset->tileset3 = SDL_LoadBMP("./pictures/tileset/tileset3.bmp");

  return tileset;

}

SDL_Surface* getTileset(Atlas* atlas, int index) {

  if(index==1) return atlas->tileset->tileset1;
  if(index==2) return atlas->tileset->tileset2;
  if(index==3) return atlas->tileset->tileset3;

}

void destroyTileset(TileSet* tileset) {

  SDL_FreeSurface(tileset->tileset1);
  SDL_FreeSurface(tileset->tileset2);
  SDL_FreeSurface(tileset->tileset3);

  free(tileset);
  tileset = NULL;

}
