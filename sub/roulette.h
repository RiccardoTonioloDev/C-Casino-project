#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif
#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

typedef struct fettaRoulette {
    int numero;
    char colore;
    struct fettaRoulette* next;
} FettaRoulette;

FettaRoulette* initFettaRoulette(int val, char color, FettaRoulette* next);
void initRoulette(FettaRoulette** fr);
void stampaRoulette(FettaRoulette* fr);
int lancioPallina(FettaRoulette* fr, int pos);