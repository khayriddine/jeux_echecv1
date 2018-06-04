#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include "structures.h"


void creer_partie(Partie *partie,Joueur j1,Joueur j2,int couleur_courant,
                    Liste_dep liste_deplacement,int taille_liste,Piece *liste_pieces);

Joueur joueur_actuel_partie(Partie p);

#endif // PARTIE_H_INCLUDED
