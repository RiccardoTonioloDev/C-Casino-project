#include "BTree.h"

int main(void) {
    BTNode* root = initBTNode(150, NULL, NULL);
    anticipata(root);
    printf("\n");
    inserisciBT(&root, 75);
    inserisciBT(&root, 900);
    inserisciBT(&root, 450);
    inserisciBT(&root, 90);
    inserisciBT(&root, 60);
    inserisciBT(&root, 1);
    anticipata(root);
    printf("\n");
    simmetrico(root);
    printf("\n");
    posticipata(root);
    printf("\n");
    cancellaBT(&root, 900);
    simmetrico(root);
    printf("\n");
    cancellaBT(&root, 150);
    simmetrico(root);
    printf("\n");
    cancellaBT(&root, 1);
    simmetrico(root);
    printf("\n");
    return 0;
}