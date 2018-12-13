#include "createText.h"

Text* createText() {

  Text* text = malloc(sizeof(Text));
  text->tab_text = malloc(sizeof(Text*) * SIZE_TAB_TEXT);
  SDL_Color couleur_noire = {0, 0, 0};

  text->font = TTF_OpenFont("./font/font.ttf", 50);

  text->tab_text[TEXT_PANNEL_START] = TTF_RenderText_Solid(text->font, "* bienvenue a joliland *", couleur_noire);
  text->tab_text[TEXT_PANNEL_CAVE_1] = TTF_RenderText_Solid(text->font, "*DANGER* entrée de la grote *DANGER*", couleur_noire);
  text->tab_text[TEXT_PANNEL_CAVE_2] = TTF_RenderText_Solid(text->font, "Vous devez lire les panneaux et", couleur_noire);
  text->tab_text[TEXT_PANNEL_CAVE_3] = TTF_RenderText_Solid(text->font, "résoudre l'énigme pour activer les leviers", couleur_noire);
  text->tab_text[TEXT_PANNEL_CAVE_ONE] = TTF_RenderText_Solid(text->font, "Ma droite est ma moitie", couleur_noire); // 3 4 2 1
  text->tab_text[TEXT_PANNEL_CAVE_TWO] = TTF_RenderText_Solid(text->font, "3 devient 1", couleur_noire); // 3 - - 1
  text->tab_text[TEXT_PANNEL_CAVE_THREE] = TTF_RenderText_Solid(text->font, "Les premiers sont les derniers", couleur_noire); // - - - 1
  text->tab_text[TEXT_PANNEL_CAVE_FOUR] = TTF_RenderText_Solid(text->font, "Je me situe une place apres moi", couleur_noire); // 3 - 2 1
  text->tab_text[TEXT_SPAWN_1] = TTF_RenderText_Solid(text->font, "Bienvenue dans SuperPixelAdventure !", couleur_noire);
  text->tab_text[TEXT_SPAWN_2] = TTF_RenderText_Solid(text->font, "Va parler au garde champetre en appuyant", couleur_noire);
  text->tab_text[TEXT_SPAWN_3] = TTF_RenderText_Solid(text->font, "sur E devant lui", couleur_noire);
  text->tab_text[TEXT_COUNTRYGUARD_1] = TTF_RenderText_Solid(text->font, "Bienvenue mon p'tiot va lire le panneau", couleur_noire);
  text->tab_text[TEXT_COUNTRYGUARD_2] = TTF_RenderText_Solid(text->font, "derriere toi et je t'ouvre le passage", couleur_noire);
  text->tab_text[TEXT_PANNEL_SPAWN_1] = TTF_RenderText_Solid(text->font, "L'eau a disparu a Joliville", couleur_noire);
  text->tab_text[TEXT_PANNEL_SPAWN_2] = TTF_RenderText_Solid(text->font, "va parler aux habitants et resous le mystere", couleur_noire);
  text->tab_text[TEXT_PANNEL_SPAWN_3] = TTF_RenderText_Solid(text->font, "Le maire", couleur_noire);
  text->tab_text[TEXT_GIRL] = TTF_RenderText_Solid(text->font, "Tu n'aurais pas vu mon frere ?", couleur_noire);
  text->tab_text[TEXT_BOY] = TTF_RenderText_Solid(text->font, "chhht ne dis pas a ma soeur que je suis ici !", couleur_noire);
  text->tab_text[TEXT_INNERKEEPER_1] = TTF_RenderText_Solid(text->font, "Le bucheron et le pecheur ont besoin ", couleur_noire);
  text->tab_text[TEXT_INNERKEEPER_2] = TTF_RenderText_Solid(text->font, "de ton aide, tu devrais aller les voir", couleur_noire);
  text->tab_text[TEXT_VILLAGER] = TTF_RenderText_Solid(text->font, ". . .", couleur_noire);
  text->tab_text[TEXT_FISHMAN_1] = TTF_RenderText_Solid(text->font, "Mon ami Kappa m'a rapporte des poissons", couleur_noire);
  text->tab_text[TEXT_FISHMAN_2] = TTF_RenderText_Solid(text->font, "peux-tu aller me les chercher?", couleur_noire);
  text->tab_text[TEXT_FISHMAN_3] = TTF_RenderText_Solid(text->font, "Ils sont plus haut, pres de la plage", couleur_noire);
  text->tab_text[TEXT_WOODMAN_1] = TTF_RenderText_Solid(text->font, "Zut ! J'ai oublie ma hache... ", couleur_noire);
  text->tab_text[TEXT_WOODMAN_2] = TTF_RenderText_Solid(text->font, "Tu pourrais aller me la chercher ?", couleur_noire);
  text->tab_text[TEXT_WOODMAN_3] = TTF_RenderText_Solid(text->font, "Elle est sur une souche plus bas", couleur_noire);
  text->tab_text[TEXT_OLD_MAN] = TTF_RenderText_Solid(text->font, "Homme : 'On ne peut pas te laisser passer'", couleur_noire);
  text->tab_text[TEXT_OLD_WOMAN] = TTF_RenderText_Solid(text->font, "Femme : 'Il nous faut les preuves de tes actes'", couleur_noire);
  text->tab_text[TEXT_END_GAME_1] = TTF_RenderText_Solid(text->font, "Vous avez fait reapparaitre l'eau ! ", couleur_noire);
  text->tab_text[TEXT_END_GAME_2] = TTF_RenderText_Solid(text->font, "Les citoyens sont heureux et votre", couleur_noire);
  text->tab_text[TEXT_END_GAME_3] = TTF_RenderText_Solid(text->font, "aventure est maintenant terminee !", couleur_noire);
  text->tab_text[TEXT_FISHMAN_AFTER_1] = TTF_RenderText_Solid(text->font, "Hohoho ! Ce fut une belle peche !", couleur_noire);
  text->tab_text[TEXT_FISHMAN_AFTER_2] = TTF_RenderText_Solid(text->font, "Tiens pour te remercier, voici une", couleur_noire);
  text->tab_text[TEXT_FISHMAN_AFTER_3] = TTF_RenderText_Solid(text->font, "lettre prouvant que tu m'as aide", couleur_noire);
  text->tab_text[TEXT_WOODMAN_AFTER_1] = TTF_RenderText_Solid(text->font, "Ah tu l'as! Merci bien mon petit!", couleur_noire);
  text->tab_text[TEXT_WOODMAN_AFTER_2] = TTF_RenderText_Solid(text->font, "Tiens je te donnes une lettre,", couleur_noire);
  text->tab_text[TEXT_OLD_MAN_TURN] = TTF_RenderText_Solid(text->font, "Homme : 'Je vois, tu as donc reussis...''", couleur_noire);
  text->tab_text[TEXT_OLD_WOMAN_TURN] = TTF_RenderText_Solid(text->font, "Femme : 'Nous avons foi en toi'", couleur_noire);
  text->tab_text[TEXT_PANNEL_CAVE_ONE_2] = TTF_RenderText_Solid(text->font, "ma gauche me precede", couleur_noire);

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
