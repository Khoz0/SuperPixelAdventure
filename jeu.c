#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define LARGEUR_TILE 32  // hauteur et largeur des tiles.
#define HAUTEUR_TILE 32 

#define NOMBRE_BLOCS_LARGEUR 45  // nombre a afficher en x et y
#define NOMBRE_BLOCS_HAUTEUR 28

char* table[] = {
"555555555555555555555555555555555555555655555",
"556555555555555555555555555556555555555555555",
"555555555555555555555555555555555555555555555",
"555556555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555565555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555655555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555655555555555655555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555556555555555",
"555555555555555555555555555555555555555555555",
"555555556555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555",
"555555555555555555555555555555555555555555555"};



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
    SDL_Surface *rightChar = NULL;
    SDL_Rect positionChar, positionMap, rightCharGo;
    
    int gameOver = 1;
    int dir = 0;
    
    SDL_Surface *screen,*tileset;
    SDL_Event event;
    
    positionMap.x = 0;
    positionMap.y = 0;
    
    positionChar.x = (1410/2) - (30/2);
    positionChar.y = (860/2) - (36/2);
    
    SDL_Init(SDL_INIT_VIDEO);		// prepare SDL
    screen = SDL_SetVideoMode(LARGEUR_TILE*NOMBRE_BLOCS_LARGEUR, HAUTEUR_TILE*NOMBRE_BLOCS_HAUTEUR, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    rightChar = SDL_LoadBMP("heroDroite.bmp");
    tileset = SDL_LoadBMP("background_jeu.bmp");
    
    SDL_SetColorKey(rightChar, SDL_SRCCOLORKEY, SDL_MapRGB(rightChar->format, 255, 255, 255));
    
    SDL_EnableKeyRepeat(10, 10);
    
    if (!tileset)
    {
	printf("Echec de chargement background.png\n");
	SDL_Quit();
	system("pause");
	exit(-1);
    }
	
    Afficher(screen,tileset,table,NOMBRE_BLOCS_LARGEUR,NOMBRE_BLOCS_HAUTEUR);
    
    do 
    {
	SDL_WaitEvent(&event);
    }
    while (event.type!=SDL_KEYDOWN);
	
    
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
					positionChar.x += 4;
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
      
      rightCharGo.x = (30)*(dir/7);
      rightCharGo.y = 0;
      rightCharGo.h = 36;
      rightCharGo.w = 30;
      Afficher(screen,tileset,table,NOMBRE_BLOCS_LARGEUR,NOMBRE_BLOCS_HAUTEUR);
      SDL_BlitSurface(rightChar, &rightCharGo, screen, &positionChar);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
    }
      
    SDL_FreeSurface(tileset);
    SDL_FreeSurface(rightChar);
    SDL_FreeSurface(screen);
	SDL_Quit();
	return 0;
}
