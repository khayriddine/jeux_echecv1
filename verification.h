#ifndef VERIFICATION_H_INCLUDED
#define VERIFICATION_H_INCLUDED

#include "structures.h"
#include "jeu.h"

#include "verification.h"

int verifier(int couleur,Deplacement dep,Case echiquier[8][8]);
int verifier_etat_roi(int couleur,Case echiquier[8][8]);
int verifier_echec_emat(int couleur,Case echiquier[8][8]);
int verifier_etat(int couleur,Deplacement dep,Case echiquier[8][8]);
int verifier_deplacement(Deplacement dep,Case echiquier[8][8]);
int parcours_horizental(Deplacement dep, Case echiquier[8][8]);
int parcours_vertical(Deplacement dep,Case echiquier[8][8]);
int parcours_diagonal(Deplacement dep,Case echiquier[8][8]);



#endif // VERIFICATION_H_INCLUDED
