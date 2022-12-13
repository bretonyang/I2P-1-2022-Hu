#include <stdio.h>

int main()
{
    int D;
    scanf("%d", &D);

    printf("%d%d%d%d\n", (D>>3)%2, (D>>2)%2, (D>>1)%2, D%2);

    return 0;
}
