#include "constants.h"

typedef struct Audio {

  Mix_Chunk* music_theme;
  Mix_Chunk* music_event;

} Audio;

Audio* createAudio();
void destroyAudio(Audio* audio);
