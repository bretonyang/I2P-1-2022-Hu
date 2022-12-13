#include <stdio.h>
#include "function.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

void swap(long long *a, long long *b) {
    long long tmp = *a;
    *a = *b;
    *b = tmp;
}

void array2d_sort(int row, int col, long long arr[][500]) {
    for (int counter = row - 1; counter > -col; counter--) {

        // sort diagonally
        int start_row = max(counter, 0);
        int start_col = max(-counter, 0);


        int swapped = 0; // flag to optimize

        // Number of bubble loops
        for (int i = min(row - start_row - 1, col - start_col - 1); i > 0; i--) {
            // exchange the largest to the end
            for (int j = 0; j < i; j++) {
                if (arr[start_row + j][start_col + j] > arr[start_row + j + 1][start_col + j + 1]) {
                    swap(&arr[start_row + j][start_col + j], &arr[start_row + j + 1][start_col + j + 1]);
                    swapped = 1;
                }
            }

            if (!swapped) {
                break; // diagonal already sorted
            }
        }
    }
}

/*

 3 5

 2 4 1 5 1
 4 9 3 0 7
 1 0 8 9 3


 5 3

 2 4 1
 8 0 3
 4 9 2
 3 5 7
 1 6 2

*/
