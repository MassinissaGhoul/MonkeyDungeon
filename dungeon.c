#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include <time.h>

#define true 1
#define false 0

void afficherRoom(room maRoom){
    for (int i = 0; i < maRoom.longueur; i++) {
        for (int j = 0; j < maRoom.largeur; j++) {
            printf("%c", maRoom.chunks[i][j]);
    }
    printf("\n");
}}


int randomNum(int min, int max){
    return rand() % (max - min + 1) + min;
}

int Spawner(room maRoom, int spawnerDisp, char type, int i, int j)
{
    if (randomNum(0, 10) == 1 && spawnerDisp > 0) {
        maRoom.chunks[i][j] = type;
        spawnerDisp = spawnerDisp - 1;
    } else {
        maRoom.chunks[i][j] = ' ';
    }
    return spawnerDisp;
}

room creatRoom(int numMonster, int xPeak, int yPeak, int largeur, int longueur) {
    int monster = numMonster;
    char typeMonster = 'M';
    room maRoom;
    maRoom.xPeak = xPeak;
    maRoom.yPeak = yPeak;
    maRoom.largeur = largeur;
    maRoom.longueur = longueur;
    maRoom.longueur = longueur;
    maRoom.chunks = (char**)malloc(largeur * sizeof(char*));
    printf("Voici la salle : \n");
    for (int i = 0; i < longueur; i++) {
        maRoom.chunks[i] = (char*)malloc(longueur * sizeof(char));
        for (int j = 0; j < largeur; j++) {
            if (i == 0 || j == 0 || i == longueur - 1 || j == largeur - 1) {
                maRoom.chunks[i][j] = '#';
            } else {
                if (longueur >= 6 && largeur >= 6) {
                    monster = Spawner(maRoom, numMonster, typeMonster, i, j);
                } else {
                    maRoom.chunks[i][j] = ' ';
                }
            }
        }
    }
    free(maRoom.chunks);
    return maRoom;
}