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

  return booleans;

}

void destroyBooleans(Booleans* booleans) {
  free(booleans->tabBooleans);
  free(booleans);
  booleans = NULL;
}
