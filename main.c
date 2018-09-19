#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char* argv[])
{
  SDL_Surface *screen = NULL, *mainChar = NULL, *background = NULL;
  SDL_Rect positionChar, charFaceSprite, positionMap;
  SDL_Event event;
  int gameOver;
  
  SDL_Init(SDL_INIT_VIDEO);
  gameOver = 1;
  
  positionChar.x = (1440/2) - ((246/4)/2);
  positionChar.y = (900/2) - (89/2);
  
  charFaceSprite.x = 0;
  charFaceSprite.y = 0;
  charFaceSprite.h = 89;
  charFaceSprite.w = 246/4;
  
  screen = SDL_SetVideoMode(1440,900, 32, SDL_HWSURFACE| SDL_RESIZABLE | SDL_DOUBLEBUF);
  
  background = SDL_LoadBMP("grass.BMP");
  
  mainChar = SDL_LoadBMP("persoFace.BMP");
  SDL_SetColorKey(mainChar, SDL_SRCCOLORKEY, SDL_MapRGB(mainChar->format, 255, 255, 255));
  

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
                      positionChar.y--;
                      break;
                  case SDLK_DOWN:
                      positionChar.y++;
                      break;
                  case SDLK_RIGHT:
                      positionChar.x++;
                      break;
                  case SDLK_LEFT:
                      positionChar.x--;
                      break;
		  case SDLK_q:
		      gameOver = 0;
		      break;
              }
              break;
      }
      
      SDL_FillRect(screen, NULL, SDL_MapRGB(mainChar->format, 0, 0, 0));
      for (int x = 0; x < 1440 / 32; x++) {
	  for (int y = 0; y < 900 / 32; y++) {
	      positionMap.x = x * 32;
	      positionMap.y = y * 32;
	      SDL_BlitSurface(background, NULL, screen, &positionMap);
	  }
      }
      SDL_BlitSurface(mainChar, &charFaceSprite, screen, &positionChar);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
  }
  
  SDL_Flip(screen);
  SDL_FreeSurface(mainChar);
  SDL_FreeSurface(background);
  SDL_Quit();
  
  return EXIT_SUCCESS;
}