
/*
***************************************************
menu.h
****************************************************
Fonctions de d'écran menu
****************************************************
par : momole02
*/
#ifndef __MENU_H__
#define __MENU_H__

#include <SDL/SDL.h>

int Menu_Load();
int Menu_HandleEvents(SDL_Event * );
void Menu_Display(SDL_Surface * );
void Menu_Free();


#endif //__MENU_H__

