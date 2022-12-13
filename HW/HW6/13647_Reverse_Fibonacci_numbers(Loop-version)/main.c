#include <stdio.h>

int main(void)
{
    int n;
    int G[31];

    scanf("%d%d%d", &G[0], &G[1], &n);

    for (int i = 2; i <= n; i++) {
        G[i] = G[i - 2] - G[i - 1];
    }

    printf("%d\n", G[n]);

    return 0;
}
