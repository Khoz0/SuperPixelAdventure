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
  booleans->tabBooleans[BOOL_CHEST] = FALSE;
  booleans->tabBooleans[BOOL_SPAWN] = TRUE;
  booleans->tabBooleans[BOOL_SPAWN_STOP] = FALSE;
  booleans->tabBooleans[BOOL_COUNTRYGUARD] = FALSE;
  booleans->tabBooleans[BOOL_CHAT_BOX] = FALSE;  booleans->tabBooleans[BOOL_FISH_QUEST] = FALSE;
  booleans->tabBooleans[BOOL_STUMP] = FALSE;
  booleans->tabBooleans[BOOL_AXE_QUEST] = FALSE;
  booleans->tabBooleans[BOOL_FISHMAN] = FALSE;
  booleans->tabBooleans[BOOL_WOODMAN] = FALSE;
  booleans->tabBooleans[BOOL_OLDMAN_CAVE] = FALSE;
  booleans->tabBooleans[BOOL_OLDWOMAN_CAVE] = FALSE;

  return booleans;

}

void destroyBooleans(Booleans* booleans) {
  free(booleans->tabBooleans);
  free(booleans);
  booleans = NULL;
}
