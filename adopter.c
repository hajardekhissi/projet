#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "rechercher.h"
#include "adopter.h"

void adopterAnimal() {
    int id_cherche;
    Animal animal_trouve;
    char espece_chaine[20];
    char ligne[256]; // Pour lire les lignes

    printf("Nous allons tout de suite demarrer l'adoption\n");

    // Demander l’ID de l’animal
    printf("Entrez l'ID de l'animal a adopter : ");
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

    int trouve = rechercher_id(fichier_pour_recherche, id_cherche, &animal_trouve);
    fclose(fichier_pour_recherche);

    if (trouve==0) {
        printf("Desole, aucun animal trouve avec l'ID %d.\n", id_cherche);
        return;
    }

    // Étape 2 : Ouvrir le fichier en lecture et un fichier temporaire en écriture
    FILE *fichier_original = fopen("animaux/animaux.txt", "r");
    FILE *fichier_2 = fopen("animaux/animaux_2.txt", "w");

    if (fichier_original == NULL || fichier_2 == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        if (fichier_original != NULL) {
            fclose(fichier_original);
        }
        if (fichier_2 != NULL) {
            fclose(fichier_2);
        }
        return;
    }

    // Lire chaque ligne et recopier sauf celle à supprimer
    while (fgets(ligne, sizeof(ligne), fichier_original)) {
        Animal courant;
        if (sscanf(ligne, "%d;%[^;];%[^;];%d;%f;%[^\n]",
 
                   &courant.id, courant.nom, espece_chaine,
                   &courant.annee_naissance, &courant.poids, courant.commentaire) == 6) {

            courant.espece = chaineVersEspece(espece_chaine);

            if (courant.id != id_cherche) {
                fprintf(fichier_2, "%d;%s;%s;%d;%.2f;%s\n",
                courant.id, courant.nom, especeVersChaine(courant.espece),
                courant.annee_naissance, courant.poids, courant.commentaire);
            }
        }
    }

    fclose(fichier_original);
    fclose(fichier_2);

    // Étape 3 : Remplacer l'ancien fichier par le temporaire
    if (remove("animaux/animaux.txt") != 0) {
        printf("Erreur : impossible de supprimer l'ancien fichier.\n");
        return;
    }

    if (rename("animaux/animaux_2.txt", "animaux/animaux.txt") != 0) {
        printf("Erreur : impossible de renommer le fichier temporaire.\n");
        return;
    }

    printf("L'animal avec l'ID %d a ete adopte avec succes !\n", id_cherche);
}
