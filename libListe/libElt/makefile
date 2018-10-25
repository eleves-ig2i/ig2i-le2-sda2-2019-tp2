all: testLibElt.exe

lib : libElt.o testLibElt.exe
	cp libElt.o ..

testLibElt.exe : testlibElt.o libElt.o
	gcc libElt.o testLibElt.o -o testLibElt.exe

testlibElt.o : testLibElt.c
	gcc -c testLibElt.c

libElt.o : libElt.c 
	gcc -c libElt.c


clean:
	rm -f  *.o *.exe
