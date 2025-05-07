#include <stdio.h>
#include <time.h>
#include "animal.h"
#include "identifiant_ani.h"
#include "choisirespece.h"
#include "nourriture.h"
#include "affichage.h"
#include "adopter.h"

void afficherNourriture() {
    FILE *fichier = fopen("animaux.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    time_t maintenant = time(NULL);
    struct tm date = *localtime(&maintenant);
    int annee = date.tm_year + 1900;

    Animal animal;
    char espece[50];
    float totalCroquettes = 0;

    float chien = 0;
    float chat = 0;
    float hamster = 0;
    float autruche = 0;

    // Lecture des animaux dans le fichier
    while (fscanf(fichier, "%d;%s;%s;%d;%f;%s\n", &animal.id, animal.nom, espece, &animal.annee_naissance, &animal.poids, animal.commentaire)== 6) {

        int age = annee - animal.annee_naissance;
        float quantite = 0;

        // Calcul de la nourriture selon l'espèce
        if (comparer(espece, "chien")) {
            if (age < 2)
                quantite = 0.5;
            else
                quantite = animal.poids * 0.1;
            chien += quantite;
        }
        else if (comparer(espece, "chat")) {
            if (age < 2)
                quantite = 0.5;
            else
                quantite = animal.poids * 0.1;
            chat += quantite;
        }
        else if (comparer(espece, "hamster")) {
            quantite = 0.02;
            hamster += quantite;
        }
        else if (comparer(espece, "autruche")) {
            quantite = 2.5;
            autruche += quantite;
        }
        else {
            printf("Espèce inconnue : %s (je sais pas combien lui donner 😬)\n", espece);
        }

        totalCroquettes += quantite;
    }

    fclose(fichier);

    // Affichage des résultats
    printf("\nRésumé des croquettes à préparer chaque jour :\n");

    if (chien > 0)
        printf(" - Chiens    : %.2f kg\n", chien);
    if (chat > 0)
        printf(" - Chats     : %.2f kg\n", chat);
    if (hamster > 0)
        printf(" - Hamsters  : %.2f kg\n", hamster);
    if (autruche > 0)
        printf(" - Autruches : %.2f kg\n", autruche);

    printf("\nTotal à prévoir : %.2f kg de croquettes ! 🍽️\n", totalCroquettes);
}
