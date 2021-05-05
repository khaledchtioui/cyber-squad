//////////////////////////////////////////
//menu.c
//////////////////////////////////////////
//implémentation des 
//fonction de gestion de l'écran du menu
//////////////////////////////////////////
//Crée le : 10-10-2015 
//Par : momole02
//////////////////////////////////////////


#include "stdinc.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>

#include "defs.h"
#include "menuu.h"
#include "gfxutils.h"
#include "score.h"

static SDL_Surface * s_title , *s_fbmp ; 

static int s_anLastTime1 = 0;
static int s_anFrame1 = 0; 

static int s_anLastTime2 = 0;
static int s_anFrame2 = 0;

static u32 s_hiscore = 0 ;

int Menu_Load()
{
	//Chargement des images et du font bitmap
	s_title = IMG_Load("pics/title.png");
	s_fbmp = IMG_Load("pics/font.bmp");
	if(!s_title || !s_fbmp){
		Menu_Free();
		return 0 ; 
	}
	SDL_SetColorKey(s_fbmp , SDL_SRCCOLORKEY , 0);
	s_anLastTime1 = SDL_GetTicks();
	s_anLastTime2 = SDL_GetTicks();
	s_hiscore = LoadHiScore();
	
	return 1; 
}

int Menu_HandleEvents(SDL_Event * ev)
{
	if(ev->type == SDL_KEYDOWN){
		switch(ev->key.keysym.sym){
			case SDLK_ESCAPE:
				return EVT_ACTION_EXIT; 
				
			case SDLK_RETURN:
				return EVT_ACTION_NEXT_SCREEN;
				
			default : 
				break;
		}
	}
	
	return EVT_ACTION_NO_ACTION ; 
}

//Coordonnées polaires -> coordonnées cartésiennes
void PolarCoords(int rad , int angle , s16 * x , s16 * y)
{
	*x = rad*cos((angle * M_PI)/180);
	*y = rad*(-sin((angle*M_PI)/180));
}

void Menu_Display(SDL_Surface * dst)
{
	SDL_Rect tdst ; 
	char buf[256];
	
	//Animation du titre
	{
		PolarCoords(16 , s_anFrame2 , &tdst.x ,&tdst.y);
		SDL_BlitSurface(s_title , NULL, dst , &tdst);
		
		s_anFrame2 = (s_anFrame2 + 5) % 360 ;
	}
	
	
	
	//Press start animé
	{
		if(!s_anFrame1)
			GFX_FontPrint(dst , s_fbmp , 16,16,32, "Press Start " , 256 , 164, s_title->h + 50 );
		
		//Effet de clignotement
		if(SDL_GetTicks() - s_anLastTime1 >= 250){
			s_anFrame1 = (s_anFrame1+1) % 2;
			s_anLastTime1 = SDL_GetTicks();
		}
	}
	
	sprintf(buf , "Hi-Score : %d" , s_hiscore );
	GFX_FontPrint(dst , s_fbmp , 16,16,32, buf , 256, 0, 0);
	GFX_FontPrint(dst , s_fbmp , 16,16,32, "Coded by Momole02" , 17 , 0, dst->h - 20);
	
}

void Menu_Free()
{
	if(s_title){
		SDL_FreeSurface(s_title);
		s_title = NULL;
	}
	
	if(s_fbmp){
		SDL_FreeSurface(s_fbmp);
		s_fbmp = NULL;
	}
	
}


