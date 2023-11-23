monkeydungeon: main.o dungeon.o room.o corridor.o
	gcc -o monkeydungeon main.o dungeon.o room.o corridor.o

main.o: main.c
	gcc -c main.c

dungeon.o: dungeon.c
	gcc -c dungeon.c

room.o: room.c
	gcc -c room.c

corridor.o: corridor.c
	gcc -c corridor.c

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