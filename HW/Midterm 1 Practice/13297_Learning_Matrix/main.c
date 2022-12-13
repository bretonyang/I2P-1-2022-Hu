#include <stdio.h>


int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    int A[n][m];
    int B[m][n];
    int C[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix Multiplication
    // loop through C matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            C[row][col] = 0;

            // fill in each element in C
            for (int i = 0; i < m; i++) {
                C[row][col] += A[row][i] * B[i][col];
            }
        }
    }

    // print the transpose matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", C[j][i]);
            printf("%c", (j < n - 1) ? ' ' : '\n');
        }
    }

    return 0;
}
