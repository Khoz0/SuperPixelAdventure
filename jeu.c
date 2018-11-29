#include "mapBuilder.h"
#include "mapBoolean.h"
#include "display.h"
#include "picture.h"
#include "tileset.h"
#include "keyboardEvent.h"
#include "constants.h"
#include "menu.h"

int main(int argc,char** argv){
    SDL_Surface *stamina = NULL, *lifePoint = NULL, *chatBox = NULL, *pannel = NULL, *fog = NULL;
    SDL_Rect staminaPos, lifePointPos, posSpriteWizardPNJ;
    SDL_Rect waterfallAnim, positionChatBox, positionPannel, fogPos;

    Picture* hero = createPicture("./pictures/characters/hero.bmp", 30, CHAR_HEIGHT);
    Picture* old_man = createPicture("./pictures/characters/papi.bmp", CHAR_WIDTH, CHAR_HEIGHT);
    Picture* old_woman = createPicture("./pictures/characters/mamie.bmp", CHAR_WIDTH, CHAR_HEIGHT);
    Picture* waterfall = createPicture("./pictures/waterfall/cascades_grandes.bmp", CHAR_WIDTH, CHAR_HEIGHT);

    int cpt = 0, animation = 0;
    int sprint, bool_pannel_start, bool_pannel_cave, bool_pannel, width, dir, staminaLength, gameOver,  bool_fog = 0, bool_tp_cave = 0, bool_waterfall = 1;
    sprint = 1;
    bool_pannel_start = 0;
    bool_pannel_cave = 0;
    bool_pannel = 0;
    width = 2;
    dir = 1;
    staminaLength = 195;
    gameOver = 0;
    int xchar, ychar, xscroll, yscroll;
    int actualTime = 0, lastTimes = 0;

    SDL_Surface *screen;
    SDL_Event event;

    TileSet* tileset = createTileset();

    //mainMenu(&gameOver);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

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

    setDstPosition(hero, SCREEN_WIDTH/1.1, SCREEN_HEIGHT/1.4);

    positionChatBox.y = (SCREEN_HEIGHT - PANNEL_HEIGHT)/2;
    positionChatBox.x = (SCREEN_WIDTH - PANNEL_WIDTH)/2;

    positionPannel.y = (SCREEN_HEIGHT - PANNEL_HEIGHT)/2;
    positionPannel.x = (SCREEN_WIDTH - PANNEL_WIDTH)/2;

    fogPos.x = 0;
    fogPos.y = 0;

    // loading pictures
    chatBox = SDL_LoadBMP("./pictures/chat/chatBox.bmp");
    pannel = SDL_LoadBMP("./pictures/chat/pannel.bmp");
    fog = SDL_LoadBMP("./pictures/tileset/fog.bmp");
    SDL_SetColorKey(hero->surface, SDL_SRCCOLORKEY, SDL_MapRGB(hero->surface->format, 255, 255, 255));
    SDL_SetColorKey(old_man->surface, SDL_SRCCOLORKEY, SDL_MapRGB(old_man->surface->format, 255, 255, 255));
    SDL_SetColorKey(old_woman->surface, SDL_SRCCOLORKEY, SDL_MapRGB(old_woman->surface->format, 255, 255, 255));
    SDL_SetColorKey(pannel, SDL_SRCCOLORKEY, SDL_MapRGB(pannel->format, 255, 255, 255));
    SDL_SetColorKey(chatBox, SDL_SRCCOLORKEY, SDL_MapRGB(chatBox->format, 255, 255, 255));
    SDL_SetColorKey(fog, SDL_SRCCOLORKEY, SDL_MapRGB(fog->format, 255, 255, 255));

    staminaPos.x = 10;
    staminaPos.y = 45;

    lifePointPos.x = 10;
    lifePointPos.y = 20;

    setDstPosition(waterfall, -2208, -1728);

    setDstPosition(old_man, -670, -1410);

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

      xchar = hero->dst.x + xscroll;
      ychar = hero->dst.y + yscroll;

      // we resume the main channel if it had been paused
      if(!Mix_Playing(1)) Mix_Resume(0);

      SDL_PollEvent(&event);
      keyboardEvent(event, &sprint, &bool_pannel_start, map_boolean, xchar, ychar, &bool_pannel_cave, &bool_pannel, &width, hero,
                    &yscroll, &xscroll, &dir, waterfall, &staminaLength, &gameOver, old_man, old_woman);

      if(map_boolean[xchar/32][(ychar - 15)/32 + 1]==3){
        bool_tp_cave = 1;
        map_builder = mapBuilder(MAP_NO_WATER);
        map_boolean = mapBoolean(map_builder);
      }

      if (bool_tp_cave){
        bool_fog = 1;
        xscroll = (MAP_PIXELS_X/2) - (SCREEN_WIDTH/1.26);
        yscroll = (MAP_PIXELS_Y/2) - (SCREEN_HEIGHT/5.5) ;
        setDstPosition(hero, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        bool_tp_cave = 0;
        bool_waterfall = 0;
      }

      if (staminaLength > -2 && staminaLength  <= 194 && sprint == 1){
        staminaLength  += (2 * sprint);
      }

      stamina = SDL_CreateRGBSurface(SDL_HWSURFACE, staminaLength  + 5, 15, 32, 0, 0 ,0 ,0);
      lifePoint = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 15, 32, 0, 0 ,0 ,0);

      SDL_FillRect(stamina, NULL, SDL_MapRGB(screen->format, 1, 215, 88));
      SDL_FillRect(lifePoint, NULL, SDL_MapRGB(screen->format, 200, 7, 7));

      setSrcPosition(hero, CHAR_WIDTH*(dir/7), CHAR_HEIGHT * width);

      setSrcPosition(waterfall, 32*animation, 0);
      waterfall->src.h = 192;
      waterfall->src.w = 64;

      cpt += 1;

      if (cpt % 37 == 0){
        animation = 0;
      }
      if (cpt % 33 == 0){
        animation = 1;
      }

      setPictureNegX(waterfall, getPictureX(waterfall));
      setPictureNegY(waterfall, getPictureY(waterfall));

      setPictureNegX(old_man, getPictureX(old_man));
      setPictureNegY(old_man, getPictureY(old_man));

      if (bool_waterfall){
        printf("OUI");
        SDL_BlitSurface(waterfall->surface, &waterfall->src, screen, &waterfall->neg);
      }
      SDL_BlitSurface(hero->surface, &hero->src, screen, &hero->dst);
      SDL_BlitSurface(old_man->surface, &old_man->src, screen, &old_man->neg);
      //SDL_BlitSurface(old_woman->surface, &old_woman->src, screen, &old_woman->dst);
      if(bool_pannel == 1) SDL_BlitSurface(pannel, NULL, screen, &positionPannel);
      if(bool_pannel_start == 1) SDL_BlitSurface(text_pannel_start, NULL, screen, &posTexte);
      if(bool_pannel_cave) SDL_BlitSurface(text_pannel_cave, NULL, screen, &posTexte);
      if(bool_fog){
        SDL_BlitSurface(fog, NULL, screen, &fogPos);
      }
      SDL_BlitSurface(stamina, NULL, screen, &staminaPos);
      SDL_BlitSurface(lifePoint, NULL, screen, &lifePointPos);
      SDL_UpdateRect(screen, 0, 0, 0, 0);
      SDL_Flip(screen);
      SDL_FreeSurface(stamina);
      SDL_FreeSurface(lifePoint);

      // print of the map
      display(map_builder, screen, xscroll, yscroll, tileset);

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

    destroyTileset(tileset);
    destroyPicture(hero);
    destroyPicture(old_man);
    destroyPicture(old_woman);
    destroyPicture(waterfall);

    // closing SDL libs
    TTF_CloseFont(font);
    Mix_CloseAudio();

    // SDL memory restitution
    SDL_FreeSurface(chatBox);
    SDL_FreeSurface(pannel);
    SDL_FreeSurface(text_pannel_start);
    SDL_FreeSurface(text_pannel_cave);
    SDL_FreeSurface(fog);
    SDL_FreeSurface(screen);
    Mix_FreeChunk(music_theme);
    Mix_FreeChunk(music_event);
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
    return 0;

}
