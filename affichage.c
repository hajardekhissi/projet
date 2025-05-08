#include <stdio.h>
#define VIOLET  "\033[95m"
#define VERT    "\033[92m"
#define BLEU    "\033[94m"
#define BLEU_CLAIR "\033[96m"
#define JAUNE   "\033[93m"
#define ROUGE   "\033[91m"
#define RESET   "\033[0m"


void afficherMenu() {
    printf(VIOLET "╔═════════════════════════════════════════════╗\n" RESET);
    printf(VIOLET "║" BLEU "          /)/) Bienvenue au Refuge ChenYl-Tech (\\(\\          " VIOLET "║\n" RESET);
    printf(VIOLET "║" BLEU "         ( . .)                               ( . .)         " VIOLET "║\n" RESET);
    printf(VIOLET "║" BLEU "        C(\")(\")                               (\")(\")C        " VIOLET "║\n" RESET);
    printf(VIOLET "╚═════════════════════════════════════════════╝\n" RESET);

    printf(BLEU "  1. Ajouter un animal\n" RESET);
    printf(BLEU "  2. Rechercher des animaux\n" RESET);
    printf(BLEU "  3. Faire adopter un animal\n" RESET);
    printf(BLEU "  4. Nourrir les animaux\n" RESET);
    printf(BLEU "  5. Voir l'inventaire\n" RESET);
    printf(ROUGE"  6. Quitter le refuge\n" RESET);

    printf( JAUNE "Votre choix : " RESET);
}