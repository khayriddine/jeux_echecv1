#include "verification.h"

int verifier(int couleur,Deplacement dep,Case echiquier[8][8])
{
    int xi,yi,xf,yf;
    convert_dep_entiers(dep,&xi,&yi,&xf,&yf);
    if(echiquier[xi][yi].est_vide == 1)
        return 0;
    if(echiquier[xi][yi].piece->couleur != couleur)
        return 0;
    if(!verifier_deplacement(dep,echiquier))
        return 0;
    if(verifier_etat(couleur,dep,echiquier) == 0)
        return 0;
    return 1;
}
int verifier_etat_roi(int couleur,Case echiquier[8][8])
{

    Position pos_du_roi;
    Case e[8][8];
    int i,j,nbre_p,nbre_d,couleur_adversaire,ind,id_du_roi,trouvee =0;
    Liste_dep liste_dep;
    Liste_pos liste_pos;
    id_du_roi = (couleur == BLANCHE) ? ROI_B : ROI_N;
    couleur_adversaire = ((couleur +1 )%2) ;
    Cellule_dep *dep_courant;
    Cellule_pos *pos_courant;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(echiquier[i][j].est_vide == 0 && echiquier[i][j].piece->ID == id_du_roi  )
                { pos_du_roi.x= i; pos_du_roi.y =j;}

    initialiser_liste_pos(&liste_pos);
    nbre_p = pieces_deplacable(couleur_adversaire,echiquier,&liste_pos);
    if(nbre_p==0)
        return NORMAL;
    pos_courant = liste_pos.tete;
        while(pos_courant != NULL)
        {
            initialiser_liste_dep(&liste_dep);
            nbre_d = deplacement_disponible(pos_courant->pos,echiquier,&liste_dep);
            dep_courant = liste_dep.tete;
            while(dep_courant != NULL && !trouvee)
            {
                if(dep_courant->dep.pos_finale.x == pos_du_roi.x && dep_courant->dep.pos_finale.y == pos_du_roi.y)
                    trouvee = 1;
                else dep_courant = dep_courant->suivant;
            }
            if(trouvee)
                return ECHEC;
            pos_courant = pos_courant->suivant;
        }

    return NORMAL;
}
int verifier_echec_emat(int couleur,Case echiquier[8][8])
{
    Position pos_du_roi;
    Case e[8][8];
    int i,j,k,h,nbre_p,nbre_d,couleur_adversaire = (couleur +1)%2,ind,id,trouvee=0;
    int xi,yi,xf,yf;
    Liste_dep liste_dep;
    Cellule_dep *dep_courant;
    Liste_pos liste_pos;
    Cellule_pos *pos_courant;
    id = (couleur == BLANCHE) ? ROI_B : ROI_N;
    initialiser_liste_pos(&liste_pos);
    nbre_p = pieces_deplacable(couleur,echiquier,&liste_pos);
    if(!nbre_p)
        return 1;
    pos_courant = liste_pos.tete;
    while(pos_courant != NULL)
    {
        initialiser_liste_dep(&liste_dep);
        nbre_d = deplacement_disponible(pos_courant->pos,echiquier,&liste_dep);
        dep_courant = liste_dep.tete;
        while(dep_courant != NULL && !trouvee)
        {
            for(k=0;k<8;k++)
                for(h=0;h<8;h++)
                    e[k][h] = echiquier[k][h];
        convert_dep_entiers(dep_courant->dep,&xi,&yi,&xf,&yf);
        modifier_case(&e[xf][yf],0,echiquier[xi][yi].piece);
        modifier_case(&e[xi][yi],1,0);
            if(verifier_etat_roi(couleur,e)==NORMAL)
                return 0;
            else dep_courant = dep_courant->suivant;
        }
    pos_courant = pos_courant->suivant;
    }
    return 1;

}
int verifier_etat(int couleur,Deplacement dep,Case echiquier[8][8])
{
    Position pos_du_roi;
    Case e[8][8];
    int i,j,nbre_p,nbre_d,couleur_adversaire = (couleur +1)%2,ind,id_du_roi,xi,yi,xf,yf;
    Cellule_dep *dep_courant;
    Liste_dep liste_dep;

    Cellule_pos *pos_courant;
    Liste_pos liste_pos;

    convert_dep_entiers(dep,&xi,&yi,&xf,&yf);
    id_du_roi = (couleur == BLANCHE) ? ROI_B : ROI_N;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            e[i][j] = echiquier[i][j];

    modifier_case(&e[xf][yf],0,echiquier[xi][yi].piece);
    modifier_case(&e[xi][yi],1,0);

    if(verifier_etat_roi(couleur,e)== ECHEC)
        return 0;
    else
        return 1;


}

