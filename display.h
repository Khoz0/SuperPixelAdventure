#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "displayMap.h"

typedef struct Booleans Booleans;
typedef struct SDL SDL;

void display(Atlas* atlas, Booleans* booleans, SDL* sdl, Uint16** map_builder, int xscroll, int yscroll);
