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

  return game;

}

void runGame(Game* game) {

    int cpt = 0, animation = 0, sprint = 1, width = 0, dir = 1, gameOver = 0;
    SDL_Event event;

    int xscroll = MAP_PIXELS_X - SCREEN_WIDTH;
    int yscroll = MAP_PIXELS_Y - SCREEN_HEIGHT;

    //mainMenu(&gameOver);

    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
        for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
            printf("%d", getTable(getGameTables(game), MAP_BOOLEAN)[j][i]);
        }
        printf("\n");
    }

    while (!gameOver) {

      setVariable(getGameVariables(game), XCHAR, getPicture(getGameAtlas(game), HERO)->dst.x + xscroll);
      setVariable(getGameVariables(game), YCHAR, getPicture(getGameAtlas(game), HERO)->dst.y + yscroll);

      //xchar = (getPicture(getGameAtlas(game), HERO)->dst.x + xscroll);
      //ychar = (getPicture(getGameAtlas(game), HERO)->dst.y + yscroll);

      // we resume the main channel if it had been paused
      //if(!Mix_Playing(1)) Mix_Resume(0);

      SDL_PollEvent(&event);
      keyboardEvent(event, &sprint, getVariable(getGameVariables(game), XCHAR), getVariable(getGameVariables(game), YCHAR), &width, &yscroll, &xscroll, &dir, &gameOver, game);

      if(getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR)-15)/32 + 1]==3) {
        setBoolean(getGameVariables(game), BOOL_TP_CAVE, TRUE);
        setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, FALSE);
        updateTables(getGameTables(game), MAP_NO_WATER);
      }

      if(getTable(getGameTables(game), MAP_BOOLEAN)[getVariable(getGameVariables(game), XCHAR)/32][(getVariable(getGameVariables(game), YCHAR) - 10)/32 + 2] == 5) {
        setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, TRUE);
        setBoolean(getGameVariables(game), BOOL_TP_CAVE, FALSE);
        updateTables(getGameTables(game), MAP_WATER);
      }

      if (getBoolean(getGameVariables(game), BOOL_TP_CAVE)) {
        setBoolean(getGameVariables(game), BOOL_FOG, TRUE);
        xscroll = ((MAP_PIXELS_X/2) - (SCREEN_WIDTH/1.26));
        //setVariable(getGameVariables(game), XSCROLL, (MAP_PIXELS_X/2) - (SCREEN_WIDTH/1.26));
        yscroll = ((MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/4.5));
        //setVariable(getGameVariables(game), YSCROLL, (MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/4.5));
        setDstPosition(getGameAtlas(game), HERO, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        setBoolean(getGameVariables(game), BOOL_TP_CAVE, FALSE);
        setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, FALSE);
        setBoolean(getGameVariables(game), BOOL_WATERFALL, FALSE);
      }
      if (getBoolean(getGameVariables(game), BOOL_TP_OUTSIDE)) {
        setBoolean(getGameVariables(game), BOOL_FOG, FALSE);
        xscroll = ((MAP_PIXELS_X/2) - (SCREEN_WIDTH/0.76));
        //setVariable(getGameVariables(game), XSCROLL, (MAP_PIXELS_X/2) - (SCREEN_WIDTH/0.76));
        yscroll = ((MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/0.555));
        //setVariable(getGameVariables(game), YSCROLL, (MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/0.555));
        setDstPosition(getGameAtlas(game), HERO, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        setBoolean(getGameVariables(game), BOOL_TP_CAVE, FALSE);
        setBoolean(getGameVariables(game), BOOL_TP_OUTSIDE, FALSE);
        setBoolean(getGameVariables(game), BOOL_WATERFALL, TRUE);
      }

      if (getStaminaLength(getGameAtlas(game)) > -2 && getStaminaLength(getGameAtlas(game))  <= 194 && sprint == 1){
        setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) + (2 * sprint));
      }

      setSrcPosition(getGameAtlas(game), HERO, CHAR_WIDTH*(dir/7), CHAR_HEIGHT * width);
      setSrcPosition(getGameAtlas(game), WATERFALL, 32*animation, 0);

      getPicture(getGameAtlas(game), WATERFALL)->src.h = 192;
      getPicture(getGameAtlas(game), WATERFALL)->src.w = 64;

      setSrcPosition(getGameAtlas(game), OLD_MAN, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);
      setSrcPosition(getGameAtlas(game), OLD_WOMAN, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);
      setSrcPosition(getGameAtlas(game), INNKEEPER, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);
      setSrcPosition(getGameAtlas(game), COUNTRY_GUARD, CHAR_WIDTH * 1, CHAR_HEIGHT * 3);
      setSrcPosition(getGameAtlas(game), KIDM, CHAR_WIDTH * 1, CHAR_HEIGHT * 2);
      setSrcPosition(getGameAtlas(game), KIDF, CHAR_WIDTH * 1, CHAR_HEIGHT * 1);
      setSrcPosition(getGameAtlas(game), WOOD_HUNTER, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);
      setSrcPosition(getGameAtlas(game), VILLAGER, CHAR_WIDTH * 1, CHAR_HEIGHT * 1);
      setSrcPosition(getGameAtlas(game), FISH_HUNTER, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);

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

      setPictureNegX(getPicture(getGameAtlas(game), OLD_MAN), getPictureX(getGameAtlas(game), OLD_MAN), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), OLD_MAN), getPictureY(getGameAtlas(game), OLD_MAN), NEG);

      setPictureNegX(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureX(getGameAtlas(game), OLD_WOMAN), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), OLD_WOMAN), getPictureY(getGameAtlas(game), OLD_WOMAN), NEG);

      setPictureNegX(getPicture(getGameAtlas(game), INNKEEPER), getPictureX(getGameAtlas(game), INNKEEPER), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), INNKEEPER), getPictureY(getGameAtlas(game), INNKEEPER), NEG);

      setPictureNegX(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureX(getGameAtlas(game), COUNTRY_GUARD), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), COUNTRY_GUARD), getPictureY(getGameAtlas(game), COUNTRY_GUARD), NEG);

      setPictureNegX(getPicture(getGameAtlas(game), KIDM), getPictureX(getGameAtlas(game), KIDM), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), KIDM), getPictureY(getGameAtlas(game), KIDM), NEG);

      setPictureNegX(getPicture(getGameAtlas(game), KIDF), getPictureX(getGameAtlas(game), KIDF), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), KIDF), getPictureY(getGameAtlas(game), KIDF), NEG);

      setPictureNegX(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureX(getGameAtlas(game), WOOD_HUNTER), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), WOOD_HUNTER), getPictureY(getGameAtlas(game), WOOD_HUNTER), NEG);

      setPictureNegX(getPicture(getGameAtlas(game), VILLAGER), getPictureX(getGameAtlas(game), VILLAGER), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), VILLAGER), getPictureY(getGameAtlas(game), VILLAGER), NEG);

      setPictureNegX(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureX(getGameAtlas(game), FISH_HUNTER), NEG);
      setPictureNegY(getPicture(getGameAtlas(game), FISH_HUNTER), getPictureY(getGameAtlas(game), FISH_HUNTER), NEG);

      display(game, xscroll, yscroll);

      if (getBoolean(getGameVariables(game), BOOL_WATERFALL)){
        SDL_BlitSurface(getPicture(getGameAtlas(game), WATERFALL)->surface, &getPicture(getGameAtlas(game), WATERFALL)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), WATERFALL)->neg);
      }

      if(getBoolean(getGameVariables(game), BOOL_PANNEL)) SDL_BlitSurface(getPicture(getGameAtlas(game), PANNEL)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PANNEL)->dst);
      if(getBoolean(getGameVariables(game), BOOL_PANNEL_START)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_START), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
      if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE)) SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
      if(getBoolean(getGameVariables(game), BOOL_FOG))  SDL_BlitSurface(getPicture(getGameAtlas(game), FOG)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), FOG)->dst);

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
  setDstPosition(getGameAtlas(game), OLD_MAN, -670, -1410);
  setDstPosition(getGameAtlas(game), OLD_WOMAN, -640, -1410);
  setDstPosition(getGameAtlas(game), INNKEEPER, -512, 138);
  setDstPosition(getGameAtlas(game), COUNTRY_GUARD, 1320, 700);
  setDstPosition(getGameAtlas(game), KIDM, -824, 2);
  setDstPosition(getGameAtlas(game), KIDF, -216, 238);
  setDstPosition(getGameAtlas(game), WOOD_HUNTER, 926, -1586);
  setDstPosition(getGameAtlas(game), VILLAGER, -1062, 255);
  setDstPosition(getGameAtlas(game), FISH_HUNTER, -1664, 625);
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
