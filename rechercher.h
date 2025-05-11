#ifndef RECHERCHER_H
#define RECHERCHER_H

#include <stdio.h>
#include "animal.h"

int rechercher_id(FILE *fichier, int idRecherche, Animal *resultat);
void rechercher_nom(FILE *fichier);
int rechercher_age(FILE *fichier);
void rechercher_espece(FILE *fichier);
int rechercherAnimaux(FILE *fichier, int idRecherche, Animal *resultat);  // Modifié pour correspondre à animal.h

#endif