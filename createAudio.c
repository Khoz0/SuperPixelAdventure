#include "createAudio.h"

Audio* createAudio(){

  Audio* audio = malloc(sizeof(Audio));

  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
    printf("Error SDL_mixer : %s\n", Mix_GetError());
  }
  Mix_AllocateChannels(2);

  audio->music_theme = Mix_LoadWAV("./music/music_theme.wav");
  audio->music_event = Mix_LoadWAV("./music/music_event.wav");

  // at the start, we play the main theme (infinite loop)
  Mix_Volume(MUSIC_THEME, VOLUME_THEME);
  Mix_PlayChannel(0, audio->music_theme, VOLUME_THEME);

  // channel for event's sound
  Mix_Volume(MUSIC_EVENT, VOLUME_EVENT);

  return audio;
}

void destroyAudio(Audio* audio) {

  Mix_FreeChunk(audio->music_theme);
  Mix_FreeChunk(audio->music_event);
  audio->music_theme = NULL;
  audio->music_event = NULL;
  Mix_CloseAudio();
  Mix_Quit();
  free(audio);
  audio = NULL;

}
