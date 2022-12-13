#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    int max = 0;
    int indices[t];
    for (int i = 0; i < t; i++) {
        scanf("%d", &indices[i]);
        if (indices[i] > max) {
            max = indices[i];
        }
    }

    // fill up fibonacci array only once
    unsigned long long fib[max + 2]; // For case: max = 0
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= max; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print out requested fibonacci numbers
    for (int i = 0; i < t; i++) {
        printf("%llu\n", fib[indices[i]]);
    }

    return 0;
}

