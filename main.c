#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"

int main()
{

    srand(time(NULL));

    //     room maSalle = creatRoom(1, 1, 20,11);
    //     room maSalle2 = creatRoom(5, 5, 20, 20);
    //     // room maSalle2 = creatRoom(20, 25, 25, 10);
    //     room maSalle3 = creatRoom(12, 12, 12, 12);
    //     // room maSalle4 = creatRoom(12, 12, 12, 12);
    //     // room maSalle5 = askPlayer();
    //     room maSalle4 = creatRoom(30, 30, 9, 9);
    //     room maSalle5 = creatRoom(30, 30, 14, 14);

    //     maSalle = fillRoom(maSalle);
    //     maSalle2 = fillRoom(maSalle2);
    //     // maSalle2 = fillRoom(maSalle2);
    //     // maSalle3 = fillRoom(maSalle3);
    //     // maSalle4 = fillRoom(maSalle4);

    //     // afficherRoom(maSalle);
    //     // afficherRoom(maSalle2);
    //     // afficherRoom(maSalle3);
    //     // afficherRoom(maSalle4);
    //     // afficherRoom(maSalle5);
    //     dungeon monDonjon = creatDungeon(60, 40, 5);
    //     monDonjon = insertRoomAuto(monDonjon, maSalle);
    //     monDonjon = insertRoomAuto(monDonjon, maSalle2);
    //     monDonjon = insertRoomAuto(monDonjon, maSalle3);
    //     monDonjon = insertRoomAuto(monDonjon, maSalle4);
    //     monDonjon = insertRoomAuto(monDonjon, maSalle5);

    //     int i = 10;
    //     int j = 12;

    //     // makeCorridor(monDonjon, i, j);

    // //    monDonjon = corridorPart(monDonjon, 10, 10, 1);
    //   //  monDonjon = corridorPart(monDonjon, 10, 11, 1);
    //     //monDonjon = corridorPart(monDonjon, 10, 12, 2);

    //     printDungeon(monDonjon);

    //     saveDungeonFile(monDonjon, "Dungeon.txt");

    //     // afficherRoom(maSalle);
    //     freeRoom(maSalle);
    //     freeRoom(maSalle2);
    //     freeRoom(maSalle3);
    //     freeRoom(maSalle4);
    //     freeRoom(maSalle5);
    //     freeDungeon(monDonjon);

    // free(maSalle);

    dungeon monDonjon;
    int how;
    int corridor;
    int corridorX;
    int corridorY;
    int combien;
    int save;
    int numRoom;

    printf("Creation assistee d'un donjon ? (0 => oui / 1 => non) ");
    scanf("%d", &how);
    if (how == 0)
    {
        monDonjon = askDungeon();
        printDungeon(monDonjon);
        printf("Voulez-vous creer des couloirs ? (0 => oui / 1 => non) ");
        scanf("%d", &corridor);
        if (corridor == 0)
        {
            printf("Combien de couloir ? ");
            scanf("%d", &combien);
            for (int i = 0; i < combien; i++)
            {
                printf("Coordonee X du couloir: ");
                scanf("%d", &corridorX);
                printf("Coordonee Y du couloir: ");
                scanf("%d", &corridorY);
                makeCorridor(monDonjon, corridorX, corridorY);
            }
            printDungeon(monDonjon);
        }
        printDungeon(monDonjon);
        freeDungeon(monDonjon);
    }
    else if (how == 1)
    {
        int largeur = 80;
        int longueur = 40;
        int salle = 5;
        int j = 2;
        int k = 2;
        monDonjon = creatDungeon(largeur, longueur, salle);
        monDonjon = dungeonAutoDoor(monDonjon);

        for (int i = 0; i < salle; i++)
        {

            room maSalle = creatRoom(j, k, randomNum(salle, salle * 4), randomNum(salle, salle * 3));
            maSalle = fillRoom(maSalle);
            maSalle = roomAutoDoor(maSalle);
            j = randomNum(maSalle.largeur, monDonjon.largeur - maSalle.largeur);
            k = randomNum(maSalle.longueur, monDonjon.longueur - maSalle.longueur);
            monDonjon = insertRoomAuto(monDonjon, maSalle);
        }
        printDungeon(monDonjon);
        printf("Voulez-vous creer des couloirs ? (0 => oui / 1 => non) ");
        scanf("%d", &corridor);
        if (corridor == 0)
        {
            printf("Coordonee X du couloir: ");
            scanf("%d", &corridorX);
            printf("Coordonee Y du couloir: ");
            scanf("%d", &corridorY);
            makeCorridor(monDonjon, corridorX, corridorY);
            corridor = 1;
        }
    }
    printDungeon(monDonjon);

    while (save != 0)
    {
        printf("Sauvegarder dans un .txt : 0: Le Donjon / 1: Une Salle / 2: Quitter sans enregistrer \n");
        scanf("%d", &save);
        if (save == 0)
        {
            saveDungeonFile(monDonjon, "Dungeon.txt");
            printf("sauvegarde Donjon reussi\n");
        }
        else if (save == 1)
        {
            printf("numero de la salle compris entre 0 et %d\n (0 Etant la premiere salle)", monDonjon.nbRoom - 1);
            scanf("%d", &numRoom);
            saveRoomFile(monDonjon, "Salle", numRoom);

            printf("sauvegarde salle reussi\n");
        }
    }
    freeDungeon(monDonjon);

    return 0;
}
