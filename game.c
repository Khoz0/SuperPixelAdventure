#include "game.h"
#include "variables.h"
#include "createSDL.h"

Game* createGame(){

  Game* game = malloc(sizeof(Game));

  game->atlas = createAtlas();
  game->variables = createVariables();
  game->sdl = createSDL(getGameAtlas(game));
  game->text = createText();
  game->tables = createTables();
  game->audio = createAudio();

  initDstPosition(game);
  updateBar(getGameAtlas(game), getScreen(getGameSdl(game)));

  return game;

}

void runGame(Game* game) {

    int cpt = 0, animation = 0;
    SDL_Event event;

    int prec_xscroll, prec_yscroll, poschar_prec_x, poschar_prec_y, poswater_prec_x, poswater_prec_y;

    //mainMenu(&gameOver);

    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
        for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
            printf("%d", getTable(getGameTables(game), MAP_BOOLEAN)[j][i]);
        }
        printf("\n");
    }

    while (!getVariable(getGameVariables(game), GAMEOVER)) {

      setVariable(getGameVariables(game), XCHAR, getPicture(getGameAtlas(game), HERO)->dst.x + getVariable(getGameVariables(game), XSCROLL));
      setVariable(getGameVariables(game), YCHAR, getPicture(getGameAtlas(game), HERO)->dst.y + getVariable(getGameVariables(game), YSCROLL));

      // we resume the main channel if it had been paused
      //if(!Mix_Playing(1)) Mix_Resume(0);

      SDL_PollEvent(&event);
      keyboardEvent(event, game);

      if(getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-15)/32 + 1]==3) {
        setBoolean(getGameVariables(game), BOOL_TP_CAVE, TRUE);
        setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, FALSE);
        updateTables(getGameTables(game), MAP_CAVE);
      }

      if(getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR) - 10)/32 + 1] == 5) {
        setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, TRUE);
        setBoolean(getGameVariables(game), BOOL_TP_CAVE, FALSE);
        updateTables(getGameTables(game), MAP_WATER);
      }

      if (getBoolean(getGameVariables(game), BOOL_TP_CAVE)) {
        setBoolean(getGameVariables(game), BOOL_FOG, TRUE);

        // we store the positions of each object blitted
        prec_xscroll = getVariable(getGameVariables(game), XSCROLL);
        prec_yscroll = getVariable(getGameVariables(game), YSCROLL);
        poschar_prec_x = getPictureX(getGameAtlas(game), HERO);
        poschar_prec_y = getPictureY(getGameAtlas(game), HERO);
        poswater_prec_x = getPictureX(getGameAtlas(game), WATERFALL);
        poswater_prec_y = getPictureY(getGameAtlas(game), WATERFALL);
        setVariable(getGameVariables(game), XSCROLL, (MAP_PIXELS_X/2) - (SCREEN_WIDTH/1.26));
        setVariable(getGameVariables(game), YSCROLL, (MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/4.9));
        setDstPosition(getGameAtlas(game), HERO, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        setBoolean(getGameVariables(game), BOOL_TP_CAVE, FALSE);
        setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, FALSE);
        setBoolean(getGameVariables(game), BOOL_WATERFALL, FALSE);
      }
      if (getBoolean(getGameVariables(game), BOOL_TP_OUTSIDE)) {
        setBoolean(getGameVariables(game), BOOL_FOG, FALSE);

        // we load the previous position of each object blitted
        setVariable(getGameVariables(game), XSCROLL, prec_xscroll);
        setVariable(getGameVariables(game), YSCROLL, prec_yscroll);
        setDstPosition(getGameAtlas(game), HERO, poschar_prec_x, poschar_prec_y+20);
        setDstPosition(getGameAtlas(game), WATERFALL, poswater_prec_x, poswater_prec_y);
        setBoolean(getGameVariables(game), BOOL_TP_CAVE, FALSE);
        setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, FALSE);
        setBoolean(getGameVariables(game), BOOL_WATERFALL, TRUE);
      }

      if (getStaminaLength(getGameAtlas(game)) > -2 && getStaminaLength(getGameAtlas(game))  <= 194 && getVariable(getGameVariables(game), SPRINT) == 1){
        setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) + (2 * getVariable(getGameVariables(game), SPRINT)));
      }

      if (getTable(getGameTables(game), MAP_BUILDER)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR))/32 + 1]==3){
        if (cpt%3 == 0){
          setLifePointLength(getGameAtlas(game), getLifePointLength(getGameAtlas(game)) - 1);
        }
      }

      if (getTable(getGameTables(game), MAP_BUILDER)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR))/32 + 1]==118 &&
          getLifePointLength(getGameAtlas(game)) < 195){
        setLifePointLength(getGameAtlas(game), getLifePointLength(getGameAtlas(game)) + 1);
      }

      if (getLifePointLength(getGameAtlas(game)) <= -1){
        printf("\n\n               LOSER !!\n\n");
        setVariable(getGameVariables(game), GAMEOVER, 1);
      }

      setSrcPosition(getGameAtlas(game), HERO, CHAR_WIDTH*(getVariable(getGameVariables(game), DIR)/7), CHAR_HEIGHT * getVariable(getGameVariables(game), WIDTH));
      setSrcPosition(getGameAtlas(game), WATERFALL, 32*animation, 0);

      getPicture(getGameAtlas(game), WATERFALL)->src.h = 192;
      getPicture(getGameAtlas(game), WATERFALL)->src.w = 64;

      cpt += 1;

      if (cpt % 3 == 0){
        if (animation){
          animation = 0;
        }else{
          animation = 1;
        }
      }

      setPictureNegX(getPicture(getGameAtlas(game), WATERFALL), getPictureX(getGameAtlas(game), WATERFALL), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), WATERFALL), getPictureY(getGameAtlas(game), WATERFALL), NEG);

      display(game);

      if (getBoolean(getGameVariables(game), BOOL_WATERFALL)){
        SDL_BlitSurface(getPicture(getGameAtlas(game), WATERFALL)->surface, &getPicture(getGameAtlas(game), WATERFALL)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), WATERFALL)->neg);
      }

      if(getBoolean(getGameVariables(game), BOOL_FOG))  SDL_BlitSurface(getPicture(getGameAtlas(game), FOG)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), FOG)->dst);
      if(getBoolean(getGameVariables(game), BOOL_PANNEL)) SDL_BlitSurface(getPicture(getGameAtlas(game), PANNEL)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PANNEL)->dst);
      if(getBoolean(getGameVariables(game), BOOL_PANNEL_START)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_START), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
      if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
      if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_ONE)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_ONE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
      if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_TWO)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_TWO), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
      if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_THREE)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_THREE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
      if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_FOUR)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_FOUR), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));

      SDL_FreeSurface(getStamina(getGameAtlas(game)));
      SDL_FreeSurface(getLifePoint(getGameAtlas(game)));
      updateBar(getGameAtlas(game), getScreen(getGameSdl(game)));

      SDL_BlitSurface(getStamina(getGameAtlas(game)), NULL, getScreen(getGameSdl(game)), getStaminaDst(getGameAtlas(game)));
      SDL_BlitSurface(getLifePoint(getGameAtlas(game)), NULL, getScreen(getGameSdl(game)), getLifePointDst(getGameAtlas(game)));

      SDL_UpdateRect(getScreen(getGameSdl(game)), 0, 0, 0, 0);
      SDL_Flip(getScreen(getGameSdl(game)));

    }
}

