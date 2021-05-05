/**
 * @file background.c
 * @brief background
 * @author youssef gharrad
 * @version 0.1
 * @date 05/05/2021 

*/
#include "background.h"

/**
* @brief initialiser_backround
* @param b backround
* @return void

*/
void initialiser_backround (background *b)
{
//b->x_relative=0;
//b->y_relative=-80;
//b->background=NULL;
b->bg=NULL;

b->camera.x=0;
b->camera.y=0;
b->camera.w=1400;
b->camera.h=1050;
//b->background=IMG_Load("bg_final.jpg");
//b->mask=IMG_Load("mask.jpg");
b->bg=IMG_Load("bg_final.jpg");
}


/**
* @brief afficher_background
* @param screen the screen 
* @param b backround
* @return void

*/

void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->bg,&b->camera,screen,NULL);
}

/**
* @brief scrolling_right
* @param b backround
* @param p perso
* @param screen the screen 
* @return void

*/

void scrolling_right (background *b,perso *p,SDL_Surface *screen)
{
	if (b->camera.x<5000)
	{
		//b->x_relative+=p->xvelocity;
		b->camera.x+=p->speedX;
  //  p->rect_relative.x+=p->speedX;

	}
}

/**
* @brief scrolling_left
* @param b backround
* @param p perso
* @param screen the screen 
* @return void

*/
void scrolling_left (background *b,perso *p,SDL_Surface *screen)
{
	if (b->camera.x>0)
	{
		//b->x_relative+=p->xvelocity;
		b->camera.x-=p->speedX;
  //  p->rect_relative.x-=p->speedX;

	}
}
