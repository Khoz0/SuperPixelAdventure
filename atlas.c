#include "atlas.h"

Atlas* createAtlas() {
  
  Atlas* atlas = malloc(sizeof(Atlas));
  atlas->pictures = malloc(sizeof(Picture*) * NB_PICTURES);
  
  Picture* hero = createPicture("./pictures/characters/hero.bmp", 30, CHAR_HEIGHT);
  atlas->pictures[0] = hero;
  Picture* old_man = createPicture("./pictures/characters/papi.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[1] = old_man;
  Picture* old_woman = createPicture("./pictures/characters/mamie.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[2] = old_woman;
  Picture* waterfall = createPicture("./pictures/waterfall/cascades_grandes.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[3] = waterfall;
  Picture* innkeeper = createPicture("./pictures/characters/aubergisteF.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[4] = innkeeper;
  Picture* country_guard = createPicture("./pictures/characters/bucheron.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[5] = country_guard;
  Picture* kidM = createPicture("./pictures/characters/enfantM.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[6] = kidM;
  Picture* kidF = createPicture("./pictures/characters/enfantF.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[7] = kidF;
  Picture* wood_hunter = createPicture("./pictures/characters/bucheron.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[8] = wood_hunter;
  Picture* villager = createPicture("./pictures/characters/villageoise.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[9] = villager;
  Picture* fish_hunter = createPicture("./pictures/characters/papi.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[10] = fish_hunter;
  
  return atlas;
  
}

void destroyAtlas(Atlas* atlas) {
  
  for (int i = 0; i < NB_PICTURES; i++) {
    destroyPicture(atlas->pictures[i]);
  }
  free(atlas->pictures);
  free(atlas);
  
}