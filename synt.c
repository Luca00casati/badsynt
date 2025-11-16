#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "synt.h"

void music_init(Music* music){
    music->freqs = malloc(sizeof(frequency)*VAINIT);
    music->freq_count = 0;
    music->freq_size = VAINIT;
    music->wave = square;
    music->duration = 0.5f;
    music->pause = 0.5f;
    music->intensity = 0.3f;
}

void vappend_end(Music* music, ...) {
    va_list args;
    va_start(args, music);

    frequency freq;
    while (1) {
        freq = va_arg(args, frequency);
        if (freq == END_FREQ ) break;

        if (music->freq_count >= music->freq_size) {
            music->freq_size *= VAGROW;
            music->freqs = realloc(music->freqs, sizeof(frequency) * music->freq_size);
            if (music->freqs == NULL){
                printf("fail to realloc vappend\n");
            }
        }
        music->freqs[music->freq_count++] = freq;
    }

    va_end(args);
}