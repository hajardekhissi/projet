#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "identifiant_ani.h"


int identifiant_generateur() {
    int id;
    id = ((int)(time(NULL) % 9000) + 1000) + (rand() % 100);
    return id;
}
