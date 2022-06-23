#include "tree.h"

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void init(BTree **ptrPtr) {
    *ptrPtr = NULL;
}

// restituisce 1 se l'albero è vuoto, 0 altrimenti
int isempty(BTree *ptr) {
    return ptr == NULL;
}

// restituisce 1 se l'albero contie l'elemento val, 0 altrimenti
int search_rec(BTree *ptr, int val) {
    if (ptr != NULL) {
        if (ptr->valore == val) {
            return 1;
        } else {
            if (ptr->valore > val)
                search_rec(ptr->leftPtr, val);
            else
                search_rec(ptr->rightPtr, val);
        }
    }
    return 0;
}

// visita ricorsiva
void print_rec(BTree *ptr) {
    if (ptr != NULL) {
        // printf("%d ", ptr->valore); // visita in pre-ordine
        print_rec(ptr->leftPtr);
        printf("%d ", ptr->valore);  // visita simmetrica (in ordine)
        print_rec(ptr->rightPtr);
        // printf("%d ", ptr->valore); // visita in post-ordine (in profondità / "depth-first")
    }
}

unsigned int depth(BTree *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    unsigned int d_s = 1 + depth(ptr->leftPtr);
    unsigned int d_d = 1 + depth(ptr->rightPtr);
    return d_s > d_d ? d_s : d_d;
}

void print_level(BTree *ptr, unsigned int currentl, int level, unsigned int depth) {
    if (ptr == NULL) {
        if (currentl == 0) {
            printf(" ");
        } else {
            print_level(NULL, currentl - 1, level, depth);
            for (int i = 0; i < exp2(depth - level) - 1; i++) {
                printf(" ");
            }
            // printf("(%d)", (depth-level)*2 +1);
            print_level(NULL, currentl - 1, level, depth);
        }
    } else if (currentl == 0) {
        printf("%d", ptr->valore);
    } else {
        print_level(ptr->leftPtr, currentl - 1, level, depth);
        for (int i = 0; i < exp2(depth - level) - 1; i++) {
            printf(" ");
        }
        // printf("(%d)", (depth-level)*2 +1);
        print_level(ptr->rightPtr, currentl - 1, level, depth);
    }
}

void print_connections(BTree *ptr, unsigned int currentl, int level, unsigned int depth) {
    if (ptr == NULL) {
        if (currentl == 0) {
            printf("  ");
            for (int i = 0; i < (level == depth - 2 ? 1 : exp2(depth - level - 2) - 1); i++) {
                printf(" ");
            }
        } else {
            print_connections(NULL, currentl - 1, level, depth);
            for (int i = 0; i < (level == depth - 2 ? 1 : exp2(depth - level - 2) - 1); i++) {
                printf(" ");
            }
            // printf("(%d)", (depth-level)*2 +1);
            print_connections(NULL, currentl - 1, level, depth);
        }
    } else if (currentl == 0) {
        if (ptr->leftPtr != NULL) {
            printf("/");
        } else
            printf(" ");
        for (int i = 0; i < (level == depth - 2 ? 1 : exp2(depth - level - 2) - 1); i++) {
            printf(" ");
        }
        if (ptr->rightPtr != NULL) {
            printf("\\");
        } else
            printf(" ");
    } else {
        print_connections(ptr->leftPtr, currentl - 1, level, depth);
        for (int i = 0; i < (level == depth - 2 ? 1 : (exp2(depth - level) + exp2(depth - 1 - level)) / 2 - 1); i++) {
            printf(" ");
        }
        // printf("(%d)", (depth-level)*2 +1);
        print_connections(ptr->rightPtr, currentl - 1, level, depth);
    }
}

void print_scheme(BTree *ptr) {
    for (int i = 0; i < depth(ptr) - 1; i++) {
        for (int j = 0; j < exp2(depth(ptr) - 1 - i) - 1; j++) {  // d(i) = d(i+1)*2 +1
            printf(" ");
        }
        print_level(ptr, i, i, depth(ptr));
        printf("\n");
        for (int j = 0; j < (i == depth(ptr) - 2 ? 0 : (exp2(depth(ptr) - 1 - i) + exp2(depth(ptr) - 2 - i)) / 2 - 1); j++) {  // d(i) = d(i+1)*2 +1
            printf(" ");
        }
        print_connections(ptr, i, i, depth(ptr));
        printf("\n");
    }
    print_level(ptr, depth(ptr) - 1, depth(ptr) - 1, depth(ptr));
    printf("\n");
}

