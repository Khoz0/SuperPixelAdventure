#include "constants.h"
#include "booleans.h"

typedef struct Variables {

  Booleans* booleans;

} Variables;

Variables* createVariables();
int getBoolean(Variables* variables, int index);
void setBoolean(Variables* variables, int index, int value);
void destroyVariables(Variables* variables);
