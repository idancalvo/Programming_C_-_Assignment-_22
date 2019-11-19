mymat: mymat.o mat.o translateText.o cleanText.o
	gcc -g -ansi -Wall -pedantic mymat.o mat.o translateText.o cleanText.o -o mymat

mymat.o: mymat.c mymat.h
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o

mat.o: mat.c mat.h
	gcc -c -ansi -Wall -pedantic mat.c -o mat.o

translateText.o: translateText.c translateText.h
	gcc -c -ansi -Wall -pedantic translateText.c -o translateText.o

cleanText.o: cleanText.c cleanText.h
	gcc -c -ansi -Wall -pedantic cleanText.c -o cleanText.o


