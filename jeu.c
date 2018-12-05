#include "jeu.h"

void createGame(){

    SDL_Surface *stamina = NULL, *lifePoint = NULL;
    SDL_Rect staminaPos, lifePointPos, posSpriteWizardPNJ;

    Atlas* atlas = createAtlas();
    Variables* variables = createVariables();
    SDL* sdl = createSDL(atlas);

    int cpt = 0, animation = 0;
    int sprint, bool_pannel_start, bool_pannel_cave, bool_pannel, width, dir, staminaLength, gameOver;
    sprint = 1;

    width = 0;
    dir = 1;
    staminaLength = 195;
    gameOver = 0;
    int xchar, ychar, xscroll, yscroll;
    int actualTime = 0, lastTimes = 0;

    SDL_Event event;

    //mainMenu(&gameOver);

    // initialisation of SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
      printf("Error SDL_mixer : %s\n", Mix_GetError());
    }
    Mix_AllocateChannels(2);
    Mix_Chunk *music_theme, *music_event;;

    music_theme = Mix_LoadWAV("./music/music_theme.wav");
    Mix_Volume(0, 4);
    Mix_PlayChannel(0, music_theme, VOLUME_THEME);

    music_event = Mix_LoadWAV("./music/music_event.wav");
    Mix_Volume(1, VOLUME_EVENT);

    Uint16** map_builder = mapBuilder(MAP_WATER);
    Uint16** map_boolean = mapBoolean(map_builder);

    setDstPosition(atlas, HERO, SCREEN_WIDTH/1.1, SCREEN_HEIGHT/1.4);
    setDstPosition(atlas, CHAT_BOX, (SCREEN_WIDTH - PANNEL_WIDTH)/2, (SCREEN_HEIGHT - PANNEL_HEIGHT)/2);
    setDstPosition(atlas, PANNEL, (SCREEN_WIDTH - PANNEL_WIDTH)/2, (SCREEN_HEIGHT - PANNEL_HEIGHT)/2);

    SDL_SetColorKey(getPicture(atlas, HERO)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, HERO)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, OLD_MAN)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, OLD_MAN)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, OLD_WOMAN)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, OLD_WOMAN)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, INNKEEPER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, INNKEEPER)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, COUNTRY_GUARD)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, COUNTRY_GUARD)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, KIDM)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, KIDM)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, KIDF)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, KIDF)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, WOOD_HUNTER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, WOOD_HUNTER)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, VILLAGER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, VILLAGER)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, FISH_HUNTER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, FISH_HUNTER)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, PANNEL)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, PANNEL)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, CHAT_BOX)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX)->surface->format, 255, 255, 255));
    SDL_SetColorKey(getPicture(atlas, FOG)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, FOG)->surface->format, 255, 255, 255));

    staminaPos.x = 10;
    staminaPos.y = 45;

    lifePointPos.x = 10;
    lifePointPos.y = 20;

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

    SDL_EnableKeyRepeat(10, 10);

    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT ; i++){
        for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
            printf("%d", map_boolean[j][i]);
        }
        printf("\n");
    }

    xscroll = MAP_PIXELS_X - SCREEN_WIDTH;
    yscroll = MAP_PIXELS_Y - SCREEN_HEIGHT;

    // SDL_ttf initialisation
    TTF_Font *font = NULL;
    font = TTF_OpenFont("./font/font.ttf", 50);
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Surface *text_pannel_start, *text_pannel_cave;
    SDL_Rect posTexte;
    posTexte.x = 470;
    posTexte.y = 415;

    // ttf texts
    text_pannel_start = TTF_RenderText_Solid(font, "* bienvenue a joliland *", couleurNoire);
    text_pannel_cave = TTF_RenderText_Solid(font, "*DANGER* entrée de la grote *DANGER*", couleurNoire);



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
      if(!Mix_Playing(1)) Mix_Resume(0);

      SDL_PollEvent(&event);
      keyboardEvent(event, &sprint, variables, map_boolean, xchar, ychar, &width,
                    &yscroll, &xscroll, &dir, &staminaLength, &gameOver, atlas);

      if(map_boolean[xchar/32][(ychar - 15)/32 + 1]==3){
        setBoolean(variables, BOOL_TP_CAVE, TRUE);
        map_builder = mapBuilder(MAP_NO_WATER);
        map_boolean = mapBoolean(map_builder);
      }

      if (getBoolean(variables, BOOL_TP_CAVE)){
        setBoolean(variables, BOOL_FOG, TRUE);
        xscroll = (MAP_PIXELS_X/2) - (SCREEN_WIDTH/1.26);
        yscroll = (MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/5.5) ;
        setDstPosition(atlas, HERO, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        setBoolean(variables, BOOL_TP_CAVE, FALSE);
        setBoolean(variables, BOOL_WATERFALL, TRUE);
      }

      if (staminaLength > -2 && staminaLength  <= 194 && sprint == 1){
        staminaLength  += (2 * sprint);
      }

      stamina = SDL_CreateRGBSurface(SDL_HWSURFACE, staminaLength  + 5, 15, 32, 0, 0 ,0 ,0);
      lifePoint = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 15, 32, 0, 0 ,0 ,0);

      SDL_FillRect(stamina, NULL, SDL_MapRGB(getScreen(sdl)->format, 1, 215, 88));
      SDL_FillRect(lifePoint, NULL, SDL_MapRGB(getScreen(sdl)->format, 200, 7, 7));

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

      display(atlas, variables, sdl, map_builder, xscroll, yscroll);
      if (getBoolean(variables, BOOL_WATERFALL)){
        SDL_BlitSurface(getPicture(atlas, WATERFALL)->surface, &getPicture(atlas, WATERFALL)->src, getScreen(sdl), &getPicture(atlas, WATERFALL)->neg);
      }

      if(getBoolean(variables, BOOL_PANNEL)) SDL_BlitSurface(getPicture(atlas, PANNEL)->surface, NULL, getScreen(sdl), &getPicture(atlas, PANNEL)->dst);
      if(getBoolean(variables, BOOL_PANNEL_START)) SDL_BlitSurface(text_pannel_start, NULL, getScreen(sdl), &posTexte);
      if(getBoolean(variables, BOOL_PANNEL_CAVE)) SDL_BlitSurface(text_pannel_cave, NULL, getScreen(sdl), &posTexte);
      if(getBoolean(variables, BOOL_FOG))  SDL_BlitSurface(getPicture(atlas, FOG)->surface, NULL, getScreen(sdl), &getPicture(atlas, FOG)->dst);

      SDL_BlitSurface(stamina, NULL, getScreen(sdl), &staminaPos);
      SDL_BlitSurface(lifePoint, NULL, getScreen(sdl), &lifePointPos);
      SDL_UpdateRect(getScreen(sdl), 0, 0, 0, 0);
      SDL_Flip(getScreen(sdl));
      SDL_FreeSurface(stamina);
      SDL_FreeSurface(lifePoint);

    }

    // memory restitutions
    destroyAtlas(atlas);
    destroyTab(map_builder);
    destroyTab(map_boolean);
    destroyVariables(variables);
    destroySDL(sdl);

    // closing SDL libs
    TTF_CloseFont(font);
    Mix_CloseAudio();

    // SDL memory restitution
    SDL_FreeSurface(text_pannel_start);
    SDL_FreeSurface(text_pannel_cave);
    Mix_FreeChunk(music_theme);
    Mix_FreeChunk(music_event);
    TTF_Quit();
    Mix_Quit();

}
