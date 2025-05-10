#include <stdio.h>
#include "rechercher.h" // Inclure l'en-tête pour cette fonction
#include "animal.h"    // Inclure animal.h car Animal est utilisé ici

// Change the function signature to accept an Animal structure directly (not a pointer)
int rechercherAnimaux(FILE *fichier_des_animaux, int id_cherche, Animal animal) {
    char especeStr[20];
    rewind(fichier_des_animaux);

    while (fscanf(fichier_des_animaux, "%d;%s;%s;%d;%f;%s\n",
                  &animal.id, animal.nom, especeStr, &animal.annee_naissance,
                  &animal.poids, animal.commentaire) == 6) {
        animal.espece = chaineVersEspece(especeStr);
        if (animal.id == id_cherche) {
            return 1;
        }
    }
    return 0;
}