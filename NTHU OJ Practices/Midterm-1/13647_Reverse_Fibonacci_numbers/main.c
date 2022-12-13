#include <stdio.h>

int reverse_fib(int g0, int g1, int k, int n);

int main(void)
{
    int G0, G1, Gn, n;
    scanf("%d %d %d", &G0, &G1, &n);

    Gn = reverse_fib(G0, G1, 0, n);
    printf("%d\n", Gn);

    return 0;
}

/** reverse fibonacci: G_n+2 = G_n - G_n+1 */
int reverse_fib(int g0, int g1, int k, int n)
{
    if (k == n) {
        return g0;
    }

    return reverse_fib(g1, g0 - g1, k + 1, n);
}

