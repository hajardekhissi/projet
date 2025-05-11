#include "animal.h"
#include <stdio.h>
#include <string.h>
#include "rechercher.h"

// Fonction pour rechercher un animal par ID
int rechercher_id(FILE *fichier, int idRecherche, Animal *resultat) {
    char espece_chaine[20];
    int trouve = 0;

    if (fichier == NULL) {
        printf("Erreur : fichier invalide.\n");
        return 0;
    }

    fseek(fichier, 0, SEEK_SET);

    while (fscanf(fichier, "%d;%[^;];%[^;];%d;%f;%[^\n]\n",
                  &((*resultat).id), (*resultat).nom, espece_chaine,
                  &((*resultat).annee_naissance), &((*resultat).poids), 
                  (*resultat).commentaire) == 6) {
        
        (*resultat).espece = chaineVersEspece(espece_chaine);

        if ((*resultat).id == idRecherche) {
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun animal trouve avec l'ID %d.\n", idRecherche);
    } else {
        printf("Animal trouve :\n");
        printf("ID: %d\n", (*resultat).id);
        printf("Nom: %s\n", (*resultat).nom);
        printf("Espece: %s\n", especeVersChaine((*resultat).espece));
        printf("Annee de naissance: %d\n", (*resultat).annee_naissance);
        printf("Commentaire: %s\n", (*resultat).commentaire);
    }

    return trouve;
}

// Fonction pour rechercher un animal par nom
void rechercher_nom(FILE *fichier) {
    Animal animal;
    char espece_chaine[20];
    int trouve = 0;
    char nom_recherche[50];

    printf("Entrez le nom a rechercher : ");
    scanf("%s", nom_recherche);
    
    fseek(fichier, 0, SEEK_SET);

    while (fscanf(fichier, "%d;%[^;];%[^;];%d;%f;%[^\n]\n",
                  &animal.id, animal.nom, espece_chaine,
                  &animal.annee_naissance, &animal.poids, 
                  animal.commentaire) == 6) {
        
        if (strcmp(animal.nom, nom_recherche) == 0) {
            trouve = 1;
            printf("\nAnimal trouve :\n");
            printf("ID: %d\n", animal.id);
            printf("Nom: %s\n", animal.nom);
            printf("Espece: %s\n", espece_chaine);
            printf("Annee de naissance: %d\n", animal.annee_naissance);
            printf("Commentaire: %s\n", animal.commentaire);
        }
    }

    if (trouve==0) {
        printf("Aucun animal trouve avec le nom %s.\n", nom_recherche);
    }
}

// Fonction pour rechercher un animal par âge
int rechercher_age(FILE *fichier) {
    Animal animal;
    char espece_chaine[20];
    int trouve = 0;
    char choix[10];
    int annee_actuelle = 2025;

    printf("Rechercher des animaux (jeune/senior) ? ");
    scanf("%s", choix);

    fseek(fichier, 0, SEEK_SET);

    while (fscanf(fichier, "%d;%[^;];%[^;];%d;%f;%[^\n]\n",
                  &animal.id, animal.nom, espece_chaine,
                  &animal.annee_naissance, &animal.poids, 
                  animal.commentaire) == 6) {
        
        int age = annee_actuelle - animal.annee_naissance;

        if ((strcmp(choix, "jeune") == 0 && age < 2) || 
            (strcmp(choix, "senior") == 0 && age > 10)) {
            trouve = 1;
            printf("\nAnimal trouve :\n");
            printf("ID: %d\n", animal.id);
            printf("Nom: %s\n", animal.nom);
            printf("Espece: %s\n", espece_chaine);
            printf("Age: %d ans\n", age);
        }
    }

    if (!trouve) {
        printf("Aucun animal %s trouve.\n", choix);
    }
    return trouve;
}

// Fonction pour rechercher un animal par espèce
void rechercher_espece(FILE *fichier) {
    Animal animal;
    char espece_chaine[20];
    int trouve = 0;
    char espece_recherchee[20];

    printf("Entrez l'espece à rechercher : ");
    scanf("%s", espece_recherchee);

    fseek(fichier, 0, SEEK_SET);

    while (fscanf(fichier, "%d;%[^;];%[^;];%d;%f;%[^\n]\n",
                  &animal.id, animal.nom, espece_chaine,
                  &animal.annee_naissance, &animal.poids, 
                  animal.commentaire) == 6) {
        
        if (strcmp(espece_chaine, espece_recherchee) == 0) {
            trouve = 1;
            printf("\nAnimal trouve :\n");
            printf("ID: %d\n", animal.id);
            printf("Nom: %s\n", animal.nom);
            printf("Espece: %s\n", espece_chaine);
            printf("Annee de naissance: %d\n", animal.annee_naissance);
        }
    }

    if (!trouve) {
        printf("Aucun animal de l'espece %s trouve.\n", espece_recherchee);
    }
}

