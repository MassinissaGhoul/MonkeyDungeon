#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"
#define true 1
#define false 0

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

dungeon insertRoom(dungeon monDungeon, room maRoom){
    for (int i = 0; i < monDungeon.longueur; i++) {
        for (int j = 0; j < monDungeon.largeur; j++) {
            if(maRoom.xPeak == i && monDungeon.chunks[maRoom.yPeak][maRoom.xPeak] != '#' && (maRoom.yPeak + maRoom.longueur -1) < monDungeon.longueur -1 && (maRoom.xPeak + maRoom.largeur -1) < monDungeon.largeur -1){
                for (int k = 0 ; k< maRoom.longueur; k++){
                    for (int l = 0; l < maRoom.largeur; l++){
                        monDungeon.chunks[k+maRoom.yPeak][l+maRoom.xPeak] = maRoom.chunks[k][l];
                    }
                }
                return monDungeon;
            }
        }
    }
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
    monDungeon = placePorte(monDungeon);
    return monDungeon;
}

dungeon placePorte(dungeon monDungeon){
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
    }else{
        printf("Combien de salle ? ");
        scanf("%d", &nbRoom);
        for (int i = 0; i < nbRoom; i++){
            monDungeon = placeSalle(monDungeon);
        }
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
        // }else if (peutPlacer()){ // ne fonctionne pas pour l'instant
        //     printf("La salle est sur une autre salle");
        }else{
            canPlace = 1;
        }
    }while(canPlace = 0);
    maRoom = askRoom();
    printf("Entite placee.\n");
    return monDonjon;
}

dungeon autoCouloir(dungeon monDonjon){

}