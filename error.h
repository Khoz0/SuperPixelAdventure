#pragma once
#include "constants.h"
#include "game.h"

typedef struct Error {
  int isError;
  char* loadGame;
  char* loadAtlas;
  char* loadSdl;
  char* loadAudio;
} Error;

typedef struct Variables Variables;

Error* createError();
void destroyError(Error* error);
void setErrorMessage(Error* error, int index, char* message);
void setErrorIsError(Error* error, int bool);
void threatErrors(Error* error, Game* game);
