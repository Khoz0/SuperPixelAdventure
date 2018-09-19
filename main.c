#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char* argv[])
{
  SDL_Surface *ecran = NULL, *persoPrincipal = NULL, *fond = NULL;
  SDL_Rect positionPerso, persoFaceSprite, positionMap;
  SDL_Event event;
  int continuer;
  
  SDL_Init(SDL_INIT_VIDEO);
  continuer = 1;
  
  positionPerso.x = (1440/2) - ((246/4)/2);
  positionPerso.y = (900/2) - (89/2);
  
  persoFaceSprite.x = 0;
  persoFaceSprite.y = 0;
  persoFaceSprite.h = 89;
  persoFaceSprite.w = 246/4;
  
  ecran = SDL_SetVideoMode(1440,900, 32, SDL_HWSURFACE| SDL_RESIZABLE | SDL_DOUBLEBUF);
  
  fond = SDL_LoadBMP("grass.BMP");
  
  for (int x = 0; x < 1440 / 32; x++) {
      for (int y = 0; y < 900 / 32; y++) {
	  positionMap.x = x * 32;
	  positionMap.y = y * 32;
	  SDL_BlitSurface(fond, NULL, ecran, &positionMap);
      }
  }
  
  persoPrincipal = SDL_LoadBMP("persoFace.BMP");
  

  SDL_WM_SetCaption("Mon jeu", NULL);
  
  
  SDL_EnableKeyRepeat(10, 10);

  while (continuer)
  {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
                  case SDLK_UP:
                      positionPerso.y--;
                      break;
                  case SDLK_DOWN:
                      positionPerso.y++;
                      break;
                  case SDLK_RIGHT:
                      positionPerso.x++;
                      break;
                  case SDLK_LEFT:
                      positionPerso.x--;
                      break;
		  case SDLK_q:
		      continuer = 0;
		      break;
              }
              break;
      }
      SDL_SetColorKey(persoPrincipal, SDL_SRCCOLORKEY, SDL_MapRGB(persoPrincipal->format, 255, 255, 255));
      SDL_BlitSurface(persoPrincipal, &persoFaceSprite, ecran, &positionPerso);
      SDL_Flip(ecran);
  }
  
  SDL_Flip(ecran);
  SDL_FreeSurface(persoPrincipal);
  SDL_FreeSurface(fond);
  SDL_Quit();
  
  return EXIT_SUCCESS;
}