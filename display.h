#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

typedef struct Variables Variables;
typedef struct SDL SDL;
typedef struct Game Game;

void display(Game* game);
void displayMap(Game* game);
void displayPannel(Game* game);
void displayTextPannel(Game* game);
void displayChar(Game* game);
void displayWaterfall(Game* game);
void displayBars(Game* game);
