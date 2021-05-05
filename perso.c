/**
 * @file perco.c
 * @brief perso 
 * @author khaled chtioui
 * @version 0.1
 * @date 05/05/2021 

*/

#include "perso.h"
#define GRAVITY 9.8

#define MAX_JUMP_SPEED 20
#define MAX_SPEED 17


/**
* @brief initialiser_perso
* @param p perso
* @return void 
*/


void initialiser_perso (perso *p){
    int i,j;
    char nomFich[60];

  /*  *Load(nomFich);
    }
    
    */
 /*  
    }
    */
     p->viehero.nbre_vie=2;
  p->viehero.imagevie=IMG_Load("vie1.png");
   p->viehero.posvie.x=16;
   p->viehero.posvie.y=17;
    
    
    
    
    
     p->score.nbre_score=0;
 
   p->score.posscore.x=100;
   p->score.posscore.y=11;
        
    
    
    
    
    for ( i = 0; i < 11; i++)
    {
        sprintf(nomFich,"per/%d.png",i+50);
        p->runright[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 11; i++)
    {
        sprintf(nomFich,"per/%d.png",i+60);
        p->runleft[i]=IMG_Load(nomFich);
    }
   /* for ( i = 0; i < 9; i++)
    {
        
    }*/
p->rect.x=0;
p->rect.y=700; //300
//p->rect_relative.x=0;
//p->rect_relative.y=150; //
p->rect.w=138;
p->rect.h=233;
p->speedX=5;
p->speedY=0;
p->frame=p->runright[0];
p->fr=0;

    
}/*
void initialiser_perso2 (perso *p){
    int i,j;
    char nomFich[60];

  /*  
    }
    *
    for ( i = 0; i < 11; i++)
    {
        sprintf(nomFich,"per2/%d.png",i+50);
        p->runright[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 11; i++)
    {
        sprintf(nomFich,"per2/%d.png",i+60);
        p->runleft[i]=IMG_Load(nomFich);
    }
   /* for ( i = 0; i < 9; i++)
    {
       
    }*
p->rect.x=0;
p->rect.y=150; //300
//p->rect_relative.x=0;
//p->rect_relative.y=150; //
p->rect.w=138;
p->rect.h=233;
p->speedX=5;
p->speedY=0;
p->frame=p->runright[0];
p->fr=0;

    
}
*/
/**
* @brief afficher_perso
* @param screen the screen
* @param p perso
* @return void 
*/
void afficher_perso (perso *p,SDL_Surface *screen)
{
  SDL_BlitSurface(p->frame,NULL,screen,&p->rect);
}



/**
* @brief animation_right

* @param p perso
* @return void 
*/





void animation_right (perso *p)
{
//if (p->speedX<7)
//{
    if ((p->fr<0)||(p->fr>9))
    {
        p->fr=0;
    }
    p->fr++;
   // 
    p->frame=p->runright[p->fr];
//}

}


/**
* @brief animation_left

* @param p perso
* @return void 
*/



void animation_left (perso *p){
//if (p->speedX>7)
//{
    if ((p->fr<0)||(p->fr>9))
    {
        p->fr=0;
    }
    p->fr++;

        p->frame=p->runleft[p->fr];
//}
//
//}

}


/**
* @brief mouvementright

* @param p perso
* @return void 
*/

void mouvementright (perso *p)
{
  

if (p->rect.x<1200)
{

p->rect.x+=p->speedX;

}
}


/**
* @brief mouvementleft

* @param p perso
* @return void 
*/


void mouvementleft (perso *p)
{
  
//if (p->speedX=MAX_SPEED)
	//p->speedX=MAX_SPEED;
if (p->rect.x>0)
{

p->rect.x-=p->speedX;
//p->rect_relative.x-=p->speedX;

}


}



/**
* @brief jumpright

* @param p perso
* @return void 
*/



void jumpright (perso *p)
{


	//p->speedX=MAX_JUMP_SPEED;
if (p->rect.x<700)
{


p->rect.x+=p->speedX;
//p->rect_relative.x+=p->speedX;
}
}


/**
* @brief jumpleft

* @param p perso
* @return void 
*/



void jumpleft (perso *p)
{

if (p->rect.x>0)
{
p->rect.x-=p->speedX;
//p->rect_relative.x-=p->speedX;
}
}

/**
* @brief initialiser_input 
* @param I Input
* @return void 
*/

void initialiser_input (Input *I)
{
I->left=0;
I->right=0;
I->down=0;
I->jump=0;
//I->acction=0;
}




/**
* @brief afficher_vie_hero
* @param screen the screen
* @param p perso
* @return void 
*/



void afficher_vie_hero(perso* p,SDL_Surface *screen)
{

   if(p->viehero.nbre_vie==3)
{   
    SDL_BlitSurface(p->viehero.imagevie,NULL,screen,&p->viehero.posvie);
}
  
   if(p->viehero.nbre_vie==2)
{    
     p->viehero.imagevie=IMG_Load("vie2.png");
     SDL_BlitSurface(p->viehero.imagevie,NULL,screen,&p->viehero.posvie);
}

   if(p->viehero.nbre_vie==1)

{    
     p->viehero.imagevie=IMG_Load("vie3.png");
     SDL_BlitSurface(p->viehero.imagevie,NULL,screen,&p->viehero.posvie);
}

if(p->viehero.nbre_vie<=0)

{    
     p->viehero.imagevie=IMG_Load("vie4.png");
     SDL_BlitSurface(p->viehero.imagevie,NULL,screen,&p->viehero.posvie);
}


}



/**
* @brief afficher_score_hero
* @param screen the screen
* @param h perso
* @return void 
*/



void afficher_score_hero(perso h,SDL_Surface *screen)
{ 
   TTF_Init();
   TTF_Font *police=NULL;
   SDL_Color couleur={200,0,0};
   police=TTF_OpenFont("arial.ttf",20);
   
   char score[20];
   sprintf(score, "Score : %d",h.score.nbre_score); 

  
  // if(h.score.nbre_score==i)
  //{
     h.score.imagescore=TTF_RenderText_Blended(police,score,couleur);
     SDL_BlitSurface(h.score.imagescore,NULL,screen,&h.score.posscore);
  //}

}


/**
* @brief incrementer_scorehero

* @param h perso
* @return void 
*/


int incrementer_scorehero(perso h)
{
     h.score.nbre_score++;

return   h.score.nbre_score;
}



/**
* @brief decrementer_scorehero

* @param h perso
* @return int 
*/


int decrementer_scorehero(perso h)
{
     h.score.nbre_score--;

return   h.score.nbre_score;
}
/**
* @brief incrementer_viehero

* @param h perso
* @return int 
*/
int incrementer_viehero(perso h)
{
   h.viehero.nbre_vie++;


return  h.viehero.nbre_vie;
}
/**
* @brief decrementer_viehero

* @param h perso
* @return int 
*/

int decrementer_viehero(perso h)
{
  
   h.viehero.nbre_vie--;

return  h.viehero.nbre_vie;
}



/**
* @brief gagner
* @param poscoin sdl_rect
* @param h perso
* @return int 
*/


int gagner(perso h,SDL_Rect poscoin)
{
   int gagner;

  if((h.rect.x+h.rect.w<poscoin.x)||(h.rect.x>poscoin.x+poscoin.w)||(h.rect.y+h.rect.h<poscoin.y)||(h.rect.y>poscoin.y+poscoin.h))

    gagner=0;
 
   else 
   
      {
          gagner=1;
      }

return gagner;


}

















