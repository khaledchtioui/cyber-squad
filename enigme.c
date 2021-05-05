#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include "enigme.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
void init_enigme(enigme *enig,int ancienne[])
{
    int i;
   // enig->fenetre_enigme=NULL;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    enig->image=NULL;
    enig->posim.x=50;
    enig->posim.y=130;
    enig->post.x=170;
    enig->post.y=180;
    for(i=0;i<6;i++)
    {
       ancienne[i]=0;
    }
}

void remplir_fichier(char fichier_question[])
{
    FILE *fq=NULL;
    fq=fopen(fichier_question,"w");
    if(fq==NULL) printf("erreur de l'ouverture");
    else
    {
	fprintf(fq,"La Coccinelle a ete conçue par Porsche a la demande d Hitler? \nLe tableau le plus cher de l histoire est La Joconde? \nLe verbe positiver ete invente par carrefour? \nUn jour,Charlie Chaplin perdit un concours de sosies de lui-meme? \nMozart etait autrichien? \nle beret est d origine basque? \n");
	fclose(fq);
    }
}
void afficher_enigme(enigme *enig,int *ancienne,char fichier_question[],int *ligne,    SDL_Surface *fenetre_enigme)
{
   FILE *fq=NULL;
   int i,ici=0,taille=200,l;
   char ch[200];
   SDL_Color couleur={0,0,0};
   do
   {  ici=0;
      l=1+random()%6;
  printf("\nvoici notre premier l :%d\n",l);
      for(i=0;i<6;i++)
      {
         if(ancienne[i]==l)
                 {
                    ici=1;
                    break;
                 }
      }
   }while(ici==1);
   for(i=0;i<6;i++)
   {
         if(ancienne[i]==0)
                 {
                    ancienne[i]=l;
                    break;
                 }
   }
   if(ancienne[5]!=0) { 
              	         for(i=0;i<6;i++)
              	         {
                            ancienne[i]=0;
              	         }
                      }
  // enig->fenetre_enigme=SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
   enig->image=IMG_Load("enigme.png");
   enig->police=TTF_OpenFont("labo.ttf",60);
   fq=fopen(fichier_question,"r");
   if(fq==NULL) printf("erreur de l'ouverture");
    else{ 
           (*ligne)=1;
	   while((fgets(ch,taille,fq)!=NULL)&&(*ligne<l))
	        {
	    	    (*ligne)++;
	        }
           enig->texte=TTF_RenderText_Blended(enig->police,ch,couleur);
	   SDL_BlitSurface(enig->image,NULL,fenetre_enigme,&(enig->posim));
	   SDL_BlitSurface(enig->texte,NULL,fenetre_enigme,&(enig->post));
	   SDL_Flip(fenetre_enigme);
	   fclose(fq);
        }
   
}

int solution(int q)
{
int s=0;
    switch(q)
    {
    case 1:
        s=1;
        break;
    case 2:
        s=2;
        break;
    case 3:
        s=1;
        break;
    case 4:
        s=1;
        break;
    case 5:
        s=2;
        break;
    case 6:
        s=2;
        break;
    }
    return s;
}

int resolution(int *affiche)
{
    SDL_Event event;
    int r=0;
    SDL_PollEvent(&event);
    switch(event.type)
    {

    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_v:
            r=1;
	    *affiche=1;
            break;
        case SDLK_f:
            r=2;
	    *affiche=1;
            break;
   
        }
        break;
    }
    return r;
}

void afficher_resultat(enigme *enig,int solution,int resolution,    SDL_Surface *fenetre_enigme)
{
   
    if(solution==resolution)
    {
        enig->image=IMG_Load("youwin.png");
        SDL_BlitSurface(enig->image,NULL,fenetre_enigme,&(enig->posim));
        SDL_Flip(fenetre_enigme);
        //p->score=p->score+20;
    }
    else
    {
        enig->image=IMG_Load("youlost.png");
        SDL_BlitSurface(enig->image,NULL,fenetre_enigme,&(enig->posim));
        SDL_Flip(fenetre_enigme);
        //p->score=p-score-20;
    }
}

void ffree(enigme *enig)
{
    TTF_CloseFont(enig->police);
    TTF_Quit();
    SDL_FreeSurface(enig->image);
    SDL_FreeSurface(enig->texte);
    SDL_Quit();
}
