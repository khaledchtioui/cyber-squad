/**
 * @file perso.h
 * @brief perso 
 * @author khaled chtioui
 * @version 0.1
 * @date 05/05/2021 

*/


#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


/**
* @struct life 
* @brief struct life 

*/

typedef struct
{

 int nbre_vie;
 SDL_Rect posvie;
 SDL_Surface *imagevie;
  
}life;
/**
* @struct score 
* @brief struct score 

*/


typedef struct
{

 SDL_Rect posscore;
 SDL_Surface *imagescore;
 int nbre_score;

}score;

/**
* @struct perso 
* @brief struct perso 

*/






typedef struct perso
{

SDL_Surface *personnage;
SDL_Rect rect;//,rect_relative;

SDL_Surface *runright[11];
SDL_Surface *runleft[11];
//SDL_Surface *die[10];
SDL_Surface *frame;
float speedX,speedY;
int fr;

  life viehero;
  score score;




}perso;

/**
* @struct input 
* @brief struct input 

*/


typedef struct Input
{
 int left,right,jump,down;

} Input;




void initialiser_input (Input *I);

void initialiser_perso (perso *p);

void initialiser_perso2 (perso *p);

void afficher_perso (perso *p,SDL_Surface *screen);

void animation_right (perso *p);

void animation_left (perso *p);

void animation_stable (perso *p);

void mouvementright (perso *p);

void mouvementleft (perso *p);

void jumpright (perso *p);

void jumpleft (perso *p);

void afficher_vie_hero(perso * p,SDL_Surface *screen)              ;

void afficher_score_hero(perso h,SDL_Surface *screen)     ;

int incrementer_scorehero(perso h)    ;

int decrementer_scorehero(perso h)    ;

int decrementer_viehero(perso h)   ;

int incrementer_viehero(perso h)   ;

int gagner(perso h,SDL_Rect poscoin)    ;

 #endif
