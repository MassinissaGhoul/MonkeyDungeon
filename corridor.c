#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"

dungeon corridorPart(dungeon monDonjon, int i, int j, int number) {
    switch (number) {
        case 1:
            monDonjon.chunks[i - 1][j] = '#';
            monDonjon.chunks[i][j] = ' ';
            monDonjon.chunks[i + 1][j] = '#';
            break;
        case 2:
            monDonjon.chunks[i][j-1] = '#';
            monDonjon.chunks[i][j] = ' ';
            monDonjon.chunks[i][j+1] = '#';
            break;
        case 3:
            monDonjon.chunks[i][j-1] = 'Y';
            monDonjon.chunks[i][j] = 'G';
            monDonjon.chunks[i][j+1] = 'T';
            break;
        default:
            break;
    }return monDonjon;
}

int verifColisionCorridor(dungeon monDonjon, int i, int j){
    
    
}

void makeCorridor(dungeon monDonjon, int i, int j){
    int choice = 10;
    int preChoice = 0;
    while(choice!=0){
        scanf("\n %d",&choice);
        switch(choice){
            case 1:
                corridorPart(monDonjon, i, j, 1);
                if(preChoice == 2 && choice == 1){
                    corridorPart(monDonjon, i, j-1, 1);
                    monDonjon.chunks[i][j-1] = '#';
                    monDonjon.chunks[i-1][j] = ' ';
                }else if(preChoice == 3 && choice == 1){
                    corridorPart(monDonjon, i, j-1, 1);
                    monDonjon.chunks[i][j-1] = '#';
                    monDonjon.chunks[i+1][j] = ' ';
                }
                j++;
                printDungeon(monDonjon);
                preChoice = choice;
                break;
            case 2:
                corridorPart(monDonjon, i, j, 2);
                if(preChoice == 1 && choice == 2){
                    monDonjon.chunks[i-1][j] = '#';
                    monDonjon.chunks[i-1][j+1] = '#';
                    monDonjon.chunks[i][j-1] = ' ';
                }else if(preChoice == 4 && choice == 2){
                    corridorPart(monDonjon, i-1, j, 2);
                    monDonjon.chunks[i-1][j] = '#';
                    monDonjon.chunks[i][j+1] = ' ';
                }
                printDungeon(monDonjon);
                i++;
                preChoice = choice;
                break;
            case 3:
                corridorPart(monDonjon, i, j, 2);   
                if(preChoice == 1 && choice == 3){
                    corridorPart(monDonjon, i+1, j, 2);
                    monDonjon.chunks[i+1][j] = '#';
                    monDonjon.chunks[i][j-1] = ' ';
                }else if(preChoice == 4 && choice == 3){
                    corridorPart(monDonjon, i+1, j, 2);
                    monDonjon.chunks[i+1][j] = '#';
                    monDonjon.chunks[i][j+1] = ' ';
                }
                printDungeon(monDonjon);
                i--;
                preChoice = choice;
                break;
            case 4:
                corridorPart(monDonjon, i, j, 1);
                if(preChoice == 1 && choice == 4){
                    monDonjon.chunks[i-1][j] = '#';
                    monDonjon.chunks[i-1][j+1] = '#';
                    monDonjon.chunks[i][j-1] = ' ';
                }else if(preChoice == 2 && choice == 4){
                    corridorPart(monDonjon, i, j+1, 1);
                    monDonjon.chunks[i][j+1] = '#';
                    monDonjon.chunks[i-1][j] = ' ';
                }else if(preChoice == 3 && choice == 4){
                    corridorPart(monDonjon, i, j+1, 1);
                    monDonjon.chunks[i][j+1] = '#';
                    monDonjon.chunks[i+1][j] = ' ';
                }
                printDungeon(monDonjon);
                j--;
                preChoice = choice;
                break;
            default:
                break;
        }
    }
}