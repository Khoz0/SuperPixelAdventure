#include "constants.h"

/**************************************************
this struct contain all the sounds used on the game
**************************************************/

typedef struct Audio {

  Mix_Chunk* music_theme;
  Mix_Chunk* music_event;

} Audio;

Audio* createAudio();
void destroyAudio(Audio* audio);
