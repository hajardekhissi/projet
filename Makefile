all: exec
animal.o: animal.c animal.h
	gcc -c animal.c -o animal.o
choisirespece.o: choisirespece.c choisirespece.h
	gcc -c choisirespece.c -o choisirespece.o
inventaire.o: inventaire.c inventaire.h
	gcc -c inventaire.c -o inventaire.o
nourriture.o: nourriture.c animal.h  rechercher.h nourriture.h
	gcc -c nourriture.c -o nourriture.o
rechercher.o: rechercher.c rechercher.h animal.h
	gcc -c rechercher.c -o rechercher.o
adopter.o: adopter.c animal.h rechercher.h adopter.h
	gcc -c adopter.c -o adopter.o
identifiant_ani.o: identifiant_ani.c identifiant_ani.h
	gcc -c identifiant_ani.c -o identifiant_ani.o
affichage.o: affichage.c affichage.h
	gcc -c affichage.c -o affichage.o
ajouter.o: ajouter.c identifiant_ani.h affichage.h animal.h
	gcc -c ajouter.c -o ajouter.o
main.o: main.c ajouter.h affichage.h rechercher.h adopter.h nourriture.h inventaire.h identifiant_ani.h choisirespece.h animal.h
	gcc -c main.c -o main.o
exec: main.o ajouter.o affichage.o animal.o choisirespece.o inventaire.o nourriture.o rechercher.o adopter.o identifiant_ani.o
	gcc main.o ajouter.o affichage.o animal.o choisirespece.o inventaire.o nourriture.o rechercher.o adopter.o identifiant_ani.o -o exec

# Delete execution files
clean:
	rm main.o ajouter.o affichage.o animal.o choisirespece.o inventaire.o nourriture.o rechercher.o adopter.o identifiant_ani.o
	rm exec
	
cleanfile:
	rm animaux/animaux.txt
	touch animaux/animaux.txt
