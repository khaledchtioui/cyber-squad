#include "background.h"

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

void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->bg,&b->camera,screen,NULL);
}

void scrolling_right (background *b,perso *p,SDL_Surface *screen)
{
	if (b->camera.x<5000)
	{
		//b->x_relative+=p->xvelocity;
		b->camera.x+=p->speedX;
  //  p->rect_relative.x+=p->speedX;

	}
}

void scrolling_left (background *b,perso *p,SDL_Surface *screen)
{
	if (b->camera.x>0)
	{
		//b->x_relative+=p->xvelocity;
		b->camera.x-=p->speedX;
  //  p->rect_relative.x-=p->speedX;

	}
}
