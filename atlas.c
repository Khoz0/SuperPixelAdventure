#include "atlas.h"

Atlas* createAtlas() {

  Atlas* atlas = malloc(sizeof(Atlas));
  atlas->pictures = malloc(sizeof(Picture*) * SIZE_ATLAS);

  atlas->pictures[HERO] = createPicture("./pictures/characters/hero.bmp", 30, CHAR_HEIGHT);
  atlas->pictures[OLD_MAN] = createPicture("./pictures/characters/papi.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[OLD_WOMAN] = createPicture("./pictures/characters/mamie.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[WATERFALL] = createPicture("./pictures/waterfall/cascades_grandes.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[INNKEEPER] = createPicture("./pictures/characters/aubergisteF.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[COUNTRY_GUARD] = createPicture("./pictures/characters/bucheron.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[KIDM] = createPicture("./pictures/characters/enfantM.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[KIDF] = createPicture("./pictures/characters/enfantF.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[WOOD_HUNTER] = createPicture("./pictures/characters/bucheron.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[VILLAGER] = createPicture("./pictures/characters/villageoise.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[FISH_HUNTER] = createPicture("./pictures/characters/papi.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX] = createPicture("./pictures/chat/chatBox.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[PANNEL] = createPicture("./pictures/chat/pannel.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[FOG] = createPicture("./pictures/tileset/fog.bmp", CHAR_WIDTH, CHAR_HEIGHT);

  atlas->tileset = createTileset();

  return atlas;

}

Picture* getPicture(Atlas* atlas, int index) {

  return atlas->pictures[index];

}

void destroyAtlas(Atlas* atlas) {

  for(int i = 0 ; i < SIZE_ATLAS ; i++) {
    destroyPicture(atlas->pictures[i]);
  }
  free(atlas->pictures);
  destroyTileset(atlas->tileset);
  free(atlas);
  atlas = NULL;

}
