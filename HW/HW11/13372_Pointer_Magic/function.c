#include "function.h"

void Swap(int* A, int* B) {
    char c1, c2;
    int n1, n2, tmp;

    scanf(" %c %c %d %d", &c1, &c2, &n1, &n2);
//    printf("scanned: %c %c %d %d\n", c1, c2, n1, n2);

    if (c1 == 'A') { // swap A with B
        if (c2 == 'B') {
            tmp = A[n1];
            A[n1] = B[n2];
            B[n2] = tmp;
        }
        else { // swap A with A
            tmp = A[n1];
            A[n1] = A[n2];
            A[n2] = tmp;
        }
    }
    else {
        if (c2 == 'B') { // swap B with B
            tmp = B[n1];
            B[n1] = B[n2];
            B[n2] = tmp;
        }
        else { // swap B with A
            tmp = B[n1];
            B[n1] = A[n2];
            A[n2] = tmp;
        }
    }
}

void Replace(int* A, int* B) {
    char c;
    int idx, num;

    scanf(" %c %d %d", &c, &idx, &num);
//    printf("scanned: %c %d %d\n", c, idx, num);

    if (c == 'A') {
        A[idx] = num;
    }
    else {
        B[idx] = num;
    }
}

void Switch(int** p_A, int** p_B) {
    int *tmp = *p_A;
    *p_A = *p_B;
    *p_B = tmp;
}
