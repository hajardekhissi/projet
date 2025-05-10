#include "animal.h" // Inclut chaineVersEspece, comparer, convertir_en_minuscule, especeVersChaine (ajoute si pas déjà fait)
#include <stdio.h>
// Pas de string.h

// Fonction pour rechercher un animal par ID dans un fichier
int rechercherAnimaux(FILE *fichier, int idRecherche, Animal *resultat) {
    char especeStr[20]; // Buffer pour lire la chaîne de l'espèce

    printf("DEBUG: Entree dans rechercherAnimaux. Recherche ID: %d\n", idRecherche); // Debug

    // Vérifie si le fichier est valide
    if (fichier == NULL) {
        printf("Erreur : fichier invalide dans rechercherAnimaux.\n");
        return 0;
    }

    // !!! Correction ajoutée : Remettre le pointeur au début du fichier !!!
    fseek(fichier, 0, SEEK_SET);

    printf("DEBUG: Pointeur fichier remis au debut.\n"); // Debug


    // Lecture ligne par ligne dans le fichier en utilisant fscanf
    while (fscanf(fichier, "%d;%s;%s;%d;%f;%s",
                  &(*resultat).id, (*resultat).nom, especeStr,
                  &(*resultat).annee_naissance, &(*resultat).poids, (*resultat).commentaire) == 6) {

        printf("DEBUG: Ligne lue - ID: %d, Nom: %s, EspeceStr: %s, Annee: %d, Poids: %.2f, Commentaire: %s\n",
               (*resultat).id, (*resultat).nom, especeStr, (*resultat).annee_naissance, (*resultat).poids, (*resultat).commentaire); // Debug


        // Convertir la chaîne de caractères de l'espèce en type Espece
        (*resultat).espece = chaineVersEspece(especeStr);
         printf("DEBUG: Espece '%s' convertie en Espece enum: %d\n", especeStr, (*resultat).espece); // Debug
         // Si possible, ajoutez l'include de animal.h dans rechercher.c
         // et utilisez especeVersChaine pour afficher l'enum:
         // printf("DEBUG: Espece '%s' convertie en Espece enum: %s\n", especeStr, especeVersChaine((*resultat).espece)); // Debug


        // Vérifier si c'est l'animal recherché
        printf("DEBUG: Comparaison ID lu (%d) avec ID cherche (%d)\n", (*resultat).id, idRecherche); // Debug
        if ((*resultat).id == idRecherche) {
            printf("DEBUG: Animal trouvé ! ID: %d\n", (*resultat).id); // Debug
            return 1; // L'animal a été trouvé
        } else {
             printf("DEBUG: ID lu ne correspond pas. On continue.\n"); // Debug
        }
    }

    printf("DEBUG: Fin du fichier. Animal non trouve.\n"); // Debug
    return 0; // L'animal n'a pas été trouvé après avoir parcouru tout le fichier
}