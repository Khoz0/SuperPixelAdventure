#include "keyboardEvent.h"
#include "variables.h"
#include "game.h"

void keyboardEvent(SDL_Event event, Game* game){

  switch(event.type){
	  case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
			  case SDLK_LSHIFT:
        setVariable(getGameVariables(game), SPRINT, 5);
				  break;

			  case SDLK_e:
				  pressE(game);
			    break;

				case SDLK_z:
				  pressZ(game);
				  break;

				case SDLK_s:
				  pressS(game);
				  break;

				case SDLK_d:
				  pressD(game);
				  break;

				case SDLK_q:
				  pressQ(game);
				  break;

				case SDLK_ESCAPE:
        setVariable(getGameVariables(game), GAMEOVER, 1);
				  break;

				default:
					break;
		  }
			break;
    case SDL_KEYUP:
			switch(event.key.keysym.sym){
				case SDLK_LSHIFT:
        setVariable(getGameVariables(game), SPRINT, 1);
					break;
			  case SDLK_z:
				  setVariable(getGameVariables(game), DIR, 8);
				 	break;
				case SDLK_s:
				  setVariable(getGameVariables(game), DIR, 8);
				  break;
				case SDLK_d:
				  setVariable(getGameVariables(game), DIR, 8);
				  break;
				case SDLK_q:
				  setVariable(getGameVariables(game), DIR, 8);
				  break;
				default:
					break;
			}
			default:
			  break;
  }
}

void pressE(Game* game) {

	if(!getBoolean(getGameVariables(game), BOOL_PANNEL_START)){
		printf("ACTION : LECTURE PANNEAU\n");
		setBoolean(getGameVariables(game), BOOL_PANNEL_START, TRUE);
		if((getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-5)/32]==2) || (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)-5)/32]==2)) {
			setBoolean(getGameVariables(game), BOOL_PANNEL_START, TRUE);
		}
		if((getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-5)/32]==4) || (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)-5)/32]==4)) {
			setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, TRUE);
		}
		setBoolean(getGameVariables(game), BOOL_PANNEL, TRUE);
	}

}

void pressZ(Game* game) {

	setVariable(getGameVariables(game), WIDTH, 3);
	setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
	if(getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-15)/32]==3 && getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)-15)/32]==3){
		setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
	}
	if (getVariable(getGameVariables(game), YSCROLL) > 0){
		if((getPictureY(getGameAtlas(game), HERO) > 448) && (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-1)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)-1)/32]==0)) {
			setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
		}else if((getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-7)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)-1)/32]==0)){
			setVariable(getGameVariables(game), YSCROLL, (getVariable(getGameVariables(game), YSCROLL) - 8 * getVariable(getGameVariables(game), SPRINT)));
			setPictureY(getPicture(getGameAtlas(game), WATERFALL), getPictureY(getGameAtlas(game), WATERFALL) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), OLD_MAN), getPictureY(getGameAtlas(game), OLD_MAN) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureY(getGameAtlas(game), OLD_WOMAN) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), INNKEEPER), getPictureY(getGameAtlas(game), INNKEEPER) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureY(getGameAtlas(game), COUNTRY_GUARD) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), KIDM), getPictureY(getGameAtlas(game), KIDM) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), KIDF), getPictureY(getGameAtlas(game), KIDF) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureY(getGameAtlas(game), WOOD_HUNTER) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), VILLAGER), getPictureY(getGameAtlas(game), VILLAGER) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureY(getGameAtlas(game), FISH_HUNTER) + 8 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
			if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
				setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
			}else if (getStaminaLength(getGameAtlas(game)) <= 2){
				setVariable(getGameVariables(game), SPRINT, 1);
			}
		}
	}else if((getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-1)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)-1)/32]==0)){
		setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
		if (getVariable(getGameVariables(game), DIR) < 20){
			setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
		}else{
			setVariable(getGameVariables(game), DIR, 0);
		}
		if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
			setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
		}else if (getStaminaLength(getGameAtlas(game)) <= 2){
			setVariable(getGameVariables(game), SPRINT, 1);
		}
	}

}

