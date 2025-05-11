#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include "identifiant_ani.h"
#include "affichage.h" 
#define ROUGE   "\033[91m"// Pour les couleurs
#define BLEU_CLAIR "\033[96m"
#define JAUNE   "\033[93m"
#define RESET   "\033[0m"
#define VERT    "\033[92m"

#define TAILLE_NOM 50
#define TAILLE_COMM 100

int compterAnimaux() {
    FILE *fichier = fopen("animaux/animaux.txt", "r");
    if (fichier==0){
        return 0;
    }

    int compteur= 0;
    char ligne[512];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        compteur++;
    }

    fclose(fichier);
    return compteur;
}

void ajouterAnimal() {
    #ifdef _WIN32
        system("mkdir animaux");
    #else
        system("mkdir -p animaux");
    #endif

    int nb_animaux = compterAnimaux();
    if (nb_animaux >= MAX_ANIMAUX) {
        printf(ROUGE "\nLe refuge est plein ! Impossible d'ajouter un nouvel animal (%d max).\n" RESET, MAX_ANIMAUX);
   
    }

    FILE *fichier = fopen("animaux/animaux.txt", "a");
    if (fichier == NULL) {
        printf(ROUGE "Erreur : Impossible d'ouvrir le fichier des animaux pour l'ajout.\n" RESET);
 
    }

    Animal nouvelAnimal;
    nouvelAnimal.id = identifiant_generateur();

    printf(BLEU_CLAIR "\n*** Ajouter un nouvel animal ***\n" RESET);

    // Nom
    printf(JAUNE "Nom de l'animal : " RESET);
    if (fgets(nouvelAnimal.nom, TAILLE_NOM, stdin) == NULL) {
        printf(ROUGE "Erreur lors de la lecture du nom.\n" RESET);
        fclose(fichier);
 
    }
    nouvelAnimal.nom[strcspn(nouvelAnimal.nom, "\n")] = '\0';

    // Espèce
    nouvelAnimal.espece = choisirEspece();

    // Année de naissance
    do {
        printf(JAUNE "Annee de naissance (1900-2025) : " RESET);
        if (scanf("%d", &nouvelAnimal.annee_naissance) != 1) {
            printf(ROUGE "Erreur : Veuillez entrer une annee valide.\n" RESET);
            while (getchar() != '\n');
        } else if (nouvelAnimal.annee_naissance < 1900 || nouvelAnimal.annee_naissance > 2025) {
            printf(ROUGE "Erreur : L'annee doit être entre 1900 et 2025.\n" RESET);
        } else {
            break;
        }
    } while (1);
    while (getchar() != '\n');

    // Poids
    do {
        printf(JAUNE "Poids (kg, > 0) : " RESET);
        if (scanf("%f", &nouvelAnimal.poids) != 1) {
            printf(ROUGE "Erreur : Veuillez entrer un poids valide.\n" RESET);
            while (getchar() != '\n');
        } else if (nouvelAnimal.poids <= 0) {
            printf(ROUGE "Erreur : Le poids doit etre superieur à 0.\n" RESET);
        } else {
            break;
        }
    } while (1);
    while (getchar() != '\n');

    // Commentaire
    printf(JAUNE "Commentaire : " RESET);
    if (fgets(nouvelAnimal.commentaire, TAILLE_COMM, stdin) == NULL) {
        printf(ROUGE "Erreur lors de la lecture du commentaire.\n" RESET);
        fclose(fichier);

    }
    nouvelAnimal.commentaire[strcspn(nouvelAnimal.commentaire, "\n")] = '\0';

    // Sauvegarde
    fprintf(fichier, "%d;%s;%s;%d;%.2f;%s\n",
            nouvelAnimal.id,
            nouvelAnimal.nom,
            especeVersChaine(nouvelAnimal.espece),
            nouvelAnimal.annee_naissance,
            nouvelAnimal.poids,
            nouvelAnimal.commentaire);
    fclose(fichier);

    printf(VERT "\nAnimal numero %d ajoute avec succes !\n" RESET, nouvelAnimal.id);
}