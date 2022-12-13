#include <stdio.h>
#include <stdlib.h>

int k;
int boxSizes[20];
int numOfWays = 0;

void pack_nuggets(int boxNum, int remaining)
{
    if (remaining == 0) { // success
        numOfWays++;
        return;
    } else if (boxNum < 0) { // fail
        return;
    }

    for (int i = remaining / boxSizes[boxNum]; i >= 0; i--) {
        pack_nuggets(boxNum - 1, remaining - i * boxSizes[boxNum]);
    }
}

int main()
{
    int n;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &boxSizes[i]);
    }

    pack_nuggets(k - 1, n);

    printf("%d\n", numOfWays);

    return 0;
}
