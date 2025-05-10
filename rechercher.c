#include "animal.h"
#include <stdio.h>

// Fonction pour rechercher un animal par ID dans un fichier
int rechercherAnimaux(FILE *fichier, int idRecherche, Animal *resultat) {
    char especeStr[20];

    // Vérifie si le fichier est valide
    if (fichier == NULL) {
        printf("Erreur : fichier invalide.\n");
        return 0;
    }

    // Lecture ligne par ligne dans le fichier
    while (fscanf(fichier, "%d;%s;%s;%d;%f;%s", 
                  &(*resultat).id, (*resultat).nom, especeStr, 
                  &(*resultat).annee_naissance, &(*resultat).poids, (*resultat).commentaire) == 6) {

        // Convertir la chaîne de caractères en type Espece
        (*resultat).espece = chaineVersEspece(especeStr);

        // Vérifier si c'est l'animal recherché
        if ((*resultat).id == idRecherche) {
            return 1; // L'animal a été trouvé
        }
    }

    return 0; // L'animal n'a pas été trouvé
}
