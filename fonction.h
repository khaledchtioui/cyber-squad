#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED

#define HAUTEUR 720
#define LARGEUR 1080
#define nbimage 5
#define Largeurimage  201.4
#define LARGEURSPRITE 864
#define HAUTEURSPRITE 280


typedef struct
{
    SDL_Surface *sprite;
    SDL_Rect posSE;
    SDL_Rect poSprite;
    int direction;
    int num;
    SDL_Surface *ennemiActuel;
}ennemi;


void InitEnnemi(ennemi *e);
void afficherEnnemi(ennemi e,SDL_Surface *screen);
void animerEnnemi(ennemi *e);
void deplacer(ennemi *e);
int boundingBox(SDL_Rect pose,SDL_Rect posSE);

enum{DROITE,GAUCHE};
#endif // ENTITE_H_INCLUDED
