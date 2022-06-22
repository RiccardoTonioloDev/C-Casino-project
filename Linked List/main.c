#include "lista.h"

int main() {
    Nodo *head = initNodo(10, NULL);
    inserisciInTesta(&head, 11);
    inserisciInTesta(&head, 12);
    inserisciInTesta(&head, 13);
    inserisciInTesta(&head, 14);
    //     printLista(head);
    //     printf("%d \n", popInTesta(&head));
    //     printf("%d \n", popInTesta(&head));
    //     printLista(head);
    inserisciLista(&head, 15, 0);
    inserisciLista(&head, 16, 0);
    inserisciLista(&head, 950, 1);
    printLista(head);
    printf("Valore cancellato: %d\n", cancellaLista(&head, 2));
    printLista(head);
    inserisciListaR(&head, 15, 2);
    printLista(head);
    head = inserisciListaRPS(head, 700, 3);
    printLista(head);
    head = cancellaListaRPS(head, 3);
    printLista(head);
    return 0;
}