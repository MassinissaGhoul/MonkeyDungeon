monkeydungeon: main.o
	gcc -o monkeydungeon main.o

main.o: main.c
	gcc -c main.c