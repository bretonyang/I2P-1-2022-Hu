#include <stdio.h>

int main(void)
{
    int h;
    scanf("%d", &h);

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= h - i; j++)    printf(" ");
        for (int j = 1; j <= i; j++)    printf("%d", j);
        for (int j = i - 1; j > 0; j--)    printf("%d", j);
        printf("\n");
    }

    for (int i = h - 1; i >= 1; i--) {
        for (int j = 1; j <= h - i; j++)    printf(" ");
        for (int j = 1; j <= i; j++)    printf("%d", j);
        for (int j = i - 1; j > 0; j--)    printf("%d", j);
        printf("\n");
    }

    return 0;
}

