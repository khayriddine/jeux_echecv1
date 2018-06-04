/*#include "autres_fonctions.h"

void changer_couleur(int t,int f)
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
void dessiner_rectangle(int x,int y,char c)
{
    int i,j;
    for(i=0; i<=y; i++)
    {
        if(i!=0 && i!=x)
            for(j=0; j<=y; j++)
            {
                if(j==0 ||j==y)
                    printf("%c",c);
                else printf(" ");
            }

        else for(j=0; j<=y; j++)printf("%c",c);
        printf("\n");
    }
}

void printf_x_y(int x,int y,const char* chaine)
{
    gotoxy(x,y);
    printf("%s",chaine);
}

int chercher(char *chaine,char c)
{
    int i,j=0;
    for(i=0;i<strlen(chaine);i++)
        if(chaine[i] == c)
         return i;
    return -1;
}
void afficher_echec()
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
*/
