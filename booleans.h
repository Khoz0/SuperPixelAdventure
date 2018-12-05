#include "constants.h"

typedef struct Booleans {

  int* tabBooleans;

} Booleans;

Booleans* createBooleans();
void destroyBooleans(Booleans* booleans);
