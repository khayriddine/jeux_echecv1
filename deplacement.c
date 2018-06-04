#include "deplacement.h"

int deplacement_aleatoire_1(int couleur,Deplacement *dep,Case echiquier[8][8])
{


    int nbre_P,nbre_D,ind_pos_alea,ind_dep_alea,i=0;
    Liste_dep liste_pieces_deplacables;
    Liste_dep liste_deps_disponible;

    Cellule_dep *dep_courant;
    Cellule_pos *pos_courant;


    initialiser_liste_pos(&liste_pieces_deplacables);

    nbre_P = pieces_deplacable(couleur,echiquier,&liste_pieces_deplacables);

    if(liste_pieces_deplacables.nbre == 0)
        return 0;
    ind_pos_alea = (rand()%liste_pieces_deplacables.nbre);

    pos_courant = liste_pieces_deplacables.tete;
    while(i < ind_pos_alea)
    {
        i++;
        pos_courant = pos_courant->suivant;

    }
    initialiser_liste_dep(&liste_deps_disponible);
    nbre_D = deplacement_disponible(pos_courant->pos,echiquier,&liste_deps_disponible);
    if(liste_deps_disponible.nbre == 0)
        return 0;
    ind_dep_alea = (rand()%liste_deps_disponible.nbre);

    dep_courant = liste_deps_disponible.tete;
    *dep = dep_courant->dep;

    //if(verifier(couleur,*dep,echiquier))
        {return 1;}
    return 0;

}
int deplacement_aleatoire_2(int couleur,Deplacement *dep,Case echiquier[8][8])
{
    Deplacement d,d_max;
    Position p_max;
    int x_i,y_i,x_f,y_f,valeur;
    if(!dep)
        return 0;
    int nbre_P,nbre_D,i,j;
    Position liste_pieces_deplacables[100];
    Deplacement liste_deps_disponible[100];
        nbre_P = pieces_deplacable(couleur,echiquier,liste_pieces_deplacables);
        if(!nbre_P)
            return 0;
        valeur = 0;
        for(i=0;i<nbre_P;i++)
        {
            nbre_D = deplacement_disponible(liste_pieces_deplacables[i],echiquier,liste_deps_disponible);
            for(j=0;j<nbre_D;j++)
            {
                convert_dep_entiers(liste_deps_disponible[j],&x_i,&y_i,&x_f,&y_f);
                if(echiquier[x_f][y_f].est_vide == 0)
                {
                    if(valeur < echiquier[x_f][y_f].piece->valeur)
                        {
                            valeur = echiquier[x_f][y_f].piece->valeur;
                            p_max.x = x_f;
                            p_max.y = y_f;
                            d_max.pos_finale = p_max;
                            d_max.pos_initiale = liste_pieces_deplacables[i];
                        }

                }
            }

        }
        if(!nbre_D)
            return 0;
        if(valeur == 0)
        {
            return deplacement_aleatoire_1(couleur,dep,echiquier);
        }
        *dep = d_max;
        if(verifier(couleur,*dep,echiquier))
            return 1;
        return 0;
}
int deplacement_aleatoire(int couleur,Deplacement *dep,Case echiquier[8][8],int niveau)
{
    switch(niveau)
    {
        case 1 : return deplacement_aleatoire_1(couleur,dep,echiquier);break;
        case 2 : return deplacement_aleatoire_2(couleur,dep,echiquier);break;
    }
    return 0;
}
void saisir_deplacement(Deplacement *dep,Case echiquier[8][8])
{
    char pi[3],pf[3];

    changer_couleur(0,12);
    gotoxy(100,14);


    printf("Saisir la position initiale : ");
    scanf("%s",pi);
    gotoxy(100,16);
    printf("Saisir la position finale : ");
    scanf("%s",pf);
    if(pi[0] < 'a' || pi[0] > 'h' || pf[0] < 'a' || pf[0] > 'h' ||
            pi[1] < '1' || pi[1] > '8' || pf[1] < '1' || pf[1] > '8')
    {
        gotoxy(100,12);
        printf("Erreur! Saisir une autre fois :");
        saisir_deplacement(dep,echiquier);
        return;
    }

    dep->pos_initiale.y =  pi[0] - 97 ;
    dep->pos_initiale.x = 8 - (pi[1] - 48);

    dep->pos_finale.y =  pf[0] - 97 ;
    dep->pos_finale.x = 8 - (pf[1] - 48);
    if(case_est_vide(dep->pos_initiale,echiquier) == 1)
    {
        gotoxy(100,12);
        printf("erreur !! saisir une autre fois :");
        saisir_deplacement(dep,echiquier);
        return;
    }


}
void convert_dep_entiers(Deplacement dep,int *x_i,int *y_i,int *x_f,int *y_f)
{
    *x_i = dep.pos_initiale.x;
    *y_i = dep.pos_initiale.y;
    *x_f = dep.pos_finale.x;
    *y_f = dep.pos_finale.y;
    return;
}

int comparer_dep(Deplacement dep1,Deplacement dep2)
{
    if(dep1.pos_initiale.x == dep2.pos_initiale.x && dep1.pos_initiale.y == dep2.pos_initiale.y &&
       dep1.pos_finale.x == dep2.pos_finale.x && dep1.pos_finale.y == dep2.pos_finale.y)
        return 1;
    return 0;
}
