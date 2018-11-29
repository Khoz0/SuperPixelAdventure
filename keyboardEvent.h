#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"

void keyboardEvent(SDL_Event event, int *sprint, int *bool_pannel_start, Uint16** map_boolean, int xchar, int ychar, int* bool_pannel_cave,
	 								 int *bool_pannel, int *width, int *yscroll, int *xscroll, int *dir, int *staminaLength, int *gameOver, Atlas* atlas);
