#include "menu.h"
#include "perso.h"
#include "background.h"
#include "load.h"




void menu(SDL_Surface *ecran,Mix_Music *musique)
{


    SDL_Surface *background = NULL,*playy=NULL,*settingg=NULL,*quit;
    SDL_Rect positionbackground,positionplay,positionsetting,positionquit,positionClic;
    SDL_Event event;


    Mix_AllocateChannels(3);
    Mix_Volume(1, MIX_MAX_VOLUME/2);
    Mix_Chunk *son;
    son = Mix_LoadWAV("BREF.wav");

    Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);

    int continuer = 1,x=1,y=1;

    background = IMG_Load("backgroundmenu.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    playy=IMG_Load("boutton_play.png");
    positionplay.x=512.5;
    positionplay.y=366;

    settingg=IMG_Load("boutton_setting.png");
    positionsetting.x=512.5;
    positionsetting.y=496;

    quit=IMG_Load("boutton_exit.png");
    positionquit.x=512.5;
    positionquit.y=626;

// txtee(ecran)         ;
 animation(ecran)               ;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        
        
         
        
        
        
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                    case SDLK_ESCAPE: // Veut arr�ter le jeu
                        continuer = 0;
                        break;
		   case SDLK_UP :
			if(x==1)

				{
					playy=IMG_Load("boutton_play.png");
					quit=IMG_Load("exit_gr.png");
					SDL_BlitSurface(quit, NULL, ecran, &positionquit);



					Mix_PlayChannel(1, son, 0);
					x=2;y=1;

				}

			else  if(x==2)
				{
					quit=IMG_Load("boutton_exit.png");
					settingg=IMG_Load("setting_gr.png");

					Mix_PlayChannel(1, son, 0);
					x=3;y=3;
				}
			else if(x==3)
					{
					settingg=IMG_Load("boutton_setting.png");
					playy=IMG_Load("play_gr.png");
					Mix_PlayChannel(1, son, 0);

					x=1;y=2;
					}
			break;
				case SDLK_DOWN :
			if(y==1)//quit->play

				{
					quit=IMG_Load("boutton_exit.png");
					playy=IMG_Load("play_gr.png");
					SDL_BlitSurface(quit, NULL, ecran, &positionplay);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;//play-->exit

				}//play->setting

			else  if(y==2)
				{	playy=IMG_Load("boutton_play.png");

					settingg=IMG_Load("setting_gr.png");
					SDL_BlitSurface(settingg, NULL, ecran, &positionsetting);
					Mix_PlayChannel(1, son, 0);
					y=3;x=3;//setting-->play
				}
			else if(y==3)//setting->quit
					{
					settingg=IMG_Load("boutton_setting.png");
					quit=IMG_Load("exit_gr.png");
					SDL_BlitSurface(playy, NULL, ecran, &positionquit);
					Mix_PlayChannel(1, son, 0);
					y=1;x=2;//quitt-->setting
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					{continuer=0;}
					else if(y==2)
					{play(ecran,son,musique);}
					else if (y==3)
					{setting(ecran,son,musique);}
			break;

                    case SDLK_j:
                        play(ecran,son,musique);
                        break;
                    case SDLK_o:
                        setting(ecran,son,musique);
                        break;
                         case SDLK_q:
                        continuer=0;
                        break;
                }
                break;
                case SDL_MOUSEMOTION  : 
               if(event.button.x >positionplay.x && event.button.x <positionplay.x+playy->w && event.button.y >positionplay.y&& event.button.y <positionplay.y+playy->h)
               {
               
                                        quit=IMG_Load("boutton_exit.png");
					playy=IMG_Load("play_gr.png");
					SDL_BlitSurface(quit, NULL, ecran, &positionplay);
					Mix_PlayChannel(1, son, 0);
               
               }
                  else if(event.button.x >positionsetting.x && event.button.x <positionsetting.x+playy->w && event.button.y >positionsetting.y&& event.button.y <positionsetting.y+settingg->h)
                
                {
                
                playy=IMG_Load("boutton_play.png");

					settingg=IMG_Load("setting_gr.png");
					SDL_BlitSurface(settingg, NULL, ecran, &positionsetting);
					Mix_PlayChannel(1, son, 0);
                
                
                
                }
                
                 else if(event.button.x >positionquit.x && event.button.x <positionquit.x+quit->w && event.button.y >positionquit.y&& event.button.y <positionquit.y+quit->h)
                {
                settingg=IMG_Load("boutton_setting.png");
					quit=IMG_Load("exit_gr.png");
					SDL_BlitSurface(playy, NULL, ecran, &positionquit);
					Mix_PlayChannel(1, son, 0);
                
                }
                else 
                {
                                      quit=IMG_Load("boutton_exit.png");
                                settingg=IMG_Load("boutton_setting.png");
                                playy=IMG_Load("boutton_play.png");
                					SDL_BlitSurface(quit, NULL, ecran, &positionplay);
                					SDL_BlitSurface(settingg, NULL, ecran, &positionsetting);
                					SDL_BlitSurface(playy, NULL, ecran, &positionquit);
                
                }
                
                break ; 
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.y;

                    if(event.button.x >512.5 && event.button.x <887.5 && event.button.y >366&& event.button.y <488)
                            {play(ecran,son,musique);}

                     else if(event.button.x >512.5&& event.button.x <887.5 && event.button.y >496&& event.button.y <618)
                            {setting(ecran,son,musique);}

                     else if (event.button.x >626&& event.button.x <1001 && event.button.y >626&& event.button.y <748)
                                {continuer=0; }

        		}

		break;
		}//switch


        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(playy, NULL, ecran, &positionplay);
        SDL_BlitSurface(settingg, NULL, ecran, &positionsetting);
        SDL_BlitSurface(quit, NULL, ecran, &positionquit);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(playy);
    SDL_FreeSurface(settingg);
    SDL_FreeSurface(quit);
    SDL_Quit();

}
void play(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{
    SDL_Surface *background=NULL,*newgame = NULL, *continuer = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positioncontinuer,positionClic,positionnewgame;
    SDL_Event event;
    int continuee = 1,x=1,y=1;



    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    newgame=IMG_Load("newgame_boutton.png");
    positionnewgame.x = 500;
    positionnewgame.y = 550;

    continuer=IMG_Load("Continue_boutton.png");
    positioncontinuer.x = 500;
    positioncontinuer.y = 700;

    back=IMG_Load("darr dhawya.png");
    positionback.x = 600;
    positionback.y = 850;



while (continuee)
    {//while
        SDL_WaitEvent(&event);
        switch(event.type)
        {//switch 1
            case SDL_QUIT:
                continuee = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {//switch 2
                    case SDLK_ESCAPE: // Veut arr�ter le jeu
                continuee = 0;
                        break;
		/*   case SDLK_LEFT :
			
                        break;
                    */

                }//switch2
                break;
       case SDL_MOUSEMOTION:
       
       if((event.motion.x<positionnewgame.x+newgame->w)&&(event.motion.x>positionnewgame.x)&&(event.motion.y<positionnewgame.y+newgame->h)&&(event.motion.y>positionnewgame.y))

         { newgame =IMG_Load("Newgama_gr.png");
SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame); SDL_Flip(ecran);       
        }
       else if ((event.motion.x<positioncontinuer.x+continuer->w)&&(event.motion.x>positioncontinuer.x)&&(event.motion.y<positioncontinuer.y+continuer->h)&&(event.motion.y>positioncontinuer.y))
{
          continuer =IMG_Load("continuer_gr.png");
SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer); SDL_Flip(ecran);      

}    

     else if ((event.motion.x<positionback.x+back->w)&&(event.motion.x>positionback.x)&&(event.motion.y<positionback.y+back->h)&&(event.motion.y>positionback.y))
{
          back =IMG_Load("darr ka7la.png");
SDL_BlitSurface(back, NULL, ecran, &positionback); SDL_Flip(ecran);      

} 

      
  else 
  {
      newgame=IMG_Load("newgame_boutton.png");
      continuer=IMG_Load("Continue_boutton.png");    back=IMG_Load("darr dhawya.png");
          SDL_Flip(ecran);
  }             
           
           
             
             
             
                   
                break;
                
                       case SDL_MOUSEBUTTONDOWN :
       
       if((event.motion.x<positionnewgame.x+newgame->w)&&(event.motion.x>positionnewgame.x)&&(event.motion.y<positionnewgame.y+newgame->h)&&(event.motion.y>positionnewgame.y))

         { 
        
         
         load(ecran)     ;
         
         
         SDL_Flip(ecran);       
        }
       else if ((event.motion.x<positioncontinuer.x+continuer->w)&&(event.motion.x>positioncontinuer.x)&&(event.motion.y<positioncontinuer.y+continuer->h)&&(event.motion.y>positioncontinuer.y))
{
          continuer =IMG_Load("continuer_gr.png");
SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer); SDL_Flip(ecran);      

}    

     else if ((event.motion.x<positionback.x+back->w)&&(event.motion.x>positionback.x)&&(event.motion.y<positionback.y+back->h)&&(event.motion.y>positionback.y))
{
          back =IMG_Load("darr ka7la.png");
SDL_BlitSurface(back, NULL, ecran, &positionback); SDL_Flip(ecran);      

} 

      
  else 
  {
      newgame=IMG_Load("newgame_boutton.png");
      continuer=IMG_Load("Continue_boutton.png");    back=IMG_Load("darr dhawya.png");
          SDL_Flip(ecran);
  }             
           
           
             
             
             
                   
                break;
                
                
                
                
                
                
                
                
                
                
			
			
			
			
			
			
			
			
			
        	}//switch

        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
        SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }//while

    SDL_FreeSurface(background);
    SDL_FreeSurface(newgame);
    SDL_FreeSurface(continuer);
    SDL_FreeSurface(back);

    SDL_Quit();
}//quiiter
void choose(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{//void
    SDL_Surface *background=NULL,*joueur1 = NULL, *joueur2 = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positionjoueur1,positionClic,positionjoueur2;
    SDL_Event event;


    int continuee = 1,y=1,x=1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    joueur1=IMG_Load("joueur1.png");
    positionjoueur1.x = 190;
    positionjoueur1.y = 220;

    joueur2=IMG_Load("joueur2.png");
    positionjoueur2.x = 875;
    positionjoueur2.y = 220;

    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;



while (continuee)
    {//while
        SDL_WaitEvent(&event);
        switch(event.type)
        {//switch 1
            case SDL_QUIT:
                continuee = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {//switch 2
			case SDLK_LEFT :
			if(x==1)

				{
					back=IMG_Load("Back_boutton.png");
					joueur2=IMG_Load("joueur2_gr.png");
					SDL_BlitSurface(joueur2, NULL, ecran, &positionjoueur2);
					Mix_PlayChannel(1, son, 0);

					x=2;y=1;

				}

			else  if(x==2)
				{
					joueur2=IMG_Load("joueur2.png");
					joueur1=IMG_Load("joueur1_gr.png");
					SDL_BlitSurface(joueur1, NULL, ecran, &positionjoueur1);
					Mix_PlayChannel(1, son, 0);

					x=3;y=3;
				}
			else if(x==3)
					{
					joueur1=IMG_Load("joueur1.png");
					back=IMG_Load("back_gr.png");
					Mix_PlayChannel(1, son, 0);
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					x=1;y=2;
					}
			break;
				case SDLK_RIGHT :
			if(y==1)

				{
					joueur2=IMG_Load("joueur2.png");
					back=IMG_Load("back_gr.png");

					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;//

				}//

			else  if(y==2)
				{
					back=IMG_Load("Back_boutton.png");

					joueur1=IMG_Load("joueur1_gr.png");
					SDL_BlitSurface(joueur1, NULL, ecran, &positionjoueur1);
					Mix_PlayChannel(1, son, 0);
					y=3;x=3;//
				}
			else if(y==3)//
					{
					joueur1=IMG_Load("joueur1.png");
					joueur2=IMG_Load("joueur2_gr.png");
					SDL_BlitSurface(joueur2, NULL, ecran, &positionjoueur2);
					Mix_PlayChannel(1, son, 0);
					y=1;x=2;//
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					{}
					else if(y==2)
					{play(ecran,son,musique);}
					else if (y==3)
					{choose(ecran,son,musique);}
			break;
                    case SDLK_ESCAPE: // Veut arr�ter le jeu
                        play(ecran,son,musique);
                        break;
                    case SDLK_KP1: // Demande resolution
                        //jouer1(ecran);
                        break;
                    case SDLK_KP2: // Demande contols
                        //jouer2(ecran);
                        break;


                }//switch2
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {//if case
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;

                    if(event.button.x >270&& event.button.x <380 && event.button.y >425&& event.button.y <570)
                            {/*jouer1(ecran);*/}

                     else if(event.button.x >1045&& event.button.x <1235 && event.button.y >315&& event.button.y <550)
                            {/*jouer2(ecran);*/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {play(ecran,son,musique);}

			}//if case
			break;
        	}//switch

        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(joueur1, NULL, ecran, &positionjoueur1);
        SDL_BlitSurface(joueur2, NULL, ecran, &positionjoueur2);
        SDL_BlitSurface(back, NULL, ecran, &positionback);


        SDL_Flip(ecran);
    }//while

    SDL_FreeSurface(background);
    SDL_FreeSurface(joueur1);
    SDL_FreeSurface(joueur2);
    SDL_FreeSurface(back);

    SDL_Quit();
}
void setting(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{//void
    SDL_Surface *background=NULL,*resoluton = NULL, *control = NULL, *sound = NULL,*home=NULL,*plus=NULL,*moins=NULL,*back=NULL;
    SDL_Rect positionresoluton,positioncontrols,positionsound,positionbackground,positionhome,positionback,positionClic,positionplus,positionmoins;
    SDL_Event event;
    int continuer = 1,x=1,y=1,i=1;

    
    
    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    resoluton=IMG_Load("full screen dhawya.png");
    positionresoluton.x = 440;
    positionresoluton.y = 640;

    sound=IMG_Load("son ma7lool dhwya.png");
    positionsound.x = 440;
    positionsound.y = 800;

   /* control=IMG_Load("Contols_boutton.png");
    positioncontrols.x = 530;
    positioncontrols.y = 310;
*/
plus=IMG_Load("augmenter_volume.png");
    positionplus.x = 835;
    positionplus.y = 500;

moins=IMG_Load("diminuer_volume.png");
    positionmoins.x = 405;
    positionmoins.y = 500;

back=IMG_Load("diminuer_gr.png");
    positionback.x = 46;
    positionback.y = 10;



    home=IMG_Load("darr dhawya.png");
    positionhome.x = 800;
    positionhome.y = 800;

int a = 0   ; 

while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE  : 
                
                                continuer = 0;
                
                break ;
			

        	}
        	break;
        	
        	
        	case SDL_MOUSEBUTTONDOWN :
        	if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x<positionresoluton.x+resoluton->w)&&(event.motion.x>positionresoluton.x)&&(event.motion.y<positionresoluton.y+resoluton->h)&&(event.motion.y>positionresoluton.y))
        	{
        
                     i++  ; 
       if (i%2==0) 
       
       
        	    ecran = SDL_SetVideoMode(1400, 1050,32, SDL_FULLSCREEN| SDL_DOUBLEBUF);
        else
        	        	    ecran = SDL_SetVideoMode(1400, 1050,32, SDL_HWSURFACE| SDL_DOUBLEBUF);
        	
        	}
        	
        	
        	//break ; 
        	else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x<positionhome.x+home->w)&&(event.motion.x>positionhome.x)&&(event.motion.y<positionhome.y+home->h)&&(event.motion.y>positionhome.y))
 {
 
                 continuer = 0;
 
 }
 //break ; 
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x<positionplus.x+plus->w)&&(event.motion.x>positionplus.x)&&(event.motion.y<positionplus.y+plus->h)&&(event.motion.y>positionplus.y))
 {
 
      Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME*4);
 }
 
   if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x<positionmoins.x+moins->w)&&(event.motion.x>positionmoins.x)&&(event.motion.y<positionmoins.y+moins->h)&&(event.motion.y>positionmoins.y))      	
        	{
        	
        	
         Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);Mix_VolumeMusic(MIX_MAX_VOLUME/4);
        	
        	
        	}
        	
        if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x<positionsound.x+sound->w)&&(event.motion.x>positionsound.x)&&(event.motion.y<positionsound.y+sound->h)&&(event.motion.y>positionsound.y)) 	
        	
        	{
        	if(a==0)
					{Mix_PauseMusic();a=1;}
						else if(a==1){
						Mix_ResumeMusic();
							a=0;}
        	
        	
        	}
        	
        	
        	
        	
        	
		
