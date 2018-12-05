#include "variables.h"

Variables* createVariables() {

  Variables* variables = malloc(sizeof(Variables));

  variables->booleans = createBooleans();

  return variables;

}

int getBoolean(Variables* variables, int index) {
  return variables->booleans->tabBooleans[index];
}

void setBoolean(Variables* variables, int index, int value) {
  variables->booleans->tabBooleans[index] = value;
}

void destroyVariables(Variables* variables) {
  destroyBooleans(variables->booleans);
  free(variables);
}
