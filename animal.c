#include "animal.h"
#include <stdio.h>
// Pas de string.h ni ctype.h

// Implémentation manuelle très simple de la conversion en minuscule (pour les lettres ASCII)
char convertir_en_minuscule(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); // Convertit majuscule en minuscule
    }
    return c; // Laisse les autres caractères inchangés
}

// Implémentation manuelle d'une comparaison de chaînes insensible à la casse
int comparer(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        // Comparer les caractères après les avoir mis en minuscule manuellement
        if (convertir_en_minuscule(a[i]) != convertir_en_minuscule(b[i])) {
            return 0; // Les chaînes sont différentes
        }
        i++;
    }
    // Les chaînes sont égales si les deux se terminent au même point
    return a[i] == '\0' && b[i] == '\0'; // Retourne 1 si égales, 0 sinon
}

// Implémentation manuelle de la copie de chaîne avec taille limite
void copierChaine(char* dest, const char* src, int taille_max) {
    int i = 0;
    while (i < taille_max - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Assurer la terminaison de la chaîne
}


// Fonction pour convertir une chaîne de caractères en type Espece
Espece chaineVersEspece(const char* str){
    // Utiliser la fonction comparer manuelle et vérifier si elle retourne 1 (égal)
    if (comparer(str, "Chien") == 1){ // <-- CHANGEMENT ICI : == 1
     return CHIEN;
    }
    if (comparer(str, "Chat") == 1){ // <-- CHANGEMENT ICI : == 1
        return CHAT;
    }
    if (comparer(str, "Hamster") == 1){ // <-- CHANGEMENT ICI : == 1
        return HAMSTER;
    }
    if (comparer(str, "Autruche") == 1){ // <-- CHANGEMENT ICI : == 1
        return AUTRUCHE;
    }
    return -1; // Espèce non reconnue
}
// Reste de animal.c (especeVersChaine, choisirEspece) ... elles étaient déjà bien
const char* especeVersChaine(Espece animal) {
    if (animal == CHIEN) {
        return "Chien";
    }
    else if (animal == CHAT) {
        return "Chat";
    }
    else if (animal == HAMSTER) {
        return "Hamster";
    }
    else if (animal == AUTRUCHE) {
        return "Autruche";
    }
    else {
        return "Espece inconnue";
    }
}

Espece choisirEspece() {
    int choix_utilisateur;
    while (1) {
        printf("Choisissez une espece :\n");
        printf("1. Chien\n");
        printf("2. Chat\n");
        printf("3. Hamster\n");
        printf("4. Autruche\n");

        if (scanf("%d", &choix_utilisateur) != 1) {
            while (getchar() != '\n');
            printf("Veuillez entrez un nombre entre 1 et 4!!\n");
        } else {
            if (choix_utilisateur >= 1 && choix_utilisateur <= 4) {
                while (getchar() != '\n');
                switch (choix_utilisateur) {
                    case 1: 
                    return CHIEN;
                    case 2: 
                    return CHAT;
                    case 3: 
                    return HAMSTER;
                    case 4: 
                    return AUTRUCHE;
                }
            }
            else {
                printf("Veuillez saisir une option existante.\n");
                while (getchar() != '\n');
            }
        }
    }
}