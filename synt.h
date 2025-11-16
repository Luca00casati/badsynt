#ifndef SYNT_H
#define SYNT_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SAMPLE_RATE   44100
#define MAX_AMPLITUDE 32767 
#define FADE_SAMPLES  100
#define TRACK_COUNT 4

#define LENGTH(X) sizeof(X) / sizeof(X[0])
#define TRUE 1
#define FALSE 0

#define VAINIT 128
#define VAGROW 2
#define END_FREQ -1.0f

typedef double frequency;

#define VA(music, ...) vappend_end(music, __VA_ARGS__, END_FREQ)

typedef enum {
    square,
    sine,
    triangle,
    sawtooth
}WaveType;

typedef struct{
    frequency* freqs;
    size_t freq_count;
    size_t freq_size;
    WaveType wave;
    float duration;
    float pause;
    float intensity;
}Music;

void music_init(Music* music);

void vappend_end(Music* music, ...);

#endif // SYNT_H
