#include "tileset.h"

Image* createImage(char* name, int width, int height) {
  
  Image* image = malloc(sizeof(image));
  
  image->surface = SDL_LoadBMP(name);
  image->isPrinted = 1;
  image->src.x = 0;
  image->src.y = 0;
  image->src.w = width;
  image->src.h = height;
  
  image->dst.x = 0;
  image->dst.y = 0;
  image->dst.w = 0;
  image->dst.h = 0;
  
  return image;
  
}

void destroyImage(Image* image) {
  
  SDL_FreeSurface(image->surface);
  free(image);
  image = NULL;
  
}