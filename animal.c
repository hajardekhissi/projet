#include "animal.h"
#include <stdio.h>
int comparer(const char *a,const char *b) {
    int i = 0;
    
    // Comparer les chaînes caractère par caractère
    while (a[i] != '\0' && b[i] != '\0') {
        // Comparer sans tenir compte de la casse (utiliser | 32 pour ignorer la casse)
        if ((a[i] | 32) != (b[i] | 32)) {
            return 0;  // Les chaînes sont différentes
        }
        i++;
    }

    // Vérifier si les deux chaînes sont terminées en même temps
    if (a[i] == '\0' && b[i] == '\0') {
        return 1;  // Les chaînes sont égales
    }

    return 0;  // Une chaîne est plus longue que l'autre
}

//Ca c'est la fonction  qui convertit une chaine de caractere en espece c'est celle qu'on a defini dans animal.h
Espece chaineVersEspece(const char* str){

    if (comparer(str, "Chien")==0){
     return CHIEN;
    }
    if (comparer(str, "Chat")==0){
        return CHAT;
    }
    if (comparer(str, "Hamster")==0){
        return HAMSTER;
    }
    if (comparer(str, "Autruche")==0){

    return AUTRUCHE;
    }
    return -1;
}
//Ca c'est la fonction qui va nous permettre de convertir une espece en chaine de caractere c'est celle qu'on a defini dans animal.h
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
        return "L'animal entrer ne correspond a aucun des animaux existant";
    }
}
//Ca c'est  fonction qui va nous permettre de chosiir les especes d'animaux c'est celle qu'on a defini dans animal.h
// Fonction permettant à l'utilisateur de choisir une espèce parmi 4 options
Espece choisirEspece() {
    int choix_utilisateur;
    // Affichage du menu de choix d'espèce
    while (1) {
        printf("Choisissez une espece :\n");
        printf("1. Chien\n");
        printf("2. Chat\n");
        printf("3. Hamster\n");
        printf("4. Autruche\n");


        // Lire le choix de l'utilisateur
        if (scanf("%d", &choix_utilisateur) != 1) {
            // Si la saisie n'est pas un nombre, on vide le buffer et on recommence
            while (getchar() != '\n');
            printf("Veuillez entrez un nombre entre 1 et 4!!\n"); 
        } else {
            // Si le choix est valide, on retourne l'espèce correspondante
            if (choix_utilisateur == 1) {
                return CHIEN;
            }
            else if (choix_utilisateur == 2) {
                return CHAT;
            }
            else if (choix_utilisateur == 3) {
                return HAMSTER;
            }
            else if (choix_utilisateur == 4) {
                return AUTRUCHE;
            }
            else {
                // Si le choix est en dehors de 1 à 4, on affiche une erreur
                printf("Veuillez saisir une option existante.\n");
                while (getchar() != '\n'); // Vider le buffer
            }
        }
    }
}
