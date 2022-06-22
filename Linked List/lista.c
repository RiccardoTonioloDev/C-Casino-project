#include "lista.h"

Nodo* initNodo(int v, Nodo* n) {
    Nodo* ptrNode = malloc(sizeof(Nodo));
    ptrNode->value = v;
    ptrNode->next = n;
    return ptrNode;
}
void printLista(Nodo* n) {
    while (n != NULL) {
        printf("%d ", n->value);
        n = n->next;
    }
    printf("\n");
}

// METODI PER LO STACK
void inserisciInTesta(Nodo** n, int v) {
    Nodo* newHead = initNodo(v, *n);
    *n = newHead;
}
int popInTesta(Nodo** n) {
    Nodo* oldHead = *n;
    *n = (*n)->next;
    int val = oldHead->value;
    free(oldHead);
    return val;
}

// METODI PER UNA LISTA REGULAR
void inserisciLista(Nodo** n, int val, int pos) {
    Nodo* tmp = *n;
    while (pos != 0) {
        tmp = tmp->next;
        n = &((*n)->next);
        pos--;
    }
    Nodo* newNode = initNodo(val, tmp);
    *n = newNode;
}
void inserisciListaR(Nodo** n, int val, int pos) {
    if (pos == 0) {
        inserisciInTesta(n, val);
        return;
    }
    inserisciListaR(&((*n)->next), val, pos - 1);
}
int cancellaLista(Nodo** n, int pos) {
    Nodo* tmp = *n;
    while (pos != 0) {
        tmp = tmp->next;
        n = &((*n)->next);
        pos--;
    }
    int val = tmp->value;
    *n = tmp->next;
    free(tmp);
    return val;
}

// METODI PER UNA LISTA REGULAR (ricorsivo a singolo puntatore)
Nodo* inserisciListaRPS(Nodo* n, int val, int pos) {
    if (pos == 0) {
        Nodo* tmp = initNodo(val, n);
        return tmp;
    }
    n->next = inserisciListaRPS(n->next, val, pos - 1);
    return n;
}
Nodo* cancellaListaRPS(Nodo* n, int pos) {
    if (pos == 0) {
        Nodo* prossimo = n->next;
        free(n);
        return prossimo;
    }
    n->next = cancellaListaRPS(n->next, pos - 1);
    return n;
}