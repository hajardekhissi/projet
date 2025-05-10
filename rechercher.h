#ifndef RECHERCHER_H
#define RECHERCHER_H

#include "animal.h" // Important : Inclure animal.h car Animal est utilisé

int rechercherAnimaux(FILE *fichier_des_animaux, int id_cherche, Animal *animal);

#endif