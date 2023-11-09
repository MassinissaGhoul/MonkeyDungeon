#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dungeon.h"

int main(){

    srand(time(NULL));

    // room maSalle = creatRoom(11, 11, 11, 11); 
    room maSalle = creatRoom(25, 25, 25, 25);
    // room maSalle = creatRoom(12, 12, 12, 12); 
    afficherRoom(maSalle);

    // free(maSalle);

    return 0;
    return 0;

}