case SDL_MOUSEMOTION:
if((event.motion.x<positionresoluton.x+resoluton->w)&&(event.motion.x>positionresoluton.x)&&(event.motion.y<positionresoluton.y+resoluton->h)&&(event.motion.y>positionresoluton.y))
{
   if(i%2==0)
 resoluton=IMG_Load("full screen ka7la.png");
 else 
  resoluton=IMG_Load("1400 1050 ka7la.png");
 
 SDL_BlitSurface(resoluton, NULL, ecran, &positionresoluton);
 SDL_Flip(ecran);

}


else if((event.motion.x<positionmoins.x+moins->w)&&(event.motion.x>positionmoins.x)&&(event.motion.y<positionmoins.y+moins->h)&&(event.motion.y>positionmoins.y))

{
moins=IMG_Load("diminuer_gr.png");
SDL_BlitSurface(moins, NULL, ecran, &positionmoins); SDL_Flip(ecran);
    // resoluton=IMG_Load("full screen dhawya.png");
}


else if((event.motion.x<positionplus.x+plus->w)&&(event.motion.x>positionplus.x)&&(event.motion.y<positionplus.y+plus->h)&&(event.motion.y>positionplus.y))
{
plus=IMG_Load("augmenter_gr.png");
 SDL_BlitSurface(plus, NULL, ecran, &positionplus); SDL_Flip(ecran);
   // resoluton=IMG_Load("full screen dhawya.png");
}
else if((event.motion.x<positionhome.x+plus->w)&&(event.motion.x>positionhome.x)&&(event.motion.y<positionhome.y+plus->h)&&(event.motion.y>positionhome.y))
{
    home=IMG_Load("darr ka7la.png");
 SDL_BlitSurface(home, NULL, ecran, &positionhome); SDL_Flip(ecran);
   // resoluton=IMG_Load("full screen dhawya.png");
}
else if ((event.motion.x<positionsound.x+sound->w)&&(event.motion.x>positionsound.x)&&(event.motion.y<positionsound.y+sound->h)&&(event.motion.y>positionsound.y))
{        if(a==1)
 sound=IMG_Load("son ak.png");
 else 
  sound=IMG_Load("couper_gr.png");
 SDL_BlitSurface(home, NULL, ecran, &positionhome); SDL_Flip(ecran);

}
else 
{
    background=IMG_Load("background.png");
   
   
   if(i%2==1)
    resoluton=IMG_Load("full screen dhawya.png");
    else 
        resoluton=IMG_Load("1400 1050 dhawya.png");
        if(a==0)
    sound=IMG_Load("son ma7lool dhwya.png");
    else
        sound=IMG_Load("couper_son.png");
    
    plus=IMG_Load("augmenter_volume.png");
    moins=IMG_Load("diminuer_volume.png");  
    back=IMG_Load("diminuer_gr.png");
    home=IMG_Load("darr dhawya.png");

}
break ;	
	





		


}//switch







        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(resoluton, NULL, ecran, &positionresoluton);
        SDL_BlitSurface(control, NULL, ecran, &positioncontrols);
        SDL_BlitSurface(sound, NULL, ecran, &positionsound);
        SDL_BlitSurface(home, NULL, ecran, &positionhome);
        SDL_BlitSurface(plus, NULL, ecran, &positionplus);
        SDL_BlitSurface(moins, NULL, ecran, &positionmoins);

        SDL_Flip(ecran);
    }

  /*SDL_FreeSurface(background);
    SDL_FreeSurface(resoluton);
    SDL_FreeSurface(control);
    SDL_FreeSurface(sound);
    SDL_FreeSurface(back);
*/
    //SDL_Quit();


}
/*
void resolution(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{//void
    SDL_Surface *background=NULL,*resoluton_1 = NULL, *resoluton_2 = NULL, *resoluton_3 = NULL,*back=NULL;
    SDL_Rect positionresoluton_1,positionresoluton_2,positionresoluton_3,positionbackground,positionback,positionClic;
    SDL_Event event;
    int FL,continuer = 1,y=1,x=1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    resoluton_1=IMG_Load("800x600.png");
    positionresoluton_1.x = 100;
    positionresoluton_1.y = 310;

    resoluton_2=IMG_Load("1280x720.png");
    positionresoluton_2.x = 958;
    positionresoluton_2.y = 310;

    resoluton_3=IMG_Load("1366x768.png");
    positionresoluton_3.x = 530;
    positionresoluton_3.y = 310;



    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;



while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {case SDLK_LEFT :
			if(x==1)

				{
					back=IMG_Load("Back_boutton.png");
					resoluton_2=IMG_Load("1280x720_gr.png");
					SDL_BlitSurface(resoluton_2, NULL, ecran, &positionresoluton_2);
					Mix_PlayChannel(1, son, 0);
					x=2;y=1;

				}



			else  if(x==2)
				{
					resoluton_2=IMG_Load("1280x720.png");
					resoluton_3=IMG_Load("1366x768_gr.png");
					SDL_BlitSurface(resoluton_3, NULL, ecran, &positionresoluton_3);
					Mix_PlayChannel(1, son, 0);
					x=3;y=4;
				}

			else if(x==3)
					{
					resoluton_3=IMG_Load("1366x768.png");
					resoluton_1=IMG_Load("800x600_gr.png");
					SDL_BlitSurface(resoluton_1, NULL, ecran, &positionresoluton_1);
					Mix_PlayChannel(1, son, 0);
					x=4;y=3;
					}
			else if(x==4)
					{
					resoluton_1=IMG_Load("800x600.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					x=1;y=2;
					}
			break;
				case SDLK_RIGHT :
			if(y==1)

				{
					resoluton_2=IMG_Load("1280x720.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;

				}

			else  if(y==2)
				{
					back=IMG_Load("Back_boutton.png");
					resoluton_1=IMG_Load("800x600_gr.png");
				 	SDL_BlitSurface(resoluton_1, NULL, ecran,&positionresoluton_1);
					Mix_PlayChannel(1, son, 0);

					y=3;x=4;
				}
			else if(y==3)
					{
					resoluton_1=IMG_Load("800x600.png");
					resoluton_3=IMG_Load("1366x768_gr.png");
					SDL_BlitSurface(resoluton_3, NULL, ecran, &positionresoluton_3);
					Mix_PlayChannel(1, son, 0);
					y=4;x=3;
					}
			else if(y==4)
					{

					resoluton_3=IMG_Load("1366x768.png");
					resoluton_2=IMG_Load("1280x720_gr.png");
					SDL_BlitSurface(resoluton_2, NULL, ecran, &positionresoluton_2);
					Mix_PlayChannel(1, son, 0);
					y=1;x=2;
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					{ecran = SDL_SetVideoMode(1280, 720,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}
					else if(y==2)
					{setting(ecran,son,musique);}
					else if (y==3)
					{ecran = SDL_SetVideoMode(800, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}
					else if (y==4)
					{ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}
			break;

                    case SDLK_ESCAPE: // Veut arr�ter le jeu
                        setting(ecran,son,musique);
                        break;
                    case SDLK_KP1: // Demande resolution
                        ecran = SDL_SetVideoMode(800, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                        break;
                    case SDLK_KP2: // Demande contols
                       ecran = SDL_SetVideoMode(1280, 720,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                        break;
                    case SDLK_KP3 :
                       ecran = SDL_SetVideoMode(1366, 768,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                        break;
                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
                    if(event.button.x >100&& event.button.x <390 && event.button.y >310&& event.button.y <390)
                            {ecran = SDL_SetVideoMode(800, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}



                     else if(event.button.x >525&& event.button.x <810 && event.button.y >310&& event.button.y <390)
                            {ecran = SDL_SetVideoMode(1280, 720,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}

                     else if(event.button.x >960&& event.button.x <1240 && event.button.y >310&& event.button.y <390)
                            {ecran = SDL_SetVideoMode(1366, 768,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {setting(ecran,son,musique);}


        		}
		break;

		}//switch

        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(resoluton_1, NULL, ecran, &positionresoluton_1);
        SDL_BlitSurface(resoluton_2, NULL, ecran, &positionresoluton_2);
        SDL_BlitSurface(resoluton_3, NULL, ecran, &positionresoluton_3);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(resoluton_1);
    SDL_FreeSurface(resoluton_2);
    SDL_FreeSurface(resoluton_3);
    SDL_FreeSurface(back);

    SDL_Quit();


}
void controls(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{//void
    SDL_Surface *background=NULL,*manette=NULL,*souris=NULL,*clavier=NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positionClic,positionmanette,positionclavier,positionsouris;
    SDL_Event event;
    int continuer = 1,y=1,x=1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    manette=IMG_Load("manette.png");
    positionmanette.x = 100;
    positionmanette.y = 310;

    souris=IMG_Load("souris.png");
    positionsouris.x = 958;
    positionsouris.y = 310;

    clavier=IMG_Load("clavier.png");
    positionclavier.x = 530;
    positionclavier.y = 310;



    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;



while (continuer)
    {//while
        SDL_WaitEvent(&event);
        switch(event.type)
        {//switch1
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {//switch2
			case SDLK_LEFT :
			if(x==1)

				{
					back=IMG_Load("Back_boutton.png");
					souris=IMG_Load("souris_gr.png");
					SDL_BlitSurface(souris, NULL, ecran, &positionsouris);
					Mix_PlayChannel(1, son, 0);
					x=2;y=1;


				}


			else  if(x==2)
				{
					souris=IMG_Load("souris.png");
					clavier=IMG_Load("clavier_gr.png");
					SDL_BlitSurface(clavier, NULL, ecran, &positionclavier);
					Mix_PlayChannel(1, son, 0);
					x=3;y=4;



				}
			else if(x==3)
					{
					clavier=IMG_Load("clavier.png");
					manette=IMG_Load("manette_gr.png");
					SDL_BlitSurface(manette, NULL, ecran, &positionmanette);
					Mix_PlayChannel(1, son, 0);
					x=4;y=3;
					}
			else if(x==4)
					{
					manette=IMG_Load("manette.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					x=1;y=2;
					}
			break;
				case SDLK_RIGHT :
			if(y==1)

				{
					souris=IMG_Load("souris.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;

				}

			else  if(y==2)
				{
					back=IMG_Load("Back_boutton.png");
					manette=IMG_Load("manette_gr.png");
					SDL_BlitSurface(manette, NULL, ecran, &positionmanette);
					Mix_PlayChannel(1, son, 0);
					y=3;x=4;
				}
			else if(y==3)
					{
					manette=IMG_Load("manette.png");
					clavier=IMG_Load("clavier_gr.png");
					SDL_BlitSurface(clavier, NULL, ecran, &positionclavier);
					Mix_PlayChannel(1, son, 0);
					y=4;x=3;
					}
			else if(y==4)
					{

					clavier=IMG_Load("clavier.png");
					souris=IMG_Load("souris_gr.png");
					SDL_BlitSurface(souris, NULL, ecran, &positionsouris);
					Mix_PlayChannel(1, son, 0);
					y=1;x=2;
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					{/*souris/}
					else if(y==2)
					{setting(ecran,son,musique);}
					else if (y==3)
					{/*manette/}
					else if (y==4)
					{/*clavier/}
			break;
                    case SDLK_ESCAPE: // Veut arr�ter le jeu
                        setting(ecran,son,musique);
                        break;
                    case SDLK_KP1: // Demande resolution
                        //jouer_mannette();
                        break;
                    case SDLK_KP2: // Demande contols
                        //jouer_clavier();
                        break;
                    case SDLK_KP3 :
                       // jouer_souris();
                        break;
                }//switch2
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
                    if(event.button.x >100&& event.button.x <390 && event.button.y >310&& event.button.y <390)
                            {/*jouer_mannette();/}

                     else if(event.button.x >525&& event.button.x <810 && event.button.y >310&& event.button.y <390)
                            {/*jouer_clavier();/}

                     else if(event.button.x >960&& event.button.x <1240 && event.button.y >310&& event.button.y <390)
                            {/*jouer_souris();/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {setting(ecran,son,musique);}


        		}
		break;
		}//switch


        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(manette, NULL, ecran, &positionmanette);
        SDL_BlitSurface(clavier, NULL, ecran, &positionclavier);
        SDL_BlitSurface(souris, NULL, ecran, &positionsouris);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
	SDL_Flip(ecran);
    }//while

    SDL_FreeSurface(background);
    SDL_FreeSurface(manette);
    SDL_FreeSurface(clavier);
    SDL_FreeSurface(souris);
    SDL_FreeSurface(back);

    SDL_Quit();


}//void
void sounds(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{
    SDL_Surface *background=NULL,*augmenter = NULL, *diminuer = NULL,*back=NULL,*couper=NULL;
    SDL_Rect positionaugmenter,positiondiminuer,positionbackground,positioncouper,positionback,positionClic;
    SDL_Event event;
    int continuer = 1,x=1,y=1,a=0,i=1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    augmenter=IMG_Load("augmenter_volume.png");
    positionaugmenter.x = 450;
    positionaugmenter.y = 310;

    diminuer=IMG_Load("diminuer_volume.png");
    positiondiminuer.x = 750;
    positiondiminuer.y = 310;

    couper=IMG_Load("couper_son.png");
    positioncouper.x = 590;
    positioncouper.y = 310;

    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;



while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
		case SDLK_LEFT :
			if(x==1)

				{
					back=IMG_Load("Back_boutton.png");
					diminuer=IMG_Load("diminuer_gr.png");
					SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
					Mix_PlayChannel(1, son, 0);
					x=2;y=1;

				}


			else  if(x==2)
				{
					diminuer=IMG_Load("diminuer_volume.png");
					couper=IMG_Load("couper_gr.png");
					SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
					Mix_PlayChannel(1, son, 0);
					x=3;y=4;
				}
			else if(x==3)
					{
					couper=IMG_Load("couper_son.png");
					augmenter=IMG_Load("augmenter_gr.png");
					SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
					Mix_PlayChannel(1, son, 0);
					x=4;y=3;
					}
			else if(x==4)
					{
					augmenter=IMG_Load("augmenter_gr.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					x=1;y=2;
					}
			break;
				case SDLK_RIGHT :
			if(y==1)

				{
					diminuer=IMG_Load("diminuer_volume.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;

				}

			else  if(y==2)
				{
					back=IMG_Load("Back_boutton.png");
					augmenter=IMG_Load("augmenter_gr.png");
					SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
					Mix_PlayChannel(1, son, 0);
					y=3;x=4;
				}
			else if(y==3)
					{
					augmenter=IMG_Load("augmenter_volume.png");
					couper=IMG_Load("couper_gr.png");
					SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
					Mix_PlayChannel(1, son, 0);
					y=4;x=3;
					}
			else if(y==4)
					{

					couper=IMG_Load("couper_son.png");
					diminuer=IMG_Load("diminuer_gr.png");
					SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
					Mix_PlayChannel(1, son, 0);
					y=1;x=2;
					}
			break;
			case SDLK_RETURN :
					if(y==1)//diminuer son
					{Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);Mix_VolumeMusic(MIX_MAX_VOLUME/4);}
					else if(y==2)//retour
					{ setting(ecran,son,musique);}
					else if (y==3)//augmenter son
					{Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME*4);}
					else if (y==4)
					{
					if(a==0)
					{
					   Mix_PauseMusic();a=1;}
						else if(a==1)
							{Mix_ResumeMusic();a=0;}
					}

			break;

                    case SDLK_ESCAPE: // Veut arr�ter le jeu
                        setting(ecran,son,musique);
                        break;
                    case SDLK_KP1: // Demande augmenter
                        Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME*4);
                        break;
                    case SDLK_KP2: // Demande diminuer
                        Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);Mix_VolumeMusic(MIX_MAX_VOLUME/4);
                        break;
		     case SDLK_KP3: // Demande  coupeer son

					if(a==0)
					{Mix_PauseMusic();a=1;}
						else if(a==1){
						Mix_ResumeMusic();
							a=0;}
                        break;

                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;

			 if(event.button.x >450&& event.button.x <540 && event.button.y >310&& event.button.y <390)
                            {Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME*4);}


			else if(event.button.x >590&& event.button.x <680 && event.button.y >310&& event.button.y <390)
                            {
					if(a==0)
					{Mix_PauseMusic();a=1;}
						else if(a==1){
						Mix_ResumeMusic();
							a=0;}
			    }

			else if(event.button.x >750&& event.button.x <840 && event.button.y >310&& event.button.y <390)
                            {Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);Mix_VolumeMusic(MIX_MAX_VOLUME/4);}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {setting(ecran,son,musique);}


        		}
		break;
		}//switch


        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
	SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
        SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(couper);
    SDL_FreeSurface(augmenter);
    SDL_FreeSurface(diminuer);
    SDL_FreeSurface(back);

    SDL_Quit();


}
*/
void animation(SDL_Surface *ecran)
{

SDL_Surface *background;
SDL_Rect posbackground;
posbackground.x=posbackground.y=300;
FILE *f;char e[3];
int i=0;char name[20];
f=fopen("loading.txt","r");
while(fscanf(f,"%s\n",e)!=EOF){
strcpy(name,"loading/");
strcat(name,e);
strcat(name,".jpg");
					//txtee(ecran)         ;
SDL_BlitSurface(IMG_Load(name),NULL,ecran,&posbackground); SDL_Flip(ecran);SDL_Delay(100); 
					txtee(ecran)         ;
}fclose(f);
}


void txtee(SDL_Surface *ecran)
{

TTF_Font * fonttest=NULL;
SDL_Color colorCoor={254,254,254};
SDL_Surface *coordinates;
SDL_Rect coordinatespos;


TTF_Init();
coordinatespos.x=900;
coordinatespos.y=800;
fonttest=TTF_OpenFont("OpenSans-ExtraBoldItalic.ttf",30);
coordinates=TTF_RenderText_Blended (fonttest,"Copyright � 2021 Cyber Squad",colorCoor);
        SDL_BlitSurface(coordinates, NULL, ecran, &coordinatespos);
        
        


}




