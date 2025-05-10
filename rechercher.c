#include "animal.h"
#include <stdio.h>
// Pas de string.h

int rechercherAnimaux(FILE *f, int idRecherche, Animal *a) {
    char especeTxt[20];
    char ligneEntiere[256];

    if (f == NULL) {
        return 0;
    }

    while (fgets(ligneEntiere, sizeof(ligneEntiere), f)) {
        if (sscanf(ligneEntiere, "%d;%s;%s;%d;%f;%s",
                   &a->id, a->nom, especeTxt,
                   &a->annee_naissance, &a->poids, a->commentaire) == 6) {

            a->espece = chaineVersEspece(especeTxt);

            if (a->id == idRecherche) {
                return 1;
            }
        }
    }

    return 0;
}
