#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char* argv[])
{
  SDL_Surface *screen = NULL, *background = NULL, *rightChar = NULL;
  SDL_Rect positionChar, positionMap, rightCharGo;
  SDL_Event event;
  int gameOver;
  int dir = 0;
  
  SDL_Init(SDL_INIT_VIDEO);
  gameOver = 1;
  
  positionMap.x = 0;
  positionMap.y = 0;
  
  positionChar.x = (1410/2) - (30/2);
  positionChar.y = (860/2) - (36/2);
  
  screen = SDL_SetVideoMode(1440,900, 32, SDL_HWSURFACE| SDL_RESIZABLE | SDL_DOUBLEBUF);
  
  background = SDL_LoadBMP("grass.BMP");
  
  rightChar = SDL_LoadBMP("heroDroite.BMP");
  
  SDL_SetColorKey(rightChar, SDL_SRCCOLORKEY, SDL_MapRGB(rightChar->format, 255, 255, 255));

  SDL_WM_SetCaption("Mon jeu", NULL);
  
  
  SDL_EnableKeyRepeat(10, 10);

  while (gameOver)
  {
      SDL_PollEvent(&event);
      switch(event.type)
      {
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
                case SDLK_UP:
				if (positionChar.y > 0){ 
					positionChar.y-=2;
				}else{
					positionChar.y += 0;
				}
                break;
                case SDLK_DOWN:
				if (positionChar.y < 860){
					positionChar.y += 2;
				}else{
					positionChar.y += 0;
				}
                break;
                case SDLK_RIGHT:
				if (positionChar.x < 1410){
					positionChar.x += 2;
					if (dir < 21){
						dir += 1;
					}else{
						dir = 0;
					}
				}else{
					positionChar.x += 0;
				}
                break;
                case SDLK_LEFT:
				if (positionChar.x > 0){
					positionChar.x -= 2;
				}else{
					positionChar.x += 0;
				}
                break;
			case SDLK_q:
				gameOver = 0;
				break;
			  }
            break;
      }
      
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
      for (int x = 0; x < 1440 / 32; x++) {
	  for (int y = 0; y <= 900 / 32; y++) {
	      positionMap.x = x * 32;
	      positionMap.y = y * 32;
	      SDL_BlitSurface(background, NULL, screen, &positionMap);
	      }
      }
      rightCharGo.x = (30)*(dir/7);
      rightCharGo.y = 0;
      rightCharGo.h = 36;
      rightCharGo.w = 30;
      SDL_BlitSurface(background, NULL, screen, &positionMap);
      SDL_BlitSurface(rightChar, &rightCharGo, screen, &positionChar);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
  }
  
  SDL_Flip(screen);
  SDL_FreeSurface(rightChar);
  SDL_FreeSurface(background);
  SDL_Quit();
  
  return EXIT_SUCCESS;
}