#include "user.h"

void creaUtente(Utente *u, char nome[20]) {
    strcpy(u->nome, nome);
    u->saldo = 0;
}

void loadMoney(Utente *u, int money) {
    u->saldo += money;
}

void manageCounterUtenti(int numeroUtentiAggiunti) {
    if (numeroUtentiAggiunti == 0) return;
    FILE *fp;
    fp = fopen("numeroutenti.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        fp = fopen("numeroutenti.txt", "w");
        fprintf(fp, "%d", numeroUtentiAggiunti);
        fclose(fp);
        return;
    }
    int contatoreVecchiUtenti;
    fscanf(fp, "%d", &contatoreVecchiUtenti);
    fclose(fp);
    fp = fopen("numeroutenti.txt", "w");
    numeroUtentiAggiunti += contatoreVecchiUtenti;
    fprintf(fp, "%d", numeroUtentiAggiunti);
    fclose(fp);
}

int getUserCounter() {
    FILE *fp;
    fp = fopen("numeroutenti.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 0;
    }
    int counter;
    fscanf(fp, "%d", &counter);
    fclose(fp);
    return counter;
}

int cercaUtente(Utente u) {
    FILE *fp;
    fp = fopen("userDB.dat", "rb");
    if (fp == NULL) {
        fclose(fp);
        return -1;
    }
    int numeroUtenti = getUserCounter();
    for (int i = 0; i < numeroUtenti; i++) {
        Utente tmp;
        fread(&tmp, sizeof(Utente), 1, fp);
        printf("Nome: %s Saldo: %d\n", tmp.nome, tmp.saldo);
        if (strcmp(tmp.nome, u.nome) == 0) {
            fclose(fp);
            return i;
        }
    }
    fclose(fp);
    return -1;
}

void saveUser(Utente u) {
    FILE *fp;
    fp = fopen("userDB.dat", "rb");
    if (fp == NULL) {
        fclose(fp);
        fp = fopen("userDB.dat", "wb");
        manageCounterUtenti(1);
        fwrite(&u, sizeof(Utente), 1, fp);
        fclose(fp);
        return;
    }
    fclose(fp);
    if (cercaUtente(u) != -1) {
        printf("Utente già esistente.\n");
        return;
    }
    fp = fopen("userDB.dat", "ab");
    manageCounterUtenti(1);
    fwrite(&u, sizeof(Utente), 1, fp);
    fclose(fp);
}

void updateSaldo(Utente u) {
    int userExist = cercaUtente(u);
    if (userExist == -1) {
        printf("Utente non esistente.\n");
        return;
    }
    FILE *fp = fopen("userDB.dat", "rb+");
    fseek(fp, sizeof(Utente) * userExist + sizeof(u.nome), SEEK_SET);
    int precedenteSaldo;
    fread(&precedenteSaldo, sizeof(u.saldo), 1, fp);
    u.saldo += precedenteSaldo;
    fseek(fp, sizeof(u.saldo) * (-1), SEEK_CUR);
    fwrite(&(u.saldo), sizeof(u.saldo), 1, fp);
    fclose(fp);
}