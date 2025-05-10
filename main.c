#include <stdio.h>
#include <time.h>     // Pour srand() et time()
#include <stdlib.h>
#include <locale.h>

#include "ajouter.h"
#include "affichage.h"
#include "rechercher.h"
#include "adopter.h"
#include "nourriture.h"     
#include "inventaire.h"
#include "identifiant_ani.h"
#include "choisirespece.h"  
#include "animal.h"   

int main() {
    // Nettoyage automatique au démarrage
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires
    setlocale(LC_NUMERIC, "C"); // Pour afficher les nombres avec des virgules au lieu de points
    int choix;
    do {
        afficherMenu();         // Affiche le menu complet
        scanf("%d", &choix);
        while (getchar() != '\n'); // Vider le buffer clavier

        switch (choix) {
            case 1:
                ajouterAnimal();
                break;
            
            case 2: {
                // Supposons que tu veux rechercher un animal par son ID
                FILE *fichier_des_animaux = fopen("animaux/animaux.txt", "r");
                if (fichier_des_animaux == NULL) {
                    printf("Erreur d'ouverture du fichier.\n");
                    break;
                }

                int id_cherche;
                printf("Entrez l'ID de l'animal à rechercher : ");
                scanf("%d", &id_cherche);
                while (getchar() != '\n'); // Vider le buffer clavier

                Animal animal;
                int animal_trouve = rechercherAnimaux(fichier_des_animaux, id_cherche, &animal);
                fclose(fichier_des_animaux);

                if (animal_trouve) {
                    printf("Animal trouvé : %s\n", animal.nom);
                } else {
                    printf("Animal non trouvé avec l'ID %d.\n", id_cherche);
                }
                break;
            }
            
            case 3:
                adopterAnimal();
                break;
                
            case 4:
                afficherNourriture(); 
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

    } while (choix != 6); // Boucle tant que l’utilisateur n’a pas choisi 6 (quitter)

    return 0;
}
