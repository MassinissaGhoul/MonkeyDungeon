monkeydungeon: main.o dungeon.o
	gcc -o monkeydungeon main.o dungeon.o

main.o: main.c
	gcc -c main.c

dungeon.o: dungeon.c
	gcc -c dungeon.c

ifneq ($(OS),Windows_NT)
clean:
		rm -f *.o
else
clean:
		del /f /q *.o
endif

all:
		make monkeydungeon
		make clean