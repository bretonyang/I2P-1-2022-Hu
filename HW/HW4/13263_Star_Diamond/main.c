#include <stdio.h>

void print_diamond(int height);
int abs(int a);

int main(void)
{
    int n;
    scanf("%d", &n);

    print_diamond(n);

    return 0;
}

void print_diamond(int height)
{
    if (height % 2 == 0) {
        printf("Stop drawing fake diamonds!\n");
        return;
    }

    for (int i = 0; i < height; i++) {
        int distance_to_mid = abs(i - height / 2);

        // spaces
        for (int j = 0; j < distance_to_mid; j++) {
            printf(" ");
        }

        // stars
        for (int j = 0; j < height - 2 * distance_to_mid; j++) {
            printf("*");
        }

        // new line
        printf("\n");
    }
}

int abs(int a)
{
    return (a < 0) ? -a : a;
}
