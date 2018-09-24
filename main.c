#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char* argv[])
{
  SDL_Surface *screen = NULL, *mainChar = NULL, *background = NULL, *rightChar = NULL;
  SDL_Rect positionChar, positionMap, rightCharGo;
  SDL_Event event;
  int gameOver;
  int dir = 0;
  
  SDL_Init(SDL_INIT_VIDEO);
  gameOver = 1;
  
  positionMap.x = 0;
  positionMap.y = 0;
  
  positionChar.x = (1440/2) - ((200/4)/2);
  positionChar.y = (900/2) - (70/2);
  
  screen = SDL_SetVideoMode(1440,900, 32, SDL_HWSURFACE| SDL_RESIZABLE | SDL_DOUBLEBUF);
  
  background = SDL_LoadBMP("grass.BMP");
  
  mainChar = SDL_LoadBMP("persoFace.BMP");
  rightChar = SDL_LoadBMP("marcheDroite.BMP");
  SDL_SetColorKey(mainChar, SDL_SRCCOLORKEY, SDL_MapRGB(mainChar->format, 255, 255, 255));
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
				if (positionChar.y < 900){
					positionChar.y += 2;
				}else{
					positionChar.y += 0;
				}
                break;
                case SDLK_RIGHT:
				if (positionChar.x < 1440){
					positionChar.x += 2;
					if (dir < 40){
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
      
      SDL_FillRect(screen, NULL, SDL_MapRGB(mainChar->format, 0, 0, 0));
      for (int x = 0; x < 1440 / 32; x++) {
	  for (int y = 0; y <= 900 / 32; y++) {
	      positionMap.x = x * 32;
	      positionMap.y = y * 32;
	      SDL_BlitSurface(background, NULL, screen, &positionMap);
	      }
      }
      rightCharGo.x = (200/4)*(dir/10);
      rightCharGo.y = 0;
      rightCharGo.h = 70;
      rightCharGo.w = (200/4);
      SDL_BlitSurface(background, NULL, screen, &positionMap);
      SDL_BlitSurface(rightChar, &rightCharGo, screen, &positionChar);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
  }
  
  SDL_Flip(screen);
  SDL_FreeSurface(mainChar);
  SDL_FreeSurface(background);
  SDL_Quit();
  
  return EXIT_SUCCESS;
}