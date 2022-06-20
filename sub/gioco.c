#include "gioco.h"

void gioco_Carte(char tipo, int *credito) {
    // INIZIALIZZO IL MAZZO, LO RIEMPIO E LO MESCOLO.
    Mazzo mazzoDaGioco;
    initMazzo(&mazzoDaGioco, tipo, 52);
    generaMazzo(&mazzoDaGioco);
    mescolaMazzo(&mazzoDaGioco);
    // SELEZIONO LE CARTE PER IL COMPUTER.
    Carta cpu1;
    Carta cpu2;
    Carta cpu3;
    int counter = 0;
    // -------- HA 8 TENTATIVI PER RIFIUTARE LE CARTE SELEZIONATE.
    while (1 && counter < 8) {
        cpu1 = pescaDalMazzo(&mazzoDaGioco);
        cpu2 = pescaDalMazzo(&mazzoDaGioco);
        cpu3 = pescaDalMazzo(&mazzoDaGioco);
        if (rand() % 2) {
            break;
        }
        counter++;
    }
    printf("IL COMPUTER HA SCELTO SE ACCETTARE O MENO.\n");
    // L'UTENTE DEVE SELEZIONARE LE PROPRIE CARTE.
    printf("Scegli se accettare(a) o meno(d) le tue carte: (a/d)\n");
    Carta persona1;
    Carta persona2;
    Carta persona3;
    char choice = 'd';
    // -------- L'UTENTE PUò CONTINUARE A PESCARE A GRUPPI DI 3 FINO A CHE IL MAZZO NON DIVENTA VUOTO.
    while (choice == 'd' && isMazzoEmpty(mazzoDaGioco) == 0) {
        persona1 = pescaDalMazzo(&mazzoDaGioco);
        persona2 = pescaDalMazzo(&mazzoDaGioco);
        persona3 = pescaDalMazzo(&mazzoDaGioco);
        printCarta(tipo, persona1);
        printCarta(tipo, persona2);
        printCarta(tipo, persona3);
        scanf("%c", &choice);
        getchar();
    }
    // SI CALCOLANO I PUNTEGGI PER OGNI GIOCATORE, USANDO IL SEME COME MOLTIPLICATORE E IL NUMERO COME PUNTEGGIO PER CARTA.
    int punteggioCPU = cpu1.CRamino.carta * cpu1.CRamino.seme +
                       cpu2.CRamino.carta * cpu2.CRamino.seme +
                       cpu3.CRamino.carta * cpu3.CRamino.seme;
    int punteggioPersona = persona1.CRamino.carta * persona1.CRamino.seme +
                           persona2.CRamino.carta * persona2.CRamino.seme +
                           persona3.CRamino.carta * persona3.CRamino.seme;
    // CHI HA IL PUNTEGGIO PIU` ALTO VINCE.
    if (punteggioCPU > punteggioPersona) {
        printf("HA VINTO IL COMPUTER!\n");
        *credito = *credito - 10;
    } else {
        printf("HAI VINTO TU!\n");
        *credito = *credito + 10;
    }
}