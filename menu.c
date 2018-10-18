#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
    SDL_Surface *screenMenu = NULL, *playCase = NULL, *ruleCase = NULL, *quitCase = NULL, *mainChar = NULL, *quitButton = NULL, *playButton = NULL, *goalButton = NULL;
    SDL_Rect playCasePos, ruleCasePos, quitCasePos, positionChar, mainCharGo, quitButtonPos, playButtonPos, goalButtonPos;
    SDL_Event event;
    int endMenu = 1;

    SDL_Init(SDL_INIT_VIDEO);
    screenMenu = SDL_SetVideoMode(600, 400, 32,SDL_HWSURFACE);
    SDL_FillRect(screenMenu, NULL, SDL_MapRGB(screenMenu->format, 70, 180, 55));

    playCasePos.x = 200;
    playCasePos.y = 100;

    ruleCasePos.x = 200;
    ruleCasePos.y = 200;

    quitCasePos.x = 200;
    quitCasePos.y = 300;

    positionChar.x = 0;
    positionChar.y = 0;

    quitButtonPos.x = 200;
    quitButtonPos.y = 300;

    playButtonPos.x = 200;
    playButtonPos.y = 100;

    goalButtonPos.x = 200;
    goalButtonPos.y = 200;

    playCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
    SDL_FillRect(playCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

    ruleCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
    SDL_FillRect(ruleCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

    quitCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
    SDL_FillRect(quitCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

    mainChar = SDL_LoadBMP("hero.bmp");
    SDL_SetColorKey(mainChar, SDL_SRCCOLORKEY, SDL_MapRGB(mainChar->format, 255, 255, 255));

    quitButton = SDL_LoadBMP("boutonQuitter.bmp");
    SDL_SetColorKey(quitButton, SDL_SRCCOLORKEY, SDL_MapRGB(quitButton->format, 255, 255, 255));

    playButton = SDL_LoadBMP("boutonJouer.bmp");
    SDL_SetColorKey(playButton, SDL_SRCCOLORKEY, SDL_MapRGB(playButton->format, 255, 255, 255));

    goalButton = SDL_LoadBMP("boutonBut.bmp");
    SDL_SetColorKey(goalButton, SDL_SRCCOLORKEY, SDL_MapRGB(goalButton->format, 255, 255, 255));

    while(endMenu){
    SDL_PollEvent(&event);
    mainCharGo.x = 33;
    mainCharGo.y = 72;
    mainCharGo.h = 36;
    mainCharGo.w = 30;
    switch(event.type)
      {
	    case SDL_MOUSEBUTTONUP:
          if (event.button.button == SDL_BUTTON_LEFT){
              if (positionChar.x != event.button.x){
                if (positionChar.x >= 0 && positionChar.x <= 567){
                  if (positionChar.x <= (playCasePos.x - 1) || positionChar.x >= (playCasePos.x + 201)){
                    if (abs(event.button.x - (positionChar.x + 1)) < abs(event.button.x - (positionChar.x - 1))){
                      positionChar.x += 1;
                    }else{
                      positionChar.x -= 1;
                    }
                  }else if (positionChar.y <= 64 && positionChar.y >= 151){
                    if (abs(event.button.y - (positionChar.y + 1)) < abs(event.button.y - (positionChar.y - 1))){
                      positionChar.y += 1;
                    }else{
                      positionChar.y -= 1;
                    }
                  }
                }
              }
              if(positionChar.y != event.button.y){
                if (positionChar.y >= 0 && positionChar.y <= 364){
                  if (positionChar.y <= (playCasePos.y - 1) || positionChar.y >= (playCasePos.y + 51)){
                    if (abs(event.button.y - (positionChar.y + 1)) < abs(event.button.y - (positionChar.y - 1))){
                      positionChar.y += 1;
                    }else{
                      positionChar.y -= 1;
                    }
                  }else if (positionChar.x <= 167 && positionChar.x >= 401){
                    if (abs(event.button.x - (positionChar.x + 1)) < abs(event.button.x - (positionChar.x - 1))){
                      positionChar.x += 1;
                    }else{
                      positionChar.x -= 1;
                    }
                  }
                }
              }
		          if (event.button.x > quitCasePos.x - 1 && event.button.x < quitCasePos.x + 199 &&
		              event.button.y > quitCasePos.y - 1 && event.button.y < quitCasePos.y + 49){
		                 endMenu = 0;
		          }
              if (event.button.x > playCasePos.x - 1 && event.button.x < playCasePos.x + 199 &&
         	        event.button.y > playCasePos.y - 1 && event.button.y < playCasePos.y + 49){
                  if (positionChar.y != 144){
                    if(abs(144 - (positionChar.y + 1)) < abs(144 - (positionChar.y - 1))){
                        positionChar.y += 1;
                    }else{
                        positionChar.y -= 1;
                    }
                  }

                  if (positionChar.x < 285 && positionChar.y >= 144){
                    if(abs(285 - (positionChar.x + 1)) < abs(285 - (positionChar.x - 1))){
                        positionChar.x += 1;
                    }else{
                        positionChar.y -= 1;
                    }
                  }
              }
	       }
	    break;
	    case SDL_QUIT:
	       endMenu = 0;
	    break;
      }
      SDL_BlitSurface(playCase, NULL, screenMenu, &playCasePos);
      SDL_BlitSurface(ruleCase, NULL, screenMenu, &ruleCasePos);
      SDL_BlitSurface(quitCase, NULL, screenMenu, &quitCasePos);
      SDL_BlitSurface(mainChar, &mainCharGo, screenMenu, &positionChar);
      SDL_BlitSurface(quitButton, NULL, screenMenu, &quitButtonPos);
      SDL_BlitSurface(playButton, NULL, screenMenu, &playButtonPos);
      SDL_BlitSurface(goalButton, NULL, screenMenu, &goalButtonPos);
      SDL_UpdateRect(screenMenu, 0, 0, 0, 0);
      SDL_Flip(screenMenu);
    }

    SDL_FreeSurface(playCase);
    SDL_FreeSurface(ruleCase);
    SDL_FreeSurface(quitCase);
    SDL_FreeSurface(mainChar);
    SDL_FreeSurface(screenMenu);
    SDL_FreeSurface(quitButton);
    SDL_FreeSurface(playButton);
    SDL_FreeSurface(goalButton);
    SDL_Quit();
    return 0;
}
