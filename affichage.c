#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "en_US.utf8");
    
    printf(
        "╔════════════════════════════════╗\n"
        "║  Bienvenue au Refuge ChenYl-Tech  ║\n"
        "╠════════════════════════════════╣\n"
        "║                                ║\n"
        "║ 1. Ajouter un animal           ║\n"
        "║ 2. Rechercher des animaux      ║\n"
        "║ 3. Faire adopter un animal     ║\n"
        "║ 4. Nourrir les animaux        ║\n"
        "║ 5. Voir l'inventaire           ║\n"
        "║ 6. Quitter                     ║\n"
        "║                                ║\n"
        "╚════════════════════════════════╝\n"
    );
    
    return 0;
}