#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED

#include "structures.h"
#include "piece.h"
#include "jeu.h"
#include "verification.h"

int deplacement_aleatoire(int couleur,Deplacement *dep,Case echiquier[8][8],int niveau);
int deplacement_aleatoire_1(int couleur,Deplacement *dep,Case echiquier[8][8]);
int deplacement_aleatoire_2(int couleur,Deplacement *dep,Case echiquier[8][8]);
void saisir_deplacement(Deplacement *dep,Case echiquier[8][8]);
void convert_dep_entiers(Deplacement dep,int *x_i,int *y_i,int *x_f,int *y_f);
int comparer_dep(Deplacement dep1,Deplacement dep2);
#endif // DEPLACEMENT_H_INCLUDED
