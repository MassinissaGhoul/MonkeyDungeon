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
    room *rooms;
}dungeon;




void afficherRoom(room maRoom);

int randomNum(int min, int max);
int Spawner(room maRoom, int spawnerDisp, char type, int i, int j);

// int Spawner(int number, char type, int longueur, int largeur, char room[][largeur]);

// void creatRoom(int largeur, int longueur);



room creatRoom(int numMonster, int xPeak, int yPeak, int largeur, int longueur);

#endif