#include "piece.h"

void remplir_piece(Piece *p, int id,int couleur,int valeur,Position pos)
{

    p->ID = id;
    p->couleur = couleur;
    p->valeur = valeur;
    p->pos = pos;

}



void modifier_pos_piece(Piece *piece,Position pos)
{
    piece->pos = pos;
    return;
}
int couleur_piece(Piece  p)
{
    return p.couleur;
}
