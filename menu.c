#include "menu.h"

void mainMenu(int* gameOver){

  SDL_Surface *playCase = NULL, *ruleCase = NULL, *quitCase = NULL, *screenMenu, *menuChar, *scroll;
  SDL_Surface *quitButton = NULL, *playButton = NULL, *goalButton = NULL;
  SDL_Event event;
  SDL_Rect playCasePos, ruleCasePos, quitCasePos, quitButtonPos, playButtonPos, goalButtonPos, positionChar, mainCharGo, scrollPos;
  int endMenu = 1, i, j, speed, authorizedX = 1, authorizedY = 1, orientation = 2, movement = 1, goalPurpose = 0;
  TTF_Font *font = NULL;
  SDL_Color couleurNoire = {0, 0, 0};
  SDL_Surface *texte1, *texte2, *texte3, *texte4, *texte5, *texte6;
  SDL_Rect posTexte1, posTexte2, posTexte3, posTexte4, posTexte5, posTexte6;

  int **tabCollide = malloc(SCREEN_WIDTH*sizeof(int*));
  for(int j = 0 ; j < SCREEN_WIDTH; j++){
    tabCollide[j] = malloc(SCREEN_HEIGHT*sizeof(int));
  }

  screenMenu = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  SDL_FillRect(screenMenu, NULL, SDL_MapRGB(screenMenu->format, 70, 180, 55));

  Mix_Init(MIX_INIT_MP3);
  TTF_Init();

  // initialisation of SDL_mixer
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
    printf("Error SDL_mixer : %s\n", Mix_GetError());
  }
  Mix_Music *themeMenu;
  themeMenu = Mix_LoadMUS("themeMenu.mp3");
  Mix_PlayMusic(themeMenu, -1);

  playCasePos.x = 600;
  playCasePos.y = 200;

  ruleCasePos.x = 600;
  ruleCasePos.y = 400;

  quitCasePos.x = 600;
  quitCasePos.y = 600;

  positionChar.x = 0;
  positionChar.y = 0;

  quitButtonPos.x = 600;
  quitButtonPos.y = 600;

  playButtonPos.x = 600;
  playButtonPos.y = 200;

  goalButtonPos.x = 600;
  goalButtonPos.y = 400;

  scrollPos.x = 400;
  scrollPos.y = 200;

  font = TTF_OpenFont("./font/font.ttf", 20);
  posTexte1.x = 550;
  posTexte1.y = 260;

  posTexte2.x = 450;
  posTexte2.y = 300;

  posTexte3.x = 450;
  posTexte3.y = 350;

  posTexte4.x = 450;
  posTexte4.y = 400;

  posTexte5.x = 450;
  posTexte5.y = 450;

  posTexte6.x = 550;
  posTexte6.y = 500;

  playCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
  SDL_FillRect(playCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

  ruleCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
  SDL_FillRect(ruleCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

  quitCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
  SDL_FillRect(quitCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

  menuChar = SDL_LoadBMP("./pictures/characters/hero.bmp");
  SDL_SetColorKey(menuChar, SDL_SRCCOLORKEY, SDL_MapRGB(menuChar->format, 255, 255, 255));

  quitButton = SDL_LoadBMP("./pictures/menu/boutonQuitter.bmp");
  SDL_SetColorKey(quitButton, SDL_SRCCOLORKEY, SDL_MapRGB(quitButton->format, 255, 255, 255));

  playButton = SDL_LoadBMP("./pictures/menu/boutonJouer.bmp");
  SDL_SetColorKey(playButton, SDL_SRCCOLORKEY, SDL_MapRGB(playButton->format, 255, 255, 255));

  goalButton = SDL_LoadBMP("./pictures/menu/boutonBut.bmp");
  SDL_SetColorKey(goalButton, SDL_SRCCOLORKEY, SDL_MapRGB(goalButton->format, 255, 255, 255));

  scroll = SDL_LoadBMP("./pictures/menu/parch1.bmp");
  SDL_SetColorKey(scroll, SDL_SRCCOLORKEY, SDL_MapRGB(scroll->format, 0, 0, 0));

  for (i = 0; i < SCREEN_WIDTH-1; i++){
    for (j = 0; j < SCREEN_HEIGHT-1; j++){
       tabCollide[i][j] = 0;					// il n'y a pas de collision
    }
  }

  for (i = playCasePos.x - 33; i <= playCasePos.x + 200; i++){
    for (j = playCasePos.y - 36; j <= playCasePos.y + 50; j++){
       tabCollide[i][j] = 2;					// il y a une collision
    }
  }

  for (i = ruleCasePos.x - 33; i <= ruleCasePos.x + 200; i++){
    for (j = ruleCasePos.y - 36; j <= ruleCasePos.y + 50; j++){
       tabCollide[i][j] = 2;					// il y a une collision
    }
  }

  for (i = quitCasePos.x - 33; i <= quitCasePos.x + 200; i++){
    for (j = quitCasePos.y - 36; j <= quitCasePos.y + 50; j++){
       tabCollide[i][j] = 2;					// il y a une collision
    }
  }

  while(endMenu){
  SDL_PollEvent(&event);
  mainCharGo.x = CHAR_WIDTH * movement;
  mainCharGo.y = CHAR_HEIGHT * orientation;
  mainCharGo.h = CHAR_WIDTH;
  mainCharGo.w = 30;
  switch(event.type)
    {
    case SDL_MOUSEBUTTONUP:
    goalPurpose = 0;
    if (event.button.button == SDL_BUTTON_LEFT){
       if ((positionChar.x != event.button.x) && authorizedX){
         if (tabCollide[positionChar.x + 1][positionChar.y] == 0 ){
           if (abs(event.button.x - (positionChar.x + 1)) < abs(event.button.x - (positionChar.x - 1))){
             orientation = 2;
             if (movement < 2){
               movement += 1;
             }else{
               movement = 0;
             }
             speed = 1;
             positionChar.x += speed;

           }
         }
         if (tabCollide[positionChar.x - 1][positionChar.y] == 0 ){
           if (abs(event.button.x - (positionChar.x - 1)) < abs(event.button.x - (positionChar.x + 1))){
             orientation = 1;
             if (movement < 2){
               movement += 1;
             }else{
               movement = 0;
             }
             speed = 1;
             positionChar.x -= speed;
           }
         }
         if ((tabCollide[positionChar.x + 1][positionChar.y] != 0 ) || (tabCollide[positionChar.x - 1][positionChar.y] != 0)){
           speed = 0;
         }
         if (speed < 1){
           authorizedY = 0;
           speed = 1;
           if ((event.button.x - positionChar.x) < 0){
             speed = 1;
             orientation = 0;
           }
           if ((event.button.x - positionChar.x) > 0){
             speed = -1;
             orientation = 3;
           }
           if (movement < 2){
             movement += 1;
           }else{
             movement = 0;
           }
           positionChar.y += speed;
         }
       }
       authorizedX = 1;


       if ((positionChar.y != event.button.y) && (authorizedY)){
         if (tabCollide[positionChar.x][positionChar.y + 1] == 0 ){
           if (abs(event.button.y - (positionChar.y + 1)) < abs(event.button.y - (positionChar.y - 1))){
             orientation = 0;
             if (movement < 2){
               movement += 1;
             }else{
               movement = 0;
             }
             speed = 1;
             positionChar.y += speed;
           }
         }
         if (tabCollide[positionChar.x][positionChar.y - 1] == 0 ){
           if (abs(event.button.y - (positionChar.y - 1)) < abs(event.button.y - (positionChar.y + 1))){
             orientation = 3;
             if (movement < 2){
               movement += 1;
             }else{
               movement = 0;
             }
             speed = 1;
             positionChar.y -= speed;
           }
         }
         if (tabCollide[positionChar.x][positionChar.y + 1] != 0 ){
           speed = 0;
         }
         if (tabCollide[positionChar.x][positionChar.y - 1] != 0 ){
           speed = 0;
         }
         if (speed < 1){
           authorizedX = 0;
           speed = 1;
           if ((event.button.y - positionChar.y) < 0){
             speed = -1;
             orientation = 1;
           }
           if ((event.button.y - positionChar.y) > 0){
             speed = 1;
             orientation = 2;
           }
           if (movement < 2){
             movement += 1;
           }else{
             movement = 0;
           }
           positionChar.x += speed;
         }
       }
       authorizedY = 1;
       if (event.button.x > playCasePos.x && event.button.x < playCasePos.x + 200 &&
           event.button.y > playCasePos.y && event.button.y < playCasePos.y + 50){
         if (positionChar.x >= playCasePos.x - 34 && positionChar.x <= playCasePos.x + 201 &&
           positionChar.y >= playCasePos.y - 1 && positionChar.y <= playCasePos.y + 51){
             endMenu = 0;
             }
         }

      if (event.button.x > ruleCasePos.x && event.button.x < ruleCasePos.x + 200 &&
          event.button.y > ruleCasePos.y && event.button.y < ruleCasePos.y + 50){
        if (positionChar.x >= ruleCasePos.x - 34 && positionChar.x <= ruleCasePos.x + 201 &&
          positionChar.y >= ruleCasePos.y - 1 && positionChar.y <= ruleCasePos.y + 51){
            texte1 = TTF_RenderText_Solid(font, "bienvenue dans 'Le mythe de Zoldo.'", couleurNoire);
            texte2 = TTF_RenderText_Solid(font, "Vous incarnerez Lien, le hero et detective sans peur. Vous devrez", couleurNoire);
            texte3 = TTF_RenderText_Solid(font, "aider les habitants de Joliland a comprendre pourquoi l'eau ne", couleurNoire);
            texte4 = TTF_RenderText_Solid(font, "coule plus dans leur jolie ville, et resoudre ce probleme", couleurNoire);
            texte5 = TTF_RenderText_Solid(font, "par vous meme.", couleurNoire);
            texte6 = TTF_RenderText_Solid(font, "* BONNE CHANCE INVOCATEUR *", couleurNoire);
            goalPurpose = 1;
            authorizedX = 0;
            authorizedY = 0;
        }
      }
      if (event.button.x > quitCasePos.x && event.button.x < quitCasePos.x + 200 &&
          event.button.y > quitCasePos.y && event.button.y < quitCasePos.y + 50){
        if (positionChar.x >= quitCasePos.x - 34 && positionChar.x <= quitCasePos.x + 201 &&
          positionChar.y >= quitCasePos.y - 1 && positionChar.y <= quitCasePos.y + 51){
            *gameOver = 1;
            endMenu = 0;
        }
     }
   }
   break;
 }

    SDL_BlitSurface(menuChar, &mainCharGo, screenMenu, &positionChar);
    SDL_BlitSurface(playCase, NULL, screenMenu, &playCasePos);
    SDL_BlitSurface(ruleCase, NULL, screenMenu, &ruleCasePos);
    SDL_BlitSurface(quitCase, NULL, screenMenu, &quitCasePos);
    SDL_BlitSurface(quitButton, NULL, screenMenu, &quitButtonPos);
    SDL_BlitSurface(playButton, NULL, screenMenu, &playButtonPos);
    SDL_BlitSurface(goalButton, NULL, screenMenu, &goalButtonPos);
    if (goalPurpose){
      SDL_BlitSurface(scroll, NULL, screenMenu, &scrollPos);
      SDL_BlitSurface(texte1, NULL, screenMenu, &posTexte1);
      SDL_BlitSurface(texte2, NULL, screenMenu, &posTexte2);
      SDL_BlitSurface(texte3, NULL, screenMenu, &posTexte3);
      SDL_BlitSurface(texte4, NULL, screenMenu, &posTexte4);
      SDL_BlitSurface(texte5, NULL, screenMenu, &posTexte5);
      SDL_BlitSurface(texte6, NULL, screenMenu, &posTexte6);
    }
    SDL_UpdateRect(screenMenu, 0, 0, 0, 0);
    SDL_Flip(screenMenu);
    SDL_FillRect(screenMenu, NULL, SDL_MapRGB(screenMenu->format, 70, 180, 55));

  }

  Mix_CloseAudio();
  TTF_CloseFont(font);

  Mix_FreeMusic(themeMenu);
  SDL_FreeSurface(menuChar);
  SDL_FreeSurface(playCase);
  SDL_FreeSurface(ruleCase);
  SDL_FreeSurface(quitCase);
  SDL_FreeSurface(quitButton);
  SDL_FreeSurface(playButton);
  SDL_FreeSurface(goalButton);
  SDL_FreeSurface(scroll);
  for(int j = 0 ; j < SCREEN_WIDTH ; j++){
     free(tabCollide[j]);
  }
  free(tabCollide);
  SDL_FreeSurface(screenMenu);
}
