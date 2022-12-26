#include <stdio.h>
#include <stdlib.h>

#include "function.h"

int compare(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

int** s(int* a,int len) {
    // Malloc returned 2d array
    int size =  (int)sqrt(len);
    int** arr = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = (int*)malloc(sizeof(int) * size);
    }

    // Sort original 1d array
    qsort(a, len, sizeof(int), compare);

    // put sorted array to 2d arr
    for (int i = 0, row = 0, col = 0; i < len; i++) {
        arr[row][col] = a[i];
        if (i == (row + 1) * size - 1) {
            row++;
            col = 0;
            continue;
        }
        col++;
    }

    return arr;
}

void print(int** ans,int len) {
    int size =  (int)sqrt(len);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }

    // (not in spec)
    // free the ans
}