void pressS(Game* game) {
	setVariable(getGameVariables(game), WIDTH, 0);
	setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
	if(getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-20)/32+2]==5 && getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)-20)/32+2]==5){
		setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
	}
	if (getVariable(getGameVariables(game), YSCROLL) < MAP_PIXELS_Y - SCREEN_HEIGHT){
		if((getPictureY(getGameAtlas(game), HERO) < 448) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+8)/32][(getVariable(getGameVariables(game), YCHAR)+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)+8)/32]==0)) {
			setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
		}else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR))/32][(getVariable(getGameVariables(game), YCHAR)+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)+8)/32+1]==0)){
			setVariable(getGameVariables(game), YSCROLL, getVariable(getGameVariables(game), YSCROLL) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), WATERFALL), getPictureY(getGameAtlas(game), WATERFALL) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), OLD_MAN), getPictureY(getGameAtlas(game), OLD_MAN) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureY(getGameAtlas(game), OLD_WOMAN) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), INNKEEPER), getPictureY(getGameAtlas(game), INNKEEPER) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureY(getGameAtlas(game), COUNTRY_GUARD) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), KIDM), getPictureY(getGameAtlas(game), KIDM) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), KIDF), getPictureY(getGameAtlas(game), KIDF) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureY(getGameAtlas(game), WOOD_HUNTER) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), VILLAGER), getPictureY(getGameAtlas(game), VILLAGER) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureY(getGameAtlas(game), FISH_HUNTER) - 8 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
			if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
				setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
			}else if (getStaminaLength(getGameAtlas(game)) <= 2){
				setVariable(getGameVariables(game), SPRINT, 1);
			}
		}
	}else if((getVariable(getGameVariables(game), YSCROLL) < MAP_PIXELS_Y) && (getPictureY(getGameAtlas(game), HERO) < SCREEN_HEIGHT - CHAR_HEIGHT)){
		if(getVariable(getGameVariables(game), XCHAR)/32 < 133){
			if((getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+8)/32][(getVariable(getGameVariables(game), YCHAR)+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32+1][(getVariable(getGameVariables(game), YCHAR)+8)/32+1]==0)){
				setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
				if (getVariable(getGameVariables(game), DIR) < 20){
					setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
				}else{
					setVariable(getGameVariables(game), DIR, 0);
				}
			}
		}else{
			if((getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+8)/32][(getVariable(getGameVariables(game), YCHAR)+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)+8)/32+1]==0)){
				setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
				if (getVariable(getGameVariables(game), DIR) < 20){
					setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
				}else{
					setVariable(getGameVariables(game), DIR, 0);
				}
			}
		}
	}
}

