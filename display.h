#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "displayMap.h"

typedef struct Variables Variables;
typedef struct SDL SDL;

void display(Atlas* atlas, Variables* variables, SDL* sdl, Uint16** map_builder, int xscroll, int yscroll);
