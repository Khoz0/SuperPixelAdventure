#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

typedef struct Variables Variables;
typedef struct Game Game;

void keyboardEvent(SDL_Event event, int *sprint, int xchar, int ychar,
	 								 int *width, int *yscroll, int *xscroll, int *dir, int *gameOver, Game* game);
