#include <stdio.h>

int main()
{
    int g, b, s;
    long long num_bullets;
    double guns_per_spy;

    scanf("%d %d %d", &g, &b, &s);

    num_bullets = (long long) g * b;
    guns_per_spy = (double) g / s;

    printf("%lld\n%.2f\n", num_bullets, guns_per_spy);

    return 0;
}
