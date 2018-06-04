#include "partie.h"

void creer_partie(Partie *partie,Joueur j1,Joueur j2,int couleur_courant,
                    Liste_dep liste_deplacement,int taille_liste,Piece *liste_pieces)
{
    if(j1.couleur == BLANCHE)
    {
        partie->joueurs[BLANCHE] = j1;
        partie->joueurs[NOIR] = j2;
    }
    else
    {
        partie->joueurs[BLANCHE] = j2;
        partie->joueurs[NOIR] = j1;
    }
    partie->couleur_courant = couleur_courant;
    partie->liste_deplacements = liste_deplacement;
    partie->taille_liste = taille_liste;
    partie->liste_pieces = liste_pieces;

}
Joueur joueur_actuel_partie(Partie p)
{
    return p.joueurs[p.couleur_courant];
}

