testlib : main.o bitmap.o debug.o hash.o hex_dump.o list.o
	gcc -Wall -o testlib main.o bitmap.o debug.o hash.o hex_dump.o list.o

main.o : main.c
	gcc -Wall -c main.c

bitmap.o : bitmap.c
	gcc -Wall -c bitmap.c

debug.o : debug.c
	gcc -Wall -c debug.c

hash.o : hash.c
	gcc -Wall -c hash.c

hex_dump.o : hex_dump.c
	gcc -Wall -c hex_dump.c

list.o : list.c
	gcc -Wall -c list.c

clean :
	rm testlib *.o
