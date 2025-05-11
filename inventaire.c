#include <stdio.h>
#include "animal.h"
#include "inventaire.h"



void afficherInventaire() {
    int total = 0;
    int nb_chien = 0, nb_chat = 0, nb_hamster = 0, nb_autruche = 0;
    Animal a;
    char espece_chaine[50];
    
    
    FILE *f = fopen("animaux/animaux.txt", "r");
    if (f == NULL) {
        printf("Erreur : impossible d’ouvrir le fichier animaux.txt\n");
        return;
    }


    while (fscanf(f, "%d;%[^;];%[^;];%d;%f;%[^\n]\n",
                  &(a.id), a.nom, espece_chaine, &(a.annee_naissance), &(a.poids), a.commentaire) == 6) {
        total++;

        if (comparer(espece_chaine, "chien")) {
            nb_chien++;
        }else if (comparer(espece_chaine, "chat")) {
            nb_chat++;
        }else if (comparer(espece_chaine, "hamster")) {
            nb_hamster++;
        }
        else if (comparer(espece_chaine, "autruche")) {
            nb_autruche++;
        }
    }

    fclose(f);

    struct EspeceCompteur {
        const char *nom;
        int nombre;
    } compteurs[4] = {
        {"Chien", nb_chien},
        {"Chat", nb_chat},
        {"Hamster", nb_hamster},
        {"Autruche", nb_autruche}
    };

    // Tri décroissant
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (compteurs[j].nombre < compteurs[j + 1].nombre) {
                struct EspeceCompteur tmp = compteurs[j];
                compteurs[j] = compteurs[j + 1];
                compteurs[j + 1] = tmp;
            }
        }
    }

    // Affichage
   printf(".............Inventaire du refuge..............\n");
    
    for (int i = 0; i < 4; i++) {
        if (compteurs[i].nombre > 0) {
            printf("- %s : %d\n", compteurs[i].nom, compteurs[i].nombre);
        }
    }
    printf("...............................................\n");
    printf("Total animaux : %d\n", total);
}
