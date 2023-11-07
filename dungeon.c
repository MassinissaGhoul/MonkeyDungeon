#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include <time.h>

#define true 1
#define false 0

void afficherRoom(room maRoom){
    for (int i = 0; i < maRoom.longueur; i++) {
        for (int j = 0; j < maRoom.largeur; j++) {
            // y'a un problème chef
            printf("%c", maRoom.chunks[i][j]);
    }
    printf("\n");
    }
    free(maRoom.chunks);
}


int randomNum(int min, int max){
    return rand() % (max - min + 1) + min;
}



int Spawner(room maRoom, int spawnerDisp, char type, int i, int j)
{
    if (randomNum(0, 10) == 1 && spawnerDisp > 0 && maRoom.chunks[i][j] == ' ') {
        maRoom.chunks[i][j] = type;
        spawnerDisp = spawnerDisp - 1;
    }
    return spawnerDisp;
}

room creatRoom(int xPeak, int yPeak, int largeur, int longueur) {
    room maRoom;
    maRoom.xPeak = xPeak;
    maRoom.yPeak = yPeak;
    maRoom.largeur = largeur;
    maRoom.longueur = longueur;
    maRoom.chunks = (char**)malloc(longueur * sizeof(char*));
    printf("Voici la salle : \n");
    for (int i = 0; i < longueur; i++) {
        maRoom.chunks[i] = (char*)malloc(largeur * sizeof(char));
        for (int j = 0; j < largeur; j++) {
            if (i == 0 || j == 0 || i == longueur - 1 || j == largeur - 1) {
                maRoom.chunks[i][j] = '#';
            } else {
                maRoom.chunks[i][j] = ' ';
            }
        }
    }
    maRoom = fillRoom(maRoom);
    return maRoom;
}


room fillRoom(room maRoom){
    int numMonster;
    char typeMonster = 'M';
    int numChest;
    char typeChest = 'C';
    int numTrap;
    char typeTrap = 'P';
    int numHostel;
    char typeHostel = 'A';

    if (maRoom.longueur <= 5 && maRoom.largeur <= 5) { //salle de 3x3 en place
        if (randomNum(0, 2) == 1){
            maRoom.chunks[maRoom.longueur/2][maRoom.largeur/2] = typeChest;
        } else {
            maRoom.chunks[maRoom.longueur/2][maRoom.largeur/2] = typeHostel;
        }
        return maRoom;
    }else if (maRoom.longueur <= 10 && maRoom.largeur <= 10)
    {
        int numMonster = 4;
        int numChest = 0;
        int numTrap = 1;
        int hostel = 0;
    }else if (maRoom.longueur <= 20 && maRoom.largeur <= 20)
    {
        int numMonster = 6;
        int numChest = 1;
        int numTrap = 3;
        int hostel = 0;
    }else if (maRoom.longueur >= 20 && maRoom.largeur >= 20)
    {
        int numMonster = 3;
        int numChest = 0;
        int numTrap = 0;
        int hostel = 0;
        maRoom.chunks[maRoom.longueur/2][maRoom.largeur/2] = *"B";
    }
    for (int i = 0; i < maRoom.longueur; i++) {
        for (int j = 0; j < maRoom.largeur; j++) {
            numMonster = Spawner(maRoom, numMonster, typeMonster, i, j);
            numChest = Spawner(maRoom, numChest, typeChest, i, j);
            numTrap = Spawner(maRoom, numTrap, typeTrap, i, j);
            numHostel = Spawner(maRoom, numHostel, typeHostel, i, j);
        }
    
    }return maRoom;
}