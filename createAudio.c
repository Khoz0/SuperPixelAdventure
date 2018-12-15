#include "createAudio.h"

Audio* createAudio(){

  Audio* audio = malloc(sizeof(Audio));

  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
    printf("Error SDL_Mixer (createAudio.c) : %s\n", Mix_GetError());
  }
  Mix_AllocateChannels(4);

  audio->music_theme = Mix_LoadWAV("./music/music_theme.wav");
  audio->music_event_chest = Mix_LoadWAV("./music/music_event_chest.wav");
  audio->music_event_pnj = Mix_LoadWAV("./music/music_event_pnj.wav");
  audio->music_event_cave = Mix_LoadWAV("./music/music_event_cave.wav");

  // at the start, we play the main theme (infinite loop)
  Mix_Volume(MUSIC_THEME, VOLUME_THEME);
  playMusic(audio, MUSIC_THEME);

  // channel for event's sound
  Mix_Volume(MUSIC_EVENT_CHEST, VOLUME_EVENT);
  Mix_Volume(MUSIC_EVENT_PNJ, VOLUME_EVENT);
  Mix_Volume(MUSIC_EVENT_CAVE, VOLUME_EVENT);

  return audio;
}

void playMusic(Audio* audio, int channel) {
  if(channel == 0) {
    Mix_PlayChannel(MUSIC_THEME, audio->music_theme, -1);
  }else if(channel == 1) {
    Mix_PlayChannel(MUSIC_EVENT_CHEST, audio->music_event_chest, 0);
  }else if(channel == 2){
    Mix_PlayChannel(MUSIC_EVENT_PNJ, audio->music_event_pnj, 0);
  }else{
    Mix_PlayChannel(MUSIC_EVENT_CAVE, audio->music_event_cave, 0);
  }
}

void destroyAudio(Audio* audio) {

  Mix_FreeChunk(audio->music_theme);
  Mix_FreeChunk(audio->music_event_chest);
  Mix_FreeChunk(audio->music_event_pnj);
  audio->music_theme = NULL;
  audio->music_event_chest = NULL;
  audio->music_event_pnj = NULL;
  Mix_CloseAudio();
  Mix_Quit();
  free(audio);
  audio = NULL;

}
