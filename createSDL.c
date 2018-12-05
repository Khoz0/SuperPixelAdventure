#include "createSDL.h"

SDL* createSDL(Atlas* atlas) {

  SDL* sdl = malloc(sizeof(SDL));
  sdl->screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

  SDL_SetColorKey(getPicture(atlas, HERO)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, HERO)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, OLD_MAN)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, OLD_MAN)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, OLD_WOMAN)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, OLD_WOMAN)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, INNKEEPER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, INNKEEPER)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, COUNTRY_GUARD)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, COUNTRY_GUARD)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, KIDM)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, KIDM)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, KIDF)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, KIDF)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, WOOD_HUNTER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, WOOD_HUNTER)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, VILLAGER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, VILLAGER)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, FISH_HUNTER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, FISH_HUNTER)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, PANNEL)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, PANNEL)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, FOG)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, FOG)->surface->format, 255, 255, 255));

  SDL_FillRect(stamina, NULL, SDL_MapRGB(getScreen(sdl)->format, 1, 215, 88));
  SDL_FillRect(lifePoint, NULL, SDL_MapRGB(getScreen(sdl)->format, 200, 7, 7));

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
