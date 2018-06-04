#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <windows.h>

#include "structures.h"
#include "piece.h"
#include "case.h"
#include "joueur.h"
#include "partie.h"

#include "autres_fonctions.h"

void jouer(Partie *partie);
void deplacer_piece(Case echiquier[8][8] , Partie *partie);
void mettre_ajour_partie(Case echiquier[8][8], Partie *partie,Deplacement dep);
int pieces_deplacable(int couleur ,Case echiquier[8][8],Liste_pos *positions);
int ID_type(int ID);
void changer_tour(Partie *partie);
int deplacement_disponible(Position pos, Case echiquier[8][8],Liste_dep *dep_possible);
void changer_tour(Partie *partie);
#endif // JEU_H_INCLUDED
