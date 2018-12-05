#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"

typedef struct Variables Variables;

void keyboardEvent(SDL_Event event, int *sprint, Variables* variables, Uint16** map_boolean, int xchar, int ychar,
	 								 int *width, int *yscroll, int *xscroll, int *dir, int *staminaLength, int *gameOver, Atlas* atlas);
