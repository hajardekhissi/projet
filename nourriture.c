#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

void nourriture() {
    int id;
    Animal animal_trouve;

    printf("Entrez l'ID de l'animal pour lequel vous voulez connaître la quantité de croquettes : ");
    if (scanf("%d", &id) != 1) {
        printf("Veuillez entrer un nombre entier valide.\n");
        while (getchar() != '\n'); // vider le buffer
        return;
    }

    // Étape 1 : Rechercher l'animal
    FILE *fichier_pour_recherche = fopen("animaux/animaux.txt", "r");
    if (fichier_pour_recherche == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des animaux.\n");
        return;
    }

    // Recherche de l'animal
    int trouve = rechercherAnimaux(fichier_pour_recherche, id, &animal_trouve);
    fclose(fichier_pour_recherche);

    if (!trouve) {
        printf("Aucun animal trouvé avec l'ID %d.\n", id);
        return;
    }

    // Étape 2 : Calcul de la quantité de croquettes
    double quantiteCroquettes = 0.0;

    switch (animal_trouve.espece) {
        case HAMSTER:
            quantiteCroquettes = 0.02;  // 20g pour un hamster
            break;
        case AUTRUCHE:
            quantiteCroquettes = 2.5;  // 2.5 kg pour une autruche
            break;
        case CHAT:
        case CHIEN:
            if (2025 - animal_trouve.annee_naissance < 2) {
                quantiteCroquettes = 0.5;  // 500g pour un chat ou chien de moins de 2 ans
            } else {
                quantiteCroquettes = 0.1 * animal_trouve.poids;  // 10% du poids pour un adulte
            }
            break;
        default:
            printf("Espèce inconnue, pas de calcul de nourriture.\n");
            return;
    }

    // Afficher la quantité de croquettes
    printf("L'animal avec l'ID %d nécessite %.2f kg de croquettes par jour.\n", id, quantiteCroquettes);
}
