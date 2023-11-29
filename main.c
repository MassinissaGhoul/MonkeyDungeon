#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"

int main(){

    srand(time(NULL));
    // creation();

    room maSalle = creatRoom(1, 1, 20,11);
    room maSalle2 = creatRoom(5, 5, 20, 20);
    // room maSalle2 = creatRoom(20, 25, 25, 10);
    // room maSalle3 = creatRoom(12, 12, 12, 12); 
    // room maSalle4 = creatRoom(12, 12, 12, 12); 
    // room maSalle5 = askPlayer();

    maSalle = fillRoom(maSalle);
    maSalle2 = fillRoom(maSalle2);
    // maSalle2 = fillRoom(maSalle2);
    // maSalle3 = fillRoom(maSalle3);
    // maSalle4 = fillRoom(maSalle4);
    

    // afficherRoom(maSalle);
    // afficherRoom(maSalle2);
    // afficherRoom(maSalle3);
    // afficherRoom(maSalle4);
    // afficherRoom(maSalle5);*
    dungeon monDonjon = creatDungeon(60, 40, 5);
    monDonjon = insertRoomAuto(monDonjon, maSalle);
    monDonjon = insertRoomAuto(monDonjon, maSalle2);

    // int i = 10;
    // int j = 10;
    // int k = 0;
    // while(k != 6){
    //     scanf("%d", &k);
    //     monDonjon = corridorPart(monDonjon, i, j, k);
    //     printDungeon(monDonjon);
    //     if(k == 1){
    //         j++;
    //     }else if(k == 3){
    //         i++;
    //     }



    // }

//    monDonjon = corridorPart(monDonjon, 10, 10, 1);
  //  monDonjon = corridorPart(monDonjon, 10, 11, 1);
    //monDonjon = corridorPart(monDonjon, 10, 12, 2);



    printDungeon(monDonjon);


    // saveDungeonFile(monDonjon, "Dungeon.txt");

    // printRoom(maSalle);
    freeRoom(maSalle);
    freeDungeon(monDonjon);


    // free(maSalle);

    return 0;
}