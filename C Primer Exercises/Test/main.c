#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Swap(int* A, int* B) {
    char c1, c2;
    int n1, n2;
    scanf(" %c %c %d %d", &c1, &c2, &n1, &n2);

    if (c1 == 'A') {
        if (c2 == 'B') {
            swap(&A[n1], &B[n2]);
        }
        else {
            swap(&A[n1], &A[n2]);
        }
    }
    else {
        if (c2 == 'B') {
            swap(&B[n1], &B[n2]);
        }
        else {
            swap(&B[n1], &A[n2]);
        }
    }
}

void Replace(int* A, int* B) {
    char c;
    int n, value;
    scanf(" %c %d %d", &c, &n, &value);

    if (c == 'A') {
        A[n] = value;
    }
    else {
        B[n] = value;
    }
}

void Switch(int** A, int** B) {
    int *tmp = *A;
    *A = *B;
    *B = tmp;
}


