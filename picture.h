#pragma once
#include "tileset.h"
#include "constants.h"

typedef struct Picture {

  SDL_Surface *surface;
  int isPrinted;
  SDL_Rect src;
  SDL_Rect dst;

} Picture;

Picture* createPicture(char* name, int width, int height);
void destroyPicture(Picture* picture);
void setSrcPosition(Picture* picture, int x, int y);
void setDstPosition(Picture* picture, int x, int y);
int getPictureX(Picture* picture);
int getPictureY(Picture* picture);
void setPictureX(Picture* picture, int x);
void setPictureY(Picture* picture, int y);
