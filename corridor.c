#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creator.h"


dungeon autoCouloir(dungeon monDonjon, int i, int j){
    char mur = '#';
    int taille = monDonjon.nbRoom*2;
    int x = i;
    int y = j;
    for (int k = 0; k < randomNum(2, taille); k++){
        monDonjon.chunks[i+1][j+1] = mur;
        monDonjon.chunks[i-1][j+1] = mur;
    }        
    return monDonjon;
}