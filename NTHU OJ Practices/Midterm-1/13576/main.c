#include <stdio.h>

int main()
{
    int G, B, S;
    scanf("%d %d %d", &G, &B, &S);

    printf("%lld\n", (long long) G * B);
    printf("%.2f\n", (double) G / S);

    return 0;
}
