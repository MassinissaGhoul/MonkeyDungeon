#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"


dungeon corridorPart(dungeon monDonjon, int i, int j, int number)
{
    switch (number)
    {
    case 1:
        if (monDonjon.chunks[i][j] != '#' || monDonjon.chunks[i - 1][j] != '#' || monDonjon.chunks[i + 1][j] != '#')
        {
            monDonjon.chunks[i - 1][j] = '#';
            monDonjon.chunks[i][j] = ' ';
            monDonjon.chunks[i + 1][j] = '#';
        }
        break;
    case 2:
        monDonjon.chunks[i][j - 1] = '#';
        monDonjon.chunks[i][j] = ' ';
        monDonjon.chunks[i][j + 1] = '#';
        break;
    case 3:
        monDonjon.chunks[i][j - 1] = 'Y';
        monDonjon.chunks[i][j] = 'G';
        monDonjon.chunks[i][j + 1] = 'T';
        break;
    default:
        break;
    }
    return monDonjon;
}

int isInRoom(dungeon monDonjon, int i, int j) {
    for (int roomIndex = 0; roomIndex < monDonjon.nbRoomIN; roomIndex++) {
        if (i >= monDonjon.rooms[roomIndex].yPeak && i < monDonjon.rooms[roomIndex].yPeak + monDonjon.rooms[roomIndex].longueur &&
            j >= monDonjon.rooms[roomIndex].xPeak && j < monDonjon.rooms[roomIndex].xPeak + monDonjon.rooms[roomIndex].largeur) {
            return 1;  
        }
    }
    return 0;  
}


void makeCorridor(dungeon monDonjon, int i, int j)
{
    int choice = 400;
    int preChoice = 0;

    while (choice != 0)
    {
        if (isInRoom(monDonjon, i, j)) {
            printf("Vous ne pouvez pas placer le début du couloir dans une salle. Entrez de nouvelles coordonnées.\n");
            printf("Coordonee X du couloir: ");
            scanf("%d", &i);
            printf("Coordonee Y du couloir: ");
            scanf("%d", &j);
        }
        printf("1: Droite 2: Bas 3: Haut 4: Gauche 5: Quitter l'edition des couloirs\n");
        scanf("\n %d", &choice);
        if(monDonjon.chunks[i][j] == '#' ){
            choice = 9;
        }
        if (i - 1 >= 0 && j + 1 < monDonjon.largeur && j - 1 >= 0 && i + 1 < monDonjon.longueur)
        {
            switch (choice)
            {
            case 1:

                corridorPart(monDonjon, i, j, 1);
                if (preChoice == 2 && choice == 1)
                {
                    corridorPart(monDonjon, i, j - 1, 1);
                    monDonjon.chunks[i][j - 1] = '#';
                    monDonjon.chunks[i - 1][j] = ' ';
                }
                else if (preChoice == 3 && choice == 1)
                {
                    corridorPart(monDonjon, i, j - 1, 1);
                    monDonjon.chunks[i][j - 1] = '#';
                    monDonjon.chunks[i + 1][j] = ' ';
                }
                j++;
                preChoice = choice;
                printDungeon(monDonjon);
                break;
            case 2:
                corridorPart(monDonjon, i, j, 2);
                if (preChoice == 1 && choice == 2)
                {
                    monDonjon.chunks[i - 1][j] = '#';
                    monDonjon.chunks[i - 1][j + 1] = '#';
                    monDonjon.chunks[i][j - 1] = ' ';
                }
                else if (preChoice == 4 && choice == 2)
                {
                    corridorPart(monDonjon, i - 1, j, 2);
                    monDonjon.chunks[i - 1][j] = '#';
                    monDonjon.chunks[i][j + 1] = ' ';
                }
                i++;
                preChoice = choice;
                printDungeon(monDonjon);
                break;
            case 3:
                corridorPart(monDonjon, i, j, 2);
                if (preChoice == 1 && choice == 3)
                {
                    corridorPart(monDonjon, i + 1, j, 2);
                    monDonjon.chunks[i + 1][j] = '#';
                    monDonjon.chunks[i][j - 1] = ' ';
                }
                else if (preChoice == 4 && choice == 3)
                {
                    corridorPart(monDonjon, i + 1, j, 2);
                    monDonjon.chunks[i + 1][j] = '#';
                    monDonjon.chunks[i][j + 1] = ' ';
                }
                i--;
                preChoice = choice;
                printDungeon(monDonjon);
                break;
            case 4:
                corridorPart(monDonjon, i, j, 1);
                if (preChoice == 1 && choice == 4)
                {
                    monDonjon.chunks[i - 1][j] = '#';
                    monDonjon.chunks[i - 1][j + 1] = '#';
                    monDonjon.chunks[i][j - 1] = ' ';
                }
                else if (preChoice == 2 && choice == 4)
                {
                    corridorPart(monDonjon, i, j + 1, 1);
                    monDonjon.chunks[i][j + 1] = '#';
                    monDonjon.chunks[i - 1][j] = ' ';
                }
                else if (preChoice == 3 && choice == 4)
                {
                    corridorPart(monDonjon, i, j + 1, 1);
                    monDonjon.chunks[i][j + 1] = '#';
                    monDonjon.chunks[i + 1][j] = ' ';
                }
                j--;
                preChoice = choice;
                printDungeon(monDonjon);
                break;
            case 5:
                choice = 0;
                break;
            case 9:
                printf("Impossible de faire un couloir ici, entre les nouvelle coordonnes du couloir\n");
                printf("Coordonee X du couloir: ");
                scanf("%d", &i);
                printf("Coordonee Y du couloir: ");
                scanf("%d", &j);
                break;
            default:
                printf("Veuillez entrer un nombre valide\n");
                scanf("%d", &choice);
                break;
            }
        }
    }
}
