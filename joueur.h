#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "structures.h"

Joueur saisir_joueur();
void remplir_joueur(Joueur *j,char *nom,int couleur,int etat,int score,int mode,int niveau);

#endif // JOUEUR_H_INCLUDED
