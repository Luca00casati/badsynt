#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "note.h"
#include "synt.h"

int main(void) {

    Music music1 = {0};
    music_init(&music1);
    for (int i = 0; i < 2; i++){
    VA(&music1,
    A4, 
    B4,
    C4,
    B4,
    A4,
    P);
    }

    VA(&music1,
    A4, 
    B4,
    C4,
    B4,
    A4);
    //add_between(&music1, P);

    Music music2 = {0};
    music_init(&music2);

    music2.wave = triangle;
    VA(&music2, P, B5, P, B5, P, P, P, B5, P, B5, P, P, P, B5, P, B5, P);

    return 0;
}

