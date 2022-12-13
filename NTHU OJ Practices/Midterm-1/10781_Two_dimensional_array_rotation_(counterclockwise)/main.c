#include <stdio.h>

int min(int a, int b);
int max(int a, int b);

int main(void)
{
    int n;
    scanf("%d", &n);

    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // SOLVE
    int times = 2 * n - 1;
    for (int i = 0; i < times; i++) {
        int row = max(i - n + 1, 0);
        int col = max(n - 1 - i, 0);
        for (int j = 0; j < min(i + 1, times - i) - 1; j++) {
            printf("%d ", arr[row][col]);
            row++;
            col++;
        }
        // print last element without space after.
        printf("%d\n", arr[row][col]);
    }

    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}
