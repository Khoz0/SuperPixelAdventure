#pragma once
#include "constants.h"
#include "picture.h"

void keyboardEvent(SDL_Event event, int *sprint, int *bool_pannel_start, Uint16** map_boolean, int xchar, int ychar, int* bool_pannel_cave, int *bool_pannel,
		   int *width, Picture* hero, int *yscroll, int *xscroll, int *dir, Picture* waterfall, int *staminaLength, int *gameOver, Picture* old_man, Picture* old_woman,
		 	 Picture* innkeeper, Picture* country_guard, Picture* kidM, Picture* kidF, Picture* wood_hunter, Picture* villager, Picture* fish_hunter);
