<h1 align="center">
🐾 Refuge ChenYl-Tech 🐾
</h1>
</p>
<p align="center">
  <a href="#">
    <img src="https://img.shields.io/badge/Status-En%20cours-orange?style=for-the-badge" alt="Status" />
  </a>
  <a href="#">
    <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language" />
  </a>
  <a href="#">
    <img src="https://img.shields.io/badge/Build%20System-Makefile-green?style=for-the-badge" alt="Build System" />
  </a>
  </p>

## À propos du Projet

Refuge ChenYl-Tech est un programme fait en langage C. Il sert à bien gérer les animaux d'un refuge. Le programme a plusieurs fonctionnalités. On peut par exemple : ajouter des animaux, en chercher, aider à les faire adopter, s'occuper de leur nourriture, et regarder combien il y a d'animaux (l'inventaire). Toutes les informations des animaux sont enregistrées dans un fichier texte qui s'appelle 'animaux/animaux.txt'.

### Construit avec

![GCC](https://img.shields.io/badge/-GCC-05122A?style=for-the-badge&logo=GNU)
![C](https://img.shields.io/badge/-C-05122A?style=for-the-badge&logo=C)
![Make](https://img.shields.io/badge/-make-05122A?style=for-the-badge&logo=C)
![Linux](https://img.shields.io/badge/-linux-05122A?style=for-the-badge&logo=linux)
## Installation et Utilisation

### Pré-requis

* Une version récente d'un compilateur C (comme GCC).
* L'outil `make` pour la compilation.

**Bibliothèques standard utilisées :**
Le projet utilise principalement les bibliothèques standard C incluses avec le compilateur, telles que `stdio.h` (pour les entrées/sorties), `stdlib.h` (pour les fonctions générales, allocation mémoire, etc.), `string.h` (pour la manipulation des chaînes de caractères), `time.h` (pour la génération d'identifiants uniques) et `locale.h`.

### Guide d’installation et Compilation

Pour compiler et préparer l'exécution du programme, naviguez dans votre terminal jusqu'au répertoire racine du projet et utilisez les commandes `make clean` et `make` :

1.  **Nettoyer le projet (optionnel mais recommandé)** :
    ```bash
    make clean
    ```
    Cette commande supprime les fichiers objets (`.o`) et l'exécutable (`exec`) créés lors des compilations précédentes.
2.  **Nettoyer le fichier de données des animaux** :
    ```bash
    make cleanfile
    ```
    **Attention :** Cette commande vide entièrement le fichier `animaux/animaux.txt`, supprimant ainsi toutes les données d'animaux enregistrées.
3.  **Compiler le programme** :
    ```bash
    make
    ```
    Cette commande compile tous les fichiers source (`.c`) nécessaires et lie les objets pour créer le fichier exécutable nommé `exec` (sur Linux/macOS) ou `exec.exe` (sur Windows).

### Fonctionnalités

Le programme **Refuge ChenYl-Tech** offre les fonctionnalités principales suivantes pour gérer les animaux du refuge :

1.  **Ajouter un animal** : Permet d'enregistrer un nouvel animal avec ses caractéristiques (nom, espèce, année de naissance, poids, commentaire). Un identifiant unique est automatiquement généré. La capacité du refuge est limitée.
2.  **Rechercher des animaux** : Propose des options de recherche flexibles :
    * Recherche par nom.
    * Recherche par âge (classification jeune/sénior).
    * Recherche par espèce (Chien, Chat, Hamster, Autruche).
3.  **Faire adopter un animal** : Permet de retirer un animal de la base de données en spécifiant son identifiant unique, simulant son adoption.
4.  **Gérer la nourriture** : Calcule et affiche la quantité de croquettes nécessaire quotidiennement pour un animal spécifique, en fonction de son espèce et de son âge.
5.  **Afficher l'inventaire** : Fournit un aperçu du nombre total d'animaux présents dans le refuge et leur répartition détaillée par espèce.

### Guide d'utilisation

Après avoir compilé le projet, exécutez le programme depuis votre terminal :

1.  **Lancer le programme** :
    ```bash
    ./exec
    ```
    Le programme affichera le menu principal du refuge dans la console.

2.  **Naviguer dans le menu** :
    Entrez le numéro correspondant à l'option souhaitée dans le menu et appuyez sur Entrée. Suivez les instructions affichées pour chaque fonctionnalité .

## Fichiers

Les informations des animaux sont stockées dans un fichier texte.
* Le fichier principal est `animaux/animaux.txt`.
* Chaque ligne de ce fichier représente un animal unique.
* Les informations de chaque animal sont séparées par des points-virgules (`;`).

Le format de chaque ligne est le suivant :
`ID;Nom;Espece;Annee_Naissance;Poids;Commentaire`

Par exemple :
`5451;loubia;Hamster;2024;0.69;il est blanc dalmatien tres calin`

## Données de Démonstration

Le fichier `animaux/animaux.txt` inclus dans le répertoire du projet peut contenir des données pré-remplies servant d'exemple ou de données de démonstration pour tester les différentes fonctionnalités du programme immédiatement après la compilation.

## Erreurs

Bien que des efforts aient été faits pour gérer les erreurs (comme les erreurs de saisie ou les problèmes d'ouverture de fichier), des comportements inattendus pourraient survenir dans certains cas limites. Assurez-vous de suivre les instructions de saisie demandées par le programme.

## Auteurs

Ce projet a été réalisé par :
* HAJAR DEKHISSI
* ZBEIR YASMINE

