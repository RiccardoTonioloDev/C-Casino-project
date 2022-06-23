#include "sub/roulette.h"

int main(void) {
    FettaRoulette *zero;
    initRoulette(&zero);
    stampaRoulette(zero);
    printf("Numero estratto: %d", lancioPallina(zero, 37));

    return 0;
}