#include <stdio.h>
#include <stdlib.h>

unsigned ***new_3d_array(unsigned n, unsigned m, unsigned k);
void delete_3d_array(unsigned ***arr);

int main(void)
{
    int n = 2, m = 3, k = 4;
    unsigned ***arr = new_3d_array(n, m, k);

    for (int i = 0; i < n; i++) {
        printf("\nprinting n = %d:\n", i);
        for (int j = 0; j < m; j++) {
            for (int h = 0; h < k; h++) {
                arr[i][j][h] = (i * m + j) * k + h;
                printf("%3d", arr[i][j][h]);
            }
            printf("\n");
        }
        printf("\n");
    }

    delete_3d_array(arr);

    return 0;
}

unsigned ***new_3d_array(unsigned n, unsigned m, unsigned k)
{
    unsigned ***arr = (unsigned ***) malloc(n * sizeof(unsigned **) + n * m * sizeof(unsigned *) + n * m * k * sizeof(unsigned));

    // unsigned ** += 1 will plus a unit of its storage unit, which is sizeof(unsigned *)
    unsigned **ptr1 = (unsigned **)(arr + n);
    for (int i = 0; i < n; i++, ptr1 += m) {
        *(arr + i) = ptr1;
    }

    return arr;
}

void delete_3d_array(unsigned ***arr)
{
    free(arr);
}
