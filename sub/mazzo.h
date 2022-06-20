#ifndef _CARTE_
#include "carte.h"
#define _CARTE_
#endif

typedef struct mazzo {
    char tipo;
    unsigned int numero_carte;
    Carta *insiemeCarte;
} Mazzo;

void initMazzo(Mazzo *m, char tipo, unsigned int numeroCarte);
void generaMazzo(Mazzo *m);
void printMazzo(Mazzo m);
void mescolaMazzo(Mazzo *m);
Carta pescaDalMazzo(Mazzo *m);
int isMazzoEmpty(Mazzo m);