#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dungeon.h"

int main(){

    srand(time(NULL));

    // room maSalle = creatRoom(11, 21, 11, 21); 
    // room maSalle2 = creatRoom(25, 25, 25, 25);
    // room maSalle3 = creatRoom(12, 12, 12, 12); 
    // room maSalle4 = creatRoom(12, 12, 12, 12); 
    room maSalle5 = askPlayer();

    // afficherRoom(maSalle);
    // afficherRoom(maSalle2);
    // afficherRoom(maSalle3);
    // afficherRoom(maSalle4);
    afficherRoom(maSalle5);

    // free(maSalle);

    return 0;
    return 0;

}