//////////////////////////////////////////
//game.h
//////////////////////////////////////////
//définition des fonction de gestion
//de l'écran de jeu
//////////////////////////////////////////
//Crée le : 10-10-2015 
//Par : momole02
//////////////////////////////////////////

#ifndef __GAME_H__
#define __GAME_H__

#include <SDL/SDL.h>

int Game_Load();
int Game_HandleEvents(SDL_Event * );
void Game_Display(SDL_Surface * );
void Game_Free();

#endif //__GAME_H__
