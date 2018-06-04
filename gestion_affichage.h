#ifndef AUTRES_FONCTIONS_H_INCLUDED
#define AUTRES_FONCTIONS_H_INCLUDED

#include "structures.h"
#include <windows.h>

void changer_couleur(int t,int f);
void gotoxy(int x, int y);
void dessiner_rectangle(int x,int y);
void printf_x_y(int x,int y,const char* chaine);
int chercher(char *chaine,char c);
void afficher_echec();
void afficher_echec_emat();
void afficher_gagnant(Partie partie);
#endif // AUTRES_FONCTIONS_H_INCLUDED
