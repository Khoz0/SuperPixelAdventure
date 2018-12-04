#include "constants.h"

typedef struct Booleans {

  int* tabBooleans;

} Booleans;

Booleans* createBooleans();
int getBoolean(Booleans* booleans, int index);
void setBoolean(Booleans* booleans, int index, int value);
void destroyBooleans(Booleans* booleans);
