#include "utils.h"
// Scambia due numeri interi.
void swap(int *x, int *y) {
    int tmp = *y;
    *y = *x;
    *x = tmp;
}