#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "structures.h"
#include "deplacement.h"
#include "jeu.h"

void remplir_piece(Piece *p, int ID,int couleur,int valeur,Position pos);
void modifier_pos_piece(Piece *piece,Position pos);
int couleur_piece(Piece  p);

#endif // PIECE_H_INCLUDED
