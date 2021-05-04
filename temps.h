#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>

typedef struct
{
SDL_Surface *imt;//image qui contient le temps 
 SDL_Rect position;// position du clock
  
    TTF_Font *pol ;

 char temps[100]; 
 int secondesEcoulees; 
SDL_Color couleurBlanche;
time_t tpi,tpa;
int min, sec;
}time  ;

void initT(time *t);
void affT(time *t, SDL_Surface *ecran);
void freeT (time *t,SDL_Surface *ecran);
