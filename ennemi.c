#include "ennemi.h"



void init_enemie2(enemie * E) {

  E -> spritesheet = IMG_Load("hero_spr.png");
  E -> pos.x = 700;
  E -> pos.y = 400;
  E -> direction = 0;

  E -> posspritesheet.x = 0;
  E -> posspritesheet.y = 0;
  E -> posspritesheet.h = 100;
  E -> posspritesheet.w = 100;

  E -> xminimale.x = 500;
  E -> xmaximale.x = 700;

}




void init_enemie(enemie * E) {

  E -> spritesheet = IMG_Load("hero_spr.png");
  E -> pos.x = 700;
  E -> pos.y = 783;
  E -> direction = 0;

  E -> posspritesheet.x = 0;
  E -> posspritesheet.y = 0;
  E -> posspritesheet.h = 100;
  E -> posspritesheet.w = 100;

  E -> xminimale.x = 500;
  E -> xmaximale.x = 700;

}

void afficher_enemie(enemie * E, SDL_Surface * screen) {
  SDL_BlitSurface(E -> spritesheet, & E -> posspritesheet, screen, & E -> pos);
}

void animate_enemie(enemie * E) {
  E -> posspritesheet.y = E -> direction * E -> posspritesheet.h;
  if (E -> posspritesheet.x >= 300) {
    E -> posspritesheet.x = 0;
  } else {
    E -> posspritesheet.x += E -> posspritesheet.w;// +=100
  }

}

void deplacer(enemie * E) {

  if (E -> pos.x < E -> xminimale.x) {
    E -> direction = 0;
  } else if (E -> pos.x > E -> xmaximale.x) {
    E -> direction = 1;

  }



  
  if (E -> direction == 0) {
    E -> pos.x += 15;
  }
  if (E -> direction == 1) {
    E -> pos.x -= 15;
  }

}

void deplacerIA(enemie * E, SDL_Rect posPerso) {
  if (((E -> pos.x - posPerso.x) < 200) && ((E -> pos.x - posPerso.x) > 80)) {
    E -> direction = 1;
    E -> pos.x -= 20;
  } else if (((E -> pos.x - posPerso.x) < -80) && ((E -> pos.x - posPerso.x) > -200)) {
    E -> direction = 0;
    E -> pos.x += 20;
  } else if (((E -> pos.x - posPerso.x) <= 80) && ((E -> pos.x - posPerso.x) >= 0)) {
    E -> direction = 3;
  } else if (((E -> pos.x - posPerso.x) <= 0) && ((E -> pos.x - posPerso.x) >= -80)) {
    E -> direction = 2;
  }

}

int collision(SDL_Rect E, SDL_Rect p) {
  int collision;
  if (((p.x + p.w) < E.x) || (p.x > (E.x + E.w)) || ((p.y + p.y) < E.y) || (p.y > (E.y + E.y))) {
    collision = 0;
  } else {
    collision = 1;
  }

  return collision;
}
