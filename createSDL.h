#include "constants.h"
#include "atlas.h"

typedef struct SDL{

  SDL_Surface* screen;

} SDL;

SDL* createSDL(Atlas* atlas);
void destroySDL(SDL* sdl);
SDL_Surface* getScreen(SDL* sdl);
