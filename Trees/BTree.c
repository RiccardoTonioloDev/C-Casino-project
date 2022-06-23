#include "BTree.h"

BTNode *initBTNode(int val, BTNode *left, BTNode *right) {
    BTNode *tmp = malloc(sizeof(BTNode));
    tmp->value = val;
    tmp->left = left;
    tmp->right = right;
    return tmp;
}

void inserisciBT(BTNode **root, int value) {
    if (*root == NULL) {
        *root = initBTNode(value, NULL, NULL);
        return;
    }
    if ((*root)->value < value) {
        inserisciBT(&((*root)->right), value);
    } else {
        inserisciBT(&((*root)->left), value);
    }
}

void anticipata(BTNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    anticipata(root->left);
    anticipata(root->right);
}
void simmetrico(BTNode *root) {
    if (root == NULL) {
        return;
    }
    simmetrico(root->left);
    printf("%d ", root->value);
    simmetrico(root->right);
}
void posticipata(BTNode *root) {
    if (root == NULL) {
        return;
    }
    posticipata(root->left);
    posticipata(root->right);
    printf("%d ", root->value);
}

void cancellaBT(BTNode **root, int value) {
    if ((*root)->value == value) {
        if ((*root)->right == NULL) {
            BTNode *toBeDeleted = *root;
            *root = (*root)->left;
            free(toBeDeleted);
        } else if ((*root)->right == NULL && (*root)->left == NULL) {
            BTNode *toBeDeleted = *root;
            *root = NULL;
            free(toBeDeleted);
        } else {
            sostituzioneConSuccessore(root);
        }
        return;
    }
    if ((*root)->value > value)
        cancellaBT(&((*root)->left), value);
    else
        cancellaBT(&((*root)->right), value);
}

int popMin(BTNode **root) {
    if ((*root)->left == NULL) {
        int val = (*root)->value;
        BTNode *toBeDeleted = *root;
        *root = (*root)->right;
        free(toBeDeleted);
        return val;
    }
    return popMin(&((*root)->left));
}

void sostituzioneConSuccessore(BTNode **root) {
    int val = popMin(&((*root)->right));
    (*root)->value = val;
}