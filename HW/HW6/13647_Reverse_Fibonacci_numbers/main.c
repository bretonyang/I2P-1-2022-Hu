#include <stdio.h>

int reverse_fib(int cnt, int n, int G0, int G1);

int main(void)
{
    int G0, G1, n;
    scanf("%d %d %d", &G0, &G1, &n);

    printf("%d\n", reverse_fib(0, n, G0, G1));

    return 0;
}

int reverse_fib(int cnt, int n, int G0, int G1)
{
    if (cnt == n) {
        return G0;
    }

    return reverse_fib(cnt + 1, n, G1, G0 - G1);
}
