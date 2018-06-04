#include "initialisation.h"

void initialiser_pieces(Piece* liste_pieces)
{
    Piece pion_b , tour_b , cavalier_b, fou_b , roi_b , reine_b;
    Piece pion_n , tour_n , cavalier_n, fou_n , roi_n , reine_n;
    int i,j;
    Position pos;
    for(i=PION_1B; i<=PION_8B; i++)
    {
        pos.x = 6;
        pos.y = i;
        remplir_piece(&liste_pieces[i],i,BLANCHE,1,pos);
    }

    for(i=PION_1N; i<=PION_8N; i++)
    {
        pos.x = 1;
        pos.y = i - PION_1N;
        remplir_piece(&liste_pieces[i],i,NOIR,1,pos);
    }
    // tours :
    pos.x = 7;
    pos.y = 0;
    remplir_piece(&liste_pieces[TOUR_1B],TOUR_1B,BLANCHE,5,pos);

    pos.x = 7;
    pos.y = 7;
    remplir_piece(&liste_pieces[TOUR_2B],TOUR_2B,BLANCHE,5,pos);

    pos.x = 0;
    pos.y = 0;
    remplir_piece(&liste_pieces[TOUR_1N],TOUR_1N,NOIR,5,pos);

    pos.x = 0;
    pos.y = 7;
    remplir_piece(&liste_pieces[TOUR_2N],TOUR_2N,NOIR,5,pos);
    // cavalier :
    pos.x = 7;
    pos.y = 1;
    remplir_piece(&liste_pieces[CAVALIER_1B],CAVALIER_1B,BLANCHE,3,pos);

    pos.x = 7;
    pos.y = 6;
    remplir_piece(&liste_pieces[CAVALIER_2B],CAVALIER_2B,BLANCHE,3,pos);

    pos.x = 0;
    pos.y = 1;
    remplir_piece(&liste_pieces[CAVALIER_1N],CAVALIER_1N,NOIR,3,pos);

    pos.x = 0;
    pos.y = 6;
    remplir_piece(&liste_pieces[CAVALIER_2N],CAVALIER_2N,NOIR,3,pos);
    // foux :
    pos.x = 7;
    pos.y = 2;
    remplir_piece(&liste_pieces[FOU_1B],FOU_1B,BLANCHE,3,pos);

    pos.x = 7;
    pos.y = 5;
    remplir_piece(&liste_pieces[FOU_2B],FOU_2B,BLANCHE,3,pos);

    pos.x = 0;
    pos.y = 2;
    remplir_piece(&liste_pieces[FOU_1N],FOU_1N,NOIR,3,pos);

    pos.x = 0;
    pos.y = 5;
    remplir_piece(&liste_pieces[FOU_2N],FOU_2N,NOIR,3,pos);
    // reines :
    pos.x = 7;
    pos.y = 3;
    remplir_piece(&liste_pieces[REINE_B],REINE_B,BLANCHE,9,pos);

    pos.x = 0;
    pos.y = 3;
    remplir_piece(&liste_pieces[REINE_N],REINE_N,NOIR,9,pos);
    // rois :
    pos.x = 7;
    pos.y = 4;
    remplir_piece(&liste_pieces[ROI_B],ROI_B,BLANCHE,0,pos);

    pos.x = 0;
    pos.y = 4;
    remplir_piece(&liste_pieces[ROI_N],ROI_N,NOIR,0,pos);

}

void initialiser_echiquier(Case echiquier[8][8] , Piece* liste_pieces)
{
    int i,j;
    Position pos;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
        {
            pos.x = i;
            pos.y = j;
            echiquier[i][j].est_vide = 1;
            echiquier[i][j].pos = pos;
            echiquier[i][j].piece = 0;
        }

    for(i=PION_1B; i<NBRE_PIECES; i++)
    {
        pos = liste_pieces[i].pos;
        remplir_case(&echiquier[pos.x][pos.y],0,&liste_pieces[i],pos);
    }

}
