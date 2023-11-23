#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"

int main(){

    srand(time(NULL));

    room maSalle = creatRoom(1, 1, 20,11);
    room maSalle2 = creatRoom(30, 35, 3, 3);
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
    monDonjon = insertRoom(monDonjon, maSalle);
    monDonjon = insertRoom(monDonjon, maSalle2);
    
    afficherDungeon(monDonjon);


    saveDungeonFile(monDonjon, "Dungeon.txt");

    // afficherRoom(maSalle);
    freeRoom(maSalle);
    freeDungeon(monDonjon);


    // free(maSalle);

    return 0;

}