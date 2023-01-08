#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K;
    int tmp;
    int answer = 0;
    int arr[30005] = {0}; // 120020

    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        for (int j = K - 1; j >= 0; j--) {
            scanf("%d", &tmp);
            arr[i] += tmp << j;
        }
    }

    int target = (1 << K) - 1;

    // i: 0 ~ N-2
    for (int i = 0; i < N - 1; i++) {
        // j: i+1 ~ N-1
        for (int j = i + 1; j < N; j++) {
            if ((arr[i] | arr[j]) == target) {
                answer++;
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}

/**

K=2:
1 1 = 2^2 - 1 = 3

0 1 = 1
1 0 = 2

0 0 = 0
1 0 = 2

1 1 = 3
0 1 = 2

---------------

K=3:
1 1 1 = 2^3 - 1 = 7

1 0 1
0 1 1
0 0 1

1 0 1 = 5
1 0 1 = 5
1 1 0 = 6

5 || 5 != 7
5 || 6 == 7

*/



