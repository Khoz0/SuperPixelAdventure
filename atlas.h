#pragma once
#include "constants.h"
#include "picture.h"
#include "tileset.h"

typedef struct Atlas {

  Picture** pictures;
  TileSet* tileset;
  int staminaLength;
  int lifePointLength;
  SDL_Rect staminaDst;
  SDL_Rect lifePointDst;
  SDL_Surface* stamina;
  SDL_Surface* life_point;

} Atlas;

Atlas* createAtlas();
void setStaminaDst(Atlas* atlas, int x, int y);
void setLifePointDst(Atlas* atlas, int x, int y);
SDL_Surface* getStamina(Atlas* atlas);
SDL_Surface* getLifePoint(Atlas* atlas);
SDL_Rect* getStaminaDst(Atlas* atlas);
SDL_Rect* getLifePointDst(Atlas* atlas);
int getStaminaLength(Atlas* atlas);
void setStaminaLength(Atlas* atlas, int value);
int getLifePointLength(Atlas* atlas);
void setLifePointLength(Atlas* atlas, int value);
Picture* getPicture(Atlas* atlas, int index);
void destroyAtlas(Atlas* atlas);
