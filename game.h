#pragma once
#include "mapBuilder.h"
#include "display.h"
#include "atlas.h"
#include "tables.h"
#include "keyboardEvent.h"
#include "constants.h"
#include "menu.h"
#include "tables.h"
#include "createText.h"
#include "createAudio.h"
#include "error.h"

typedef struct Variables Variables;
typedef struct SDL SDL;
typedef struct Error Error;

typedef struct Game {

  Atlas* atlas;
  Variables* variables;
  SDL* sdl;
  Text* text;
  Tables* tables;
  Audio* audio;
  Error* error;

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
void teleports(Game* game);
void updateMapOld(Game* game);
void updateNegPos(Game* game);
void spawn(Game* game);
void updateAnimationChest(Game* game);
void updateHeroPos(Game* game);
void updatePos(Game* game);
void updateInsideCave(Game* game);
void capFps();
void closeGame();
void talkToCountryGuard(Game* game);
