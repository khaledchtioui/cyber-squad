#include "perso.h"
#include "background.h"
#include "load.h"
#include "time.h"
#include "minimap.h"
#include "collision.h"
#include "ennemi.h"
#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 30





void load(SDL_Surface *screen)
{


int ii =2 ; 
  SDL_Rect posJoueurABS;
 // posJoueurABS.x = 1281;
 // posJoueurABS.y = 0;

SDL_Surface *coin,*gameover;
gameover=IMG_Load("Game over.jpg");
coin=IMG_Load("coin.png");
SDL_Rect poscoin   ,poscoinn,ppp;
ppp.x=0;
ppp.y=0;
poscoin.x=350;
poscoin.y=670;
poscoinn.y=670;
float t =1;
//SDL_Init(SDL_INIT_VIDEO);
//SDL_Surface *screen;
SDL_Surface *back,*mask;
minimap m;
back=IMG_Load("background.png");
//screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024);
 Mix_Music *musique; //Création du pointeur de type Mix_Music
   musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
Mix_PlayMusic(musique, -1);
//SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
//SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
mask=IMG_Load("mask.png");
background b;
Input I,I2;
perso p ,p2;
  enemie E,EE;
SDL_Event event;
initialiser_perso (&p);
//initialiser_perso2 (&p2);
initialiser_input (&I);
initialiser_input (&I2);
initialiser_backround (&b);
 init_enemie( & E);
  init_enemie( & EE);
init_map(&m);
bool running=true;



SDL_EnableKeyRepeat(200,0);


while(running)
{




 


while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		//
		case SDL_QUIT:
		// (*action)=0;
			running=false;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			/*	
			break; */
			case SDLK_LEFT :
				I.left=1;



      		break;
      		case SDLK_RIGHT :
				I.right=1;
				


      		break;
			case SDLK_SPACE :
				I.jump=1;
				if(p.rect.y==525)//
				p.speedY = -110;


			break; 
				case SDLK_p   : 
			p.speedX=MAX_SPEED;
			t=2  ; 
			
			
			
			
			break; 
			/*;*/
				case SDLK_q :
				I2.left=1;



      		break;
      		case SDLK_d :
				I2.right=1;
				


      		break;
			case SDLK_z :
				I2.jump=1;
				if(p2.rect.y==330)//collision with ground
								p2.speedY = -60;
			 //collision with stairs -1 au lieu de -30
					//p.speedX=MAX_JUMP_SPEED;
			break; 
			 
			case SDLK_b   : 
			p2.speedX=MAX_SPEED;
			break; 
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
			break;
			case SDLK_LEFT :
				I.left=0;
      		break;
			case SDLK_SPACE :
			I.jump=0; 

			break;
			case SDLK_p   : 
			p.speedX=5;
			t=1;
			break; 
			//
		//	break;
		
		
		case SDLK_d:
				I2.right=0;
			break;
			case SDLK_q :
				I2.left=0;
      		break;
			case SDLK_z :
			I2.jump=0; 

			break;
			case SDLK_b   : 
			p2.speedX=5;
			break; 
			//
		//	break;
			}
		break;
		
		}//
	}

 posJoueurABS.x = p.rect.x + b.camera.x;
  posJoueurABS.y = p.rect.y + b.camera.y;
 if (I.right==1)
{
	//p.speedX+=1;
	animation_right(&p);
	if    ( (I.jump==0)&& ((p.rect.x<700)||((b.camera.x>5000)&&(b.camera.x<6070))) )  // &&   (  collision_parfaite_right(mask,posJoueurABS)==0)  )
	{
	
	
	

	mouvementright (&p);
	

	
	
	
	
	}
	 else if (I.jump==1) // &&   (  collision_parfaite_right(mask,posJoueurABS)==0)  )
	 {jumpright (&p);}
         scrolling_right (&b,&p,screen);
         
         
}
else if (I.left==1 )
{
	//p.speedX+=SPEED  ;
	animation_left(&p)     ;
	if     ((I.jump==0)&& ((p.rect.x>0)||((b.camera.x>0)&&(b.camera.x<1400))))// &&  (  collision_parfaite_right(mask,posJoueurABS)==0)  )
	
	mouvementleft (&p);
	else if (I.jump==1) jumpleft (&p);
	scrolling_left (&b,&p,screen);

}

 if (I2.right==1)
{
	//p.speedX+=1;
	animation_right(&p2);
	if (I2.jump==0) mouvementright (&p2);
	 else if (I2.jump==1) jumpright (&p2);
         scrolling_right (&b,&p2,screen);
}
else if (I2.left==1 )
{
	//p.speedX+=SPEED  ;
	animation_left(&p2)     ;
	if (I2.jump==0)  mouvementleft (&p2);
	else if (I2.jump==1) jumpleft (&p2);
	scrolling_left (&b,&p2,screen);

}
/*else if (I.left==0 && I.down==0 && I.jump==0 && I.right==0 )
{
	animation_stable(&p);
}*/
p.speedY+=GRAVITY;
 //if (collision_parfaite_down(mask, posJoueurABS)==0) 
 p.rect.y += p.speedY;
 //p.rect_relative.y += p.speedY;
 if(p.rect.y >= 525)
 	 {
 		 p.rect.y= 525;
		// p.rect_relative.y= ground;
 		 p.speedY = 0;
         }
    //
	
	
	
	p2.speedY+=GRAVITY;
	
 p2.rect.y += p2.speedY;
 //p.rect_relative.y += p.speedY;
 if(p2.rect.y >= 330)
 	 {
 		 p2.rect.y= 330;
		// p.rect_relative.y= ground;
 		 p2.speedY = 0;
         }

                   if (  collision_parfaite_right(mask,posJoueurABS)!=0) 
                   {
                   
                   printf("\ncollision en right");
                   
                   }
                    if (  collision_parfaite_down(mask,posJoueurABS)!=0) 
                   {
                   
                   printf("\ncollision en bas");
                   
                   }

	afficher_background(screen,&b);
	afficher_perso (&p,screen);
	     afficher_vie_hero(&p,screen);
	      afficher_score_hero(p,screen) ;
	//SDL_Flip(screen);
	//SDL_Delay(16);
	MAJMinimap(p.rect ,&m, b.camera, 10);
        afficherminimap(m,screen);

	timer(screen  ,t) ; 
	//if(b.camera.x<600)
	//{
	E.pos.x=EE.pos.x-b.camera.x         ;
    afficher_enemie( & E, screen);
    animate_enemie( & E);
    if ((((E.pos.x - p.rect.x) < 200) && ((E.pos.x - p.rect.x) > -200))) 
    {
      deplacerIA( & E, p.rect);
    } else  
     {
    
    
      deplacer( & E);
    }
     if (collision(E.pos,p.rect)==1)
    {
p.viehero.nbre_vie= decrementer_viehero( p)  ;
    }
    
    
    
    
   // }

    	
    	    poscoinn.x=poscoin.x - b.camera.x  ; 
    	
    SDL_BlitSurface(coin,NULL,screen,&poscoinn);
    
    
     
 
    
if( gagner(p,poscoinn)    ) 
 {p.score.nbre_score=incrementer_scorehero(p)    ;
 coin=NULL;
 poscoin.x=11111;
 }




if((p.viehero.nbre_vie==0) )
{


 ii=enigmee(screen)  ;
 if (ii==1)
  {	
         initialiser_input (&I)   ;
    p.rect.x-=221 ;
  p.viehero.nbre_vie=1;
SDL_Delay(1006);
  
  
  }
  else {
  
  printf("\nGame over ") ;

      SDL_BlitSurface(gameover,NULL,screen,&ppp);

      	SDL_Flip(screen);
            	SDL_Delay(5000);

  return 0   ; 
  }

}









	//afficher_perso (&p2,screen);
	SDL_Flip(screen);
	SDL_Delay(16);
}
TTF_Quit();




}
