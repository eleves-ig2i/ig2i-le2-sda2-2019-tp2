all: testLibListe.exe

lib : libListe.o libElt.o

INC = -I./libElt

testLibListe.exe : testLibListe.o libListe.o libElt.o
	gcc $(INC) libElt.o libListe.o testLibListe.o -o testLibListe.exe

testLibListe.o : testLibListe.c
	gcc $(INC) -c testLibListe.c

libListe.o : libListe.c
	gcc $(INC) -c libListe.c

libElt.o : 
	cd ./libElt; make lib;


clean:
	rm -f  *.o *.exe
	cd ./libElt; make clean;
