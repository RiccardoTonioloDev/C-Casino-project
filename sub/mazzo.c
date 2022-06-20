#include "mazzo.h"

// Crea un mazzo vuoto, del tipo e con numero di carte richiesto(il numero di carte è associato al tipo).
void initMazzo(Mazzo *m, char tipo, unsigned int numeroCarte) {
    m->tipo = tipo;
    m->numero_carte = numeroCarte;
    m->insiemeCarte = NULL;
}
// Riempie il mazzo con carte dal contenuto sensato, ma ordinato.
void generaMazzo(Mazzo *m) {
    m->insiemeCarte = malloc(sizeof(Carta) * (m->numero_carte));
    int numeroCartePerSeme = (m->numero_carte) / 4;
    for (int i = 0; i < 4; i++) {
        for (int c = 1; c <= numeroCartePerSeme; c++) {
            generaCarta(m->tipo, m->insiemeCarte + i * numeroCartePerSeme + c - 1, i, c);
        }
    }
}
// Vado a stampare carta per carta l'interno mazzo.
void printMazzo(Mazzo m) {
    for (int i = 0; i < m.numero_carte; i++) {
        printCarta(m.tipo, *(m.insiemeCarte + i));
    }
}
// Va a mischiare un numero prestabilito di volte in base al numero di carte nel mazzo, il mazzo stesso.
void mescolaMazzo(Mazzo *m) {
    unsigned int primaScelta;
    unsigned int secondaScelta;

    for (int i = 0; i < m->numero_carte; i++) {
        primaScelta = rand() % m->numero_carte;
        while (1) {
            secondaScelta = rand() % m->numero_carte;
            if (secondaScelta != primaScelta) {
                break;
            }
        }
        Carta *primaCarta = m->insiemeCarte + (primaScelta);
        Carta *secondaCarta = m->insiemeCarte + (secondaScelta);
        swapCarte(m->tipo, primaCarta, secondaCarta);
    }
}
// Pesca una carta dalla cima del mazzo e ne diminuisce (al mazzo), il numero totali di carte.
Carta pescaDalMazzo(Mazzo *m) {
    m->numero_carte -= 1;
    return *(m->insiemeCarte + m->numero_carte);
}
// Verifica se il mazzo è vuoto o meno.
int isMazzoEmpty(Mazzo m) {
    return m.numero_carte > 0 ? 0 : 1;
}