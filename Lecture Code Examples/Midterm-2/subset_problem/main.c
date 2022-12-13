#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int n, int arr[])
{
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    putchar('\n');
}

void print_subsets(int cnt, int n, int arr[], int soFarCnt, int soFar[])
{
    if (cnt == n) {
        print_arr(soFarCnt, soFar);
        return;
    }

    // don't add to soFar subset
    print_subsets(cnt + 1, n, arr, soFarCnt, soFar);

    // add to soFar subset
    soFar[soFarCnt] = arr[cnt];
    print_subsets(cnt + 1, n, arr, soFarCnt + 1, soFar);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    int soFar[n];

    print_subsets(0, n, arr, 0, soFar);

    return 0;
}
