#include <stdio.h>
#include "menu.h"
#include "rechercher.h"

void afficherMenurRecherche(FILE *fichier) {
    if (fichier == NULL) {
        // Menu principal
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ajouter un animal\n");
        printf("2. Rechercher un animal\n");
        printf("3. Adopter un animal\n");
        printf("4. Gérer la nourriture\n");
        printf("5. Afficher l'inventaire\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
    } else {
        // Menu de recherche
        int choix;
        printf("\n=== MENU RECHERCHE ===\n");
        printf("1. Rechercher par nom\n");
        printf("2. Rechercher par age\n");
        printf("3. Rechercher par espece\n");
        printf("4. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        while (getchar() != '\n') {
            // Vider le buffer clavier
        }

        switch (choix) {
            case 1: {
                rechercher_nom(fichier);
                break;
            }
            case 2: {
                rechercher_age(fichier);
                break;
            }
            case 3: {
                rechercher_espece(fichier);
                break;
            }
            case 4: {
                printf("Retour au menu principal...\n");
                break;
            }
            default: {
                printf("Choix invalide!\n");
            }
        }
    }
}
