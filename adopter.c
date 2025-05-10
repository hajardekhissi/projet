#include <stdio.h>
#include <stdlib.h>
// Pas de string.h
#include "animal.h"
#include "rechercher.h"
#include "adopter.h"

void adopterAnimal() {
    int id_cherche;
    Animal animal_trouve_data;
    char especeStr[20];
    char ligne[256]; // Pour lire les lignes

    printf("Nous allons tout de suite démarrer l'adoption\n");

    // Demander l’ID de l’animal
    printf("Entrez l'ID de l'animal à adopter : ");
    if (scanf("%d", &id_cherche) != 1) {
        printf("Veuillez entrer un nombre entier valide.\n");
        while (getchar() != '\n'); // vider le buffer
        return;
    }
    while (getchar() != '\n'); // vider le buffer

    // Étape 1 : Rechercher l'animal
    FILE *fichier_pour_recherche = fopen("animaux/animaux.txt", "r");
    if (fichier_pour_recherche == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des animaux.\n");
        return;
    }

    int trouve = rechercherAnimaux(fichier_pour_recherche, id_cherche, &animal_trouve_data);
    fclose(fichier_pour_recherche);

    if (!trouve) {
        printf("Désolé, aucun animal trouvé avec l'ID %d.\n", id_cherche);
        return;
    }

    // Étape 2 : Ouvrir le fichier en lecture et un fichier temporaire en écriture
    FILE *fichier_original = fopen("animaux/animaux.txt", "r");
    FILE *fichier_temp = fopen("animaux/animaux_temp.txt", "w");

    if (fichier_original == NULL || fichier_temp == NULL) {
        printf("Erreur lors de la réouverture des fichiers.\n");
        if (fichier_original) fclose(fichier_original);
        if (fichier_temp) fclose(fichier_temp);
        return;
    }

    // Lire chaque ligne et recopier sauf celle à supprimer
    while (fgets(ligne, sizeof(ligne), fichier_original)) {
        Animal courant;
        if (sscanf(ligne, "%d;%s;%s;%d;%.2f;%s[^\n]",
                   &courant.id, courant.nom, especeStr,
                   &courant.annee_naissance, &courant.poids, courant.commentaire) == 6) {

            courant.espece = chaineVersEspece(especeStr);

            if (courant.id != id_cherche) {
                fprintf(fichier_temp, "%d;%s;%s;%d;%.2f;%s\n",
                        courant.id, courant.nom, especeVersChaine(courant.espece),
                        courant.annee_naissance, courant.poids, courant.commentaire);
            }
        }
    }

    fclose(fichier_original);
    fclose(fichier_temp);

    // Étape 3 : Remplacer l'ancien fichier par le temporaire
    if (remove("animaux/animaux.txt") != 0) {
        printf("Erreur : impossible de supprimer l'ancien fichier.\n");
        return;
    }

    if (rename("animaux/animaux_temp.txt", "animaux/animaux.txt") != 0) {
        printf("Erreur : impossible de renommer le fichier temporaire.\n");
        return;
    }

    printf("L'animal avec l'ID %d a été adopté avec succès !\n", id_cherche);
}
