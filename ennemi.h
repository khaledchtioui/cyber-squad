#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct enemie
	{
    SDL_Surface *spritesheet;
	//int frame;
	int direction;
	SDL_Rect pos,xminimale,xmaximale;
	SDL_Rect posspritesheet;
	}enemie;

void init_enemie (enemie *E);
void afficher_enemie (enemie *E,SDL_Surface *screen);
void animate_enemie (enemie *E);
int collision (SDL_Rect E,SDL_Rect personnage);
void deplacer( enemie * E);
void deplacerIA( enemie * E, SDL_Rect posPerso);




















#endif // DS_H_INCLUDED
