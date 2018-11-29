#include "constants.h"

typedef struct Atlas {

  Picture** pictures;

} Atlas;

Atlas* createAtlas();
void destroyAtlas(Atlas* atlas);