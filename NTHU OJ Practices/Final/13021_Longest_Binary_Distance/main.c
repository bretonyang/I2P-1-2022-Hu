#include <stdio.h>
#include <stdlib.h>

int main()
{
    int q;
    long long n;
    scanf("%d", &q);
    while (q--) {
        scanf("%lld", &n);

        // solve
        int max = -1;
        int cnt = -1;

        // find all other 1s
        while (n != 0) {
            if (n & 1) {
                if (cnt > max) {
                    max = cnt;
                }
                cnt = 0;
            }
            else {
                // do not record if first 1 is not found yet
                if (cnt != -1) {
                    cnt++;
                }
            }

            n = n >> 1;
        }

        printf("%d\n", max);
    }

    return 0;
}
