#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

typedef struct Variables Variables;
typedef struct SDL SDL;
typedef struct Game Game;

void display(Game* game, int xscroll, int yscroll);
void displayMap(Tables* tables, SDL_Surface *screen, int xscroll, int yscroll, Atlas* atlas);
void displayPannel(SDL_Surface* screen, Atlas* atlas, Variables* variables);
void displayChar(SDL_Surface* screen, Atlas* atlas);
