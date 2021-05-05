/*
***************************************************
main.c
****************************************************
Fonction principale
****************************************************
par : momole02
*/

#include "stdinc.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "defs.h"
#include "menuu.h"
#include "game.h"


enum{
	MENU,
	GAME,
};

struct scr_t
{
	int (*cb_load)();
	int (*cb_handle_events)(SDL_Event * );
	void (*cb_display)(SDL_Surface * );
	void (*cb_free)();
};

static struct scr_t s_scrs[2];
static int s_cur_screen = -1;

void InitScrs()
{
	memset(s_scrs , 0 , 2*sizeof(struct scr_t));
	
	//Menu 
	s_scrs[MENU].cb_load = &Menu_Load;
	s_scrs[MENU].cb_handle_events = &Menu_HandleEvents;
	s_scrs[MENU].cb_display = &Menu_Display;
	s_scrs[MENU].cb_free = &Menu_Free;
	
	//Jeu..
	s_scrs[GAME].cb_load = &Game_Load;
	s_scrs[GAME].cb_handle_events = &Game_HandleEvents;
	s_scrs[GAME].cb_display = &Game_Display;
	s_scrs[GAME].cb_free = &Game_Free;
	
}

void SetCurScreen(int scr)
{
	if(s_cur_screen != -1)
		s_scrs[s_cur_screen].cb_free();
	
	if(s_scrs[scr].cb_load())
		s_cur_screen = scr; 
}

void sss(SDL_Surface * screen )
{

	SDL_Event ev; 
	int done = 0 ;
	int evt_action = 0;
	
	
	//if(SDL_Init(SDL_INIT_VIDEO)<0){
	//	fprintf(stderr , "Une erreur s'est produite : %s" , SDL_GetError());
	//	return EXIT_FAILURE;
	//}
	
	atexit(SDL_Quit);
	
	//screen = SDL_SetVideoMode(WINDOW_W , WINDOW_H , 32 , SDL_HWSURFACE|SDL_DOUBLEBUF);
	//if(!screen){
		//fprintf(stderr , "Erreur : %s" , SDL_GetError());
	//	return EXIT_FAILURE;
	//}
	
	//Initialiser les écrans
	InitScrs();
	
	//Passer au menu
	SetCurScreen(MENU);
	
	
	SDL_WM_SetCaption("mSnake" , NULL);
	
	while(!done){
		while(SDL_PollEvent(&ev)){
			evt_action = s_scrs[s_cur_screen].cb_handle_events(&ev);
			
			if( evt_action == EVT_ACTION_EXIT)			done=1;
			if( evt_action == EVT_ACTION_NEXT_SCREEN)	SetCurScreen(s_cur_screen+1);
			if( evt_action == EVT_ACTION_PREV_SCREEN )	SetCurScreen(s_cur_screen-1);
			
		}
		
		SDL_FillRect(screen  ,NULL,0);
		s_scrs[s_cur_screen].cb_display(screen);
		SDL_Flip(screen);
		
	}
	
	return EXIT_SUCCESS;
}
