#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "displayMap.h"
#include "tables.h"

typedef struct Variables Variables;
typedef struct SDL SDL;

void display(Atlas* atlas, Variables* variables, SDL* sdl, Tables* tables, int xscroll, int yscroll);