void pressD(Game* game) {
	setVariable(getGameVariables(game), WIDTH, 2);
	setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
	if (getVariable(getGameVariables(game), XSCROLL) < MAP_PIXELS_X - SCREEN_WIDTH){
		if((getPictureX(getGameAtlas(game), HERO) < 720) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+7)/32+1][getVariable(getGameVariables(game), YCHAR)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+7)/32+1][getVariable(getGameVariables(game), YCHAR)/32+1]==0)) {
			setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
		}else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+7)/32+1][getVariable(getGameVariables(game), YCHAR)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+7)/32+1][getVariable(getGameVariables(game), YCHAR)/32+1]==0)){
			setVariable(getGameVariables(game), XSCROLL, getVariable(getGameVariables(game), XSCROLL) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), WATERFALL), getPictureX(getGameAtlas(game), WATERFALL) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), OLD_MAN), getPictureX(getGameAtlas(game), OLD_MAN) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureX(getGameAtlas(game), OLD_WOMAN) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), INNKEEPER), getPictureX(getGameAtlas(game), INNKEEPER) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureX(getGameAtlas(game), COUNTRY_GUARD) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), KIDM), getPictureX(getGameAtlas(game), KIDM) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), KIDF), getPictureX(getGameAtlas(game), KIDF) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureX(getGameAtlas(game), WOOD_HUNTER) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), VILLAGER), getPictureX(getGameAtlas(game), VILLAGER) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureX(getGameAtlas(game), FISH_HUNTER) - 8 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
			if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
				setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
			}else if (getStaminaLength(getGameAtlas(game)) <= 2){
				setVariable(getGameVariables(game), SPRINT, 1);
			}
		}
	}else if((getVariable(getGameVariables(game), XSCROLL) < MAP_PIXELS_X) && (getPictureX(getGameAtlas(game), HERO) < SCREEN_WIDTH - CHAR_WIDTH)){
		if((getVariable(getGameVariables(game), XCHAR))/32 < 133){
			if((getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+7)/32+1][getVariable(getGameVariables(game), YCHAR)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+7)/32+1][getVariable(getGameVariables(game), YCHAR)/32+1]==0)){
				setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
				if (getVariable(getGameVariables(game), DIR) < 20){
					setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
				}else{
					setVariable(getGameVariables(game), DIR, 0);
				}
			}
		}else{
			if((getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+7)/32][getVariable(getGameVariables(game), YCHAR)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)+7)/32][getVariable(getGameVariables(game), YCHAR)/32+1]==0) && (getVariable(getGameVariables(game), XCHAR) < 4281)){
				setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
				if (getVariable(getGameVariables(game), DIR) < 20){
					setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
				}else{
					setVariable(getGameVariables(game), DIR, 0);
				}
			}
		}
	}
}

void pressQ(Game* game) {
	setVariable(getGameVariables(game), WIDTH, 1);
	setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
	if (getVariable(getGameVariables(game), XSCROLL) > 0){
		if((getPictureX(getGameAtlas(game), HERO) > 720) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)-7)/32][getVariable(getGameVariables(game), YCHAR)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)-7)/32][getVariable(getGameVariables(game), YCHAR)/32+1]==0)) {
			setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
		}else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)-7)/32][getVariable(getGameVariables(game), YCHAR)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)-7)/32][getVariable(getGameVariables(game), YCHAR)/32+1]==0)){
			setVariable(getGameVariables(game), XSCROLL, (getVariable(getGameVariables(game), XSCROLL) - 8 * getVariable(getGameVariables(game), SPRINT)));
			setPictureX(getPicture(getGameAtlas(game), WATERFALL), getPictureX(getGameAtlas(game), WATERFALL) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), OLD_MAN), getPictureX(getGameAtlas(game), OLD_MAN) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureX(getGameAtlas(game), OLD_WOMAN) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), INNKEEPER), getPictureX(getGameAtlas(game), INNKEEPER) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureX(getGameAtlas(game), COUNTRY_GUARD) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), KIDM), getPictureX(getGameAtlas(game), KIDM) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), KIDF), getPictureX(getGameAtlas(game), KIDF) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureX(getGameAtlas(game), WOOD_HUNTER) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), VILLAGER), getPictureX(getGameAtlas(game), VILLAGER) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureX(getGameAtlas(game), FISH_HUNTER) + 8 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
        setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
			if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
				setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
			}else if (getStaminaLength(getGameAtlas(game)) <= 2){
				setVariable(getGameVariables(game), SPRINT, 1);
			}
		}
	}else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)-7)/32][getVariable(getGameVariables(game), YCHAR)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(getVariable(getGameVariables(game), XCHAR)-7)/32][getVariable(getGameVariables(game), YCHAR)/32+1]==0)){
		setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
		if (getVariable(getGameVariables(game), DIR) < 20){
			setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + 1 * getVariable(getGameVariables(game), SPRINT));
		}else{
			setVariable(getGameVariables(game), DIR, 0);
		}
	}
}
