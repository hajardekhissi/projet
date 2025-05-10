#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include "rechercher.h"
#include "adopter.h"

void adopterAnimal() {
    char especeStr[20];
    int id_cherche;
    Animal animal;
    int animal_trouve = 0;

    printf("Nous allons tout de suite démarrer l'adoption\n");

    // Demander à l'utilisateur l'ID de l'animal
    printf("Entrez l'ID de l'animal à adopter : ");
    if (scanf("%d", &id_cherche) != 1) {
        printf("Veuillez entrer un nombre entier valide.\n");
        return;
    }

    // Ouvrir le fichier des animaux pour lecture
    FILE *fichier_animaux_lecture = fopen("animaux/animaux.txt", "r");
    if (fichier_animaux_lecture == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des animaux.\n");
        return;
    }

    // Recherche de l'animal à adopter
    animal_trouve = rechercherAnimaux(fichier_animaux_lecture, id_cherche, &animal);
    fclose(fichier_animaux_lecture);

    if (animal_trouve == 0) {
        printf("Désolé, aucun animal trouvé avec l'ID %d.\n", id_cherche);
        return;
    }

    // Réouverture pour réécriture dans un nouveau fichier sans l'animal adopté
    fichier_animaux_lecture = fopen("animaux/animaux.txt", "r");
    FILE *fichier_animaux_temporaire = fopen("animaux/animaux_temp.txt", "w");
    if (fichier_animaux_lecture == NULL || fichier_animaux_temporaire == NULL) {
        printf("Erreur lors de la réouverture des fichiers.\n");
        return;
    }

    // Lire tous les animaux et réécrire ceux qui ne sont pas l'animal adopté
    while (fscanf(fichier_animaux_lecture, "%d;%s;%s;%d;%f;%s",
                  &animal.id, animal.nom, especeStr,
                  &animal.annee_naissance, &animal.poids, animal.commentaire) == 6) {

        animal.espece = chaineVersEspece(especeStr);

        if (animal.id != id_cherche) {
            // Réécrire l'animal non adopté dans le fichier temporaire
            fprintf(fichier_animaux_temporaire, "%d;%s;%s;%d;%.2f;%s\n",
                    animal.id, animal.nom, especeVersChaine(animal.espece),
                    animal.annee_naissance, animal.poids, animal.commentaire);
        }
    }

    fclose(fichier_animaux_lecture);
    fclose(fichier_animaux_temporaire);

    // Remplacer le fichier original par le fichier temporaire
    remove("animaux/animaux.txt");
    rename("animaux/animaux_temp.txt", "animaux/animaux.txt");

    printf("L'animal avec l'ID %d a été adopté avec succès !\n", id_cherche);
}
