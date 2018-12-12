#pragma once
#include "constants.h"
#include "game.h"

typedef struct Error Error;
typedef struct Variables Variables;

Error* createError();
void destroyError(Error* error);
void setErrorMessage(Error* error, char* message);
void setErrorIsError(Error* error, int bool);
void threatErrors(Game* game);
