#pragma once
// includes
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
#define MAP_CAVE 5

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

// define of the numbers corresponding to the texts used on the game
#define TEXT_PANNEL_START 0
#define TEXT_PANNEL_CAVE 1
#define TEXT_PANNEL_CAVE_ONE 2
#define TEXT_PANNEL_CAVE_TWO 3
#define TEXT_PANNEL_CAVE_THREE 4
#define TEXT_PANNEL_CAVE_FOUR 5

// define of the index of tabVariables
#define XCHAR 0
#define YCHAR 1
#define XSCROLL 2
#define YSCROLL 3
#define SPRINT 4
#define GAMEOVER 5
#define WIDTH 6
#define DIR 7

// define of a boolean value (only 1 because only used to make it TRUE, by default FALSE)
#define NEG 1

// define of the sizes of the tables
#define SIZE_ATLAS 5
#define SIZE_TAB_BOOLEAN 11
#define SIZE_TAB_TEXT 6
#define SIZE_TAB_VARIABLES 8

// define of boolean to fill the table map_builder & map_boolean
#define MAP_BUILDER 0
#define MAP_BOOLEAN 1

// define of the number corresponding to the musics
#define MUSIC_THEME 0
#define MUSIC_EVENT 1
