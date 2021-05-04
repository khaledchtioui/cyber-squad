#include "perso.h"
#include "background.h"
#include "load.h"
#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 30
#include "menu.h"
int main (void)
{
    int continuee=1;
    SDL_Surface *ecran =NULL;
    Mix_Music *musique;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(IMG_Load("logo.png"), NULL); // L'icône doit être chargée avant SDL_SetVideoMode
    ecran = SDL_SetVideoMode(1400, 1050,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("LUPIN", NULL);
    SDL_Event event;
SDL_Surface*    icon;
 
icon = SDL_LoadBMP("logo.bmp");
if (icon != 0)
        SDL_WM_SetIcon(icon, NULL);
if (ecran==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {printf("%s",Mix_GetError()); }

	   musique=Mix_LoadMUS("music2.mp3");
           Mix_PlayMusic(musique,-1);





while (continuee)
{
menu(ecran,musique);					
}

Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_FreeSurface(ecran);
SDL_FreeSurface(icon);
SDL_Quit();
return EXIT_SUCCESS;
}




