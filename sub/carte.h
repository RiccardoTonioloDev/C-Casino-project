#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif
#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif
#include <time.h>

#include "utils.h"

typedef enum cartePerSeme_piacentino {
    x1 = 1,
    x2,
    x3,
    x4,
    x5,
    x6,
    x7,
    fante,
    cavallo,
    re
} CartePerSeme_piacentino;
typedef enum seme_piacentino {
    spade,
    coppe,
    denari,
    bastoni
} Seme_piacentino;
typedef struct carta_piacentino {
    CartePerSeme_piacentino carta;
    Seme_piacentino seme;
} Carta_piacentino;

typedef enum cartePerSeme_ramino {
    r1 = 1,
    r2,
    r3,
    r4,
    r5,
    r6,
    r7,
    r8,
    r9,
    r10,
    jack,
    queen,
    king
} CartePerSeme_ramino;
typedef enum seme_ramino {
    picche,
    fiori,
    quadri,
    cuori
} Seme_ramino;
typedef struct carta_ramino {
    CartePerSeme_ramino carta;
    Seme_ramino seme;
} Carta_ramino;

typedef union carta {
    Carta_piacentino CPiacentino;
    Carta_ramino CRamino;
} Carta;

void generaCarta(char tipo, Carta *c, int s, int carta);
void printCarta(char, Carta);
void swapCarte(char tipo, Carta *prima, Carta *seconda);