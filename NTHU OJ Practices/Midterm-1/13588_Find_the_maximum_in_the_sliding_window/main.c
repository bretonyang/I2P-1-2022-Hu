#include <stdio.h>

int main(void)
{
    int N, M;
    int matrix[15][15] = {0};

    // Read input
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print output
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            // find max
            int max = 0;
            for (int row = i; row < i + M; row++) {
                for (int col = j; col < j + M; col++) {
                    if (matrix[row][col] > max) {
                        max = matrix[row][col];
                    }
                }
            }
            // print max
            printf("%5d", max);
        }
        printf("\n");
    }

    return 0;
}

