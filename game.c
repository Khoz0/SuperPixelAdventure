#include "game.h"
#include "variables.h"
#include "createSDL.h"

/**************************************************************************
this function execute all events of the game (musics, quests, displays ...)
**************************************************************************/

Game* createGame(){

  printf("-> Loading game\n");

  Game* game = malloc(sizeof(Game));

  game->atlas = createAtlas();
  game->variables = createVariables();
  game->sdl = createSDL(getGameAtlas(game));
  game->text = createText();
  game->tables = createTables();
  game->audio = createAudio();
  game->error = createError();

  initDstPosition(game);
  createBars(getGameAtlas(game), getScreen(getGameSdl(game)));
  threatErrors(game);

  return game;

}

void runGame(Game* game) {

    SDL_Event event;
    //mainMenu(&gameOver);

    while (!getVariable(getGameVariables(game), GAMEOVER)) {

      updateHeroPos(game);
      // we resume the main channel if it had been paused
      //if(!Mix_Playing(1)) Mix_Resume(0);
      SDL_PollEvent(&event);
      keyboardEvent(event, game);
      teleports(game);
      display(game);

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

/* all the functions after this comment are used to set
or get in game struct, or to execute parts of th game*/

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
  // x: 2368 - 2880 = -512 --> -2880 x difference fen/map
  // y: 380 - 1790 = -1410 --> -1790 y difference fen/map
  setDstPosition(getGameAtlas(game), WATERFALL, -2208, -1728);
  setDstPosition(getGameAtlas(game), CHEST, -2306, -1122);
}

void teleports(Game* game) {
  /**********************************************
  this function is used when we enter in the cave
  **********************************************/
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
  updateAnimationChest(game);
  updateInsideCave(game);
  updateNegPos(game);
}

void updateNegPos(Game* game) {
  setPictureNegX(getPicture(getGameAtlas(game), WATERFALL), getPictureX(getGameAtlas(game), WATERFALL), NEG);
  setPictureNegY(getPicture(getGameAtlas(game), WATERFALL), getPictureY(getGameAtlas(game), WATERFALL), NEG);

  setPictureNegX(getPicture(getGameAtlas(game), CHEST), getPictureX(getGameAtlas(game), CHEST), NEG);
  setPictureNegY(getPicture(getGameAtlas(game), CHEST), getPictureY(getGameAtlas(game), CHEST), NEG);
}

void updateAnimationChest(Game* game){
  if (getBoolean(getGameVariables(game), BOOL_CHEST)){
    if (getVariable(getGameVariables(game), CPT) < 3){
      setSrcPosition(getGameAtlas(game), CHEST, 0, 32*getVariable(getGameVariables(game), CPT));
    }else{
      setSrcPosition(getGameAtlas(game), CHEST, 0, 32*getVariable(getGameVariables(game), CPT));
    }
    getPicture(getGameAtlas(game), CHEST)->src.h = 32;
    getPicture(getGameAtlas(game), CHEST)->src.w = 32;
  }
}

void updateHeroPos(Game* game) {
  setVariable(getGameVariables(game), XCHAR, getPicture(getGameAtlas(game), HERO)->dst.x + getVariable(getGameVariables(game), XSCROLL));
  setVariable(getGameVariables(game), YCHAR, getPicture(getGameAtlas(game), HERO)->dst.y + getVariable(getGameVariables(game), YSCROLL));
}

void updatePos(Game* game) {
  setSrcPosition(getGameAtlas(game), HERO, CHAR_WIDTH*(getVariable(getGameVariables(game), DIR)/7), CHAR_HEIGHT * getVariable(getGameVariables(game), WIDTH));
  setSrcPosition(getGameAtlas(game), WATERFALL, 32*getVariable(getGameVariables(game), ANIMATION), 0);
  getPicture(getGameAtlas(game), WATERFALL)->src.h = 192;
  getPicture(getGameAtlas(game), WATERFALL)->src.w = 64;
}

void updateInsideCave(Game* game) {
  if (getBoolean(getGameVariables(game), BOOL_TP_CAVE)) {
    setBoolean(getGameVariables(game), BOOL_FOG, TRUE);
    // we store the positions of each object blitted
    setVariable(getGameVariables(game), PREC_XSCROLL, getVariable(getGameVariables(game), XSCROLL));
    setVariable(getGameVariables(game), PREC_YSCROLL, getVariable(getGameVariables(game), YSCROLL));
    setVariable(getGameVariables(game), PREC_POSCHAR_X, getPictureX(getGameAtlas(game), HERO));
    setVariable(getGameVariables(game), PREC_POSCHAR_Y, getPictureY(getGameAtlas(game), HERO));
    setVariable(getGameVariables(game), PREC_POSWATERFALL_X, getPictureX(getGameAtlas(game), WATERFALL));
    setVariable(getGameVariables(game), PREC_POSWATERFALL_Y, getPictureY(getGameAtlas(game), WATERFALL));
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
    setVariable(getGameVariables(game), XSCROLL, getVariable(getGameVariables(game), PREC_XSCROLL));
    setVariable(getGameVariables(game), YSCROLL, getVariable(getGameVariables(game), PREC_YSCROLL));
    setDstPosition(getGameAtlas(game), HERO, getVariable(getGameVariables(game), PREC_POSCHAR_X), getVariable(getGameVariables(game), PREC_POSCHAR_Y) + 20);
    setDstPosition(getGameAtlas(game), WATERFALL, getVariable(getGameVariables(game), PREC_POSWATERFALL_X), getVariable(getGameVariables(game), PREC_POSWATERFALL_Y));
    setBoolean(getGameVariables(game), BOOL_TP_CAVE, FALSE);
    setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, FALSE);
    setBoolean(getGameVariables(game), BOOL_WATERFALL, TRUE);
  }

  if (getStaminaLength(getGameAtlas(game)) > -2 && getStaminaLength(getGameAtlas(game))  <= 194 && getVariable(getGameVariables(game), SPRINT) == 1){
    setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) + (2 * getVariable(getGameVariables(game), SPRINT)));
  }

  if (getTable(getGameTables(game), MAP_BUILDER)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR))/32 + 1]==3){
    if (getVariable(getGameVariables(game), CPT)%3 == 0){
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

  updatePos(game);
  setVariable(getGameVariables(game), CPT, getVariable(getGameVariables(game), CPT) + 1);

  if (getVariable(getGameVariables(game), CPT) % 3 == 0){
    if (getVariable(getGameVariables(game), ANIMATION)){
      setVariable(getGameVariables(game), ANIMATION, 0);
    }else{
      setVariable(getGameVariables(game), ANIMATION, 1);
    }
  }
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
