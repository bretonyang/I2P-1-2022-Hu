#include <stdio.h>

void print_pattern(int height);
int min(int a, int b);

int main(void)
{
    int n;
    scanf("%d", &n);

    print_pattern(n);

    return 0;
}

void print_pattern(int height)
{
    for (int i = 0; i < height; i++) {
        // spaces
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }

        // numbers
        for (int j = 0, width = 2 * i + 1; j < width; j++) {
            printf("%d", min(j + 1, width - j));
        }

        printf("\n");
    }
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}
