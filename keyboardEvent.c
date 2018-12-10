#include "keyboardEvent.h"
#include "variables.h"
#include "game.h"

void keyboardEvent(SDL_Event event, int *sprint, int xchar, int ychar,
	 								 int *width, int *dir, int *gameOver, Game* game){

  switch(event.type){
	  case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
			  case SDLK_LSHIFT:
				  *sprint = 5;
				  break;

			  case SDLK_e:
				  if(!getBoolean(getGameVariables(game), BOOL_PANNEL_START)){
				    printf("ACTION : LECTURE PANNEAU\n");
				    setBoolean(getGameVariables(game), BOOL_PANNEL_START, TRUE);
				    if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==2) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==2)) {
							setBoolean(getGameVariables(game), BOOL_PANNEL_START, TRUE);
						}
				    if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==4) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==4)) {
							setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, TRUE);
						}
				    setBoolean(getGameVariables(game), BOOL_PANNEL, TRUE);
				  }
			    break;

				case SDLK_z:
				  *width = 3;
				  setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
				  setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
				  setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
				  if(getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-15)/32]==3 && getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-15)/32]==3){
					  setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * *sprint);
				  }
				  if (getVariable(getGameVariables(game), YSCROLL) > 0){
					  if((getPictureY(getGameAtlas(game), HERO) > 448) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-1)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-1)/32]==0)) {
						  setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * *sprint);
					    if (*dir < 20){
							  *dir += (1 * *sprint);
					    }else{
							  *dir = 0;
					    }
					  }else if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-7)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-1)/32]==0)){
							setVariable(getGameVariables(game), YSCROLL, (getVariable(getGameVariables(game), YSCROLL) - 8 * *sprint));
							setPictureY(getPicture(getGameAtlas(game), WATERFALL), getPictureY(getGameAtlas(game), WATERFALL) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), OLD_MAN), getPictureY(getGameAtlas(game), OLD_MAN) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureY(getGameAtlas(game), OLD_WOMAN) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), INNKEEPER), getPictureY(getGameAtlas(game), INNKEEPER) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureY(getGameAtlas(game), COUNTRY_GUARD) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), KIDM), getPictureY(getGameAtlas(game), KIDM) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), KIDF), getPictureY(getGameAtlas(game), KIDF) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureY(getGameAtlas(game), WOOD_HUNTER) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), VILLAGER), getPictureY(getGameAtlas(game), VILLAGER) + 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureY(getGameAtlas(game), FISH_HUNTER) + 8 * *sprint);
					    if (*dir < 20){
						    *dir += (1 * *sprint);
					    }else{
						    *dir = 0;
					    }
					    if (*sprint == 2 && getStaminaLength(getGameAtlas(game)) > 1){
						  	setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * *sprint));
					    }else if (getStaminaLength(getGameAtlas(game)) <= 2){
						    *sprint = 1;
					    }
					  }
				  }else if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-1)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-1)/32]==0)){
					  setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * *sprint);
					  if (*dir < 20){
					    *dir += (1 * *sprint);
					  }else{
					    *dir = 0;
					  }
					  if (*sprint == 2 && getStaminaLength(getGameAtlas(game)) > 1){
					    setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * *sprint));
					  }else if (getStaminaLength(getGameAtlas(game)) <= 2){
					    *sprint = 1;
					  }
				  }
				  break;
				case SDLK_s:
				  *width = 0;
				  setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
				  setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
				  setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
					if(getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-10)/32+3]==5 && getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-10)/32+3]==5){
						setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * *sprint);
					}
				  if (getVariable(getGameVariables(game), YSCROLL) < MAP_PIXELS_Y - SCREEN_HEIGHT){
				    if((getPictureY(getGameAtlas(game), HERO) < 448) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+8)/32][(ychar+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar+8)/32]==0)) {
						  setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * *sprint);
					    if (*dir < 20){
						    *dir += (1 * *sprint);
					    }else{
						    *dir = 0;
					    }
				    }else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+8)/32][(ychar+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar+8)/32+1]==0)){
							setVariable(getGameVariables(game), YSCROLL, getVariable(getGameVariables(game), YSCROLL) + 8 * *sprint);
						  setPictureY(getPicture(getGameAtlas(game), WATERFALL), getPictureY(getGameAtlas(game), WATERFALL) - 8 * *sprint);
						  setPictureY(getPicture(getGameAtlas(game), OLD_MAN), getPictureY(getGameAtlas(game), OLD_MAN) - 8 * *sprint);
  						setPictureY(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureY(getGameAtlas(game), OLD_WOMAN) - 8 * *sprint);
	  					setPictureY(getPicture(getGameAtlas(game), INNKEEPER), getPictureY(getGameAtlas(game), INNKEEPER) - 8 * *sprint);
		  				setPictureY(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureY(getGameAtlas(game), COUNTRY_GUARD) - 8 * *sprint);
			  			setPictureY(getPicture(getGameAtlas(game), KIDM), getPictureY(getGameAtlas(game), KIDM) - 8 * *sprint);
							setPictureY(getPicture(getGameAtlas(game), KIDF), getPictureY(getGameAtlas(game), KIDF) - 8 * *sprint);
				  		setPictureY(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureY(getGameAtlas(game), WOOD_HUNTER) - 8 * *sprint);
					  	setPictureY(getPicture(getGameAtlas(game), VILLAGER), getPictureY(getGameAtlas(game), VILLAGER) - 8 * *sprint);
						  setPictureY(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureY(getGameAtlas(game), FISH_HUNTER) - 8 * *sprint);
					    if (*dir < 20){
						    *dir += (1 * *sprint);
					    }else{
						    *dir = 0;
					    }
					    if (*sprint == 2 && getStaminaLength(getGameAtlas(game)) > 1){
						    setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * *sprint));
					    }else if (getStaminaLength(getGameAtlas(game)) <= 2){
						    *sprint = 1;
					    }
				    }
				  }else if((getVariable(getGameVariables(game), YSCROLL) < MAP_PIXELS_Y) && (getPictureY(getGameAtlas(game), HERO) < SCREEN_HEIGHT - CHAR_HEIGHT)){
				    if(xchar/32 < 133){
				      if((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+8)/32][(ychar+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar+8)/32+1]==0)){
					      setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * *sprint);
					      if (*dir < 20){
					        *dir += (1 * *sprint);
					      }else{
					        *dir = 0;
					      }
				      }
				    }else{
				      if((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+8)/32][(ychar+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar+8)/32+1]==0)){
					      setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * *sprint);
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
				  setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
				  setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
				  setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
				  if (getVariable(getGameVariables(game), XSCROLL) < MAP_PIXELS_X - SCREEN_WIDTH){
				    if((getPictureX(getGameAtlas(game), HERO) < 720) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32+1]==0)) {
						  setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * *sprint);
					    if (*dir < 20){
						    *dir += (1 * *sprint);
					    }else{
						    *dir = 0;
					    }
				    }else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32+1]==0)){
							setVariable(getGameVariables(game), XSCROLL, getVariable(getGameVariables(game), XSCROLL) + 8 * *sprint);
							//*xscroll += 8 * *sprint;
  						setPictureX(getPicture(getGameAtlas(game), WATERFALL), getPictureX(getGameAtlas(game), WATERFALL) - 8 * *sprint);
	  					setPictureX(getPicture(getGameAtlas(game), OLD_MAN), getPictureX(getGameAtlas(game), OLD_MAN) - 8 * *sprint);
		  				setPictureX(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureX(getGameAtlas(game), OLD_WOMAN) - 8 * *sprint);
			  			setPictureX(getPicture(getGameAtlas(game), INNKEEPER), getPictureX(getGameAtlas(game), INNKEEPER) - 8 * *sprint);
				 			setPictureX(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureX(getGameAtlas(game), COUNTRY_GUARD) - 8 * *sprint);
				  		setPictureX(getPicture(getGameAtlas(game), KIDM), getPictureX(getGameAtlas(game), KIDM) - 8 * *sprint);
					  	setPictureX(getPicture(getGameAtlas(game), KIDF), getPictureX(getGameAtlas(game), KIDF) - 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureX(getGameAtlas(game), WOOD_HUNTER) - 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), VILLAGER), getPictureX(getGameAtlas(game), VILLAGER) - 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureX(getGameAtlas(game), FISH_HUNTER) - 8 * *sprint);
						  if (*dir < 20){
						    *dir += (1 * *sprint);
					    }else{
						    *dir = 0;
					    }
					    if (*sprint == 2 && getStaminaLength(getGameAtlas(game)) > 1){
						    setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * *sprint));
					  	}else if (getStaminaLength(getGameAtlas(game)) <= 2){
						    *sprint = 1;
					  	}
				    }
				  }else if((getVariable(getGameVariables(game), XSCROLL) < MAP_PIXELS_X) && (getPictureX(getGameAtlas(game), HERO) < SCREEN_WIDTH - CHAR_WIDTH)){
				    if((xchar)/32 < 133){
				      if((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32+1]==0)){
								setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * *sprint);
								if (*dir < 20){
					  		  *dir += (1 * *sprint);
								}else{
					  		  *dir = 0;
					   		}
				      }
				    }else{
				      if((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32][ychar/32+1]==0) && (xchar < 4281)){
								setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * *sprint);
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
				  setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
				  setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
				  setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
				  if (getVariable(getGameVariables(game), XSCROLL) > 0){
				    if((getPictureX(getGameAtlas(game), HERO) > 720) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32+1]==0)) {
					    setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) - 4 * *sprint);
					    if (*dir < 20){
						    *dir += (1 * *sprint);
					    }else{
						    *dir = 0;
					    }
				    }else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32+1]==0)){
						  setVariable(getGameVariables(game), XSCROLL, (getVariable(getGameVariables(game), XSCROLL) - 8 * *sprint));
							setPictureX(getPicture(getGameAtlas(game), WATERFALL), getPictureX(getGameAtlas(game), WATERFALL) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), OLD_MAN), getPictureX(getGameAtlas(game), OLD_MAN) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureX(getGameAtlas(game), OLD_WOMAN) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), INNKEEPER), getPictureX(getGameAtlas(game), INNKEEPER) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureX(getGameAtlas(game), COUNTRY_GUARD) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), KIDM), getPictureX(getGameAtlas(game), KIDM) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), KIDF), getPictureX(getGameAtlas(game), KIDF) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureX(getGameAtlas(game), WOOD_HUNTER) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), VILLAGER), getPictureX(getGameAtlas(game), VILLAGER) + 8 * *sprint);
							setPictureX(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureX(getGameAtlas(game), FISH_HUNTER) + 8 * *sprint);
						  if (*dir < 20){
						    *dir += (1 * *sprint);
					    }else{
						    *dir = 0;
					    }
					    if (*sprint == 2 && getStaminaLength(getGameAtlas(game)) > 1){
						    setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * *sprint));
					    }else if (getStaminaLength(getGameAtlas(game)) <= 2){
						    *sprint = 1;
					    }
				    }
				  }else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32+1]==0)){
				    setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) - 4 * *sprint);
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

				default:
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
				default:
					break;
			}
			default:
			  break;
  }
}
