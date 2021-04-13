#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "entite.h"


void InitEnnemi(ennemi *e)
{
   //Initialiser les ressources lies a l'ennemi

  e->direction=DROITE;
  e->sprite=IMG_Load("sprite.png");
  e->posSE.x=100;
  e->posSE.y=HAUTEUR-200;
 // e->poSprite.x=LARGEURSPRITE-e->poSprite.w;
  e->poSprite.y=0;
  e->poSprite.x=0;
  e->poSprite.w=LARGEURSPRITE / 8;
  e->poSprite.h=HAUTEURSPRITE / 2;
}

void afficherEnnemi(ennemi e,SDL_Surface *screen)
{

      SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
      SDL_BlitSurface(e.sprite,&e.poSprite,screen,&e.posSE);
      SDL_Flip(screen);
}


void animerEnnemi(ennemi *e)
{
   SDL_Surface *screen;


    if(e->poSprite.x==LARGEURSPRITE)
      e->poSprite.x=0;
    else
     e->poSprite.x=e->poSprite.x+e->poSprite.w;

       e->poSprite.y=e->direction*e->poSprite.h;
}

void deplacer(ennemi *e)
{
  int posmax=LARGEUR-300;
  
   if(e->posSE.x>posmax)
        e->direction=GAUCHE;
   if(e->posSE.x<300)
        e->direction=DROITE;
    if( e->direction==GAUCHE)
         e->posSE.x--;
    else
         e->posSE.x++;
}

int boundingBox(SDL_Rect pose,SDL_Rect posSE)
{
    int colision;
        if((pose.x+pose.w<posSE.x)||(pose.x>posSE.x+posSE.w)||(pose.y+pose.h<posSE.y)||(pose.y>posSE.y+posSE.h))
         colision=0;
         else
        colision=1; 
  
   return colision;
}
