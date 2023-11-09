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
}dungeon;




void afficherRoom(room maRoom);

int randomNum(int min, int max);
room Spawner(room maRoom, int spawnerDisp, char type);

// int Spawner(int number, char type, int longueur, int largeur, char room[][largeur]);

// void creatRoom(int largeur, int longueur);



room creatRoom(int xPeak, int yPeak, int largeur, int longueur);

room fillRoom(room maRoom);

#endif