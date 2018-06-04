#include "dynamique.h"

void initialiser_liste_dep(Liste_dep *ma_liste)
{
    ma_liste->tete=ma_liste->courant=malloc (sizeof(Deplacement));
    ma_liste->tete=ma_liste->courant = NULL;
    ma_liste->nbre =0;
}

void ajouter_dep(Deplacement dep, Liste_dep * ma_liste)
{
    Cellule_dep *q;
    q = malloc(sizeof(Cellule_dep));
    if(!q)
        return;
    q->dep = dep;
    q->suivant = ma_liste->tete;

    ma_liste->tete = q;
    ma_liste->nbre += 1;

}

int chercher_liste_dep(Liste_dep *ma_liste, Deplacement dep)
{
    Cellule_dep *dep_courant,*pred;
    int trouvee = 0;
    if(!ma_liste)
        return -1;
    dep_courant = ma_liste->tete;
    while(dep_courant != NULL && !trouvee)
    {
        if(comparer_dep(dep_courant->dep,dep))
            trouvee = 1;
        else
        {
            dep_courant = dep_courant->suivant;
        }

    }
    if(trouvee)
    {
        ma_liste->courant = dep_courant;
        return 1;
    }
    return 0;
}

void initialiser_liste_pos(Liste_pos *ma_liste)
{
    ma_liste->tete=ma_liste->courant=malloc (sizeof(Position));
    ma_liste->tete=ma_liste->courant = NULL;
    ma_liste->nbre =0;
}

void ajouter_pos(Position pos, Liste_pos * ma_liste)
{
    Cellule_pos *q;
    q = malloc(sizeof(Cellule_pos));
    if(!q)
        return;
    q->pos = pos;
    q->suivant = ma_liste->tete;

    ma_liste->tete = q;
    ma_liste->nbre += 1;
}

int chercher_liste_pos(Liste_pos *ma_liste, Position pos)
{
    Cellule_pos *pos_courant;
    int trouvee = 0;
    if(!ma_liste)
        return -1;
   pos_courant = ma_liste->tete;
    while(pos_courant != NULL && !trouvee)
    {
        if(pos_courant->pos.x == pos.x && pos_courant->pos.y == pos.y)
            trouvee = 1;
        else
        {
            pos_courant = pos_courant->suivant;
        }

    }
    if(trouvee)
    {
        ma_liste->courant = pos_courant;
        return 1;
    }
    return 0;
}
