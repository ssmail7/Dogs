records3: readline3.o dogs3.o records3.o
	gcc -o records3 readline3.o dogs3.o records3.o

records3.o: dogs3.h records3.c
	gcc -c records3.c

dogs3.o: readline3.h dogs3.h dogs3.c
	gcc -c dogs3.c

readline3.o: readline3.h readline3.c
	gcc -c readline3.c