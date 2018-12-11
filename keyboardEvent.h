#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

typedef struct Variables Variables;
typedef struct Game Game;

void keyboardEvent(SDL_Event event, Game* game);
void pressE(Game* game, int xchar, int ychar);
void pressZ(Game* game, int xchar, int ychar);
void pressS(Game* game, int xchar, int ychar);
void pressQ(Game* game, int xchar, int ychar);
void pressD(Game* game, int xchar, int ychar);
