#include "createSDL.h"

SDL* createSDL(Atlas* atlas) {

  SDL* sdl = malloc(sizeof(SDL));
  sdl->screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

  SDL_SetColorKey(getPicture(atlas, HERO)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, HERO)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, PANNEL)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, PANNEL)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, FOG)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, FOG)->surface->format, 255, 255, 255));

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_AUDIO);
  TTF_Init();
  Mix_Init(MIX_INIT_MP3);
  SDL_EnableKeyRepeat(10, 10);

  return sdl;

}

void destroySDL(SDL* sdl) {
  SDL_FreeSurface(sdl->screen);
  SDL_Quit();
  free(sdl);
}

SDL_Surface* getScreen(SDL* sdl) {
  return sdl->screen;
}
