#include "gestion_affichage.h"

void changer_couleur(int f,int t)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dessiner_rectangle(int x,int y)
{
    int i,j;

    changer_couleur(0,12);

    for(i=0;i<=y;i++)
    {
        if(i!=0 && i!=x)
        for(j=0;j<=y;j++)
        {
            if(j==0 ||j==y)
                printf("    ");
            else printf("   ");
        }

        else for(j=0;j<=y;j++)printf("  ");
        printf("\n");
    }
}
void printf_x_y(int x,int y,const char* chaine)
{
    gotoxy(x,y);
    printf("%s",chaine);
}


void afficher_echec()
{

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
printf_x_y(26,14,"                                                           \a");
printf_x_y(26,15,"  *********        ****  *         *  *********        ****\n");
printf_x_y(26,16,"  *             **       *         *  *             **     \n");
printf_x_y(26,17,"  *          **          *         *  *          **        \n");
printf_x_y(26,18,"  *         **           *         *  *         **         \n");
printf_x_y(26,19,"  ********  **           ***********  ********  **         \n");
printf_x_y(26,20,"  *         **           *         *  *         **         \n");
printf_x_y(26,21,"  *          **          *         *  *          **        \n");
printf_x_y(26,22,"  *             **       *         *  *             **     \n");
printf_x_y(26,23,"  *********        ****  *         *  *********        ****\n");
Sleep(500);

}
void afficher_echec_emat()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
printf_x_y(26,15,"  *********        ****  *         *  *********        ****\n");
printf_x_y(26,16,"  *             **       *         *  *             **     \n");
printf_x_y(26,17,"  *          **          *         *  *          **        \n");
printf_x_y(26,18,"  *         **           *         *  *         **         \n");
printf_x_y(26,19,"  ********  **           ***********  ********  **         \n");
printf_x_y(26,20,"  *         **           *         *  *         **         \n");
printf_x_y(26,21,"  *          **          *         *  *          **        \n");
printf_x_y(26,22,"  *             **       *         *  *             **     \n");
printf_x_y(26,23,"  *********        ****  *         *  *********        **** \n");
printf_x_y(26,27,"  ********* ******           ******      ***     ***********\n");
printf_x_y(26,28,"  *         **  ****       ****  **     *****    ***********\n");
printf_x_y(26,29,"  *         **   ****     ****   **    **   **       ***    \n");
printf_x_y(26,30,"  *         **    ****   ****    **   **     **      ***    \n");
printf_x_y(26,31,"  ********  **     *********     ** *************    ***    \n");
printf_x_y(26,32,"  *         **        ***        **   *********      ***    \n");
printf_x_y(26,33,"  *         **         *         **   **     **      ***    \n");
printf_x_y(26,34,"  *         **                   **   **     **      ***    \n");
printf_x_y(26,35,"  ********* **                   **   **     **      ***    \n");
}


void afficher_gagnant(Partie partie)
{
    system("cls");
    int couleur_gagnant = (partie.couleur_courant + 1)%2;
    printf("\n\n\n");
    printf("\t\t\t\t\t\tLe gagnant est  : %s\n",partie.joueurs[couleur_gagnant].nom);
    printf("\t\t\t\t\t\tLa couleur est  : %s\n",(couleur_gagnant == BLANCHE )? "blanche" : "noir");
    printf("\t\t\t\t\t\tLe score est    : %d\n\n",partie.joueurs[couleur_gagnant].score);

}
