#include "jeu.h"

void createGame() {

    Atlas* atlas = createAtlas();
    Variables* variables = createVariables();
    SDL* sdl = createSDL(atlas);
    Text* text = createText();
    Tables* tables = createTables();
    Audio* audio = createAudio();

    int cpt = 0, animation = 0;
    int sprint, width, dir, gameOver;
    sprint = 1;

    width = 0;
    dir = 1;
    gameOver = 0;
    int xchar, ychar, xscroll, yscroll;
    int actualTime = 0, lastTimes = 0;

    SDL_Event event;

    //mainMenu(&gameOver);

    setDstPosition(atlas, HERO, SCREEN_WIDTH/1.1, SCREEN_HEIGHT/1.4);
    setDstPosition(atlas, CHAT_BOX, (SCREEN_WIDTH - PANNEL_WIDTH)/2, (SCREEN_HEIGHT - PANNEL_HEIGHT)/2);
    setDstPosition(atlas, PANNEL, (SCREEN_WIDTH - PANNEL_WIDTH)/2, (SCREEN_HEIGHT - PANNEL_HEIGHT)/2);

    // x: 2368 - 2880 = -512 --> -2880 différence fen/map en x
    // y: 380 - 1790 = -1410 --> -1790 différence fen/map en y
    setDstPosition(atlas, WATERFALL, -2208, -1728);
    setDstPosition(atlas, OLD_MAN, -670, -1410);
    setDstPosition(atlas, OLD_WOMAN, -640, -1410);
    setDstPosition(atlas, INNKEEPER, -512, 138);
    setDstPosition(atlas, COUNTRY_GUARD, 1320, 700);
    setDstPosition(atlas, KIDM, -824, 2);
    setDstPosition(atlas, KIDF, -216, 238);
    setDstPosition(atlas, WOOD_HUNTER, 926, -1586);
    setDstPosition(atlas, VILLAGER, -1062, 255);
    setDstPosition(atlas, FISH_HUNTER, -1664, 625);

    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
        for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
            printf("%d", getTable(tables, MAP_BOOLEAN)[j][i]);
        }
        printf("\n");
    }

    xscroll = MAP_PIXELS_X - SCREEN_WIDTH;
    yscroll = MAP_PIXELS_Y - SCREEN_HEIGHT;

    while (!gameOver){

      //Compteur d'images par secondes
      actualTime = SDL_GetTicks();
      float dt = (actualTime - lastTimes);
      if(dt < 1000.0 / FPS_CAP){
        SDL_Delay((1000.0 / FPS_CAP) - dt); //On limite les images par secondes en faisant des pauses entre chaque image
      }
      lastTimes = SDL_GetTicks();
      //Compteur d'images par secondes

      xchar = getPicture(atlas, HERO)->dst.x + xscroll;
      ychar = getPicture(atlas, HERO)->dst.y + yscroll;

      // we resume the main channel if it had been paused
      //if(!Mix_Playing(1)) Mix_Resume(0);

      SDL_PollEvent(&event);
      keyboardEvent(event, &sprint, variables, tables, xchar, ychar, &width,
                    &yscroll, &xscroll, &dir, &gameOver, atlas);

      if(getTable(tables, MAP_BOOLEAN)[xchar/32][(ychar - 15)/32 + 1]==3){
        setBoolean(variables, BOOL_TP_CAVE, TRUE);
        setBoolean(variables, BOOL_TP_OUTSIDE, FALSE);
        updateTables(tables, MAP_NO_WATER);
      }
      if(getTable(tables, MAP_BOOLEAN)[xchar/32][(ychar - 10)/32 + 2] == 5){
        setBoolean(variables, BOOL_TP_OUTSIDE, TRUE);
          setBoolean(variables, BOOL_TP_CAVE, FALSE);
          updateTables(tables, MAP_WATER);
      }

      if (getBoolean(variables, BOOL_TP_CAVE)){
        setBoolean(variables, BOOL_FOG, TRUE);
        xscroll = (MAP_PIXELS_X/2) - (SCREEN_WIDTH/1.26);
        yscroll = (MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/4.5) ;
        setDstPosition(atlas, HERO, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        setBoolean(variables, BOOL_TP_CAVE, FALSE);
        setBoolean(variables, BOOL_TP_OUTSIDE, FALSE);
        setBoolean(variables, BOOL_WATERFALL, FALSE);
      }
      if (getBoolean(variables, BOOL_TP_OUTSIDE)){
        setBoolean(variables, BOOL_FOG, FALSE);
        xscroll = (MAP_PIXELS_X/2) - (SCREEN_WIDTH/0.76);
        yscroll = (MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/0.555) ;
        setDstPosition(atlas, HERO, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        setBoolean(variables, BOOL_TP_CAVE, FALSE);
        setBoolean(variables, BOOL_TP_OUTSIDE, FALSE);
        setBoolean(variables, BOOL_WATERFALL, TRUE);
      }

      if (getStaminaLength(atlas) > -2 && getStaminaLength(atlas)  <= 194 && sprint == 1){
        setStaminaLength(atlas, getStaminaLength(atlas) + (2 * sprint));
      }

      setSrcPosition(atlas, HERO, CHAR_WIDTH*(dir/7), CHAR_HEIGHT * width);
      setSrcPosition(atlas, WATERFALL, 32*animation, 0);

      getPicture(atlas, WATERFALL)->src.h = 192;
      getPicture(atlas, WATERFALL)->src.w = 64;

      setSrcPosition(atlas, OLD_MAN, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);
      setSrcPosition(atlas, OLD_WOMAN, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);
      setSrcPosition(atlas, INNKEEPER, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);
      setSrcPosition(atlas, COUNTRY_GUARD, CHAR_WIDTH * 1, CHAR_HEIGHT * 3);
      setSrcPosition(atlas, KIDM, CHAR_WIDTH * 1, CHAR_HEIGHT * 2);
      setSrcPosition(atlas, KIDF, CHAR_WIDTH * 1, CHAR_HEIGHT * 1);
      setSrcPosition(atlas, WOOD_HUNTER, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);
      setSrcPosition(atlas, VILLAGER, CHAR_WIDTH * 1, CHAR_HEIGHT * 1);
      setSrcPosition(atlas, FISH_HUNTER, CHAR_WIDTH * 1, CHAR_HEIGHT * 0);

      cpt += 1;

      if (cpt % 3 == 0){
        if (animation){
          animation = 0;
        }else{
          animation = 1;
        }
      }

      setPictureNegX(getPicture(atlas, WATERFALL), getPictureX(atlas, WATERFALL), NEG);
      setPictureNegY(getPicture(atlas, WATERFALL), getPictureY(atlas, WATERFALL), NEG);

      setPictureNegX(getPicture(atlas, OLD_MAN), getPictureX(atlas, OLD_MAN), NEG);
      setPictureNegY(getPicture(atlas, OLD_MAN), getPictureY(atlas, OLD_MAN), NEG);

      setPictureNegX(getPicture(atlas, OLD_WOMAN), getPictureX(atlas, OLD_WOMAN), NEG);
      setPictureNegY(getPicture(atlas, OLD_WOMAN), getPictureY(atlas, OLD_WOMAN), NEG);

      setPictureNegX(getPicture(atlas, INNKEEPER), getPictureX(atlas, INNKEEPER), NEG);
      setPictureNegY(getPicture(atlas, INNKEEPER), getPictureY(atlas, INNKEEPER), NEG);

      setPictureNegX(getPicture(atlas, COUNTRY_GUARD), getPictureX(atlas, COUNTRY_GUARD), NEG);
      setPictureNegY(getPicture(atlas, COUNTRY_GUARD), getPictureY(atlas, COUNTRY_GUARD), NEG);

      setPictureNegX(getPicture(atlas, KIDM), getPictureX(atlas, KIDM), NEG);
      setPictureNegY(getPicture(atlas, KIDM), getPictureY(atlas, KIDM), NEG);

      setPictureNegX(getPicture(atlas, KIDF), getPictureX(atlas, KIDF), NEG);
      setPictureNegY(getPicture(atlas, KIDF), getPictureY(atlas, KIDF), NEG);

      setPictureNegX(getPicture(atlas, WOOD_HUNTER), getPictureX(atlas, WOOD_HUNTER), NEG);
      setPictureNegY(getPicture(atlas, WOOD_HUNTER), getPictureY(atlas, WOOD_HUNTER), NEG);

      setPictureNegX(getPicture(atlas, VILLAGER), getPictureX(atlas, VILLAGER), NEG);
      setPictureNegY(getPicture(atlas, VILLAGER), getPictureY(atlas, VILLAGER), NEG);

      setPictureNegX(getPicture(atlas, FISH_HUNTER), getPictureX(atlas, FISH_HUNTER), NEG);
      setPictureNegY(getPicture(atlas, FISH_HUNTER), getPictureY(atlas, FISH_HUNTER), NEG);

      display(atlas, variables, sdl, tables, xscroll, yscroll);
      if (getBoolean(variables, BOOL_WATERFALL)){
        SDL_BlitSurface(getPicture(atlas, WATERFALL)->surface, &getPicture(atlas, WATERFALL)->src, getScreen(sdl), &getPicture(atlas, WATERFALL)->neg);
      }

      if(getBoolean(variables, BOOL_PANNEL)) SDL_BlitSurface(getPicture(atlas, PANNEL)->surface, NULL, getScreen(sdl), &getPicture(atlas, PANNEL)->dst);
      if(getBoolean(variables, BOOL_PANNEL_START)) SDL_BlitSurface(getText(text, TEXT_PANNEL_START), NULL, getScreen(sdl), getTextDst(text));
      if(getBoolean(variables, BOOL_PANNEL_CAVE)) SDL_BlitSurface(getText(text, TEXT_PANNEL_CAVE), NULL, getScreen(sdl), getTextDst(text));
      if(getBoolean(variables, BOOL_FOG))  SDL_BlitSurface(getPicture(atlas, FOG)->surface, NULL, getScreen(sdl), &getPicture(atlas, FOG)->dst);

      SDL_BlitSurface(getStamina(atlas), NULL, getScreen(sdl), getStaminaDst(atlas));
      SDL_BlitSurface(getLifePoint(atlas), NULL, getScreen(sdl), getLifePointDst(atlas));
      SDL_UpdateRect(getScreen(sdl), 0, 0, 0, 0);
      SDL_Flip(getScreen(sdl));

    }

    // memory restitutions
    destroyAtlas(atlas);
    destroyTables(tables);
    destroyVariables(variables);
    destroySDL(sdl);
    destroyText(text);
    destroyAudio(audio);

}
