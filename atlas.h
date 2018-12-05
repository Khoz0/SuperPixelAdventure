#pragma once
#include "constants.h"
#include "picture.h"
#include "tileset.h"

typedef struct Atlas {

  Picture** pictures;
  TileSet* tileset;

} Atlas;

Atlas* createAtlas();
Picture* getPicture(Atlas* atlas, int index);
void destroyAtlas(Atlas* atlas);
