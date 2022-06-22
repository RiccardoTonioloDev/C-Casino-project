#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int value;
    struct nodo *next;
} Nodo;

Nodo *initNodo(int v, Nodo *n);
void inserisciInTesta(Nodo **n, int v);
int popInTesta(Nodo **n);
void printLista(Nodo *n);
void inserisciLista(Nodo **n, int val, int pos);
void inserisciListaR(Nodo **n, int val, int pos);
int cancellaLista(Nodo **n, int pos);
Nodo *inserisciListaRPS(Nodo *n, int val, int pos);
Nodo *cancellaListaRPS(Nodo *n, int pos);