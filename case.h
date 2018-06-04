#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

#include "structures.h"

void remplir_case(Case *_case,int est_vide,Piece *piece,Position pos);
int case_est_vide(Position pos ,Case echiquier[8][8]);
void modifier_case(Case *_case,int est_vide,Piece *piece);
#endif // CASE_H_INCLUDED
