#include "jeu.h"

void jouer(Partie *partie)
{
    system("cls");
    int i,j,k,h,a=0,couleur = partie->couleur_courant,repense;
    Case echiquier[8][8];
    Position pos_l[100],pos;
    Deplacement dep;
    Liste_dep ld;
    Liste_pos lp;
    if(!partie)
        return;
    pos.x = pos.y =1;
    initialiser_echiquier(echiquier,partie->liste_pieces);
    /*dep.pos_initiale = pos;
    dep.pos_finale.y = 1;
    dep.pos_finale.x = 3;
    initialiser_echiquier(echiquier,partie->liste_pieces);
    initialiser_liste_dep(&ld);
    deplacement_disponible(pos,echiquier,&ld);
    initialiser_liste_pos(&lp);
    pieces_deplacable(NOIR,echiquier,&lp);
    deplacement_aleatoire(BLANCHE,&dep,echiquier,1);
    printf("%d",lp.nbre);*/
    do
    {
        system("mode 140 , 70");
        system("cls");
        changer_couleur(0,12);

        afficher_tour(echiquier,*partie);
        afficher_menu_autre_action(*partie,echiquier);
        if(partie->joueurs[partie->couleur_courant].etat == ECHEC)
        {
            afficher_echec();
            afficher_tour(echiquier,*partie);
        }

        Sleep(250);
        deplacer_piece(echiquier,partie);
        changer_tour(partie);
        partie->joueurs[partie->couleur_courant].etat = verifier_etat_roi(partie->couleur_courant,echiquier);

        if(partie->joueurs[partie->couleur_courant].etat == ECHEC)
        {
            if(verifier_echec_emat(partie->couleur_courant,echiquier) == 1)
            partie->joueurs[partie->couleur_courant].etat = ECHEC_EMAT;

        }

    }while(partie->joueurs[partie->couleur_courant].etat != ECHEC_EMAT);

    if(partie->joueurs[partie->couleur_courant].etat == ECHEC_EMAT)
    {
        //afficher_tour(echiquier,*partie);
    changer_couleur(8,8);
    afficher_echec_emat();
    Sleep(500);
    afficher_gagnant(*partie);
    Sleep(500);

    printf("\t\t\t Choisissez :\n\n");
    printf("\t\t1- Menu principale\n");
    printf("\t\t2- Quitter \n");
    scanf("%d",&repense);
    switch(repense)
    {
        case 1 : afficher_menu_principale();break;
        case 2 :  break;

    }
    }

    return;
}
void deplacer_piece(Case echiquier[8][8] , Partie *partie)
{
    if(!partie)
        return;
    Deplacement dep,liste_dep;

    Piece *piece,liste_p;
    int a =0,couleur, nbre_D,nbre_P,ind_dep_alea,ind_pos_alea,niveau ;

    couleur = partie->couleur_courant;
    Joueur joueur_actuel = partie->joueurs[couleur];
    niveau = partie->joueurs[couleur].niveau;
   if(partie->joueurs[couleur].mode == MACHINE)
    {
       if(joueur_actuel.etat == ECHEC)
            niveau = 1;
        while(!deplacement_aleatoire(couleur,&dep,echiquier,niveau));

    }
    else
    {
        do
        {
            saisir_deplacement(&dep,echiquier);
        }while(!verifier(couleur,dep,echiquier));

    }
    printf("%d%d%d%d",dep.pos_finale.x,dep.pos_finale.y,dep.pos_initiale.x,dep.pos_initiale.y);
    Sleep(1500);
    mettre_ajour_partie(echiquier,partie,dep);
}
void mettre_ajour_partie(Case echiquier[8][8], Partie *partie,Deplacement dep)
{
    int id_f,id,couleur;
    if(!partie)
        return;

    couleur = partie->couleur_courant;
        changer_couleur(0,12);

     printf("hahahhuhuh");
   id = echiquier[dep.pos_initiale.x][dep.pos_initiale.y].piece->ID;

    if(echiquier[dep.pos_finale.x][dep.pos_finale.y].est_vide == 0)
    {
        id_f = echiquier[dep.pos_finale.x][dep.pos_finale.y].piece->ID;
        partie->liste_pieces[id_f].pos.x=9  ; partie->liste_pieces[id_f].pos.y=9;
        partie->joueurs[couleur].score += (echiquier[dep.pos_finale.x][dep.pos_finale.y].piece->valeur);
    }

    ajouter_dep(dep,&partie->liste_deplacements);
    partie->taille_liste += 1;
    modifier_case(&echiquier[dep.pos_finale.x][dep.pos_finale.y],0,&partie->liste_pieces[id]);
    modifier_case(&echiquier[dep.pos_initiale.x][dep.pos_initiale.y],1,0);
    modifier_pos_piece(&partie->liste_pieces[id],dep.pos_finale);
}
int pieces_deplacable(int couleur ,Case echiquier[8][8],Liste_pos *positions)
{
    int i=0,j=0,nbre = 0;
    Position pos_v;
    Liste_dep dep_disponibles;

    initialiser_liste_pos(positions);
    if(!positions)
        return 0;


    for(i=0;i<8;i++)
    {

         for(j=0;j<8;j++)
        {
            pos_v.x = i;
            pos_v.y = j;
            if(echiquier[i][j].est_vide == 0 && echiquier[i][j].piece->couleur == couleur)
            {
                initialiser_liste_dep(&dep_disponibles);
                if(deplacement_disponible(pos_v,echiquier,&dep_disponibles)>0 )
                ajouter_pos(pos_v,positions);
            }
        }

    }
    return positions->nbre;

}

