# Variables
CC = gcc                    # Le compilateur
CFLAGS = -Wall -g            # Options de compilation (détails sur les warnings et débogage)
LDFLAGS =                    # Si tu as besoin de lier des bibliothèques supplémentaires

# Liste des fichiers source
SRC = main.c ajouter.c affichage.c animal.c choisirespece.c inventaire.c nourriture.c rechercher.c

# Transformation des fichiers .c en .o (objets)
OBJ = $(SRC:.c=.o)

# Nom de l'exécutable final
EXEC = chenil.exe

# Règle par défaut (créer l'exécutable)
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

# Règle pour créer les fichiers objets à partir des fichiers sources
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés (objets et l'exécutable)
clean:
	rm -f $(OBJ) $(EXEC)
