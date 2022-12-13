#include <stdio.h>

double power(double n, int p);

int main(void)
{
    double n;
    int p;

    scanf("%lf %d", &n, &p);

    printf("%.6f\n", power(n, p));

    return 0;
}

double power(double n, int p)
{
    // Basis step
    if (p == 0) {
        return 1;
    }

    // Recursive step: power(n, p) = n * power(n, p-1)
    return n * power(n, p - 1);
}
