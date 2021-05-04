#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

#include "temps.h"

void initT(temps *t)
{
 t->imt = NULL; 
 t->position.x=1100;
   t->position.y=250;
  t->pol = TTF_OpenFont("outils/.ttf", 60);
    strcpy( t->temps,"");
(t->secondesEcoulees)=0;
time(&(t->tpi)); //temps du debut



}


void affT(temps *t,SDL_Surface *ecran)
{	
SDL_Color couleurBlanche= {255, 255, 255};

    	time(&(t->tpa));

		t->secondesEcoulees = t->tpa - t->tpi;

        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);

	 sprintf(t->temps,"%d:%d",t->min,t->sec);
        t->temps = TTF_RenderUTF8_Solid(t->pol, t->temps, couleurBlanche);
      

SDL_BlitSurface(t->temps, NULL, ecran, &(t->position)); 
  
	
}

void freeT(temps *t,SDL_Surface *ecran)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->pol);
}
