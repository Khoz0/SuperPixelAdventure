#pragma once
#include "constants.h"

typedef struct Image {
  
  SDL_Surface *surface;
  int isPrinted;
  SDL_Rect src;
  SDL_Rect dst;
  
} Image;

Image* createImage(char* name, int width, int height);