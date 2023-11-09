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



room Spawner(room maRoom, int spawnerDisp, char type){
    for (int i = 0; i < maRoom.longueur; i++) {
        for (int j = 0; j < maRoom.largeur; j++) {
            if (randomNum(0, 10) == 1 && spawnerDisp > 0 && (maRoom.chunks[i][j] != '#' && maRoom.chunks[i][j] == ' ')) {
                maRoom.chunks[i][j] = type;
                spawnerDisp = spawnerDisp - 1;
            }
        }
    
    }
    
    return maRoom;
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
        numMonster = 4;
        numChest = 0;
        numTrap = 1;
        numHostel = 0;
    }else if (maRoom.longueur <= 20 && maRoom.largeur <= 20)
    {
        numMonster = 6;
        numChest = 1;
        numTrap = 3;
        numHostel = 0;
    }else if (maRoom.longueur >= 20 && maRoom.largeur >= 20)
    {
        numMonster = 5;
        numChest = 0;
        numTrap = 5;
        numHostel = 0;
        maRoom.chunks[maRoom.longueur/2][maRoom.largeur/2] = *"B";

        maRoom.chunks[maRoom.longueur/3][maRoom.largeur/3] = *"#";
        maRoom.chunks[maRoom.longueur/3 + maRoom.longueur/3][maRoom.largeur/3] = *"#";
        maRoom.chunks[maRoom.longueur/3][maRoom.largeur/3 + maRoom.longueur/3] = *"#";
        maRoom.chunks[maRoom.longueur/3 + maRoom.longueur/3][maRoom.largeur/3 + maRoom.longueur/3] = *"#";
    }
    maRoom = Spawner(maRoom, numMonster, typeMonster);
    maRoom = Spawner(maRoom, numChest, typeChest);
    maRoom = Spawner(maRoom, numTrap, typeTrap);
    maRoom = Spawner(maRoom, numHostel, typeHostel);
    return maRoom;
}