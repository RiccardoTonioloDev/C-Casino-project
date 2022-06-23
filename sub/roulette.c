#include "roulette.h"

FettaRoulette* initFettaRoulette(int val, char color, FettaRoulette* next) {
    FettaRoulette* tmp = malloc(sizeof(FettaRoulette));
    tmp->numero = val;
    tmp->next = next;
    tmp->colore = color;
    return tmp;
}

void initRoulette(FettaRoulette** fr) {
    FettaRoulette* zero = initFettaRoulette(0, 'V', NULL);
    zero->next = zero;
    FettaRoulette* tmp = zero;

    for (int i = 1; i <= 36; i++) {
        if (i <= 18) {
            tmp->next = initFettaRoulette(i, 'R', tmp->next);
        } else {
            tmp->next = initFettaRoulette(i, 'N', tmp->next);
        }
        tmp = tmp->next;
    }
    *fr = zero;  // Restituiamo la testa.
}

void stampaRoulette(FettaRoulette* fr) {
    int count = 0;
    while (count == 0 || fr->numero != 0) {
        printf("Numero: %d  Colore: %C\n", fr->numero, fr->colore);
        fr = fr->next;
        count++;
    }
}

int lancioPallina(FettaRoulette* fr, int pos) {
    if (pos == 0) return fr->numero;
    return lancioPallina(fr->next, pos - 1);
}