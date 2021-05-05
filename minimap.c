/**
 * @file minimap.c
 * @brief mini map
 * @author youssef gharrad
 * @version 0.1
 * @date 05/05/2021 

*/
#include "minimap.h"
#include <SDL/SDL.h>

/**
* @brief init_map
* @param m minimap
* @return void

*/
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


/**
* @brief MAJMinimap
* @posJoueur position
* @param m minimap
* @posJoueur camera
* @param redimensionnement int
* @return void

*/
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

/**
* @brief afficherminimap
* @param m minimap
* @param screen the screen 
* @return void

*/
void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
}

