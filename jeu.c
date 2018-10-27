#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "display.h"
#include "constants.h"

int main(int argc,char** argv){
  
    SDL_Surface *mainChar = NULL, *stamina = NULL, *lifePoint = NULL, *wizardWPNJ = NULL;
    SDL_Rect positionChar, mainCharGo, staminaPos, lifePointPos, positionWizardWPNJ, posSpriteWizardPNJ;
    
    int gameOver = 0;
    int dir = 1, width = 2, sprint = 1, staminaLength = 195;
    
    SDL_Surface *screen, *tileset;
    SDL_Event event;
    
    positionChar.x = 50;
    positionChar.y = (860/2) - (36/2);

    positionWizardWPNJ.x = 960;
    positionWizardWPNJ.y = 480;
    
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(WIDTH_TILE*MAP_BLOCKS_WIDTH, HEIGHT_TILE*MAP_BLOCKS_HEIGHT, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    mainChar = SDL_LoadBMP("hero.bmp");
    wizardWPNJ = SDL_LoadBMP("wizardWoman.bmp");
    tileset = SDL_LoadBMP("background_jeu.bmp");
    
    staminaPos.x = 10;
    staminaPos.y = 45;

    lifePointPos.x = 10;
    lifePointPos.y = 20;

    SDL_EnableKeyRepeat(10, 10);
    
    if(!tileset){
      
	printf("failure : map didn't load\n");
	SDL_Quit();
	system("pause");
	exit(-1);
	
    }

    Display(screen,tileset);
    SDL_SetColorKey(mainChar, SDL_SRCCOLORKEY, SDL_MapRGB(mainChar->format, 255, 255, 255));
    SDL_SetColorKey(wizardWPNJ, SDL_SRCCOLORKEY, SDL_MapRGB(wizardWPNJ->format, 255, 255, 255));
    
    while (!gameOver){
      
      SDL_PollEvent(&event);
      switch(event.type){
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym){
		    case SDLK_LSHIFT:
			sprint = 2;
		    break;
		    case SDLK_z:
			width = 0;
			if (positionChar.y > 0){
			    positionChar.y -= (4 * sprint);
			    if (dir < 20){
				dir += (1 * sprint);
			    }else{
				dir = 0;
			    }
			    if (sprint == 2 && staminaLength > 1){
				staminaLength -= (2 * sprint);
			    }else if (staminaLength <= 2){
				sprint = 1;
			    }
			}else{
			    positionChar.y += 0;
			}
		    break;
		    case SDLK_s:
			width = 2;
			if (positionChar.y < 860){
			    positionChar.y += (4 * sprint);
			    if (dir < 20){
				dir += (1 * sprint);
			    }else{
				dir = 0;
			    }
			    if (sprint == 2 && staminaLength > 1){
				staminaLength -= (2 * sprint);
			    }else if (staminaLength <= 2){
				sprint = 1;
			    }
			}else{
			    positionChar.y += 0;
			}
		    break;
		    case SDLK_d:
			width = 1;
			if (positionChar.x < 1410){
			    positionChar.x += (4 * sprint);
			    if (dir < 20){
				dir += (1 * sprint);
			    }else{
				dir = 0;
			    }
			    if (sprint == 2 && staminaLength > 1){
				staminaLength -= (2 * sprint);
			    }else if (staminaLength <= 2){
				sprint = 1;
			    }
			}else{
			    positionChar.x += 0;
			}
		    break;
		    case SDLK_q:
			width = 3;
			if (positionChar.x > 0){
			    positionChar.x -= (4 * sprint);
			    if (dir < 20){
				dir += (1 * sprint);
			    }else{
				dir = 0;
			    }
			    if (sprint == 2 && staminaLength > 1){
				staminaLength -= (2 * sprint);
			    }else if (staminaLength <= 2){
				sprint = 1;
			    }
			}else{
			    positionChar.x += 0;
			}
		    break;
		    case SDLK_ESCAPE:
			gameOver = 1;
		    break;
	      }
          break;
	  
	  case SDL_KEYUP:  
	      switch(event.key.keysym.sym){
		  case SDLK_LSHIFT:
		    sprint = 1;
		  break;
		  case SDLK_z:
			dir = 8;
		  break;
		  case SDLK_s:
			dir = 8;
		  break;
		  case SDLK_d:
			dir = 8;
		  break;
		  case SDLK_q:
			dir = 8;
		  break;
	      }
	  break;
      
      }
      
      if (staminaLength > -2 && staminaLength <= 194 && sprint == 1){
	
	  staminaLength += (2 * sprint);
	  
      }
  
      stamina = SDL_CreateRGBSurface(SDL_HWSURFACE, staminaLength + 5, 15, 32, 0, 0 ,0 ,0);
      lifePoint = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 15, 32, 0, 0 ,0 ,0);
  
      SDL_FillRect(stamina, NULL, SDL_MapRGB(screen->format, 1, 215, 88));
      SDL_FillRect(lifePoint, NULL, SDL_MapRGB(screen->format, 200, 7, 7));
  
      mainCharGo.x = 33*(dir/7);
      mainCharGo.y = 36*width;
      mainCharGo.h = 36;
      mainCharGo.w = 30;
  
      posSpriteWizardPNJ.x = 30;
      posSpriteWizardPNJ.y = 36;
      posSpriteWizardPNJ.h = 36;
      posSpriteWizardPNJ.w = 30;

      Display(screen,tileset);
      SDL_BlitSurface(stamina, NULL, screen, &staminaPos);
      SDL_BlitSurface(lifePoint, NULL, screen, &lifePointPos);
      SDL_BlitSurface(wizardWPNJ, &posSpriteWizardPNJ, screen, &positionWizardWPNJ);
      SDL_BlitSurface(mainChar, &mainCharGo, screen, &positionChar);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
      SDL_Flip(screen);
      
    }
      
    SDL_FreeSurface(tileset);
    SDL_FreeSurface(stamina);
    SDL_FreeSurface(lifePoint);
    SDL_FreeSurface(wizardWPNJ);
    SDL_FreeSurface(mainChar);
    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
    
}
