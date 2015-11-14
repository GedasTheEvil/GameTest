#include "sounds.h"

void InitSounds()
{
     if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
     {
	  printf(  "Video/Audio initialization failed: %s\n", SDL_GetError( ) );
     }

     if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers))
     {
	  printf(  "Unable to open audio!\n" );
     }


     
     Shot   = Mix_LoadWAV("Sounds/Shot.wav");
     AnbAtt = Mix_LoadWAV("Sounds/Anubis_attack.wav");
     AnbDie = Mix_LoadWAV("Sounds/Anubis_die.wav"); 
     SpdAtt = Mix_LoadWAV("Sounds/Spider_attack.wav"); 
     SpdDie = Mix_LoadWAV("Sounds/Spider_die.wav");       

}

void KillSounds()
{

     Mix_FreeChunk(Shot);
     Mix_FreeChunk(AnbAtt);
     Mix_FreeChunk(AnbDie); 
     Mix_FreeChunk(SpdAtt); 
     Mix_FreeChunk(SpdDie);

     Mix_CloseAudio();
     
     SDL_Quit( );
}

