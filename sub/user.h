#include <stdio.h>
#include <string.h>

typedef struct utente {
    char nome[20];
    unsigned int saldo;
} Utente;

// Gestione in RAM dell'utente
void creaUtente(Utente *u, char nome[20]);
void loadMoney(Utente *u, int money);

// Gestione in mem. secondaria dell'Utente
void manageCounterUtenti(int numeroUtentiAggiunti);
int getUserCounter();

void saveUser(Utente u);
int cercaUtente(Utente u);
void updateSaldo(Utente u);