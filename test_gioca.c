#include <time.h>

#include "sub/gioco.h"

int main(void) {
    time_t tempo;
    srand((unsigned int)time(&tempo));
    int credito = 90;
    gioco_Carte('R', &credito);
    printf("Credito: %d\n", credito);
}