int verifier_deplacement(Deplacement dep,Case echiquier[8][8])
{
    int id,xi,yi,xf,yf;
    convert_dep_entiers(dep,&xi,&yi,&xf,&yf);
    if(xf == xi && yf == yi)
    return 0;
       if(echiquier[xi][yi].est_vide == 1)
    return 0;
    if(echiquier[xf][yf].est_vide == 0 )
       if(echiquier[xi][yi].piece->couleur == echiquier[xf][yf].piece->couleur)
        return 0;
    if(xi < 0 || yi <0 || xf <0 || yf <0
       || xi >7 || yi >7 || xf >7 || yf > 7)
       return 0;
       id = echiquier[xi][yi].piece->ID;
   if(id >=PION_1B && id <= PION_8B)
   {
       if(yf == yi)
            {
                if((xi == 6 && xf == 4 )&&
                   (case_est_vide(dep.pos_finale,echiquier) == 1 && echiquier[5][yi].est_vide == 1))
                    return 1;
                else if(xf - xi == -1 )
                {
                    if(case_est_vide(dep.pos_finale,echiquier) == 1)
                        return 1;
                    return 0;
                }
            }
        else if(abs(yf - yi ) == 1 && (xf - xi)  == -1
                && case_est_vide(dep.pos_finale,echiquier) == 0)
        {
            if(echiquier[xf][yf].piece->couleur == NOIR)
                    return 1;
            return 0;
        }
        return 0;
   }
   else if(id >=PION_1N && id <= PION_8N)
   {
       if(yf == yi)
            {
                if((xi == 1 && xf == 3 )&&
                   (case_est_vide(dep.pos_finale,echiquier) == 1 && echiquier[2][yi].est_vide == 1))
                    return 1;
                else if(xf - xi == 1 )
                {
                    if(case_est_vide(dep.pos_finale,echiquier) == 1)
                        return 1;
                    return 0;
                }
            }
        else if(abs(yf - yi ) == 1 && (xf - xi)  == 1
                && case_est_vide(dep.pos_finale,echiquier) == 0)
        {
            if(echiquier[xf][yf].piece->couleur == BLANCHE)
                    return 1;
            return 0;
        }
        return 0;
   }
   else if(id == TOUR_1B || id == TOUR_2B || id == TOUR_1N || id == TOUR_2N )
   {
            if(xi == xf )
                return parcours_horizental(dep,echiquier);
            else if(yi == yf )
                return parcours_vertical(dep,echiquier);
            return 0;
    }
   else if(id == CAVALIER_1B || id == CAVALIER_2B || id == CAVALIER_1N || id == CAVALIER_2N)
    {
            if(abs(xf - xi) == 2  && abs(yf - yi) == 1)
            {
                if(case_est_vide(dep.pos_finale,echiquier) == 1 )
                    return 1;
                else if(echiquier[xf][yf].piece->couleur != echiquier[xi][yi].piece->couleur)
                        return 1;
                return 0;

            }
            else if(abs(xf - xi) == 1  && abs(yf - yi) == 2)
            {
                        if(case_est_vide(dep.pos_finale,echiquier) == 1 )
                            return 1;
                        else if(echiquier[xf][yf].piece->couleur != echiquier[xi][yi].piece->couleur)
                            return 1;
                        return 0;
            }
            return 0;
    }
    else if(id == FOU_1B || id == FOU_2B || id == FOU_1N || id == FOU_2N)
    {
        if(abs(xf - xi) ==  abs(yf - yi))
        return parcours_diagonal(dep,echiquier);
        return 0;

    }
    else if(id == REINE_B ||id == REINE_N)
    {
        if(xi == xf)
            return parcours_horizental(dep,echiquier);
        else if(yi == yf)
            return parcours_vertical(dep,echiquier);
        else if(abs(xf - xi) ==  abs(yf - yi))
            return parcours_diagonal(dep,echiquier);
        else return 0;
    }
    else if(id == ROI_B ||id == ROI_N)
    {
            if(abs(xf - xi) == 1 && abs(yf - yi) == 1)
                return 1;
            else if(abs(xf - xi) == 1 && abs(yf - yi) == 0)
                return 1;
            else if(abs(xf - xi) == 0 && abs(yf - yi) == 1)
                return 1;
            return 0;
    }
   return 0;


}
int parcours_horizental(Deplacement dep, Case echiquier[8][8])
{
    int estVide,i,j,facteur_x,facteur_y,xi,yi,xf,yf;
    estVide = 1;
    convert_dep_entiers(dep,&xi,&yi,&xf,&yf);
    facteur_y = (yf - yi)/abs(yf - yi);
    i = yi + facteur_y;
    while(i != yf && estVide)
    {
        if(echiquier[xi][i].est_vide == 0)
            estVide = 0;
        else
            i = i + facteur_y;
    }
    if(estVide == 1)
        return 1;
    return 0;
}
int parcours_vertical(Deplacement dep,Case echiquier[8][8])
{
    int estVide,i,j,facteur_x,facteur_y,xi,yi,xf,yf;
    estVide = 1;
    convert_dep_entiers(dep,&xi,&yi,&xf,&yf);
    facteur_x = (xf - xi)/abs(xf - xi);
    i = xi + facteur_x;
    while(i != xf && estVide)
    {
        if(echiquier[i][yi].est_vide == 0)
            estVide = 0;
        else
            i = i + facteur_x;
    }
    if(estVide == 1)
        return 1;
    return 0;
}
int parcours_diagonal(Deplacement dep,Case echiquier[8][8])
{
    int estVide,i,j,facteur_x,facteur_y,xi,yi,xf,yf;
    estVide = 1;
    convert_dep_entiers(dep,&xi,&yi,&xf,&yf);
    facteur_x = (xf - xi)/abs(xf - xi);
    facteur_y = (yf - yi)/abs(yf - yi);

    i = xi + facteur_x;
    j = yi + facteur_y;
    while(i != xf && estVide)
    {
        if(echiquier[i][j].est_vide == 0)
            estVide = 0;
        else
        {
            i = i + facteur_x;
            j = j + facteur_y;
        }

    }
    if(estVide == 1)
        return 1;
    return 0;
}
