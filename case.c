#include "case.h"

void remplir_case(Case *_case,int est_vide,Piece *piece,Position pos)
{
    _case->est_vide = est_vide;
    if(est_vide == 0)
    {
        _case->piece = piece;

    }
    _case->pos = pos;

}

int case_est_vide(Position pos ,Case echiquier[8][8])
{
    return echiquier[pos.x][pos.y].est_vide ;
}
void modifier_case(Case *_case,int est_vide,Piece *piece)
{
    _case->est_vide = est_vide;
    _case->piece = piece;
}
