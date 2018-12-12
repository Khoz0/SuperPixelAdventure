#include "error.h"
#include "variables.h"

typedef struct Error {
  int isError;
  char* message;
} Error;

Error* createError() {

  Error* error = malloc(sizeof(Error));

  error->isError = FALSE;
  error->message = "-> Game has launch without any error\n";

  return error;
}

void destroyError(Error* error) {
  free(error);
  error = NULL;
}

void setErrorMessage(Error* error, char* message) {
  error->message = message;
}

void setErrorIsError(Error* error, int bool) {
  error->isError = bool;
}

void threatErrors(Game* game) {
  if(game->error->isError) {
    setVariable(getGameVariables(game), GAMEOVER, TRUE);
  }
  printf("%s", game->error->message);
}
