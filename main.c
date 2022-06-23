#include "sub/gioco.h"
#include "sub/user.h"

void setupUtente() {
    printf("1) Crea utente;\n");
    printf("2) Aggiungi credito.\n");
    int scelta = 0;
    scanf("%d", &scelta);
    char nome[20];
    printf("Scrivere il tuo nome: ");
    scanf("%s", &nome);
    getchar();
    Utente u;
    creaUtente(&u, nome);
    if (scelta == 1) {
        saveUser(u);
    } else {
        updateSaldo(u);
    }
}

void scegliGiochi() {
    printf("1) Ramino (R);\n");
    printf("2) Piacentine (P);\n");
    printf("3) Roulette (Z).\n");
    char scelta = 0;
    scanf("%c", &scelta);
    getchar();
    char nome[20];
    printf("Scrivere il tuo nome: ");
    scanf("%s", &nome);
    getchar();
    Utente u;
    creaUtente(&u, nome);
    updateSaldo(u);
    if (scelta == 'Z')
        gioco_Roulette(&(u.saldo));
    else
        gioco_Carte(scelta, &(u.saldo));
    updateSaldo(u);
    printf("Saldo disponibile: %d\n", u.saldo);
}

void (*arrayScelte[2])() = {setupUtente, scegliGiochi};

int main() {
    printf("1) Setup Utente (0);\n");
    printf("2) Gioca (1).\n");
    int scelta = 0;
    scanf("%d", &scelta);
    getchar();
    (*arrayScelte[scelta])();
    return 0;
}