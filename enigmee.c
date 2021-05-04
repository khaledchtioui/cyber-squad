#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include"enigme.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<time.h>
int enigmee(    SDL_Surface *fenetre_enigme)
{
    enigme enig;
    int ancienne[6],s,r,continuer=1,affiche=0,nouvelleenig=1,temps_actuel=0,temps_pred=0,ligne=0;
    SDL_Event event;
    srand(time(NULL));

    init_enigme(&enig,ancienne);
    remplir_fichier("fichier question");

    while(nouvelleenig)
   {
    afficher_enigme(&enig,ancienne,"fichier question",&ligne,fenetre_enigme);
    s=solution(ligne);
    continuer=1;
    while(continuer)
    {   
   
       temps_actuel=SDL_GetTicks();
       if(temps_actuel-temps_pred>10000)
       {
          //p->score--;
          continuer=0;
          temps_pred=temps_actuel;
       }
       else
          { 
          r=resolution(&affiche);
          if(affiche==1) 
          {
             afficher_resultat(&enig,s,r,fenetre_enigme);
            // while(continuer)
             //{
	      //  SDL_PollEvent(&event);
                //if(event.type==SDL_QUIT)
               //   if (r==s)
                // {
                                          continuer=0;
                                            nouvelleenig=0;
		 //}
            // }
          }
          }
    }
   }    
   // ffree(&enig);
  //  return EXIT_SUCCESS;
  if (r==s)
  return 1  ; 
  else 
  return 0    ;
  
  
}

