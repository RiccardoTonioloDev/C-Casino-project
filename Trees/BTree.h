#include <stdio.h>
#include <stdlib.h>

typedef struct btNode {
    int value;
    struct btNode *left;
    struct btNode *right;
} BTNode;

BTNode *initBTNode(int val, BTNode *left, BTNode *right);
void inserisciBT(BTNode **root, int value);

void anticipata(BTNode *root);
void simmetrico(BTNode *root);
void posticipata(BTNode *root);
int popMin(BTNode **root);
void sostituzioneConSuccessore(BTNode **root);
void cancellaBT(BTNode **root, int value);