CC = gcc
CFLAGS = -Wall -g
OBJS = main.o ajouter.o affichage.o animal.o choisirespece.o inventaire.o nourriture.o rechercher.o nettoyeur.o adopter.o identifiant_ani.o

chenil.exe: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o chenil.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) chenil.exe