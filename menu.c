#include "Menu.h"


void afficher_menu_principale()
{
    int c;
    system("mode 120,60");
    system("cls");
    changer_couleur(0,12);
    printf("\n\n");
    printf("\t\t\t\t\t\tMENU PRINCIPAL :\n");
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t1) Gerer une partie \n");
    printf("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t2) Regles du jeu \n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t3) Quitter\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1 :
        afficher_menu_gestion_de_partie();
        break;
    case 2 :
        afficher_menu_regle_du_jeu();
        break;

    case 3 :
        return ;
        break;
    default :
        printf("\nerreur\n");
        afficher_menu_principale();
        break;
    }
}
void afficher_menu_gestion_de_partie()

{
    int c;
    system("mode 120,60");
        changer_couleur(0,12);

    system("cls");
    printf("\n\n");
    printf("\t\t\t\t\t\tGESTION D UNE PARTIE\n\n\n");
    printf ("\t\t\t\t\t_________________________________________\n");

    printf("\t\t\t\t\t\t1.Creer une nouvelle partie \n") ;
    printf ("\t\t\t\t\t_________________________________________\n");

    printf("\t\t\t\t\t\t2.Ouvrir une partie enregistree \n");
    printf ("\t\t\t\t\t_________________________________________\n");

    printf  ("\t\t\t\t\t\t3.Revenir au menu principal\n");
    printf ("\t\t\t\t\t_________________________________________\n");

    scanf("%d",&c);
    switch (c)
    {
    case 1 :
        creer_nouvelle_partie();
        break;
    case 2 :
        ouvrir_partie();
        break;
    case 3 :
        afficher_menu_principale() ;
        break;
    default :
        printf("erreur\n");
        afficher_menu_gestion_de_partie();
    }
}


void afficher_menu_regle_du_jeu()
{
    int c;
    system("mode 120,60");
        changer_couleur(0,12);

    system("cls");
    printf("\n\n");
    printf("\t\t\t\t\t\tREGLES DU JEU  :\n\n\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t1.L echiquier\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t2.Les pieces et leurs emplacements\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t3.Le but du jeu \n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t4.Revenir au menu principal\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1 :
        printf("L echiquier est le tablier ou plateau du jeu d echecs. C est une grille carree de 8 cases de cote, soit 64 cases en tout, en alternance noires et blanches. Ou on place et manipule les pieces :") ;getch();
        afficher_menu_regle_du_jeu();
        break;
    case 2 :
        afficher_menu_pieces();
    case 3 :
        printf("Le but du jeu d echecs est de capturer le Roi de l adversaire . Il est alors  echec et mat  et la partie est finie.");getch();afficher_menu_regle_du_jeu();
        break;
    case 4 :
        afficher_menu_principale();break;
    default :
        printf("erreur \n");
        afficher_menu_regle_du_jeu();
    }
}
void afficher_menu_pieces()
{
    int c ;
    system("mode 120,60");
        changer_couleur(0,12);

    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t\t\tDEPLACEMENT DES PIECES:\n\n\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t1.Pion\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t2.Tour\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t3.Cavalier \n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t4.Fou \n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t5.Reine \n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t6.Roi \n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t7.Revenir au menu precedent \n");
    printf ("\t\t\t\t\t_________________________________________\n");



    scanf("%d",&c);
    switch(c)
    {

    case 1 :
        printf("\tLe Pion ne peut revenir en arriere,ce qui fait que chacun de ses mouvements est irreversible.\n Depuis sa case, il peut se deplacer d’une ou de deux cases.\n Ensuite il ne peut avancer que d’une case. \n Il prend les autres pieces uniquement en diagonales.");
        getch();afficher_menu_pieces();break;
    case 2 :
        printf("\t La Tour se deplace sur les lignes et colonnes de la position qu’elle occupe au depart.");;
        getch();afficher_menu_pieces();break;
    case 3 :
        printf("\tLe mouvement du Cavalier est particulier (Deux cases à la verticale ou à l horizontale, puis une case en diagonale).");
        getch();afficher_menu_pieces();break;
    case 4 :
        printf("\tLe fou se deplace sur les deux diagonales de la position qu il occupe.\n Le Fou restant durant toute la partie sur la couleur de sa case de depart.");
        getch();afficher_menu_pieces();break;
    case 5 :
        printf("\tLa reine peut se deplacer sans restrictions, sur les verticales, les horizontales et les diagonales.");
        getch();afficher_menu_pieces();break;
    case 6 :
        printf("\tLe roi se deplace d une seule case dans n importe quelle direction.");
        getch();afficher_menu_pieces();break;
    case 7 :
        afficher_menu_regle_du_jeu();break;
    default :
        printf("erreur \n");
        afficher_menu_pieces();
    }

}


void afficher_menu_autre_action(Partie partie)
{
    int reponse;
    //dessiner_rectangle(40,40);
    changer_couleur(0,12);


    printf_x_y(100,26,"Choisir une  action :");
    printf_x_y(100,28,"1-Continuer la partie  ");
    printf_x_y(100,29,"2-Sauvgarder la partie ");
    printf_x_y(100,30,"3-Revenir au menu principale ");
    gotoxy(100,31);
    do
    {
        reponse = getchar();
    }while(reponse <'1' && reponse >'2');


    switch(reponse)
    {
    case '1' :
        return;
    case '2' :
        sauvgarder_partie(partie);
        afficher_menu_autre_action(partie);
        break;

    case '3' :
        afficher_menu_principale();return;
        break;
    default :
    {
        afficher_menu_autre_action(partie);

    }break;
    }
    return;
}
