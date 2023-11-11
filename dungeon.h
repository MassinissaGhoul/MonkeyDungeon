#ifndef DUNGEON_H
#define DUNGEON_H

/**
 \file dungeon.h


 \brief Ces fonctions permettent la creation d'un donjon automatiquement ou par un utilisateurs.

 \author Ghoul Massinissa /Boulogne Yanis
 \version 1
 \date Novembre 2023
*/

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

/*
 \brief : Cette fonction permet la sauvegarde d'un donjon dans un fichier txt.

 \param monDungeon : dungeon : un donjon.
 \param fileName : char* : nom du fichier de sauvegarde.

 \remark :
*/
void saveDungeonFile(dungeon monDungeon, char* fileName);

void freeRoom(room maRoom);

void freeDungeon(dungeon monDungeon);

dungeon insertRoom(dungeon monDungeon, room maRoom);

void afficherDungeon(dungeon monDungeon);

dungeon creatDungeon(int width, int height, int nbRoom);

dungeon placePorte(dungeon monDongeon);

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