// DA IMPLEMENTARE

BTree *ordinsert_rec(BTree *ptr, int val) {
    // Se arriviamo fino alle foglie oppure se la radice è vuota.
    if (ptr == NULL) {
        BTree *tmpPtr = malloc(sizeof(BTree));
        tmpPtr->rightPtr = NULL;
        tmpPtr->leftPtr = NULL;
        tmpPtr->valore = val;
        return tmpPtr;
    }

    if (ptr->valore == val) {
        return ptr;
    }

    // Confronto con valore attuale.
    // Se val è minore allora deve andare a sinistra.
    if (ptr->valore > val) {
        ptr->leftPtr = ordinsert_rec(ptr->leftPtr, val);
    }
    // Se val è minore allora deve andare a destra.
    else {
        ptr->rightPtr = ordinsert_rec(ptr->rightPtr, val);
    }

    // Restituisco il ptr aggiornato.
    return ptr;
}

int min(BTree *ptrPtr) {
    if (ptrPtr == NULL) {
        // Int Max viene resituito dalle foglie o da una radice vuota.
        return INT_MAX;
    }
    int minSx = min(ptrPtr->leftPtr);
    int minDx = min(ptrPtr->rightPtr);

    if (ptrPtr->valore < minSx && ptrPtr->valore < minDx) {
        return ptrPtr->valore;
    } else if (minSx < minDx) {
        return minSx;
    } else {
        return minDx;
    }
}

unsigned int size(BTree *ptrPtr) {
    if (ptrPtr == NULL) {
        return 0;
    } else {
        int sizeSx = size(ptrPtr->leftPtr);

        int sizeDx = size(ptrPtr->rightPtr);

        return 1 + sizeSx + sizeDx;
    }
}

void delete_pos(BTree **ptrPtr, unsigned pos) {
    if (pos == 1) {
        // Situazione per le foglie.
        if ((*ptrPtr)->leftPtr == NULL && (*ptrPtr)->rightPtr == NULL) {
            free(*ptrPtr);
            *ptrPtr = NULL;
            return;
        }

        // Situazione dove non esiste la foglia sinistra, e quindi si assegna il valore della foglia destra.
        if ((*ptrPtr)->leftPtr == NULL) {
            (*ptrPtr)->valore = (*ptrPtr)->rightPtr->valore;
            delete_pos(&((*ptrPtr)->rightPtr), pos);
            return;
        }
        // Situazione dove non esiste la foglia destra, e quindi si assegna il valore della foglia sinistra.
        if ((*ptrPtr)->rightPtr == NULL) {
            (*ptrPtr)->valore = (*ptrPtr)->leftPtr->valore;
            delete_pos(&((*ptrPtr)->leftPtr), pos);
            return;
        }
        // Situazione in cui esistano entrambe le foglie.
        if ((*ptrPtr)->leftPtr->valore > (*ptrPtr)->rightPtr->valore) {
            (*ptrPtr)->valore = (*ptrPtr)->rightPtr->valore;
            delete_pos(&((*ptrPtr)->rightPtr), pos);
        } else {
            (*ptrPtr)->valore = (*ptrPtr)->leftPtr->valore;
            delete_pos(&((*ptrPtr)->leftPtr), pos);
        }
        return;

    } else {
        // Posizione inesistente: eccede la size dell' albero.
        if (pos > size(*ptrPtr)) {
            return;
        } else {
            // Questa situazione significa che la posizione cercata è per forza nel ramo sinistro.
            int sizeSinistra = size((*ptrPtr)->leftPtr);
            pos--;
            if (sizeSinistra >= pos) {
                delete_pos(&((*ptrPtr)->leftPtr), pos);
            } else {
                pos -= sizeSinistra;

                // Se abbiamo superato le prime due condizioni vuol dire che la posizione è nel ramo destro.
                delete_pos(&((*ptrPtr)->rightPtr), pos);
            }
        }
    }
}