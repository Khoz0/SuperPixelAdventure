#include "atlas.h"

Atlas* createAtlas() {

  Atlas* atlas = malloc(sizeof(Atlas));
  atlas->pictures = malloc(sizeof(Picture*) * SIZE_ATLAS);

  setStaminaLength(atlas, 195);
  setLifePointLength(atlas, 200);
  setStaminaDst(atlas, 10, 45);
  setLifePointDst(atlas, 10, 20);

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

  atlas->stamina = SDL_CreateRGBSurface(SDL_HWSURFACE, getStaminaLength(atlas) + 5, 15, 32, 0, 0 ,0 ,0);
  atlas->life_point = SDL_CreateRGBSurface(SDL_HWSURFACE, getLifePointLength(atlas), 15, 32, 0, 0 ,0 ,0);

  atlas->tileset = createTileset();

  return atlas;

}

void setStaminaDst(Atlas* atlas, int x, int y) {
  atlas->staminaDst.x = x;
  atlas->staminaDst.y = y;
}

void setLifePointDst(Atlas* atlas, int x, int y) {
  atlas->lifePointDst.x = x;
  atlas->lifePointDst.y = y;
}

SDL_Rect* getStaminaDst(Atlas* atlas) {
  return &atlas->staminaDst;
}

SDL_Rect* getLifePointDst(Atlas* atlas) {
  return &atlas->lifePointDst;
}

SDL_Surface* getStamina(Atlas* atlas) {
  return atlas->stamina;
}

SDL_Surface* getLifePoint(Atlas* atlas) {
  return atlas->life_point;
}

int getStaminaLength(Atlas* atlas) {
  return atlas->staminaLength;
}

void setStaminaLength(Atlas* atlas, int value) {
  atlas->staminaLength = value;
}

int getLifePointLength(Atlas* atlas) {
  return atlas->lifePointLength;
}

void setLifePointLength(Atlas* atlas, int value) {
  atlas->lifePointLength = value;
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
