#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dungeon.h"

int main(){

    srand(time(NULL));

    room maSalle = creatRoom(1, 4, 10,10); 
    // room maSalle2 = creatRoom(25, 25, 25, 25);
    // room maSalle3 = creatRoom(12, 12, 12, 12); 
    // room maSalle4 = creatRoom(12, 12, 12, 12); 
    // room maSalle5 = askPlayer();

    maSalle = fillRoom(maSalle);
    // maSalle2 = fillRoom(maSalle2);
    // maSalle3 = fillRoom(maSalle3);
    // maSalle4 = fillRoom(maSalle4);
    

    // afficherRoom(maSalle);
    // afficherRoom(maSalle2);
    // afficherRoom(maSalle3);
    // afficherRoom(maSalle4);
    // afficherRoom(maSalle5);*
    dungeon monDonjon = creatDungeon(30, 50, 5);
    monDonjon = insertRoom(monDonjon, maSalle);
    
    afficherDungeon(monDonjon);

    // afficherRoom(maSalle);
    freeRoom(maSalle);
    freeDungeon(monDonjon);


    // free(maSalle);

    return 0;

}