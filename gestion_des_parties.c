#include "gestion_des_parties.h"
void creer_nouvelle_partie()
{
    Joueur j1,j2;
    Case echiquier[8][8];
    int mode,tour,couleur_courant,score,niveau,taille_listes;
    char nom[100];
    Partie partie;
    Liste_dep liste_deplacement;
    Piece liste_pieces[32];


    choisir_adversaire(&j1,&j2);
    initialiser_liste_dep(&liste_deplacement);
    initialiser_pieces(liste_pieces);

    creer_partie(&partie,j1,j2,BLANCHE,liste_deplacement,0,liste_pieces);

    jouer(&partie);

}
void sauvgarder_partie(Partie p)
{
    char nom_fichier[100],nbre_f[10];
    int i=0,xi,yi,xf,yf;
    Cellule_dep *dep_courant;
    printf("\n\t\t saisir le nom de la partie:");
    scanf("%s",nom_fichier);
    strcat(nom_fichier,".txt");
    FILE *fichier = fopen(nom_fichier,"w");
    if(!fichier)
    {
        printf("\n\nerreur !!!");
        return;
    }
for(i=0;i<2;i++)
{

    fputs(p.joueurs[i].nom,fichier);
    fputs("\n",fichier);
    sprintf(nbre_f,"%d",p.joueurs[i].couleur);
    fputs(nbre_f,fichier);fputs("\n",fichier);
    sprintf(nbre_f,"%d",p.joueurs[i].etat);
    fputs(nbre_f,fichier);fputs("\n",fichier);
    sprintf(nbre_f,"%d",p.joueurs[i].mode);
    fputs(nbre_f,fichier);fputs("\n",fichier);
    sprintf(nbre_f,"%d",p.joueurs[i].niveau);
    fputs(nbre_f,fichier);fputs("\n",fichier);
    sprintf(nbre_f,"%d",p.joueurs[i].score);
    fputs(nbre_f,fichier);fputs("\n",fichier);
}
    sprintf(nbre_f,"%d",p.couleur_courant);
    fputs(nbre_f,fichier);fputs("\n",fichier);
    sprintf(nbre_f,"%d",p.taille_liste);
    fputs(nbre_f,fichier);fputs("\n",fichier);
    dep_courant = p.liste_deplacements.tete;
    while(dep_courant != NULL)
    {

        convert_dep_entiers(dep_courant->dep,&xi,&yi,&xf,&yf);
        sprintf(nbre_f,"%d%d%d%d",xi,yi,xf,yf);
        fputs(nbre_f,fichier);
        dep_courant = dep_courant->suivant;
    }
    fputs("\n",fichier);
    for(i=0;i<32;i++)
    {
        sprintf(nbre_f,"%d%d",p.liste_pieces[i].pos.x,p.liste_pieces[i].pos.y);
        fputs(nbre_f,fichier);
    }
    fclose(fichier);
}
void ouvrir_partie()
{

    int continuer,i,j=0 ,tab[100],nbre,couleur,taille;
    char c,s[100],caractere,chaine[100] ="",nom[100] ="";
    Piece liste_p[32];
    Liste_dep liste_dep;
    Cellule_dep *dep_courant;
    Partie partie;
    Joueur liste_joueurs[2];
    FILE* fichier = NULL;
    system("mode 120,60");system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t\t\tCHARGER UNE PARTIE \n\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t1.Choisir la partie \n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t2.Revenir au menu precedent\n");
    printf ("\t\t\t\t\t_________________________________________\n\n");
    scanf("%d",&c);
    switch(c)
    {
         case 1 :
         {
             printf("\t\tsaisir le nom de la partie enregistrée \n");
             scanf("%s",s);
             strcat(s,".txt");
             fichier = fopen(s,"r");
             if(!fichier)
             {
                 printf("\n erreur !");
                 ouvrir_partie();
                 return;
             }
            for(i=0;i<2;i++)
            {
               fgets(chaine,25,fichier);
               strcpy(liste_joueurs[i].nom,chaine);
                printf("%s",liste_joueurs[i].nom);
                fgets(chaine,25,fichier);
               liste_joueurs[i].couleur = atoi(chaine);
                printf("%d",liste_joueurs[i].couleur);
                fgets(chaine,25,fichier);
                liste_joueurs[i].etat = atoi(chaine);
                printf("%d",liste_joueurs[i].etat);
                fgets(chaine,25,fichier);
                liste_joueurs[i].mode = atoi(chaine);
                printf("%d",liste_joueurs[i].mode);
                fgets(chaine,25,fichier);
                liste_joueurs[i].niveau = atoi(chaine);
                printf("%d",liste_joueurs[i].niveau);
                fgets(chaine,25,fichier);
                liste_joueurs[i].score = atoi(chaine);
                printf("%d",liste_joueurs[i].score);
                printf("\n");
            }
            fgets(chaine,25,fichier);
            couleur = atoi(chaine);
            printf("%d",couleur);
            fgets(chaine,25,fichier);
            taille= atoi(chaine);
            printf("%d",taille);
            dep_courant = partie.liste_deplacements.tete;
           /* while(dep_courant != NULL)
            {

                c= fgetc(fichier);
                liste_dep[i].pos_initiale.x = c - 48;
                printf("%d",dep_courant->dep.pos_initiale.x);
                c= fgetc(fichier);
                liste_dep[i].pos_initiale.y = c - 48;
                printf("%d",liste_dep[i].pos_initiale.y);
                c= fgetc(fichier);
                liste_dep[i].pos_finale.x = c - 48;
                printf("%d",liste_dep[i].pos_finale.x);
                c= fgetc(fichier);
                liste_dep[i].pos_finale.x = c - 48;
                printf("%d",liste_dep[i].pos_finale.y);

            }*/

            printf("\n");
            fgets(chaine,25,fichier);
            for(i=0;i<64;i++)
            {
                c = fgetc(fichier);
                tab[i] = c - 48;
                printf("%d",c - 48);

            }
            printf("\n");
            initialiser_pieces(liste_p);
            for(i=0;i<32;i++)
            {
                liste_p[i].pos.x = tab[2*i];
                liste_p[i].pos.y = tab[2*i + 1];
            }
            creer_partie(&partie,liste_joueurs[0],liste_joueurs[1],couleur,liste_dep,taille,liste_p);
            jouer(&partie);

             fclose(fichier);
            return;

         }
         break;
         case 2 :
         afficher_menu_gestion_de_partie();
         break;
         default :
         printf("erreur\n ");
         ouvrir_partie();
         break;
    }
    return;

}
void choisir_adversaire(Joueur *j1,Joueur *j2)
{
    int c,niveau;char nom1[20],nom2[20];

    system("mode 120,60");
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t\t\tCHOISIR ADVERSAIRE\n\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t1.Machine\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t2.Autre utilisateur\n");
    printf ("\t\t\t\t\t_________________________________________\n");
    printf("\t\t\t\t\t\t3.Revenir au menu precedent\n");
    printf ("\t\t\t\t\t_________________________________________\n");

    scanf("%d",&c);
    switch(c)
    {
        case 1 :
            {

                printf("vous avez choisi la machine\n\n");
                *j1 = saisir_joueur();
                strcpy(j2->nom,"machine");
                printf("\nchoisir niveau : \n");
                scanf("%d",&niveau);
                remplir_joueur(j2,"machine",(j1->couleur+1)%2,NORMAL,0,MACHINE,niveau);
                return ;
            }

        break;
        case 2 : {

                printf("\t\tVous avez choisi un autre utilisateur\n\n");
                printf("\tJoueur 1 : \n");
                *j1 = saisir_joueur();
                printf("joueur 2 : \n");
                printf("\t\tSasir le nom  : ");
                scanf("%s",nom2);
                strcpy(j2->nom,nom2);
                remplir_joueur(j2,"",(j1->couleur+1)%2,NORMAL,0,HOMME,-1);
                return;
                }
        break;
        case 3 : afficher_menu_gestion_de_partie();return;
        break;
        default : printf("\n erreur\n");
                  choisir_adversaire(j1,j2);return;

        break;
    }
}