int deplacement_disponible(Position pos, Case echiquier[8][8],Liste_dep *dep_possible)
{
    int i,j,nbre = 0;
    Deplacement dep_v;
    dep_v.pos_initiale = pos;
    if(!dep_possible)
        return 0;

    if(echiquier[pos.x][pos.y].est_vide == 1)
        return 0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            dep_v.pos_finale.x = i;
            dep_v.pos_finale.y = j;
            if(verifier_deplacement(dep_v,echiquier) == 1)
            {
                ajouter_dep(dep_v,dep_possible);
            }
        }
    }

    return dep_possible->nbre;
}
void afficher_tour(Case echiquier[8][8],Partie partie)
{

    int i=0,j,k,h,a,c,xi,yi,xf,yf;
    Cellule_dep *dep_courant;
    char piece_symbole[7][7][12] ={{"           ","     *     ","    ***    ","     *     ","    ***    ","  *******  "},
                                   {"  * * * *  ","  * * * *  ","   * * *   ","   *****   ","   *****   ","***** *****"},
                                   {"    ***    ","  **  ***  "," **   **   "," ***       ","  *****     ","*********  "},
                                   {"     *     ","    * *    ","    ***    ","   *****   ","  *******  "," ********* "},
                                   {" O  O O  O ","   * * *   ","    * *    ","   *****   ","  *******  ","***********"},
                                   {"   *\\ /*   ","    *Y*    ","   *****   ","    ***    ","    ***    ","   *****   "},
                                   {"           ","           ","           ","           ","           ","           "}};

    changer_couleur(0,12);
    printf("\n\n\n\n");printf("\t");
     for(i=0;i<8;i++)
    {
        for(j=0;j<6;j++)
        {
            for(k=0;k<8;k++)
            {

                if(echiquier[i][k].est_vide == 0)
                {
                    a = ID_type(echiquier[i][k].piece->ID);
                    c = echiquier[i][k].piece->couleur;
                }
                else a = 6;
                if(c == BLANCHE)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((k + (i%2))%2 == 0 ?  127: 79));
                else
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((k + (i%2))%2 == 0 ?  112: 64));
                for(h=0;h<11;h++)
                    printf("%c",piece_symbole[a][j][h]);
                changer_couleur(0,12);

            }

            printf("\n");printf("\t");
        }
    }

    changer_couleur(12,12);
    for(i=0;i<4+8*11;i++)
        printf_x_y(6+i,3," ");

    for(i=0;i<=8*6;i++)
    {
        printf_x_y(6,4+i,"  ");
        printf_x_y(88+8,4+i,"  ");
    }
    for(i=0;i<=2+8*11;i++)
        printf_x_y(7+i,4+48," ");

    changer_couleur(0,12);
    gotoxy(100,4);
    printf("C'est le tour de : %s   ",partie.joueurs[partie.couleur_courant].nom);
    gotoxy(100,6);
    printf("Votre couleur est : %s   ",partie.couleur_courant == 0 ? "Blanche" : "Noir");
    gotoxy(100,8);
    printf("Votre score est : %d ",joueur_actuel_partie(partie).score);
    gotoxy(100,10);
    printf("Type de joueur : %s   ",partie.joueurs[partie.couleur_courant].mode == 0 ? "Homme" : "Machine");
    gotoxy(100,18);
    printf("Historique de deplacement:  ");
    j=0;
    dep_courant = partie.liste_deplacements.tete;
    while(dep_courant != NULL)
    {
    i++;
        if(i%4 == 0)
            j++;
    gotoxy(100 + (i%4)*8 ,20+j);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(i%2 == 0 ? 240 : 12));
    convert_dep_entiers(dep_courant->dep,&xi,&yi,&xf,&yf);
    printf("%c%d %c%d",yi + 97 , 8 - xi , yf + 97 , 8 - xf);
    dep_courant = dep_courant->suivant;
    }


}

int ID_type(int ID)
{
    if((ID>=PION_1B && ID <=PION_8B)||(ID>=PION_1N && ID <=PION_8N))
        return 0;
    else if(ID == TOUR_1B || ID == TOUR_2B||ID == TOUR_1N || ID == TOUR_2N)
    return 1;
    else if(ID == CAVALIER_1B || ID == CAVALIER_2B ||ID == CAVALIER_1N || ID == CAVALIER_2N)
    return 2;
    else if(ID == FOU_1B || ID == FOU_2B||ID == FOU_1N || ID == FOU_2N)
    return 3;
    else if(ID == REINE_B|| ID == REINE_N)
    return 4;
    else if(ID == ROI_B|| ID == ROI_N)
    return 5;
    else return 6;


}
void changer_tour(Partie *partie)
{
    partie->couleur_courant = ((partie->couleur_courant + 1)%2);
    return;
}
