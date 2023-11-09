#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dungeon.h"

int main(){

    srand(time(NULL));

    room maSalle = creatRoom(11, 11, 11, 11); 
    room maSalle2 = creatRoom(25, 25, 25, 25);
    room maSalle3 = creatRoom(12, 12, 12, 12); 
    room maSalle4 = creatRoom(12, 12, 12, 12); 

    afficherRoom(maSalle);
    afficherRoom(maSalle2);
    afficherRoom(maSalle3);
    afficherRoom(maSalle4);

    // free(maSalle);

    return 0;
    return 0;

}