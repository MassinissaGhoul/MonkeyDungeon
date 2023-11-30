#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"

int main()
{    srand(time(NULL));

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
    printf("Donjon final :\n");
    printDungeon(monDonjon);

    printf("Sauvegarder dans un .txt : 0: Le Donjon / 1: Une Salle / 2: Quitter sans enregistrer ");
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
    freeDungeon(monDonjon);

    return 0;
}
