#include <stdio.h>

int main(void)
{
    int Am, An;
    scanf("%d %d", &Am, &An);

    int A[Am][An];
    for (int i = 0; i < Am; i++) {
        for (int j = 0; j < An; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int Bm, Bn;
    scanf("%d %d", &Bm, &Bn);

    int B[Bm][Bn];
    for (int i = 0; i < Bm; i++) {
        for (int j = 0; j < Bn; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // SOLVE
    int C[Am][Bn];
    for (int i = 0; i < Am; i++) {
        for (int j = 0; j < Bn; j++) {
            C[i][j] = 0;
            for (int k = 0; k < An; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // print result
    for (int i = 0; i < Am; i++) {
        for (int j = 0; j < Bn; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
