#ifndef DYNAMIQUE_H_INCLUDED
#define DYNAMIQUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

void ajouter_dep(Deplacement dep, Liste_dep * ma_liste);
void initialiser_liste_dep(Liste_dep *ma_liste);
int chercher_liste_dep(Liste_dep *ma_liste, Deplacement dep);
#endif // DYNAMIQUE_H_INCLUDED
