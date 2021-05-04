#include "minimap.h"
#include <SDL/SDL.h>

void init_map (minimap *m)
{ m -> map = IMG_Load("minimap.jpg");
  m-> minijoueur = IMG_Load("joueurmini.png");
  m->positionmap.x =375;
  m->positionmap.y =50;
  m->positionminijoueur.x =0;
  m->positionminijoueur.y =2;
}
/*void movemini (minimap *m, int sens)
{ if (sens == 0)
 m-> positionminijoueur.x+=4;
if (sens  == 1) 
 m-> positionminijoueur.x-=4;
}*/

void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
 // posJoueurABS.x = 1281;
 // posJoueurABS.y = 0;
  posJoueurABS.x = posJoueur.x + camera.x;
  posJoueurABS.y = posJoueur.y + camera.y;
  m->positionminijoueur.x=(posJoueurABS.x * redimensionnement/100)+378;
  m->positionminijoueur.y=(posJoueurABS.y * redimensionnement/100)+50;
 //   m->positionminijoueur.x=(posJoueur.x)/5;
   //   m->positionminijoueur.y=(posJoueur.y)/5+2;
  
  
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
}

