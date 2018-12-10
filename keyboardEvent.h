#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

typedef struct Variables Variables;
typedef struct Game Game;

void keyboardEvent(SDL_Event event, Game* game);
void pressE(Game* game);
void pressZ(Game* game);
void pressS(Game* game);
void pressQ(Game* game);
void pressD(Game* game);
