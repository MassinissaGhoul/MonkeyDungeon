#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"

int main(){

    srand(time(NULL));
    creation();

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

    return 0;
}