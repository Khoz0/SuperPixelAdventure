#include "mapBuilder.h"
#include "mapBoolean.h"
#include "constants.h"
#include "menu.h"

int main(int argc,char** argv){

    SDL_Surface *mainChar = NULL, *stamina = NULL, *lifePoint = NULL, *waterfall = NULL, *chatBox = NULL, *pannel = NULL;
    SDL_Rect positionChar, mainCharGo, staminaPos, lifePointPos, posSpriteWizardPNJ, waterfallPos, waterfallAnim, waterfallNeg, positionChatBox, positionPannel;

    int gameOver = 0, cpt = 0, animation = 0;
    int dir = 1, width = 2, sprint = 1, staminaLength = 195;
    int xchar, ychar, xscroll, yscroll, ttf_bool = 0, pannel_bool = 0;
    int actualTime = 0, lastTimes = 0;

    SDL_Surface *screen, *tileset1, *tileset2, *tileset3;
    SDL_Event event;

    mainMenu(&gameOver);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    // initialisation of SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
      printf("Error SDL_mixer : %s\n", Mix_GetError());
    }
    Mix_Music *theme;
    theme = Mix_LoadMUS("theme.mp3");
    Mix_PlayMusic(theme, -1);

    Uint16** map_builder = mapBuilder(MAP_WATER);
    Uint16** map_boolean = mapBoolean(map_builder);

    positionChar.y = SCREEN_HEIGHT/1.4;
    positionChar.x = SCREEN_WIDTH/1.1;

    positionChatBox.y = (SCREEN_HEIGHT - PANNEL_HEIGHT)/2;
    positionChatBox.x = (SCREEN_WIDTH - PANNEL_WIDTH)/2;

    positionPannel.y = (SCREEN_HEIGHT - PANNEL_HEIGHT)/2;
    positionPannel.x = (SCREEN_WIDTH - PANNEL_WIDTH)/2;

    // loading pictures
    mainChar = SDL_LoadBMP("./pictures/characters/hero.bmp");
    chatBox = SDL_LoadBMP("./pictures/chat/chatBox.bmp");
    pannel = SDL_LoadBMP("./pictures/chat/pannel.bmp");
    waterfall = SDL_LoadBMP("./pictures/waterfall/cascades_grandes.bmp");
    SDL_SetColorKey(mainChar, SDL_SRCCOLORKEY, SDL_MapRGB(mainChar->format, 255, 255, 255));
    SDL_SetColorKey(pannel, SDL_SRCCOLORKEY, SDL_MapRGB(pannel->format, 255, 255, 255));
    SDL_SetColorKey(chatBox, SDL_SRCCOLORKEY, SDL_MapRGB(chatBox->format, 255, 255, 255));
    // loading the entire tileset cut in 3 separated parts
    tileset1 = SDL_LoadBMP("./pictures/tileset/tileset1.bmp");
    tileset2 = SDL_LoadBMP("./pictures/tileset/tileset2.bmp");
    tileset3 = SDL_LoadBMP("./pictures/tileset/tileset3.bmp");

    staminaPos.x = 10;
    staminaPos.y = 45;

    lifePointPos.x = 10;
    lifePointPos.y = 20;

    waterfallPos.x = -2208;
    waterfallPos.y = -1728;

    SDL_EnableKeyRepeat(10, 10);

    if(!tileset1 || !tileset2 || !tileset3){
      printf("Error : tileset didn't load\n");
      return 0;
    }

    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
        for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
            printf("%d", map_boolean[j][i]);
        }
        printf("\n");
    }

    //xscroll = MAP_PIXELS_X/4;
    //yscroll = MAP_PIXELS_Y/4;
    xscroll = MAP_PIXELS_X - SCREEN_WIDTH;
    yscroll = MAP_PIXELS_Y - SCREEN_HEIGHT;

    // SDL_ttf initialisation
    TTF_Font *font = NULL;
    font = TTF_OpenFont("./font/font.ttf", 50);
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Surface *texte;
    SDL_Rect posTexte;
    posTexte.x = 470;
    posTexte.y = 415;



    while (!gameOver){


      //Compteur d'images par secondes
      actualTime = SDL_GetTicks();
      float dt = (actualTime - lastTimes);
      if(dt < 1000.0 / FPS_CAP){
        SDL_Delay((1000.0 / FPS_CAP) - dt); //On limite les images par secondes en faisant des pauses entre chaque image
      }
      lastTimes = SDL_GetTicks();
      //Compteur d'images par secondes

      xchar = positionChar.x + xscroll;
      ychar = positionChar.y + yscroll;

      SDL_PollEvent(&event);
      switch(event.type){
      case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
		  case SDLK_LSHIFT:
			   sprint = 5;
		  break;

      case SDLK_e:
        if((map_boolean[xchar/32][(ychar-5)/32]==2) || (map_boolean[xchar/32+1][(ychar-5)/32]==2)){
	        if(ttf_bool == 0){
	          printf("ACTION : LECTURE PANNEAU\n");
	          ttf_bool = 1;
              pannel_bool = 1;
	          texte = TTF_RenderText_Solid(font, "* bienvenue a joliland *", couleurNoire);
		  map_builder = mapBuilder(MAP_NO_WATER);
		  map_boolean = mapBoolean(map_builder);
		  for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
		      for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
			  printf("%d", map_boolean[j][i]);
		      }
		      printf("\n");
		  }
		}
        }else{
          printf("PAS D'ACTION\n");
        }
	    break;

		  case SDLK_z:
			    width = 3;
			    ttf_bool = 0;
                pannel_bool = 0;
			    if (yscroll > 0){
			         if((positionChar.y > 448) && (map_boolean[xchar/32][(ychar-1)/32]==0) && (map_boolean[xchar/32+1][(ychar-1)/32]==0)) {
 			             positionChar.y -= 4 * sprint;
 			             if (dir < 20){
				                 dir += (1 * sprint);
         		             }else{
				                 dir = 0;
 			             }
				 }else if((map_boolean[xchar/32][(ychar-1)/32]==0) && (map_boolean[xchar/32+1][(ychar-1)/32]==0)){
				   yscroll -= 8 * sprint;
				   waterfallPos.y += 8 * sprint;
				   if (dir < 20){
					dir += (1 * sprint);
				   }else{
					dir = 0;
				   }
				   if (sprint == 2 && staminaLength > 1){
					staminaLength -= (1 * sprint);
				   }else if (staminaLength <= 2){
					sprint = 1;
				   }
				 }
			    }else if((map_boolean[xchar/32][(ychar-1)/32]==0) && (map_boolean[xchar/32+1][(ychar-1)/32]==0)){
			        positionChar.y -= 4 * sprint;
			        if (dir < 20){
			             dir += (1 * sprint);
			        }else{
			             dir = 0;
			        }
 			        if (sprint == 2 && staminaLength > 1){
    				     staminaLength -= (1 * sprint);
    			        }else if (staminaLength <= 2){
    				     sprint = 1;
    			        }
			    }else{
			        positionChar.y -= 0;
			    }
		      break;
		  case SDLK_s:
			width = 0;
			ttf_bool = 0;
			pannel_bool = 0;
			if (yscroll < MAP_PIXELS_Y - SCREEN_HEIGHT){
			    if((positionChar.y < 448) && (map_boolean[(xchar+8)/32][(ychar+8)/32+1]==0) && (map_boolean[xchar/32+1][(ychar+8)/32]==0)) {
			         positionChar.y += 4 * sprint;
			         if (dir < 20){
				             dir += (1 * sprint);
			         }else{
				             dir = 0;
			         }
			    }else if ((map_boolean[(xchar+8)/32][(ychar+8)/32+1]==0) && (map_boolean[xchar/32+1][(ychar+8)/32+1]==0)){
			         yscroll += 8 * sprint;
                                 waterfallPos.y -= 8 * sprint;
			         if (dir < 20){
				             dir += (1 * sprint);
			         }else{
				             dir = 0;
			         }
			         if (sprint == 2 && staminaLength > 1){
				             staminaLength -= (1 * sprint);
			         }else if (staminaLength <= 2){
				             sprint = 1;
			         }
			    }
			}else if((yscroll < MAP_PIXELS_Y) && (positionChar.y < SCREEN_HEIGHT - CHAR_HEIGHT)){
			  if(xchar/32 < 133){
			    if((map_boolean[(xchar+8)/32][(ychar+8)/32+1]==0) && (map_boolean[xchar/32+1][(ychar+8)/32+1]==0)){
			      positionChar.y += 4 * sprint;
			      if (dir < 20){
				dir += (1 * sprint);
			      }else{
				dir = 0;
			      }
			    }else{
			      positionChar.y += 0;
			    }
			  }else{
			    if((map_boolean[(xchar+8)/32][(ychar+8)/32+1]==0) && (map_boolean[xchar/32][(ychar+8)/32+1]==0)){
			      positionChar.y += 4 * sprint;
			      if (dir < 20){
				dir += (1 * sprint);
			      }else{
				dir = 0;
			      }
			    }else{
			      positionChar.y += 0;
			    }
			  }
			}
		  break;
		  case SDLK_d:
			width = 2;
			ttf_bool = 0;
			pannel_bool = 0;
			if (xscroll < MAP_PIXELS_X - SCREEN_WIDTH){
			    if((positionChar.x < 720) && (map_boolean[(xchar+7)/32+1][ychar/32]==0) && (map_boolean[(xchar+7)/32+1][ychar/32+1]==0)) {
			         positionChar.x += 4 * sprint;
			         if (dir < 20){
				             dir += (1 * sprint);
			         }else{
				             dir = 0;
			         }
			    }else if ((map_boolean[(xchar+7)/32+1][ychar/32]==0) && (map_boolean[(xchar+7)/32+1][ychar/32+1]==0)){
			         xscroll += 8 * sprint;
                                 waterfallPos.x -= 8 * sprint;
			         if (dir < 20){
				             dir += (1 * sprint);
			         }else{
				             dir = 0;
			         }
			         if (sprint == 2 && staminaLength > 1){
				             staminaLength -= (1 * sprint);
			         }else if (staminaLength <= 2){
				             sprint = 1;
			         }
			    }
			}else if((xscroll < MAP_PIXELS_X) && (positionChar.x < SCREEN_WIDTH - CHAR_WIDTH)){
			  if((xchar)/32 < 133){
			    if((map_boolean[(xchar+7)/32+1][ychar/32]==0) && (map_boolean[(xchar+7)/32+1][ychar/32+1]==0)){
			      positionChar.x += 4 * sprint;
			      if (dir < 20){
				dir += (1 * sprint);
			      }else{
				dir = 0;
			      }
			    }
			  }else{
			    if((map_boolean[(xchar+7)/32][ychar/32]==0) && (map_boolean[(xchar+7)/32][ychar/32+1]==0) && (xchar < 4281)){
			      positionChar.x += 4 * sprint;
			      if (dir < 20){
				dir += (1 * sprint);
			      }else{
				dir = 0;
			      }
			    }
			  }
			}else{
			  positionChar.x += 0;
			}
		  break;
		  case SDLK_q:
			width = 1;
			ttf_bool = 0;
			pannel_bool = 0;
			if (xscroll > 0){
			    if((positionChar.x > 720) && (map_boolean[(xchar-7)/32][ychar/32]==0) && (map_boolean[(xchar-7)/32][ychar/32+1]==0)) {
			         positionChar.x -= 4 * sprint;
			         if (dir < 20){
				             dir += (1 * sprint);
			         }else{
				             dir = 0;
			         }
			    }else if ((map_boolean[(xchar-7)/32][ychar/32]==0) && (map_boolean[(xchar-7)/32][ychar/32+1]==0)){
			         xscroll -= 8 * sprint;
				 waterfallPos.x += 8 * sprint;
			         if (dir < 20){
				             dir += (1 * sprint);
			         }else{
				             dir = 0;
			         }
			         if (sprint == 2 && staminaLength > 1){
				             staminaLength -= (1 * sprint);
			         }else if (staminaLength <= 2){
				             sprint = 1;
			         }
			    }
			}else if ((map_boolean[(xchar-7)/32][ychar/32]==0) && (map_boolean[(xchar-7)/32][ychar/32+1]==0)){
			    positionChar.x -= 4 * sprint;
			    if (dir < 20){
			         dir += (1 * sprint);
			    }else{
			         dir = 0;
			    }
			}else{
			     positionChar.x -= 0;
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

      mainCharGo.x = CHAR_WIDTH*(dir/7);
      mainCharGo.y = CHAR_HEIGHT*width;
      mainCharGo.h = CHAR_HEIGHT;
      mainCharGo.w = 30;

      waterfallAnim.x = 32 * animation;
      waterfallAnim.y = 0;
      waterfallAnim.h = 192;
      waterfallAnim.w = 64;

      SDL_Rect Rect_dest;
      SDL_Rect Rect_source;
      Rect_source.w = WIDTH_TILE;
      Rect_source.h = HEIGHT_TILE;


      // printing tiles, the file depend on the number of the tile
      for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
        for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
          if((i*WIDTH_TILE > xscroll - WIDTH_TILE) && (i*WIDTH_TILE < xscroll + SCREEN_WIDTH + WIDTH_TILE)
            && (j*WIDTH_TILE > yscroll - WIDTH_TILE) && (j*WIDTH_TILE < yscroll + SCREEN_HEIGHT + WIDTH_TILE)){
            if(map_builder[i][j]<171){
                Rect_dest.x = i*WIDTH_TILE - xscroll;
                Rect_dest.y = j*HEIGHT_TILE - yscroll;
                Rect_source.x = (map_builder[i][j])*WIDTH_TILE;
                Rect_source.y = 0;
                SDL_BlitSurface(tileset1,&Rect_source,screen,&Rect_dest);
            }else if((map_builder[i][j]<341) && (map_builder[i][j]>170)){
                Rect_dest.x = i*WIDTH_TILE - xscroll;
                Rect_dest.y = j*HEIGHT_TILE - yscroll;
                Rect_source.x = (map_builder[i][j]%171)*WIDTH_TILE;
                Rect_source.y = 0;
                SDL_BlitSurface(tileset2,&Rect_source,screen,&Rect_dest);
            }else{
                Rect_dest.x = i*WIDTH_TILE - xscroll;
                Rect_dest.y = j*HEIGHT_TILE - yscroll;
                Rect_source.x = (map_builder[i][j]%171)*WIDTH_TILE;
                Rect_source.y = 0;
                SDL_BlitSurface(tileset3,&Rect_source,screen,&Rect_dest);
            }
          }
        }
      }

      cpt += 1;

      if (cpt % 37 == 0){
        animation = 0;
      }
      if (cpt % 33 == 0){
        animation = 1;
      }

      waterfallNeg.x = waterfallPos.x;
      waterfallNeg.y = waterfallPos.y;

      SDL_BlitSurface(stamina, NULL, screen, &staminaPos);
      SDL_BlitSurface(lifePoint, NULL, screen, &lifePointPos);
      SDL_BlitSurface(waterfall, &waterfallAnim, screen, &waterfallNeg);
      SDL_BlitSurface(mainChar, &mainCharGo, screen, &positionChar);
      if(pannel_bool == 1) SDL_BlitSurface(pannel, NULL, screen, &positionPannel);
      if(ttf_bool == 1) SDL_BlitSurface(texte, NULL, screen, &posTexte);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
      SDL_Flip(screen);
      SDL_FreeSurface(stamina);
      SDL_FreeSurface(lifePoint);
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

    // closing SDL libs
    TTF_CloseFont(font);
    Mix_CloseAudio();

    // SDL memory restitution
    SDL_FreeSurface(waterfall);
    SDL_FreeSurface(tileset1);
    SDL_FreeSurface(tileset2);
    SDL_FreeSurface(tileset3);
    SDL_FreeSurface(mainChar);
    SDL_FreeSurface(chatBox);
    SDL_FreeSurface(pannel);
    SDL_FreeSurface(screen);
    Mix_FreeMusic(theme);
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
    return 0;

}
