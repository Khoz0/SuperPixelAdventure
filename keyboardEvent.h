#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

typedef struct Variables Variables;

void keyboardEvent(SDL_Event event, int *sprint, Variables* variables, Tables* tables, int xchar, int ychar,
	 								 int *width, int *yscroll, int *xscroll, int *dir, int *staminaLength, int *gameOver, Atlas* atlas);
