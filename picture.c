#include "picture.h"

Picture* createPicture(char* name, int width, int height) {

  Picture* picture = malloc(sizeof(Picture));

  picture->surface = SDL_LoadBMP(name);
  picture->isPrinted = 1;
  picture->src.x = 0;
  picture->src.y = 0;
  picture->src.w = width;
  picture->src.h = height;

  picture->dst.x = 0;
  picture->dst.y = 0;
  picture->dst.w = 0;
  picture->dst.h = 0;

  return picture;

}

void destroyPicture(Picture* picture) {

  SDL_FreeSurface(picture->surface);
  free(picture);
  picture = NULL;

}

void setDstPosition(Picture* picture, int x, int y) {

  picture->dst.x = x;
  picture->dst.y = y;

}

void setSrcPosition(Picture* picture, int x, int y) {

  picture->src.x = x;
  picture->src.y = y;

}

int getPictureX(Picture* picture){
  return picture->dst.x;
}

int getPictureY(Picture* picture){
  return picture->dst.y;
}

void setPictureX(Picture* picture, int x){
  picture->dst.x = x;
}

void setPictureY(Picture* picture, int y){
  picture->dst.y = y;
}
