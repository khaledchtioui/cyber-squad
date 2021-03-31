#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"

void initialiser(Objet tab[], Objet tab2[])
{
  int i;
  char image[20];
  char image2[20];

  for (i = 0; i < 5; i++)
  {
    sprintf(image, "%d.png", i + 1);
    sprintf(image2, "ennemiD/%d.png", i + 1);




    tab[i].img = IMG_Load(image);
    tab[i].pos.x = 0;
    tab[i].pos.y = 200;

    tab2[i].img = IMG_Load(image2);
    tab2[i].pos.x = 0;
    tab2[i].pos.y = 0;


  }
}
void deplacement_objet(SDL_Surface **screen, Objet tab[], Objet tab2[],Objet tab10[], Objet tab20[], int *running, int *i ,int  * k )
{
  SDL_Event event;

  SDL_WaitEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    *running = 0;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
    {
    case SDLK_RIGHT:
      (*i)++;
      tab[0].pos.x +=25;
      if (*i == 5)
        *i = 0;
     SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 255, 255, 255));
      SDL_BlitSurface(tab2[*i].img, NULL, *screen, &(tab[0].pos));
      SDL_BlitSurface(tab20[*k].img, NULL, *screen, &(tab10[0].pos));

      break;
    case SDLK_LEFT:
      (*i)--;
      if (*i <= 0)
        *i = 4;
      tab[0].pos.x -=25;
      SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 255, 255, 255));
      SDL_BlitSurface(tab[*i].img, NULL, *screen, &(tab[0].pos));
      SDL_BlitSurface(tab10[*k].img, NULL, *screen, &(tab10[0].pos));

      break;
      
       case SDLK_d:
      (*k)++;
      tab10[0].pos.x +=25;
      if (*k == 5)
        *k = 0;
      SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 255, 255, 255));
      SDL_BlitSurface(tab2[*i].img, NULL, *screen, &(tab[0].pos));
          SDL_BlitSurface(tab20[*k].img, NULL, *screen, &(tab10[0].pos));

      break;
    case SDLK_q:
      (*k)--;
      if (*k <= 0)
        *k = 4;
      tab10[0].pos.x -=25;
      SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 255, 255, 255));
      SDL_BlitSurface(tab[*i].img, NULL, *screen, &(tab[0].pos));
      SDL_BlitSurface(tab10[*k].img, NULL, *screen, &(tab10[0].pos));

      break;
      
      
      
      
      
      
      
      
    }
  }
  
}

void initialiser2(Objet tab[], Objet tab2[])
{
  int i;
  char image[20];
  char image2[20];

  for (i = 5; i < 10; i++)
  {
    sprintf(image, "%d.png", i + 1);
    sprintf(image2, "ennemiD2/%d.png", i + 1);




    tab[i].img = IMG_Load(image);
    tab[i].pos.x = 0;
    tab[i].pos.y = 200;

    tab2[i].img = IMG_Load(image2);
    tab2[i].pos.x = 0;
    tab2[i].pos.y = 0;


  }
}


      
