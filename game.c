//////////////////////////////////////////
//game.c
//////////////////////////////////////////
//implémentation des fonction de gestion
//de l'écran de jeu
//////////////////////////////////////////
//Crée le : 10-10-2015 
//Par : momole02
//////////////////////////////////////////

#include "stdinc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


#include "gfxutils.h"
#include "score.h"
#include "game.h"
#include "snake.h"
#include "defs.h"


//Grille
static u8 s_grid[NBLOCKS_H*NBLOCKS_W];
static u32 s_colors[3];
static SList_t s_snake; 
static u32 s_appleX , s_appleY;
static u32 s_anLastTime1;
static u32 s_score , s_hiscore;
static SDL_Surface * s_fbmp ; 
static u8 s_isPaused = 0;

void AppleRand()
{
	do{
		s_appleX = rand() % NBLOCKS_W;
		s_appleY = rand() % NBLOCKS_H;
	}while(SList_IsOnSnake(&s_snake ,s_appleX , s_appleY , 1));
}

int Game_Load()
{
	srand(time(NULL));
	memset(s_grid , IT_EMPTY , NBLOCKS_H*NBLOCKS_W);
	
	s_fbmp = IMG_Load("pics/font.bmp");
	if(!s_fbmp)
		return 0; 
	
	SDL_SetColorKey(s_fbmp , SDL_SRCCOLORKEY , 0);
		
	s_score = 0 ;
	s_hiscore = LoadHiScore();
	
	s_colors[IT_EMPTY] = 0 ;
	s_colors[IT_SNAKE_PART] =  0x008800 ; 
	s_colors[IT_APPLE] =  0xff0000;
	
	//Commencer par 3 blocks
	SList_Push(&s_snake);
	s_snake.first->x = 2 ; 
	s_snake.first->y = 0; 
	
	SList_Push(&s_snake);
	SList_Push(&s_snake);
	
	AppleRand();
	
	s_anLastTime1 = SDL_GetTicks();
	
	return 1 ;	
}

int Game_HandleEvents(SDL_Event * ev)
{
	if(ev->type == SDL_KEYDOWN ){
		
		switch(ev->key.keysym.sym){
			case SDLK_ESCAPE : 
				return EVT_ACTION_PREV_SCREEN;
			
			case SDLK_PAUSE : 
			case SDLK_p:
			case SDLK_RETURN:
				s_isPaused = !s_isPaused; 
				
			case SDLK_DOWN:		SList_SetVector(&s_snake , 0,1);	break ; 
			case SDLK_UP : 		SList_SetVector(&s_snake , 0,-1);	break ; 
			case SDLK_LEFT: 	SList_SetVector(&s_snake , -1,0);	break ; 
			case SDLK_RIGHT : 	SList_SetVector(&s_snake , 1,0);	break ;
				
			default : 
				break; 
		}
	}
	
	return EVT_ACTION_NO_ACTION;
}

void Game_Display(SDL_Surface * dst)
{
	int ii , ij , k; 
	SDL_Rect frct; 
	SDL_Event ev ; 
	char buf[256];
	
	if(s_isPaused){
		GFX_FontPrint(dst , s_fbmp , 16,16,32, "Paused !" , 10 , 190, 164);
		return ; 
	}
	
	memset(s_grid , 0 , sizeof(s_grid));
	SList_DisplaySnake(&s_snake, s_grid);	//Dessiner le serpent
	s_grid[s_appleX+(NBLOCKS_W*s_appleY)] = IT_APPLE;	//Dessiner la pomme
	
	for(ij = 0 ; ij < NBLOCKS_H ; ++ij){
		for(ii = 0 ; ii < NBLOCKS_W ; ++ii){
			frct.x = ii * BLOCK_W - 1;
			frct.y = ij * BLOCK_H - 1;
			frct.w = BLOCK_W - 2;
			frct.h = BLOCK_H - 2 ;
			
			k = s_grid[(ij*NBLOCKS_W)+ii];
			if(k==IT_APPLE){
				frct.x += 3 ;	frct.y += 3 ;
				frct.w -= 6 ;	frct.h -= 6;
			}
			SDL_FillRect(dst , &frct , s_colors[k]);
		}
	}	
	
	sprintf(buf , "Score : %d (%d) ",  s_score , s_hiscore);
	GFX_FontPrint(dst, s_fbmp , 16,16,32,buf , 256 , 0 , 0 );
	
	if(SDL_GetTicks() - s_anLastTime1 >= 250){
		SList_SnakeMove(&s_snake);
		
		
		if(	s_snake.first->x < 0 || 
			s_snake.first->y < 0 || 
			s_snake.first->x > NBLOCKS_W-1 || 
			s_snake.first->y > NBLOCKS_H-1 ||
			SList_IsOnSnake(&s_snake , s_snake.first->x , s_snake.first->y , 0) ){
				memset(&ev , 0 , sizeof(SDL_Event));
				//Envoyer un évenement pour retourner au menu
				ev.type = SDL_KEYDOWN;
				ev.key.keysym.sym = SDLK_ESCAPE;
				SDL_PushEvent(&ev);
				
				if(s_hiscore < s_score)
					SaveHiScore(s_score);
			}
		
		if(s_snake.first->x==s_appleX && s_snake.first->y ==s_appleY ){
			SList_Push(&s_snake);	
			AppleRand();
			s_score += 10 ; 
		}	
		s_anLastTime1 = SDL_GetTicks();
	}	
}

void Game_Free()
{
	SList_Free(&s_snake);
}

