#include "animal.h"
#include <stdio.h>
//Ici on a fait une fonction qui va permettre de comparer deux chaines de caracteres
int comparerChaines(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        char ca = a[i];
        char cb = b[i];

        // Convertir en minuscule
        if (ca >= 'A' && ca <= 'Z') ca += 32;
        if (cb >= 'A' && cb <= 'Z') cb += 32;

        if (ca != cb)
            return 0;

        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}
//Ca c'est la fonction  qui convertit une chaine de caractere en espece c'est celle qu'on a defini dans animal.h
Espece chaineVersEspece(const char* str) {
    if (comparerChaines(str, "Chien")) return CHIEN;
    if (comparerChaines(str, "Chat")) return CHAT;
    if (comparerChaines(str, "Hamster")) return HAMSTER;
    if (comparerChaines(str, "Autruche")) return AUTRUCHE;
    return -1;
}
//Ca c'est la fonction qui va nous permettre de convertir une espece en chaine de caractere c'est celle qu'on a defini dans animal.h
const char* especeVersChaine(Espece e) {
    switch (e) {
        case CHIEN: return "Chien";
        case CHAT: return "Chat";
        case HAMSTER: return "Hamster";
        case AUTRUCHE: return "Autruche";
        default: return "Inconnu";
    }
}
//Ca c'est la fonction qui va nous permettre de chosiir les especes d'animaux c'est celle qu'on a defini dans animal.h
Espece choisirEspece() {
    int c;
    char input;

    while (1) {
        printf("Choisissez une espèce :\n");
        printf("1. Chien\n2. Chat\n3. Hamster\n4. Autruche\nVotre choix : ");

        if (scanf(" %c", &input) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (input >= '1' && input <= '4') {
            if (getchar() == '\n') {
                return (Espece)(input - '1');
            } else {
                printf("Erreur : Entrez UN SEUL chiffre.\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }
        } else {
            printf("Erreur : Chiffre entre 1 et 4 requis.\n");
        }

        while ((c = getchar()) != '\n' && c != EOF);
    }
}