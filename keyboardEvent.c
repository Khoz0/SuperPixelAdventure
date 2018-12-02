#include "keyboardEvent.h"

void keyboardEvent(SDL_Event event, int *sprint, int *bool_pannel_start, Uint16** map_boolean, int xchar, int ychar, int* bool_pannel_cave,
	 								 int *bool_pannel, int *width, int *yscroll, int *xscroll, int *dir, int *staminaLength, int *gameOver, Atlas* atlas){

  switch(event.type){
	case SDL_KEYDOWN:
	switch(event.key.keysym.sym){
		    case SDLK_LSHIFT:
			    *sprint = 5;
		    break;

	case SDLK_e:
		  if(*bool_pannel_start == 0){
		    printf("ACTION : LECTURE PANNEAU\n");
		    *bool_pannel_start = 1;
		    if((map_boolean[xchar/32][(ychar-5)/32]==2) || (map_boolean[xchar/32+1][(ychar-5)/32]==2)) *bool_pannel_start = 1;
		    if((map_boolean[xchar/32][(ychar-5)/32]==4) || (map_boolean[xchar/32+1][(ychar-5)/32]==4)) *bool_pannel_cave = 1;
		    *bool_pannel = 1;
		    //map_builder = mapBuilder(MAP_NO_WATER);
		    //map_boolean = mapBoolean(map_builder);
		    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
			    for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
			      printf("%d", map_boolean[j][i]);
			    }
			  printf("\n");
		    }
		  }
	      break;

		    case SDLK_z:
			      *width = 3;
			      *bool_pannel_start = 0;
			      *bool_pannel = 0;
			      *bool_pannel_cave = 0;
			      if(map_boolean[xchar/32][(ychar-15)/32]==3 && map_boolean[xchar/32+1][(ychar-15)/32]==3){
						setPictureY(getPicture(atlas, HERO), getPictureY(atlas, HERO) - 4 * *sprint);
			      }
			      if (*yscroll > 0){
				  if((getPictureY(atlas, HERO) > 448) && (map_boolean[xchar/32][(ychar-1)/32]==0) && (map_boolean[xchar/32+1][(ychar-1)/32]==0)) {
							setPictureY(getPicture(atlas, HERO), getPictureY(atlas, HERO) - 4 * *sprint);
				      if (*dir < 20){
						  *dir += (1 * *sprint);
				      }else{
						  *dir = 0;
				      }
				  }else if((map_boolean[xchar/32][(ychar-1)/32]==0) && (map_boolean[xchar/32+1][(ychar-1)/32]==0)){
				    *yscroll -= 8 * *sprint;
						setPictureY(getPicture(atlas, WATERFALL), getPictureY(atlas, WATERFALL) + 8 * *sprint);
						setPictureY(getPicture(atlas, OLD_MAN), getPictureY(atlas, OLD_MAN) + 8 * *sprint);
						setPictureY(getPicture(atlas, OLD_WOMAN), getPictureY(atlas, OLD_WOMAN) + 8 * *sprint);
						setPictureY(getPicture(atlas, INNKEEPER), getPictureY(atlas, INNKEEPER) + 8 * *sprint);
						setPictureY(getPicture(atlas, COUNTRY_GUARD), getPictureY(atlas, COUNTRY_GUARD) + 8 * *sprint);
						setPictureY(getPicture(atlas, KIDM), getPictureY(atlas, KIDM) + 8 * *sprint);
						setPictureY(getPicture(atlas, KIDF), getPictureY(atlas, KIDF) + 8 * *sprint);
						setPictureY(getPicture(atlas, WOOD_HUNTER), getPictureY(atlas, WOOD_HUNTER) + 8 * *sprint);
						setPictureY(getPicture(atlas, VILLAGER), getPictureY(atlas, VILLAGER) + 8 * *sprint);
						setPictureY(getPicture(atlas, FISH_HUNTER), getPictureY(atlas, FISH_HUNTER) + 8 * *sprint);
				    if (*dir < 20){
					  *dir += (1 * *sprint);
				    }else{
					  *dir = 0;
				    }
				    if (*sprint == 2 && *staminaLength > 1){
					  *staminaLength -= (1 * *sprint);
				    }else if (*staminaLength <= 2){
					  *sprint = 1;
				    }
				  }
			      }else if((map_boolean[xchar/32][(ychar-1)/32]==0) && (map_boolean[xchar/32+1][(ychar-1)/32]==0)){
					setPictureY(getPicture(atlas, HERO), getPictureY(atlas, HERO) - 4 * *sprint);
				  if (*dir < 20){
				      *dir += (1 * *sprint);
				  }else{
				      *dir = 0;
				  }
				  if (*sprint == 2 && *staminaLength > 1){
				      *staminaLength -= (1 * *sprint);
				  }else if (*staminaLength <= 2){
				      *sprint = 1;
				  }
			      }
			break;
		    case SDLK_s:
			  *width = 0;
			  *bool_pannel_start = 0;
			  *bool_pannel = 0;
			  *bool_pannel_cave = 0;
			  if (*yscroll < MAP_PIXELS_Y - SCREEN_HEIGHT){
			      if((getPictureY(atlas, HERO) < 448) && (map_boolean[(xchar+8)/32][(ychar+8)/32+1]==0) && (map_boolean[xchar/32+1][(ychar+8)/32]==0)) {
					setPictureY(getPicture(atlas, HERO), getPictureY(atlas, HERO) + 4 * *sprint);
				  if (*dir < 20){
					      *dir += (1 * *sprint);
				  }else{
					      *dir = 0;
				  }
			      }else if ((map_boolean[(xchar+8)/32][(ychar+8)/32+1]==0) && (map_boolean[xchar/32+1][(ychar+8)/32+1]==0)){
				  *yscroll += 8 * *sprint;
					setPictureY(getPicture(atlas, WATERFALL), getPictureY(atlas, WATERFALL) - 8 * *sprint);
					setPictureY(getPicture(atlas, OLD_MAN), getPictureY(atlas, OLD_MAN) - 8 * *sprint);
					setPictureY(getPicture(atlas, OLD_WOMAN), getPictureY(atlas, OLD_WOMAN) - 8 * *sprint);
					setPictureY(getPicture(atlas, INNKEEPER), getPictureY(atlas, INNKEEPER) - 8 * *sprint);
					setPictureY(getPicture(atlas, COUNTRY_GUARD), getPictureY(atlas, COUNTRY_GUARD) - 8 * *sprint);
					setPictureY(getPicture(atlas, KIDM), getPictureY(atlas, KIDM) - 8 * *sprint);
					setPictureY(getPicture(atlas, KIDF), getPictureY(atlas, KIDF) - 8 * *sprint);
					setPictureY(getPicture(atlas, WOOD_HUNTER), getPictureY(atlas, WOOD_HUNTER) - 8 * *sprint);
					setPictureY(getPicture(atlas, VILLAGER), getPictureY(atlas, VILLAGER) - 8 * *sprint);
					setPictureY(getPicture(atlas, FISH_HUNTER), getPictureY(atlas, FISH_HUNTER) - 8 * *sprint);
				  if (*dir < 20){
					      *dir += (1 * *sprint);
				  }else{
					      *dir = 0;
				  }
				  if (*sprint == 2 && *staminaLength > 1){
					      *staminaLength -= (1 * *sprint);
				  }else if (*staminaLength <= 2){
					      *sprint = 1;
				  }
			      }
			  }else if((*yscroll < MAP_PIXELS_Y) && (getPictureY(atlas, HERO) < SCREEN_HEIGHT - CHAR_HEIGHT)){
			    if(xchar/32 < 133){
			      if((map_boolean[(xchar+8)/32][(ychar+8)/32+1]==0) && (map_boolean[xchar/32+1][(ychar+8)/32+1]==0)){
				setPictureY(getPicture(atlas, HERO), getPictureY(atlas, HERO) + 4 * *sprint);
				if (*dir < 20){
				  *dir += (1 * *sprint);
				}else{
				  *dir = 0;
				}
			      }
			    }else{
			      if((map_boolean[(xchar+8)/32][(ychar+8)/32+1]==0) && (map_boolean[xchar/32][(ychar+8)/32+1]==0)){
				setPictureY(getPicture(atlas, HERO), getPictureY(atlas, HERO) + 4 * *sprint);
				if (*dir < 20){
				  *dir += (1 * *sprint);
				}else{
				  *dir = 0;
				}
			      }
			    }
			  }
		    break;
		    case SDLK_d:
			  *width = 2;
			  *bool_pannel_start = 0;
			  *bool_pannel = 0;
			  *bool_pannel_cave = 0;
			  if (*xscroll < MAP_PIXELS_X - SCREEN_WIDTH){
			      if((getPictureX(atlas, HERO) < 720) && (map_boolean[(xchar+7)/32+1][ychar/32]==0) && (map_boolean[(xchar+7)/32+1][ychar/32+1]==0)) {
					setPictureX(getPicture(atlas, HERO), getPictureX(atlas, HERO) + 4 * *sprint);
				  if (*dir < 20){
					      *dir += (1 * *sprint);
				  }else{
					      *dir = 0;
				  }
			      }else if ((map_boolean[(xchar+7)/32+1][ychar/32]==0) && (map_boolean[(xchar+7)/32+1][ychar/32+1]==0)){
				  *xscroll += 8 * *sprint;
					setPictureX(getPicture(atlas, WATERFALL), getPictureX(atlas, WATERFALL) - 8 * *sprint);
					setPictureX(getPicture(atlas, OLD_MAN), getPictureX(atlas, OLD_MAN) - 8 * *sprint);
					setPictureX(getPicture(atlas, OLD_WOMAN), getPictureX(atlas, OLD_WOMAN) - 8 * *sprint);
					setPictureX(getPicture(atlas, INNKEEPER), getPictureX(atlas, INNKEEPER) - 8 * *sprint);
					setPictureX(getPicture(atlas, COUNTRY_GUARD), getPictureX(atlas, COUNTRY_GUARD) - 8 * *sprint);
					setPictureX(getPicture(atlas, KIDM), getPictureX(atlas, KIDM) - 8 * *sprint);
					setPictureX(getPicture(atlas, KIDF), getPictureX(atlas, KIDF) - 8 * *sprint);
					setPictureX(getPicture(atlas, WOOD_HUNTER), getPictureX(atlas, WOOD_HUNTER) - 8 * *sprint);
					setPictureX(getPicture(atlas, VILLAGER), getPictureX(atlas, VILLAGER) - 8 * *sprint);
					setPictureX(getPicture(atlas, FISH_HUNTER), getPictureX(atlas, FISH_HUNTER) - 8 * *sprint);
				  if (*dir < 20){
					      *dir += (1 * *sprint);
				  }else{
					      *dir = 0;
				  }
				  if (*sprint == 2 && *staminaLength > 1){
					      *staminaLength -= (1 * *sprint);
				  }else if (*staminaLength <= 2){
					      *sprint = 1;
				  }
			      }
			  }else if((*xscroll < MAP_PIXELS_X) && (getPictureX(atlas, HERO) < SCREEN_WIDTH - CHAR_WIDTH)){
			    if((xchar)/32 < 133){
			      if((map_boolean[(xchar+7)/32+1][ychar/32]==0) && (map_boolean[(xchar+7)/32+1][ychar/32+1]==0)){
				setPictureX(getPicture(atlas, HERO), getPictureX(atlas, HERO) + 4 * *sprint);
				if (*dir < 20){
				  *dir += (1 * *sprint);
				}else{
				  *dir = 0;
				}
			      }
			    }else{
			      if((map_boolean[(xchar+7)/32][ychar/32]==0) && (map_boolean[(xchar+7)/32][ychar/32+1]==0) && (xchar < 4281)){
				setPictureX(getPicture(atlas, HERO), getPictureX(atlas, HERO) + 4 * *sprint);
				if (*dir < 20){
				  *dir += (1 * *sprint);
				}else{
				  *dir = 0;
				}
			      }
			    }
			  }
		    break;
		    case SDLK_q:
			  *width = 1;
			  *bool_pannel_start = 0;
			  *bool_pannel = 0;
			  *bool_pannel_cave = 0;
			  if (*xscroll > 0){
			      if((getPictureX(atlas, HERO) > 720) && (map_boolean[(xchar-7)/32][ychar/32]==0) && (map_boolean[(xchar-7)/32][ychar/32+1]==0)) {
				  setPictureX(getPicture(atlas, HERO), getPictureX(atlas, HERO) - 4 * *sprint);
				  if (*dir < 20){
					      *dir += (1 * *sprint);
				  }else{
					      *dir = 0;
				  }
			      }else if ((map_boolean[(xchar-7)/32][ychar/32]==0) && (map_boolean[(xchar-7)/32][ychar/32+1]==0)){
				  *xscroll -= 8 * *sprint;
					setPictureX(getPicture(atlas, WATERFALL), getPictureX(atlas, WATERFALL) + 8 * *sprint);
					setPictureX(getPicture(atlas, OLD_MAN), getPictureX(atlas, OLD_MAN) + 8 * *sprint);
					setPictureX(getPicture(atlas, OLD_WOMAN), getPictureX(atlas, OLD_WOMAN) + 8 * *sprint);
					setPictureX(getPicture(atlas, INNKEEPER), getPictureX(atlas, INNKEEPER) + 8 * *sprint);
					setPictureX(getPicture(atlas, COUNTRY_GUARD), getPictureX(atlas, COUNTRY_GUARD) + 8 * *sprint);
					setPictureX(getPicture(atlas, KIDM), getPictureX(atlas, KIDM) + 8 * *sprint);
					setPictureX(getPicture(atlas, KIDF), getPictureX(atlas, KIDF) + 8 * *sprint);
					setPictureX(getPicture(atlas, WOOD_HUNTER), getPictureX(atlas, WOOD_HUNTER) + 8 * *sprint);
					setPictureX(getPicture(atlas, VILLAGER), getPictureX(atlas, VILLAGER) + 8 * *sprint);
					setPictureX(getPicture(atlas, FISH_HUNTER), getPictureX(atlas, FISH_HUNTER) + 8 * *sprint);
				  if (*dir < 20){
					      *dir += (1 * *sprint);
				  }else{
					      *dir = 0;
				  }
				  if (*sprint == 2 && *staminaLength > 1){
					      *staminaLength -= (1 * *sprint);
				  }else if (*staminaLength <= 2){
					      *sprint = 1;
				  }
			      }
			  }else if ((map_boolean[(xchar-7)/32][ychar/32]==0) && (map_boolean[(xchar-7)/32][ychar/32+1]==0)){
			      setPictureX(getPicture(atlas, HERO), getPictureX(atlas, HERO) - 4 * *sprint);
			      if (*dir < 20){
				  *dir += (1 * *sprint);
			      }else{
				  *dir = 0;
			      }
			  }
		    break;
		    case SDLK_ESCAPE:
			  *gameOver = 1;
		    break;
	      }
	break;

	      case SDL_KEYUP:
		switch(event.key.keysym.sym){
		    case SDLK_LSHIFT:
			*sprint = 1;
			break;
		    case SDLK_z:
			      *dir = 8;
			break;
		    case SDLK_s:
			      *dir = 8;
			break;
		    case SDLK_d:
			      *dir = 8;
			break;
		    case SDLK_q:
			      *dir = 8;
			break;
	    }
	    break;
      }
}
