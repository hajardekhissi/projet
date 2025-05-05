#include <stdio.h>

// Définition des codes de couleur ANSI
#define VIOLET  "\033[95m"
#define VERT    "\033[92m"
#define BLEU    "\033[94m"
#define BLEU_CLAIR "\033[96m"
#define JAUNE   "\033[93m"
#define ROUGE   "\033[91m"
#define RESET   "\033[0m"

void afficherMenu() {
    printf(VIOLET "╔═════════════════════════════════════════════╗\n" RESET);
    printf(VIOLET "║" BLEU "        🐾 " VERT "Bienvenue au Refuge ChenYl-Tech" BLEU " 🐾        " VIOLET "║\n" RESET);
    printf(VIOLET "╚═════════════════════════════════════════════╝\n" RESET);

    printf(BLEU "  " VERT "1." BLEU " Ajouter un animal" BLEU_CLAIR "        ➕🐶🐱\n" RESET);
    printf(BLEU "  " VERT "2." BLEU " Rechercher des animaux" BLEU_CLAIR "     🔎🐾\n" RESET);
    printf(BLEU "  " VERT "3." BLEU " Faire adopter un animal" BLEU_CLAIR "    🏠💖\n" RESET);
    printf(BLEU "  " VERT "4." BLEU " Nourrir les animaux" BLEU_CLAIR "      🥣😋\n" RESET);
    printf(BLEU "  " VERT "5." BLEU " Voir l'inventaire" BLEU_CLAIR "        📦📜\n" RESET);
    printf(BLEU "  " ROUGE "6." BLEU " Quitter le refuge" BLEU_CLAIR "        🚪👋\n" RESET);

    printf(BLEU_CLAIR "\n👉 " JAUNE "Votre choix : " RESET);
}