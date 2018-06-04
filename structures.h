#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

enum
{
    PION_1B, PION_2B, PION_3B, PION_4B, PION_5B, PION_6B, PION_7B, PION_8B,
    TOUR_1B, TOUR_2B, CAVALIER_1B, CAVALIER_2B, FOU_1B, FOU_2B, REINE_B, ROI_B,
    PION_1N, PION_2N, PION_3N, PION_4N, PION_5N, PION_6N, PION_7N, PION_8N,
    TOUR_1N, TOUR_2N, CAVALIER_1N, CAVALIER_2N, FOU_1N, FOU_2N, REINE_N, ROI_N,
    NBRE_PIECES
};
enum
{
    BLANCHE =0 , NOIR
};
enum Etat
{
    NORMAL , ECHEC , ECHEC_EMAT
};
enum
{
    HOMME, MACHINE
};
typedef struct
{
    int x;
    int y;
} Position;

typedef struct
{
    Position pos_initiale;
    Position pos_finale;

} Deplacement;

typedef struct
{
    int ID;
    int couleur;
    int valeur;
    Position pos;
} Piece;

typedef struct
{
    int est_vide;
    Piece *piece;
    Position pos;
} Case;

typedef struct
{
    char nom[20];
    int couleur;
    int etat;
    int score;
    int mode;
    int niveau;
} Joueur;

typedef struct Cellule_dep Cellule_dep;
struct Cellule_dep
{

   Deplacement dep;
    Cellule_dep *suivant;
} ;

typedef struct Cellule_pos Cellule_pos;
struct Cellule_pos
{
    Position pos;
    Cellule_pos *suivant ;
};

typedef struct Liste_dep Liste_dep;
struct Liste_dep
{
    Cellule_dep *tete;
    Cellule_dep *courant;
    int nbre;
};

typedef struct Liste_pos Liste_pos;
struct Liste_pos
{
    Cellule_pos *tete;
    Cellule_pos *courant;
    int nbre;
};
typedef struct
{
    Joueur joueurs[2];
    int couleur_courant;
    Liste_dep liste_deplacements;
    Piece *liste_pieces;
    int taille_liste;
} Partie;



#endif // STRUCTURES_H_INCLUDED
