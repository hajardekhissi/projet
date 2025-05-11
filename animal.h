#ifndef ANIMAL_H
#define ANIMAL_H
#include <stdio.h>

// Définition des tailles maximales pour les tableaux de caractères

#define MAX_ANIMAUX 50 //C'est le nombre maximum d'animaux
#define TAILLE_NOM 50 //C'est la taille maximale du prenom de l'animal
#define TAILLE_COMMENTAIRE 256//C'est la taille maximale du commentaire qui est lier a l'animale qui lui correspond

//Ici on a une enumeration qui va enumerer l'ensemble des especes d'animaux du refuge qu'on peut avoir
typedef enum { CHIEN, CHAT, HAMSTER, AUTRUCHE } Espece;

typedef struct {
    
    int id;//On a l'identifiant de l'animal qui est unique 
    
    char nom[TAILLE_NOM];// Ici on a le nom de l'animal qui a pour taille maximale TAILLE_NOM
    
    Espece espece;//Ici on l'espece de l'animal qui est de type espece c'est ce qu'on a defini en haut
    
    int annee_naissance;// Ici on a l'annee de naissance de l'animal qui va etre entre 1900 et 2025
    
    float poids;// Ici on a le poid de l'animal qui va etre poisitif et non nul
    
    char commentaire[TAILLE_COMMENTAIRE];// Ici on a le commentaire qui va decire l'animal quoi 
} Animal;

//Ici on a defini une fonction qui va nous permettre de chosir l'espece de l'animal
Espece choisirEspece();

//Ici on a defini une fonction qui va convertir une chaine de caractere en espece
Espece chaineVersEspece(const char* chaine);

//Ici on a une fonction qui va convertir une espece en chaine de caractere
const char* especeVersChaine(Espece e);

//Ici on a une fonction qui va nous permettre d'adopter un animal
void adopterAnimal(); // Déclaration de la fonction
int comparer(const char* a, const char* b); // Déclaration de la fonction comparer
void afficherInventaire(); // Déclaration de la fonction afficherInventaire
void afficherNourriture(); // Déclaration de la fonction afficherNourriture


#endif