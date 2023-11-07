#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dungeon.h"

int main(){

    srand(time(NULL));
    
    // creatRoom(5, 5);
    // creatRoom(10, 7);
    // room* maSalle;

    room maSalle = creatRoom(6, 10, 10, 10, 10); 
    afficherRoom(maSalle);

    // free(maSalle);

    return 0;
    return 0;

}