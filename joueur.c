#include "joueur.h"

Joueur saisir_joueur()
{
    Joueur j;
    char nom[10];
    int couleur;

    printf("sasir le nom  : ");
    scanf("%s",nom);

    do
    {
        printf("\n choisir la couleur de la piece : ");
        printf("\n 0 - couleur blanche");
        printf("\n 1 - couleur noir \n");
        scanf("%d",&couleur);
    }
    while(couleur != NOIR && couleur != BLANCHE);

    strcpy(j.nom,nom);
    j.couleur = couleur;
    j.etat = NORMAL;
    j.score = 0;
    j.mode = HOMME;
    j.niveau = -1;


    return j;
}

void remplir_joueur(Joueur *j,char *nom,int couleur,int etat,int score,int mode,int niveau)
{
    j->couleur = couleur;
    j->etat = etat;
    j->score = score;
    j->mode = mode;
    j->niveau = niveau;
}

