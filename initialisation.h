#ifndef INIT_MAJ_ENREGISTREMENT_H_INCLUDED
#define INIT_MAJ_ENREGISTREMENT_H_INCLUDED

#include "structures.h"
#include "piece.h"
#include "case.h"

void initialiser_pieces(Piece *liste_pieces);
void initialiser_echiquier(Case echiquier[8][8] , Piece *liste_pieces);
#endif // INIT_MAJ_ENREGISTREMENT_H_INCLUDED
