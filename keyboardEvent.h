#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

typedef struct Variables Variables;
typedef struct Game Game;

void keyboardEvent(SDL_Event event, int *sprint, int xchar, int ychar,
	 								 int *width, int *dir, int *gameOver, Game* game);
void pressE(Game* game, int xchar, int ychar);
void pressZ(Game* game, int xchar, int ychar, int *sprint, int *dir, int *width);
void pressS(Game* game, int xchar, int ychar, int *sprint, int *dir, int *width);
void pressQ(Game* game, int xchar, int ychar, int *sprint, int *dir, int *width);
void pressD(Game* game, int xchar, int ychar, int *sprint, int *dir, int *width);
