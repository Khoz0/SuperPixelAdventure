#include "mapBuilder.h"
#include "mapBoolean.h"
#include "constants.h"
#include "menu.h"

int main(int argc,char** argv){

    SDL_Surface *mainChar = NULL, *stamina = NULL, *lifePoint = NULL, *wizardWPNJ = NULL;
    SDL_Rect positionChar, mainCharGo, staminaPos, lifePointPos, posSpriteWizardPNJ;

    int gameOver = 0;
    int dir = 1, width = 2, sprint = 1, staminaLength = 195;
    
    Uint16** map_builder = mapBuilder();
    Uint16** map_boolean = mapBoolean(map_builder);
    
     for(int i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
       for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
 	printf("%d", map_boolean[j][i]);
       }
       printf("\n");
     }

    int xscroll = MAP_PIXELS_X/4, yscroll = MAP_PIXELS_Y/4;

    SDL_Surface *screen, *tileset;
    SDL_Event event;

    positionChar.x = SCREEN_WIDTH/2;
    positionChar.y = SCREEN_HEIGHT/2;
    
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    mainChar = SDL_LoadBMP("./pictures/hero.bmp");
    tileset = SDL_LoadBMP("./pictures/tileset_background.bmp");

    staminaPos.x = 10;
    staminaPos.y = 45;

    lifePointPos.x = 10;
    lifePointPos.y = 20;

    SDL_EnableKeyRepeat(10, 10);
    //mainMenu();

    if(!tileset){
	printf("Error : tileset didn't load\n");
	return 0;
    }

    SDL_SetColorKey(mainChar, SDL_SRCCOLORKEY, SDL_MapRGB(mainChar->format, 255, 255, 255));

    while (!gameOver){
      int xchar = positionChar.x + xscroll, ychar = positionChar.y + yscroll;
      SDL_PollEvent(&event);
      switch(event.type){
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym){
		    case SDLK_LSHIFT:
			sprint = 2;
		    break;
		    case SDLK_z:
			width = 0;
			printf("\n(%d", xchar/32);
			printf(" ; %d)", ychar/32-1);
			printf(" numéro case : %d", map_boolean[xchar/32][ychar/32]);
			if (yscroll > 0){
			    if(positionChar.y > 448) {
 			      positionChar.y -= 4 * sprint;
 			      if (dir < 20){
 				  dir += (1 * sprint);
 			      }else{
 				  dir = 0;
 			      }
			    }else{
			      yscroll -= 8 * sprint;
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
			    }
			}else if(map_boolean[xchar/32][(ychar+15)/32]==0){
			    positionChar.y -= 4 * sprint;
			    if (dir < 20){
				dir += (1 * sprint);
			    }else{
				dir = 0;
			    }
			}else{
			  positionChar.y -= 0;
			}
		    break;
		    case SDLK_s:
			width = 2;
			printf("\n(%d", xchar/32);
			printf(" ; %d)", ychar/32-1);
			printf(" numéro case : %d", map_boolean[xchar/32][ychar/32+1]);
			if (yscroll < MAP_PIXELS_Y - SCREEN_HEIGHT){
			    if(positionChar.y < 448) {
			      positionChar.y += 4 * sprint;
			      if (dir < 20){
				  dir += (1 * sprint);
			      }else{
				  dir = 0;
			      }
			    }else{
			      yscroll += 8 * sprint;
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
			    }
			}else if((yscroll < MAP_PIXELS_Y) && (positionChar.y < SCREEN_HEIGHT - CHAR_HEIGHT) && (map_boolean[xchar/32][ychar/32+1]==0)){
			    positionChar.y += 4 * sprint;
			    if (dir < 20){
				dir += (1 * sprint);
			    }else{
				dir = 0;
			    }
			}else{
			  positionChar.y += 0;
			}
		    break;
		    case SDLK_d:
			width = 1;
			if (xscroll < MAP_PIXELS_X - SCREEN_WIDTH){
			    if(positionChar.x < 720) {
			      positionChar.x += 4 * sprint;
			      if (dir < 20){
				  dir += (1 * sprint);
			      }else{
				  dir = 0;
			      }
			    }else{
			      xscroll += 8 * sprint;
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
			    }
			}else if((xscroll < MAP_PIXELS_X) && (positionChar.x < SCREEN_WIDTH - CHAR_WIDTH)){
			    positionChar.x += 4 * sprint;
			    if (dir < 20){
				dir += (1 * sprint);
			    }else{
				dir = 0;
			    }
			}else{
			  positionChar.x += 0;
			}
		    break;
		    case SDLK_q:
			width = 3;
			if (xscroll > 0){
			  if(positionChar.x > 720) {
			      positionChar.x -= 4 * sprint;
			      if (dir < 20){
				  dir += (1 * sprint);
			      }else{
				  dir = 0;
			      }
			    }else{
			      xscroll -= 8 * sprint;
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
			    }
			}else{
			    positionChar.x -= 4 * sprint;
			    if (dir < 20){
				dir += (1 * sprint);
			    }else{
				dir = 0;
			    }
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

      SDL_Rect Rect_dest;
      SDL_Rect Rect_source;
      Rect_source.w = WIDTH_TILE;
      Rect_source.h = HEIGHT_TILE;

      for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
	for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
	  Rect_dest.x = i*WIDTH_TILE - xscroll;
	  Rect_dest.y = j*HEIGHT_TILE - yscroll;
	  Rect_source.x = (map_builder[i][j])*WIDTH_TILE;
	  Rect_source.y = 0;
	  SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
	}
      }

      SDL_BlitSurface(stamina, NULL, screen, &staminaPos);
      SDL_BlitSurface(lifePoint, NULL, screen, &lifePointPos);
      SDL_BlitSurface(mainChar, &mainCharGo, screen, &positionChar);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
      SDL_Flip(screen);

    }

    // memory restitution of map_builder
    for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
       free(map_builder[j]);
    }
    free(map_builder);
    
    // memory restitution of map_boolean
    for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
       free(map_boolean[j]);
    }
    free(map_boolean);

    SDL_FreeSurface(tileset);
    SDL_FreeSurface(stamina);
    SDL_FreeSurface(lifePoint);
    SDL_FreeSurface(mainChar);
    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;

}
