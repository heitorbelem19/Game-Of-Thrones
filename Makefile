main:	main.o	arvore.o
	gcc -g main.o arvore.o -o main
main.o:	main.c
	gcc -g -c main.c
arvore.o:	arvore.c	arvore.h
	gcc -g -c arvore.c
clean:
	rm *.o
