#include "booleans.h"

Booleans* createBooleans() {

  Booleans* booleans = malloc(sizeof(Booleans));
  booleans->tabBooleans = malloc(sizeof(Booleans*) * SIZE_TAB_BOOLEAN);

  booleans->tabBooleans[BOOL_WATERFALL] = TRUE;
  booleans->tabBooleans[BOOL_TP_CAVE] = FALSE;
  booleans->tabBooleans[BOOL_FOG] = FALSE;
  booleans->tabBooleans[BOOL_PANNEL] = FALSE;
  booleans->tabBooleans[BOOL_PANNEL_CAVE] = FALSE;
  booleans->tabBooleans[BOOL_PANNEL_START] = FALSE;
  booleans->tabBooleans[BOOL_TP_OUTSIDE] = FALSE;
  booleans->tabBooleans[BOOL_PANNEL_CAVE_ONE] = FALSE;
  booleans->tabBooleans[BOOL_PANNEL_CAVE_TWO] = FALSE;
  booleans->tabBooleans[BOOL_PANNEL_CAVE_THREE] = FALSE;
  booleans->tabBooleans[BOOL_PANNEL_CAVE_FOUR] = FALSE;
  booleans->tabBooleans[BOOL_LEVIER_UN] = FALSE;
  booleans->tabBooleans[BOOL_LEVIER_DEUX] = FALSE;
  booleans->tabBooleans[BOOL_LEVIER_TROIS] = FALSE;
  booleans->tabBooleans[BOOL_LEVIER_QUATRE] = FALSE;

  return booleans;

}

void destroyBooleans(Booleans* booleans) {
  free(booleans->tabBooleans);
  free(booleans);
  booleans = NULL;
}