void destroyGame(Game* game) {
  destroyAtlas(getGameAtlas(game));
  destroyTables(getGameTables(game));
  destroyVariables(getGameVariables(game));
  destroyText(getGameText(game));
  destroyAudio(getGameAudio(game));
  destroySDL(getGameSdl(game));
  free(game);
  game = NULL;
}

Atlas* getGameAtlas(Game* game) {
  return game->atlas;
}

Variables* getGameVariables(Game* game) {
  return game->variables;
}

SDL* getGameSdl(Game* game) {
  return game->sdl;
}

Text* getGameText(Game* game) {
  return game->text;
}

Tables* getGameTables(Game* game) {
  return game->tables;
}

Audio* getGameAudio(Game* game) {
  return game->audio;
}

void initDstPosition(Game* game) {
  setDstPosition(getGameAtlas(game), HERO, SCREEN_WIDTH/1.1, SCREEN_HEIGHT/1.4);
  setDstPosition(getGameAtlas(game), CHAT_BOX, (SCREEN_WIDTH - PANNEL_WIDTH)/2, (SCREEN_HEIGHT - PANNEL_HEIGHT)/2);
  setDstPosition(getGameAtlas(game), PANNEL, (SCREEN_WIDTH - PANNEL_WIDTH)/2, (SCREEN_HEIGHT - PANNEL_HEIGHT)/2);
  // x: 2368 - 2880 = -512 --> -2880 différence fen/map en x
  // y: 380 - 1790 = -1410 --> -1790 différence fen/map en y
  setDstPosition(getGameAtlas(game), WATERFALL, -2208, -1728);
}

void capFps() {
  int actualTime = 0, lastTimes = 0;
  float dt;

  actualTime = SDL_GetTicks();
  dt = (actualTime - lastTimes);
  if(dt < 1000.0 / FPS_CAP){
    SDL_Delay((1000.0 / FPS_CAP) - dt); //On limite les images par secondes en faisant des pauses entre chaque image
  }
  lastTimes = SDL_GetTicks();
}
