#include <stdio.h>

#define SIZE 2048

int main(void)
{
    int t, n, tmp;

    scanf("%d %d", &t, &n);

    while (t-- > 0) {
        // arrays to check whether a certain line is invalid to be a star's center
        int invalid_row[SIZE] = {0}; // check the rows
        int invalid_col[SIZE]= {0}; // check the columns
        int invalid_tl[2 * SIZE] = {0}; // check the top left to bottom right lines
        int invalid_tr[2 * SIZE] = {0}; // check the top right to bottom left lines

        // Read the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &tmp);

                if (tmp < 255) {
                    invalid_row[i] = 1;
                    invalid_col[j] = 1;
                    invalid_tl[n + (i - j)] = 1; // all points on this line have the same i-j.
                    invalid_tr[i + j] = 1; // all points on this line have the same i+j.
                }
            }
        }

        // Count number of valid star centers
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // determine
                if (!invalid_row[i] &&
                    !invalid_col[j] &&
                    !invalid_tl[n + (i - j)] &&
                    !invalid_tr[i + j]) {
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}

