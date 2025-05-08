#include <stdio.h>
#include <stdlib.h>
#include "animal.h"

void adopterAnimal() {
    
    printf("Nous allons tout de suite demmarer l'adoption\n");

    // Ouvrir le fichier des animaux en mode lecture
    FILE *fichier_des_animaux = fopen("animaux/animaux.txt", "r");
    if (fichier_des_animaux == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des animaux.\n");
        return;
    }

    // Demander à l'utilisateur l'ID de l'animal à adopter
    int id_cherche;
    printf("Entrez l'ID de l'animal à adopter : ");
    if (scanf("%d", &id_cherche)!=1){
        printf("Veuillez entrer un nombre entier valide\n");
        fclose(fichier_des_animaux);
        return;
    }

    // Créer un fichier temporaire pour stocker les animaux restants
    FILE *fichier_temp = fopen("animaux/animaux_temp.txt", "w");
    if (fichier_temp == NULL) {
        printf("Erreur : Impossible de créer le fichier temporaire.\n");
        fclose(fichier_des_animaux);
        return;
    }

    int animal_trouve = 0;
    Animal animal;

    // Parcours du fichier des animaux
    char especeStr[20]; // Variable temporaire pour lire l'espèce sous forme de texte

    while (fscanf(fichier_des_animaux, "%d;%s;%s;%d;%f;%s", 
                  &animal.id, animal.nom, especeStr, &animal.annee_naissance, &animal.poids, animal.commentaire) == 6) {
        
        animal.espece = chaineVersEspece(especeStr); // Convertir la chaîne en enum Espece
    
        if (animal.id == id_cherche) {
            animal_trouve = 1;  // L'animal a été trouvé, donc on ne l'écrit pas
        } else {
            // Écrire les animaux non adoptés dans le fichier temporaire
            fprintf(fichier_temp, "%d;%s;%s;%d;%.2f;%s\n",
                    animal.id, animal.nom, especeVersChaine(animal.espece),
                    animal.annee_naissance, animal.poids, animal.commentaire);
        }
    }
    

    // Fermeture des fichiers
    fclose(fichier_des_animaux);
    fclose(fichier_temp);

    // Vérifier si l'animal a été trouvé
    if (animal_trouve) {
        // Supprimer l'ancien fichier et renommer le fichier temporaire
        remove("animaux/animaux.txt");
        rename("animaux/animaux_temp.txt", "animaux/animaux.txt");
        printf("Félicitations ! L'animal avec l'ID %d a été adopté.\n", id_cherche);
    } else {
        // Supprimer le fichier temporaire si l'animal n'a pas été trouvé
        remove("animaux/animaux_temp.txt");
        printf("Désolé, aucun animal trouvé avec l'ID %d.\n", id_cherche);
    }

    printf("Nous avons terminer la procedure d'adoption\n");
}
