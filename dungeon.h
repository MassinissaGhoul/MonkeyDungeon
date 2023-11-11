#ifndef DUNGEON_H
#define DUNGEON_H


typedef struct room {
    int longueur;
    int largeur;
    int xPeak;
    int yPeak;
    char** chunks;
}room;


typedef struct dungeon {
    int width;
    int height;
    int nbRoom;
    room** rooms;
    char** chunks;
}dungeon;

room freeRoom(room maRoom);

dungeon freeDungeon(dungeon monDungeon);
dungeon insertRoom(dungeon monDungeon, room maRoom);
void afficherDungeon(dungeon monDungeon);

dungeon creatDungeon(int width, int height, int nbRoom);



void afficherRoom(room maRoom);

int randomNum(int min, int max);

room Spawner(room maRoom, int spawnerDisp, char type);

room creatRoom(int xPeak, int yPeak, int largeur, int longueur);

room fillRoom(room maRoom);


room askPlayer();

room placeCarac(room maRoom, char typeCarac);

room bossPlace(room maRoom);

room killMob(room maRoom);

#endif