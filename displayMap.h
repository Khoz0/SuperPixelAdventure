#pragma once
#include "constants.h"
#include "tileset.h"

void displayMap(Uint16** map_builder, SDL_Surface *screen, int xscroll, int yscroll, Atlas* atlas);
