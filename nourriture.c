#include "animal.h"
#include <stdio.h>
#include <stdlib.h>
#include "rechercher.h"
#include "nourriture.h"

// Fonction de recherche d'animal et de calcul de la nourriture
void nourriture() {
    int id;
    Animal animal_trouve;

    printf("Entrez l'ID de l'animal pour lequel vous voulez connaitre la quantite de croquettes : ");
    if (scanf("%d", &id) != 1) {
        printf("Veuillez entrez un ID valide svp\n");
        while (getchar() != '\n'); // vider le buffer
        return;
    }

    FILE *fichier_pour_recherche = fopen("animaux/animaux.txt", "r");
    if (fichier_pour_recherche == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des animaux.\n");
        return;
    }

    // Recherche de l'animal
    int trouve = rechercherAnimaux(fichier_pour_recherche, id, &animal_trouve);
    fclose(fichier_pour_recherche);

    if (!trouve) {
        printf("Desole nous ne trouvons pas d'animal avec cet ID  %d.\n", id);

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
        case CHAT :
            if (2025 - animal_trouve.annee_naissance < 2) {
                quantiteCroquettes = 0.3;  // 300g pour un chat de moins de 2 ans
            } else {
                quantiteCroquettes = 0.05 * animal_trouve.poids;  // 5% du poids pour un adulte
            }
            break;
        case CHIEN:
            if (2025 - animal_trouve.annee_naissance < 2) {
                quantiteCroquettes = 0.5;  // 500g pour un chat ou chien de moins de 2 ans
            } else {
                quantiteCroquettes = 0.1 * animal_trouve.poids;  // 10% du poids pour un adulte
            }
            break;
        default:
            printf("Cette espece n'existe pas donc on ne peux pas calculer le taux de croquettes par jour\n");
            return;
    }

    // Afficher la quantité de croquettes
    printf("L'animal avec l'ID %d necessite %.2f kg de croquettes par jour.\n", id, quantiteCroquettes);
}
