#include <stdio.h>
#include <time.h>     // Pour srand() et time()
#include <stdlib.h>

#include "ajouter.h"
#include "affichage.h"
#include "rechercher.h"  // Inclure rechercher.h
#include "adopter.h"
#include "nourriture.h"     
#include "inventaire.h"
#include "identifiant_ani.h"
#include "animal.h"
#include "menu.h"  // Inclure le fichier menu.h pour afficher le menu de recherche

int main() {
    // Nettoyage automatique au démarrage
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    int choix;
    do {
        afficherMenu(NULL);  // Affiche le menu principal sans fichier à passer
        scanf("%d", &choix);
        while (getchar() != '\n'); // Vider le buffer clavier

        switch (choix) {
            case 1:
                ajouterAnimal();
                break;
            
            case 2: {
                // Ouvrir le fichier des animaux
                FILE *fichier_des_animaux = fopen("animaux/animaux.txt", "r");
                if (fichier_des_animaux == NULL) {
                    printf("Erreur d'ouverture du fichier.\n");
                    break;
                }

                int choix_recherche;
                do {
                    // Afficher le menu de recherche
                    printf("\n=== MENU RECHERCHE ===\n");
                    printf("1. Rechercher par nom\n");
                    printf("2. Rechercher par âge\n");
                    printf("3. Rechercher par espèce\n");
                    printf("4. Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &choix_recherche);
                    while (getchar() != '\n');

                    switch (choix_recherche) {
                        case 1:
                            rechercher_nom(fichier_des_animaux);
                            break;
                        case 2:
                            rechercher_age(fichier_des_animaux);
                            break;
                        case 3:
                            rechercher_espece(fichier_des_animaux);
                            break;
                        case 4:
                            printf("Retour au menu principal...\n");
                            break;
                        default:
                            printf("Choix invalide!\n");
                    }
                } while (choix_recherche != 4);

                // Fermer le fichier après utilisation
                fclose(fichier_des_animaux);
                break;
            }
            
            case 3:
                adopterAnimal();
                break;
                
            case 4:
                nourriture(); 
                break;

            case 5:
                afficherInventaire();
                break;

            case 6:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide !\n");
        }

    } while (choix != 6); // Boucle tant que l'utilisateur n'a pas choisi 6 (quitter)

    return 0;
}