#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"

int iteration = 1;

int randomNum(int min, int max){
    return rand() % (max - min + 1) + min;
}

void ask(){
    int how;
    printf("Creation assistee d'un donjon ? (0 => oui / 1 => non) ");
    scanf("%d", &how);
    if (how == 0){
        dungeon monDonjon = askDungeon();
    }else{
        dungeon monDonjon = creatDungeon(50, 30, 5);
    }
}

void saveDungeonFile(dungeon monDungeon, char* fileName) {
    FILE* fileLocation;
    fileLocation = fopen(fileName, "w");
    if (fileLocation == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    fprintf(fileLocation, "Longueur: %d\n", monDungeon.longueur);
    fprintf(fileLocation, "Largeur: %d\n", monDungeon.largeur);
    for(int i = 0; i < monDungeon.longueur; i++ ){
        for(int j = 0; j < monDungeon.largeur; j++){
            fprintf(fileLocation, "%c", monDungeon.chunks[i][j]);
        }
        fprintf(fileLocation, "\n");
    }
    fclose(fileLocation);
}



void freeDungeon(dungeon monDungeon){
    for (int i = 0; i < monDungeon.longueur; i++) {
        free(monDungeon.chunks[i]);
    }
    free(monDungeon.chunks);
}
dungeon deletRoom(dungeon monDungeon, int i){
    for(int l = 0; l < monDungeon.rooms[i].longueur; l++){
        for(int m = 0; m < monDungeon.rooms[i].largeur; m++){
            if(monDungeon.chunks[l+monDungeon.rooms[i].yPeak][m+monDungeon.rooms[i].xPeak] == monDungeon.rooms[i].chunks[l][m]){
                monDungeon.chunks[l+monDungeon.rooms[i].yPeak][m+monDungeon.rooms[i].xPeak] = ' ';
            }
        }
    }
    return monDungeon;
}

dungeon detectCollision(dungeon monDungeon, room maRoom){
    for(int i = 0; i < monDungeon.nbRoomIN; i++){ 
        // if((monDungeon.rooms[i].xPeak + monDungeon.rooms[i].largeur ) < (maRoom.xPeak + maRoom.largeur ) || (monDungeon.rooms[i].yPeak + monDungeon.rooms[i].largeur  < (maRoom.yPeak + maRoom.longueur ))){
        if(monDungeon.rooms[i].yPeak < maRoom.yPeak + maRoom.longueur && monDungeon.rooms[i].yPeak + monDungeon.rooms[i].longueur > maRoom.yPeak){
            if(monDungeon.rooms[i].xPeak < maRoom.xPeak + maRoom.largeur && monDungeon.rooms[i].xPeak + monDungeon.rooms[i].largeur > maRoom.xPeak){
                monDungeon = deletRoom(monDungeon, i);
                return monDungeon;
        }
        } 
    }    
        return monDungeon;
}
dungeon insertRoom(dungeon monDungeon, room maRoom){
    for (int i = 0; i < monDungeon.longueur; i++) {
        for (int j = 0; j < monDungeon.largeur; j++) {
            if(maRoom.xPeak == i && monDungeon.chunks[maRoom.yPeak][maRoom.xPeak] != '#' && (maRoom.yPeak + maRoom.longueur -1) < monDungeon.longueur -1 && (maRoom.xPeak + maRoom.largeur -1) < monDungeon.largeur -1){
                for (int k = 0 ; k< maRoom.longueur; k++){
                    for (int l = 0; l < maRoom.largeur; l++){
                        monDungeon.chunks[k+maRoom.yPeak][l+maRoom.xPeak] = maRoom.chunks[k][l];
                        monDungeon.rooms[monDungeon.nbRoomIN] = maRoom; 
                        // printf("\n %d",detectCollision(monDungeon, maRoom));
                    }
                }
            }
        }
            
        }
    if(monDungeon.nbRoomIN != 0){
        monDungeon = detectCollision(monDungeon, maRoom);
        }
    monDungeon.nbRoomIN += 1;
    return monDungeon;
}

void afficherDungeon(dungeon monDungeon){
    for (int i = 0; i < monDungeon.longueur; i++) {
        for (int j = 0; j < monDungeon.largeur; j++) {
            printf("%c", monDungeon.chunks[i][j]);
        }
         printf("\n");
    }
}

dungeon creatDungeon(int largeur, int longueur, int nbRoom){
    dungeon monDungeon;
    monDungeon.largeur = largeur;
    monDungeon.longueur = longueur;
    monDungeon.nbRoom = nbRoom;
    monDungeon.nbRoomIN = 0;
    monDungeon.rooms = (room*)malloc(nbRoom * sizeof(room));
    monDungeon.chunks = (char**)malloc(longueur * sizeof(char*));
    for (int i = 0; i < longueur; i++) {
        monDungeon.chunks[i] = (char*)malloc(largeur * sizeof(char));
        for(int j = 0; j < largeur; j++) {
            if (i == 0 || j == 0 || i == longueur - 1 || j == largeur - 1) {
                monDungeon.chunks[i][j] = '#';
            } else {
                monDungeon.chunks[i][j] = ' ';
            }
        }
    }
    monDungeon = placePorteDonjonAuto(monDungeon);
    return monDungeon;
}

dungeon placePorteDonjonAuto(dungeon monDungeon){
    int nbEntree = 1;
    char caracEntree = 'E';
    int nbSortie = 1;
    char caracSortie = 'S';
    for (int i = 1; i < monDungeon.largeur - 1; i++){
        if (randomNum(0, 4) == 1 && nbEntree == 1){
            monDungeon.chunks[0][i] = caracEntree;
            nbEntree -= 1;
        }
        if (randomNum(0, 4) == 1 && nbSortie == 1){
            monDungeon.chunks[monDungeon.longueur -1][i] = caracSortie;
            nbSortie -= 1;
        }
    }
    if (nbEntree == 1){
        monDungeon.chunks[0][1] = caracEntree;
    }
    if (nbSortie == 1){
        monDungeon.chunks[monDungeon.longueur][1] = caracSortie;
    }
    return monDungeon;
}

dungeon placePorteDonjon(dungeon monDonjon){
    char *caracPorte[2] = {"Entree","Sortie"};
    int canPlace = 0;
    int porteX;
    int porteY;
    for(int i = 0; i < 2; i++){
    do {
        printf("Coordonee X de la porte %c: ", caracPorte[i]);
        scanf("%d", &porteX);
        printf("Coordonee Y de la porte %c: ", caracPorte[i]);
        scanf("%d", &porteY);
        if ((monDonjon.largeur <= porteX)){
            printf("La valeur de X est trop grande");
        }else if ((monDonjon.longueur <= porteY)){
            printf("La valeur de Y est trop grande");
        }else{
            canPlace = 1;
        }
    }while(canPlace = 0);
    monDonjon.chunks[porteX][porteY] = caracPorte[i][0];
    }
    return monDonjon;
}

dungeon askDungeon(){
    dungeon monDungeon;
    int longueur;
    int largeur;
    int whoPlace;
    int nbRoom; 
    printf("Longueur du donjon: ");
    scanf("%d", &longueur);
    printf("Largeur du donjon: ");
    scanf("%d", &largeur);
    monDungeon = creatDungeon(largeur, longueur, 0);
    printf("Voulez-vous que les salles soit remplies et placees automatiquement ? ( 0 => oui / 1 => non) ");
    scanf("%d", &whoPlace);
    if (whoPlace == 0){
        printf("Combien de salle ? ");
        scanf("%d", &nbRoom);
        int largeurRoom = randomNum(4, monDungeon.largeur/5);
        int longueurRoom = randomNum(4, monDungeon.longueur/5);
        room maRoom;
        for (int i = 0; i < nbRoom; i++){
            maRoom = creatRoom(1, 1, largeurRoom, longueurRoom);
            maRoom = fillRoom(maRoom);
            monDungeon = insertRoom(monDungeon, maRoom);
        }
        monDungeon = placePorteDonjonAuto(monDungeon);
    }else{
        printf("Combien de salle ? ");
        scanf("%d", &nbRoom);
        for (int i = 0; i < nbRoom; i++){
            monDungeon = placeSalle(monDungeon);
        }
        monDungeon = placePorteDonjon(monDungeon);
    }
    return monDungeon;
}

dungeon placeSalle(dungeon monDonjon){
    room maRoom;
    int coorX;
    int coorY;
    int canPlace = 0;
    do {
        printf("Coordonee X: ");
        scanf("%d", &coorX);
        printf("Coordonee Y: ");
        scanf("%d", &coorY);
        if ((monDonjon.largeur <= coorX)){
            printf("La valeur de X est trop grande");
        }else if ((monDonjon.longueur <= coorY)){
            printf("La valeur de Y est trop grande");
        }else{
            canPlace = 1;
        }
    }while(canPlace = 0);
    maRoom = askRoom();
    printf("Entite placee.\n");
    return monDonjon;
}