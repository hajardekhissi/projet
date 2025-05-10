#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "rechercher.h" // Inclure pour utiliser rechercherAnimaux

void adopterAnimal() {
    printf("Nous allons tout de suite demmarer l'adoption\n");

    FILE *fichier_des_animaux = fopen("animaux/animaux.txt", "r+");
    if (fichier_des_animaux == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des animaux.\n");
        return;
    }

    int id_cherche;
    printf("Entrez l'ID de l'animal a adopter : ");
    if (scanf("%d", &id_cherche) != 1) {
        printf("Veuillez entrer un nombre entier valide\n");
        fclose(fichier_des_animaux);
        return;
    }
    while (getchar() != '\n');

    Animal animal;
    int animal_trouve = 0;

    // Utiliser la fonction rechercherAnimaux du fichier rechercher.c
    // But we need to pass the address of animal
    animal_trouve = rechercherAnimaux(fichier_des_animaux, id_cherche, animal);

    if (animal_trouve) {
        // ... (le reste de votre code pour adopter)
    } else {
        fclose(fichier_des_animaux);
        printf("Desole, aucun animal trouve avec l'ID %d.\n", id_cherche);
    }

    printf("Nous avons terminer la procedure d'adoption\n");
}