#include <stdio.h>
#include <stdlib.h>
// Pas de string.h
#include "animal.h" // Inclut chaineVersEspece, comparer, especeVersChaine
#include "rechercher.h" // Pour utiliser rechercherAnimaux
#include "adopter.h"

void adopterAnimal() {
    int id_cherche;
    Animal animal_trouve_data; // Structure pour stocker les données de l'animal trouvé par rechercherAnimaux
    char especeStr[20]; // Buffer pour lire la chaîne de l'espèce pendant la copie

    printf("Nous allons tout de suite démarrer l'adoption\n");

    // Demander à l'utilisateur l'ID de l'animal à adopter
    printf("Entrez l'ID de l'animal à adopter : ");
    if (scanf("%d", &id_cherche) != 1) {
        printf("Veuillez entrer un nombre entier valide.\n");
        while (getchar() != '\n'); // Vider le buffer
        return;
    }
    while (getchar() != '\n'); // Vider le reste de la ligne après un scanf réussi

    // --- Étape 1 : Rechercher l'animal à adopter ---
    // rechercherAnimaux gère l'ouverture/fermeture et le fseek.
    // Elle nous dit si l'animal existe et met ses données dans animal_trouve_data.
    FILE *fichier_pour_recherche = fopen("animaux/animaux.txt", "r");
     if (fichier_pour_recherche == NULL) {
         printf("Erreur : Impossible d'ouvrir le fichier des animaux pour la recherche d'adoption.\n");
         return;
     }
    int animal_trouve_flag = rechercherAnimaux(fichier_pour_recherche, id_cherche, &animal_trouve_data);
     // Note : rechercherAnimaux ferme le fichier passé en argument.


    if (animal_trouve_flag == 0) {
        printf("Désolé, aucun animal trouvé avec l'ID %d.\n", id_cherche);
        return;
    }
     // Si on arrive ici, l'animal a été trouvé.

    // --- Étape 2 : Créer un nouveau fichier sans l'animal adopté ---
    // Ouvrir le fichier original pour lecture et créer un fichier temporaire pour écriture
    FILE *fichier_animaux_lecture = fopen("animaux/animaux.txt", "r"); // Ouvrir à nouveau pour relire
    FILE *fichier_animaux_temporaire = fopen("animaux/animaux_temp.txt", "w");

    if (fichier_animaux_lecture == NULL || fichier_animaux_temporaire == NULL) {
        printf("Erreur lors de la réouverture des fichiers pour modification.\n");
        if (fichier_animaux_temporaire != NULL) fclose(fichier_animaux_temporaire);
        if (fichier_animaux_lecture != NULL) fclose(fichier_animaux_lecture);
        return;
    }

    // Remettre le pointeur au début du fichier original pour la copie
    fseek(fichier_animaux_lecture, 0, SEEK_SET);

    // Lire toutes les lignes du fichier original et réécrire celles qui ne correspondent PAS à l'animal adopté
    Animal animal_courant; // Structure pour lire les données de chaque ligne
    // Note : Utilisation de fscanf ici suppose toujours que les champs nom/commentaire n'ont pas d'espaces.
    while (fscanf(fichier_animaux_lecture, "%d;%s;%s;%d;%f;%s",
                  &animal_courant.id, animal_courant.nom, especeStr,
                  &animal_courant.annee_naissance, &animal_courant.poids, animal_courant.commentaire) == 6) {

        // Convertir la chaîne d'espèce lue en type Espece
        animal_courant.espece = chaineVersEspece(especeStr);

        // Si l'ID de l'animal lu n'est PAS l'ID de l'animal à adopter, on écrit cette ligne dans le fichier temporaire
        if (animal_courant.id != id_cherche) {
            fprintf(fichier_animaux_temporaire, "%d;%s;%s;%d;%.2f;%s\n",
                    animal_courant.id, animal_courant.nom, especeVersChaine(animal_courant.espece), // Utiliser especeVersChaine pour l'écriture
                    animal_courant.annee_naissance, animal_courant.poids, animal_courant.commentaire);
        }
    }

    // --- Étape 3 : Remplacer le fichier original par le fichier temporaire ---
    fclose(fichier_animaux_lecture);
    fclose(fichier_animaux_temporaire);

    // Supprimer le fichier original
    if (remove("animaux/animaux.txt") != 0) {
        printf("Erreur lors de la suppression de l'ancien fichier d'animaux.\n");
         if (rename("animaux/animaux_temp.txt", "animaux/animaux.txt") != 0) {
             printf("ERREUR CRITIQUE : Impossible de renommer le fichier temporaire. Le fichier original n'existe plus, et le fichier animaux_temp.txt doit être renommé manuellement en animaux.txt\n");
         }
         return;
    }

    // Renommer le fichier temporaire pour qu'il devienne le nouveau fichier original
    if (rename("animaux/animaux_temp.txt", "animaux/animaux.txt") != 0) {
        printf("Erreur lors du renommage du fichier temporaire.\n");
        printf("Le fichier animaux_temp.txt contient les données mises à jour. Veuillez le renommer manuellement en animaux.txt\n");
        return;
    }

    // Si tout s'est bien passé
    printf("L'animal avec l'ID %d a été adopté avec succès !\n", id_cherche);
}