#pragma once
#include "constants.h"

void keyboardEvent(SDL_Event event, int *sprint, int *bool_pannel_start, Uint16** map_boolean, int xchar, int ychar, int* bool_pannel_cave, int *bool_pannel, 
		   int *width, SDL_Rect *positionChar, int *yscroll, int *xscroll, int *dir, SDL_Rect *waterfallPos, int *staminaLength, int *gameOver);