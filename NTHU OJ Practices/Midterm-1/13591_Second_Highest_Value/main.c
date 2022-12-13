#include <stdio.h>

int main(void)
{
    int i, j;
    int n;
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    // SOLVE
    int ans[n];
    ans[0] = 0;

    // start finding from 2nd number
    for (i = 1; i < n; i++) {
        int max;
        int max_2nd;

        (arr[0] > arr[1]) ?

        for (j = 0; j <= i; j++) {
            if (arr[j] > max) {
                max_2nd = max;
                max = arr[j];
            }
        }
        ans[i] = max_2nd;
    }

    // print
    for (i = 0; i < n - 1; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[i]);

    return 0;
}
