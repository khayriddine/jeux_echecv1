#ifndef GESTION_DES_PARTIES_H_INCLUDED
#define GESTION_DES_PARTIES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "joueur.h"
#include "partie.h"
#include "init_maj_enregistrement.h"
#include "jeu.h"
void creer_nouvelle_partie();
void sauvgarder_partie(Partie p);
void ouvrir_partie();
void choisir_adversaire(Joueur *j1,Joueur *j2);
#endif // GESTION_DES_PARTIES_H_INCLUDED
