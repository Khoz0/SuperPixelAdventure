#pragma once
#include "mapBuilder.h"
#include "mapBoolean.h"
#include "display.h"
#include "atlas.h"
#include "tables.h"
#include "destroyTab.h"
#include "keyboardEvent.h"
#include "constants.h"
#include "menu.h"
#include "tables.h"
#include "createText.h"
#include "createAudio.h"

typedef struct Variables Variables;
typedef struct SDL SDL;

typedef struct Game {

  Atlas* atlas;
  Variables* variables;
  SDL* sdl;
  Text* text;
  Tables* tables;
  Audio* audio;

} Game;

Game* createGame();
void runGame(Game* game);
void destroyGame(Game* game);
Atlas* getGameAtlas(Game* game);
Variables* getGameVariables(Game* game);
SDL* getGameSdl(Game* game);
Text* getGameText(Game* game);
Tables* getGameTables(Game* game);
Audio* getGameAudio(Game* game);
void initDstPosition(Game* game);
void capFps();
