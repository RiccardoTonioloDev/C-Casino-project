#include "sub/user.h"

int main(void) {
    Utente u;
    creaUtente(&u, "Riccardo");
    loadMoney(&u, 100);
    saveUser(u);
    printf("Numero utenti: %d\n", getUserCounter());
    Utente y;
    creaUtente(&y, "Menny");
    loadMoney(&y, 200);
    saveUser(y);
    printf("Numero utenti: %d\n", getUserCounter());
    y.saldo = 150;
    updateSaldo(y);
    return 0;
    printf("Menny in pos: %d", cercaUtente(y));
}