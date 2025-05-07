#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "identifiant_ani.h"


int genererID() {
    srand(time(NULL));  // Initialise le générateur aléatoire avec le temps
    int base = (int)(time(NULL) % 9000) + 1000; // Prend un nombre entre 1000 et 9999
    int alea = rand() % 100;  // Ajoute un petit nombre aléatoire entre 0 et 99
    return base + alea;  // Mélange les deux pour l'unicité
}
