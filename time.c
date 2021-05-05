/**
 * @file time.c
 * @brief time 
 * @author khaled chtioui
 * @version 0.1
 * @date 05/05/2021 

*/
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include <time.h>

#include "time.h"



/**
* @brief timer
* @param screen the surface
* @param t float
* @return void 
*/




void timer(SDL_Surface *screen , float t)
{    Uint32 time ,tim ;
    char chrono[16];
    TTF_Font *police;
    SDL_Rect postime;
    SDL_Surface *texte =  NULL;
    SDL_Color noir = {4,9,30,0}, blanc = {255,255,255};

    postime.x = 1100;
    postime.y = 50;


    TTF_Init();
    police = TTF_OpenFont("GenBasB.ttf", 69);
    tim = SDL_GetTicks()-time;             //Minute       //Seconde   //Dixieme
    time = time +tim ;             //Minute       //Seconde   //Dixieme
    sprintf(chrono, "%02u:%02u.%u", time/1000/60%60,time/1000%60, time%1000/100);
    texte = TTF_RenderText_Blended(police, chrono, blanc);

    SDL_BlitSurface(texte, NULL,screen, &postime);

    if (texte != NULL)
    {
        SDL_FreeSurface(texte);
    }

    TTF_CloseFont(police);

}

