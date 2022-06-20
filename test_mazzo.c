#include "sub/mazzo.h"

int main(void) {
    time_t tempo;
    srand((unsigned int)time(&tempo));

    Mazzo prova;
    initMazzo(&prova, 'R', 52);
    generaMazzo(&prova);
    printf("--------------------------------Genero  il mazzo-------------------------------\n");
    printMazzo(prova);
    printf("--------------------------------Mischio il mazzo-------------------------------\n");
    mescolaMazzo(&prova);
    printMazzo(prova);
    printf("--------------------------------Pesca  dal mazzo-------------------------------\n");
    Carta pescata = pescaDalMazzo(&prova);
    printCarta(prova.tipo, pescata);
    printMazzo(prova);
    return 0;
}