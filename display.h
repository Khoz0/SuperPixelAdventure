#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "displayMap.h"

typedef struct Booleans Booleans;

void display(Atlas* atlas, Booleans* booleans, SDL_Surface* screen, Uint16** map_builder, int xscroll, int yscroll);
