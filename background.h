#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

typedef struct background
{
int x_relative,y_relative;
SDL_Surface *bg,*mask;
SDL_Rect pos;
SDL_Rect camera;
}background;
void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling_right (background *b,perso *p,SDL_Surface *screen);
void scrolling_left (background *b,perso *p,SDL_Surface *screen);

