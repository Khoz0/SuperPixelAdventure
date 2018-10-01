#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define LARGEUR_TILE 32  // hauteur et largeur des tiles.
#define HAUTEUR_TILE 32 

#define NOMBRE_BLOCS_LARGEUR 45  // nombre a afficher en x et y // 135
#define NOMBRE_BLOCS_HAUTEUR 28                                 // 84    pour map de 3x3

char* table[] = {
"555555555555522255555555555555555522255655555",
"555555555555562225655555555556555522555555555",
"555555555555555222555555555555555522555555555", 
"555556555555555522255555555555555522555555555",
"555555555555555552255555555555555522555555555",
"555555555555555552255555555555555522555555555",
"555555555555555552265555555555555522555555555",
"555555555555555552255555555555555522555555555",
"555555555555555552255555555555555522555555555",
"555555555555555552255555555555555522555555555",
"555555555555555552255555555555555222555555555",
"555555555555555552255555555555555225555555555",
"DDDDDDDDDDDDDDDDD225555555555552222DDDDDDDDDD",
"222222BB2222222222222226222222222222222222222",
"222222222222222222222222222222222222222622222",
"DDDDDDDDDDDDDDDDD2255555555555522DDDDDDDDDDDD",
"555555555555555552255555555555522555555555555",
"555555555555555552255555555555222555555555555",
"555555555555555552255555555552225555555555555",
"555555555555555552255555555552255555555555555",
"555555555555555552255555555552255555555555555",
"555555555555555552255555555522255556555555555",
"555555555555555552255555555222555555555555555",
"555555556555555552222255552225555555555555555",
"555555555555555555652255522255555555555555555",
"555555555555555555552225222555555555555555555",
"555555555555555555555222225555555555555555555",
"555555555555555555555552225555555555555555555"};



void Afficher(SDL_Surface* screen,SDL_Surface* tileset,char** table,int nombre_blocs_largeur,int nombre_blocs_hauteur)
{
	int i,j;
	int test;
	SDL_Rect Rect_dest;
	SDL_Rect Rect_source;
	Rect_source.w = LARGEUR_TILE;
	Rect_source.h = HAUTEUR_TILE;
	for(i=0;i<nombre_blocs_largeur;i++)
	{
		for(j=0;j<nombre_blocs_hauteur;j++)
		{
			if(table[j][i] == 'A'){
			    test = 10;
			    Rect_dest.x = i*LARGEUR_TILE;
			    Rect_dest.y = j*HAUTEUR_TILE;
			    Rect_source.x = test*LARGEUR_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else if(table[j][i] == 'B'){
			    test = 11;
			    Rect_dest.x = i*LARGEUR_TILE;
			    Rect_dest.y = j*HAUTEUR_TILE;
			    Rect_source.x = test*LARGEUR_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else if(table[j][i] == 'C'){
			    test = 12;
			    Rect_dest.x = i*LARGEUR_TILE;
			    Rect_dest.y = j*HAUTEUR_TILE;
			    Rect_source.x = test*LARGEUR_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else if(table[j][i] == 'D'){
			    test = 13;
			    Rect_dest.x = i*LARGEUR_TILE;
			    Rect_dest.y = j*HAUTEUR_TILE;
			    Rect_source.x = test*LARGEUR_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else if(table[j][i] == 'E'){
			    test = 14;
			    Rect_dest.x = i*LARGEUR_TILE;
			    Rect_dest.y = j*HAUTEUR_TILE;
			    Rect_source.x = test*LARGEUR_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}else{
			    Rect_dest.x = i*LARGEUR_TILE;
			    Rect_dest.y = j*HAUTEUR_TILE;
			    Rect_source.x = (table[j][i] - '0')*LARGEUR_TILE;
			    Rect_source.y = 0;
			    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
			}
		}
	}
	SDL_Flip(screen);
}

int main(int argc,char** argv)
{
    SDL_Surface *mainChar = NULL, *stamina = NULL, *lifePoint = NULL, *wizardWPNJ = NULL;
    SDL_Rect positionChar, mainCharGo, staminaPos, lifePointPos, positionWizardWPNJ, posSpriteWizardPNJ;
    
    int gameOver = 1;
    int dir = 1, width = 2, sprint = 1, staminaLength = 195;
    
    SDL_Surface *screen,*tileset;
    SDL_Event event;
    
    positionChar.x = 50;
    positionChar.y = (860/2) - (36/2);
	
	positionWizardWPNJ.x = 960;
	positionWizardWPNJ.y = 480;
    
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(LARGEUR_TILE*NOMBRE_BLOCS_LARGEUR, HAUTEUR_TILE*NOMBRE_BLOCS_HAUTEUR, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    mainChar = SDL_LoadBMP("hero.bmp");
	wizardWPNJ = SDL_LoadBMP("wizardWoman.bmp");
    tileset = SDL_LoadBMP("background_jeu.bmp");
    
	staminaPos.x = 10;
	staminaPos.y = 45;
	
	lifePointPos.x = 10;
	lifePointPos.y = 20;
	
    SDL_EnableKeyRepeat(10, 10);
    
    if (!tileset)
    {
	printf("Echec de chargement background.bmp\n");
	SDL_Quit();
	system("pause");
	exit(-1);
    }
	
    Afficher(screen,tileset,table,NOMBRE_BLOCS_LARGEUR,NOMBRE_BLOCS_HAUTEUR);
    SDL_SetColorKey(mainChar, SDL_SRCCOLORKEY, SDL_MapRGB(mainChar->format, 255, 255, 255));
	SDL_SetColorKey(wizardWPNJ, SDL_SRCCOLORKEY, SDL_MapRGB(wizardWPNJ->format, 255, 255, 255));
    
    while (gameOver)
    {
      SDL_PollEvent(&event);
      switch(event.type)
      {
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
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
            break;
		case SDLK_ESCAPE:
		  gameOver = 0;
		break;
	    }
      break;
	  case SDL_KEYUP:
	      switch(event.key.keysym.sym)
	      {
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
      posSpriteWizardPNJ.y = 30;
      posSpriteWizardPNJ.h = 36;
      posSpriteWizardPNJ.w = 30;
	
      Afficher(screen,tileset,table,NOMBRE_BLOCS_LARGEUR,NOMBRE_BLOCS_HAUTEUR);
      SDL_BlitSurface(stamina, NULL, screen, &staminaPos);
      SDL_BlitSurface(lifePoint, NULL, screen, &lifePointPos);
      SDL_BlitSurface(wizardWPNJ, &posSpriteWizardPNJ, screen, &positionWizardWPNJ);
      SDL_BlitSurface(mainChar, &mainCharGo, screen, &positionChar);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
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
