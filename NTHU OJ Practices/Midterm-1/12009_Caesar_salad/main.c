#include <stdio.h>

#define SIZE 3

int main(void)
{
    char str[SIZE + 1];
    int n;
    scanf("%s", str);
    scanf("%d", &n);

    // Caesar cipher
    for (int i = 0; i < SIZE; i++)
    {
        long long int a = str[i] - 'A' + (long long int)n;
        while (a < 0)
        {
            a += 26;
        }
        str[i] = 'A' + a % 26;
    }

    printf("%s\n", str);

    return 0;
}
