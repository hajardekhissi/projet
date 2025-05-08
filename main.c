#include <stdio.h>
#include <time.h>     // Pour srand() et time()
#include <stdlib.h>

#include "ajouter.h"
#include "affichage.h"
#include "rechercher.h"
#include "nettoyeur.h"
#include "adopter.h"
#include "nourriture.h"     
#include "inventaire.h"
#include "identifiant_ani.h"
#include "choisirespece.h"  
#include "animal.h"          
int main() {
    // Nettoyage automatique au démarrage
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires
   nettoyerFichierAnimaux();

    int choix;
    do {
        afficherMenu();         // Affiche le menu complet
        scanf("%d", &choix);
        while (getchar() != '\n'); // Vider le buffer clavier

        switch (choix) {
            case 1:
                ajouterAnimal();
                break;
            case 2:
                rechercherAnimaux();
                break;
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
} // Fin de la fonction main*/

