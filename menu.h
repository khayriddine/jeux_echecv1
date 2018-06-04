#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <windows.h>
#include <stdio.h>
#include "autres_fonctions.h"
#include "structures.h"
#include "gestion_des_parties.h"

void afficher_menu_principale();
void afficher_menu_gestion_de_partie();
void afficher_menu_pieces();
void afficher_menu_option();
void afficher_menu_regle_du_jeu();
void afficher_menu_autre_action(Partie partie);
//void ouvrir_partie();
#endif // MENU_H_INCLUDED
