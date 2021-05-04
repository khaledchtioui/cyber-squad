#ifndef minimap_H
#define minimao_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{SDL_Surface *map;
SDL_Surface  *minijoueur;
SDL_Rect positionmap;
SDL_Rect positionminijoueur;
}minimap;
void init_map (minimap *m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen);
//void movemini (minimap *m, int sens);
#endif

