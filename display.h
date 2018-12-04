#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "displayMap.h"

void display(Atlas* atlas, SDL_Surface* screen, Uint16** map_builder, int xscroll, int yscroll);