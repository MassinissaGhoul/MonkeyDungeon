#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"

void freeRoom(room maRoom){
    for (int i = 0; i < maRoom.longueur; i++) {
        free(maRoom.chunks[i]);
    }
    free(maRoom.chunks);
}

void printRoom(room maRoom){
    for (int i = 0; i < maRoom.longueur; i++) {
        for (int j = 0; j < maRoom.largeur; j++) {
            printf("%c", maRoom.chunks[i][j]);
    }
    printf("\n");
    }
    free(maRoom.chunks);
}

room spawner(room maRoom, int spawnerDisp, char type){
    for (int i = 0; i < maRoom.longueur; i++) {
        for (int j = 0; j < maRoom.largeur; j++) {
            if (randomNum(0, 10 + iteration) == 1 && spawnerDisp > 0 && maRoom.chunks[i][j] == ' ') {
                maRoom.chunks[i][j] = type;
                spawnerDisp = spawnerDisp - 1;
                if(type == 'P'){
                    maRoom = killMob(maRoom, i, j);
                }
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
    int itearation = 1;

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
        iteration = (maRoom.largeur > maRoom.longueur) ? maRoom.largeur*1.8 : maRoom.longueur*1.8;
        numMonster = 8;
        numChest = 4;
        numTrap = 5;
        numHostel = 0;
        maRoom.chunks[maRoom.longueur/2][maRoom.largeur/2] = *"B";
        maRoom.chunks[maRoom.longueur/3][maRoom.largeur/3] = *"#";
        maRoom.chunks[maRoom.longueur/3 + maRoom.longueur/3][maRoom.largeur/3] = *"#";
        maRoom.chunks[maRoom.longueur/3][maRoom.largeur/3 + maRoom.longueur/3] = *"#";
        maRoom.chunks[maRoom.longueur/3 + maRoom.longueur/3][maRoom.largeur/3 + maRoom.longueur/3] = *"#";
    }else
    {
        numMonster = maRoom.longueur / 3;
        numChest = maRoom.longueur / 6;
        numTrap = maRoom.longueur / 5;
        numHostel = 0;
        iteration = (maRoom.largeur > maRoom.longueur) ? maRoom.largeur*1.8 : maRoom.longueur*1.8;

    }
    maRoom = spawner(maRoom, numMonster, typeMonster);
    maRoom = spawner(maRoom, numChest, typeChest);
    maRoom = spawner(maRoom, numTrap, typeTrap);
    maRoom = spawner(maRoom, numHostel, typeHostel);
    return maRoom;
}

room askRoom(){
    room maRoom;
    int longueur;
    int largeur;
    char *typeCarac[4] = {"Monstre","Coffre","Piege","Autel"};
    int whoPlace;
    printf("Longueur de la salle: ");
    scanf("%d", &longueur);
    printf("Largeur de la salle: ");
    scanf("%d", &largeur);
    maRoom = creatRoom(largeur, longueur, largeur, longueur);
    iteration = (maRoom.largeur > maRoom.longueur) ? maRoom.largeur*1.8 : maRoom.longueur*1.8;
    printf("Voulez-vous que les elements soit places automatiquement ? ( 0 => oui / 1 => non) ");
    scanf("%d", &whoPlace);
    if (whoPlace == 0){
        maRoom = insertBoss(maRoom);
        for (int i = 0; i < 4; i++){
            int numCarac = 0;
            printf("Combien de %s maximum ? ", typeCarac[i]);
            scanf("%d", &numCarac);
            maRoom = spawner(maRoom, numCarac, typeCarac[i][0]);
        }
    maRoom = roomAutoDoor(maRoom);
    }else{
        maRoom = insertBoss(maRoom);
        for (int i = 0; i < 4; i++){
            int numCarac = 0;
            printf("Combien de %s maximum ? ", typeCarac[i]);
            scanf("%d", &numCarac);
            for (int j = numCarac; j > 0; j--){
                insertType(maRoom, typeCarac[i][0]);
            }
        }
    maRoom = roomDoor(maRoom);
    }
    return maRoom;
}

room insertType(room maRoom, char typeCarac){
    int coorX;
    int coorY;
    int canPlace = 0;
    do {
        printf("Coordonee X: ");
        scanf("%d", &coorX);
        printf("Coordonee Y: ");
        scanf("%d", &coorY);
        if ((maRoom.largeur <= coorX)){
            printf("La valeur de X est trop grande");
        }else if ((maRoom.longueur <= coorY)){
            printf("La valeur de Y est trop grande");
        }else{
            canPlace = 1;
        }
    }while(canPlace = 0);
    if (maRoom.chunks[coorX][coorY] == ' '){
                maRoom.chunks[coorX][coorY] = typeCarac;
                printf("Entite placee.\n");
        }
    return maRoom;
}

room insertBoss(room maRoom){
    int boss;
    if (maRoom.longueur >= 20 && maRoom.largeur >= 20){
        printf("Y a t il un boss ? (0 => oui /1 => non) ");
        scanf("%d", &boss);
        if (boss == 0){
            maRoom.chunks[maRoom.longueur/2][maRoom.largeur/2] = 'B';
            printf("Boss place.\n");
        }
        maRoom.chunks[maRoom.longueur/3][maRoom.largeur/3] = '#';
        maRoom.chunks[maRoom.longueur/3 + maRoom.longueur/3][maRoom.largeur/3] = '#';
        maRoom.chunks[maRoom.longueur/3][maRoom.largeur/3 + maRoom.longueur/3] = '#';
        maRoom.chunks[maRoom.longueur/3 + maRoom.longueur/3][maRoom.largeur/3 + maRoom.longueur/3] = '#';
        printf("Des pilliers ont été places pour soutenir la salle.\n");
    }
    return maRoom;
}

room killMob(room maRoom, int i, int j){
    for (int k = -1; k < 2; k++){
        for (int u = -1; u < 2; u++){
            if (maRoom.chunks[i + k][j + u] == 'M'){
                maRoom.chunks[i + k][j + u] = 'W';
            }
        }
    }
    return maRoom;
}

room roomDoor(room maSalle){
    int porte = 0;
    int porteX;
    int porteY;
    int canPlace = 0;
    do {
        printf("Combien de porte voulez-vous ? ");
        scanf("%d", &porte);
        if (porte > 4){
            printf("Il y a trop de porte");
        }else{
            canPlace = 1;
        }
    }while(canPlace = 0);
    for (int i = 0; i < porte; i++){
        do {
            printf("Coordonee X de la porte %d: ", i);
            scanf("%d", &porteX);
            printf("Coordonee Y de la porte %d: ", i);
            scanf("%d", &porteY);
            if ((maSalle.largeur <= porteX)){
                printf("La valeur de X est trop grande");
            }else if ((maSalle.longueur <= porteY)){
                printf("La valeur de Y est trop grande");
            }else{
                canPlace = 1;
            }
        }while(canPlace = 0);
        maSalle.chunks[porteX][porteY] = 'P';
    }
    return maSalle;

}

room roomAutoDoor(room maSalle){
    int nbEntree = 1;
    char caracEntree = 'O';
    int nbSortie = 1;
    char caracSortie = 'F';
    if (maSalle.largeur > 5 && maSalle.longueur > 5){
        for (int i = 1; i < maSalle.largeur - 1; i++){
            if (randomNum(0, 4) == 1 && nbEntree == 1){
                maSalle.chunks[0][i] = caracEntree;
                nbEntree -= 1;
            }
            if (randomNum(0, 4) == 1 && nbSortie == 1){
                maSalle.chunks[maSalle.longueur -1][i] = caracSortie;
                nbSortie -= 1;
            }
        }
    }
    if (nbEntree == 1){
        maSalle.chunks[0][1] = caracEntree;
    }
    if (nbSortie == 1){
        maSalle.chunks[maSalle.longueur - 1][1] = caracSortie;
    }
    return maSalle;
}