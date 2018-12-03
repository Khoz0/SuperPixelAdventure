#pragma once
#include "tileset.h"
#include "constants.h"

typedef struct Atlas Atlas;

typedef struct Picture {

  SDL_Surface *surface;
  SDL_Rect src;
  SDL_Rect dst;
  SDL_Rect neg;
  int isPrinted;
  int isNeg;
  
} Picture;

Picture* createPicture(char* name, int width, int height);
void destroyPicture(Picture* picture);
void setSrcPosition(Atlas* atlas, int index, int x, int y);
void setDstPosition(Atlas* atlas, int index, int x, int y);
int getPictureX(Atlas* atlas, int index);
int getPictureY(Atlas* atlas, int index);
void setPictureX(Picture* picture, int x);
void setPictureY(Picture* picture, int y);
void setPictureNegX(Picture* picture, int x, int isNeg);
void setPictureNegY(Picture* picture, int y, int isNeg);
int getIsPrinted(Atlas* atlas, int index);
int getIsNeg(Atlas* atlas, int index);