#ifndef _CARTE_
#include "carte.h"
#define _CARTE_
#endif

// Va a creare una carta nel tipo e numero specificato.
void generaCarta(char tipo, Carta *c, int s, int carta) {
    if (tipo == 'R') {
        c->CRamino.carta = carta;
        c->CRamino.seme = s;
    } else {
        c->CPiacentino.carta = carta;
        c->CPiacentino.seme = s;
    }
}
// Va a stampare su console una carta, secondo il tipo prestabilito.
void printCarta(char tipo, Carta c) {
    if (tipo == 'R') {
        printf("Seme: %d Numero: %d\n", c.CRamino.seme, c.CRamino.carta);
    } else {
        printf("Seme: %d Numero: %d\n", c.CPiacentino.seme, c.CPiacentino.carta);
    }
}
// Va a scambiare due carte tra di loro, sfruttanto il metodo swap dichiarato in utils.
void swapCarte(char tipo, Carta *prima, Carta *seconda) {
    if (tipo == 'R') {
        swap(&(prima->CRamino.carta), &(seconda->CRamino.carta));
        swap(&(prima->CRamino.seme), &(seconda->CRamino.seme));
    } else {
        swap(&(prima->CPiacentino.carta), &(seconda->CPiacentino.carta));
        swap(&(prima->CPiacentino.seme), &(seconda->CPiacentino.seme));
    }
}