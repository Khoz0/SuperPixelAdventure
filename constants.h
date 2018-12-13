/**************************************************************
this tile contain all #define and SDL includes used on the game
**************************************************************/

#pragma once
// SDL includes
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

// define of the booleans values
#define TRUE 1
#define FALSE 0

// height and width of the tiles
#define WIDTH_TILE 32
#define HEIGHT_TILE 32

// total sizes of the map (in blocs)
#define MAP_BLOCKS_WIDTH 135
#define MAP_BLOCKS_HEIGHT 84

// sizes of the screen (in pixels)
#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 896

// total sizes of the map (in pixels)
#define MAP_PIXELS_X MAP_BLOCKS_WIDTH*WIDTH_TILE
#define MAP_PIXELS_Y MAP_BLOCKS_HEIGHT*HEIGHT_TILE

// sizes of the character (in pixels)
#define CHAR_WIDTH 32
#define CHAR_HEIGHT 32

// number corresponding to the level
#define MAP_WATER 1
#define MAP_NO_WATER_SPAWN_OLD 2
#define MAP_NO_WATER_NO_SPAWN_OLD 3
#define MAP_NO_WATER_NO_SPAWN_NO_OLD 4
#define MAP_CAVE 6

// sizes of pannel
#define PANNEL_WIDTH 870
#define PANNEL_HEIGHT 206

// define of the max pictures/seconds
#define FPS_CAP 25

// define the volume of the sounds played on differents channels
#define VOLUME_THEME 4
#define VOLUME_EVENT 50

// define of the index of each tileset of the atlas->tileset
#define TILESET1 1
#define TILESET2 2
#define TILESET3 3

// define of the index of each picture in the atlas
#define HERO 0
#define WATERFALL 1
#define CHAT_BOX 2
#define PANNEL 3
#define FOG 4
#define CHEST 5
#define FISH 6
#define PASS_FISH 7
#define AXE 8
#define PASS_WOOD 9

// define of the index of each boolean in the booleanTab
#define BOOL_WATERFALL 0
#define BOOL_TP_CAVE 1
#define BOOL_FOG 2
#define BOOL_PANNEL 3
#define BOOL_PANNEL_CAVE 4
#define BOOL_PANNEL_START 5
#define BOOL_TP_OUTSIDE 6
#define BOOL_PANNEL_CAVE_ONE 7
#define BOOL_PANNEL_CAVE_TWO 8
#define BOOL_PANNEL_CAVE_THREE 9
#define BOOL_PANNEL_CAVE_FOUR 10
#define BOOL_LEVIER_UN 11
#define BOOL_LEVIER_DEUX 12
#define BOOL_LEVIER_TROIS 13
#define BOOL_LEVIER_QUATRE 14
#define BOOL_CHEST 15
#define BOOL_SPAWN 16
#define BOOL_SPAWN_STOP 17
#define BOOL_COUNTRYGUARD 18
#define BOOL_CHAT_BOX 19
#define BOOL_FISH_QUEST 20
#define BOOL_STUMP 21
#define BOOL_AXE_QUEST 22
#define BOOL_FISHMAN 23
#define BOOL_WOODMAN 24
#define BOOL_OLDMAN_CAVE 25
#define BOOL_OLDWOMAN_CAVE 26
#define BOOL_PANNEL_SPAWN 27
#define BOOL_FOG_ACCESS 28
#define BOOL_END_CAVE 29
#define BOOL_GIRL 30
#define BOOL_BOY 31
#define BOOL_INNERKEEPER 32
#define BOOL_VILLAGER 33
#define BOOL_PANNEL_FISH_MAN 34
#define BOOL_PANNEL_WOOD_MAN 35
#define BOOL_GUARDIANS 36

// define of the numbers corresponding to the texts used on the game
#define TEXT_PANNEL_START 0
#define TEXT_PANNEL_CAVE 1
#define TEXT_PANNEL_CAVE_ONE 2
#define TEXT_PANNEL_CAVE_TWO 3
#define TEXT_PANNEL_CAVE_THREE 4
#define TEXT_PANNEL_CAVE_FOUR 5
#define TEXT_SPAWN_1 6
#define TEXT_SPAWN_2 7
#define TEXT_SPAWN_3 8
#define TEXT_COUNTRYGUARD_1 9
#define TEXT_COUNTRYGUARD_2 10
#define TEXT_PANNEL_SPAWN_1 11
#define TEXT_PANNEL_SPAWN_2 12
#define TEXT_PANNEL_SPAWN_3 13
#define TEXT_GIRL 14
#define TEXT_BOY 15
#define TEXT_INNERKEEPER_1 16
#define TEXT_INNERKEEPER_2 17
#define TEXT_VILLAGER 18
#define TEXT_FISHMAN_1 19
#define TEXT_FISHMAN_2 20
#define TEXT_FISHMAN_3 21
#define TEXT_WOODMAN_1 22
#define TEXT_WOODMAN_2 23
#define TEXT_WOODMAN_3 24
#define TEXT_OLD_MAN 25
#define TEXT_OLD_WOMAN 26

// define of the index of tabVariables
#define XCHAR 0
#define YCHAR 1
#define XSCROLL 2
#define YSCROLL 3
#define SPRINT 4
#define GAMEOVER 5
#define WIDTH 6
#define DIR 7
#define PREC_XSCROLL 8
#define PREC_YSCROLL 9
#define PREC_POSCHAR_X 10
#define PREC_POSCHAR_Y 11
#define PREC_POSWATERFALL_X 12
#define PREC_POSWATERFALL_Y 13
#define CPT 14
#define ANIMATION 15
#define CPT_CHEST 16

// define of a boolean value (only 1 because only used to make it TRUE, by default FALSE)
#define NEG 1

// define of the sizes of the tables
#define SIZE_ATLAS 10
#define SIZE_TAB_BOOLEAN 37
#define SIZE_TAB_TEXT 27
#define SIZE_TAB_VARIABLES 17

// define of boolean to fill the table map_builder & map_boolean
#define MAP_BUILDER 0
#define MAP_BOOLEAN 1

// define of the number corresponding to the musics
#define MUSIC_THEME 0
#define MUSIC_EVENT 1

// define of the index to threat threatErrors  if(index == LOAD_ATLAS) game->error->loadAtlas = message;
#define LOAD_ATLAS 1
#define LOAD_SDL 2
