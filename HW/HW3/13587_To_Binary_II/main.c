#include <stdio.h>

#define SIZE 31

void print_binary(int d);

int main(void)
{
    int d; // non-negative decimal number
    scanf("%d", &d);

    print_binary(d);

    return 0;
}

void print_binary(int d)
{
    if (d == 0)
    {
        printf("0\n");
        return;
    }

    int bin[SIZE];

    // convert
    int i = 0;
    while (d > 0)
    {
        bin[i] = d % 2;
        d /= 2;
        i++;
    }

    // display
    i--;
    while (i >= 0)
    {
        printf("%d", bin[i]);
        i--;
    }
    printf("\n");
}
