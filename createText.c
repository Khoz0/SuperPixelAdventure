#include "createText.h"

Text* createText() {

  Text* text = malloc(sizeof(Text));
  text->tab_text = malloc(sizeof(Text*) * SIZE_TAB_TEXT);
  SDL_Color couleur_noire = {0, 0, 0};

  text->font = TTF_OpenFont("./font/font.ttf", 50);

  text->tab_text[TEXT_PANNEL_START] = TTF_RenderText_Solid(text->font, "* bienvenue a joliland *", couleur_noire);
  text->tab_text[TEXT_PANNEL_CAVE] = TTF_RenderText_Solid(text->font, "*DANGER* entrée de la grote *DANGER*", couleur_noire);

  setTextDst(text, 470, 415);

  return text;

}

SDL_Surface* getText(Text* text, int index) {
  return text->tab_text[index];
}

SDL_Rect* getTextDst(Text* text) {
  return &text->textDst;
}

void setTextDst(Text* text, int x, int y) {
  text->textDst.x = x;
  text->textDst.y = y;
}

void destroyText(Text* text) {

  TTF_CloseFont(text->font);
  for(int i = 0 ; i < SIZE_TAB_TEXT ; i++) {
    SDL_FreeSurface(text->tab_text[i]);
  }
  free(text->tab_text);
  free(text);
  text = NULL;
  TTF_Quit();

}
