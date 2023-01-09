#include <stdio.h>
#include <stdlib.h>

int arr[1000005]; // 4,000,000
int appeared[1000005]; // 4,000,000

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // solve
    /* [Idea]: Use a sliding window of length K */

    int numOfUnique = 0;
    int answer = 0;

    // First K elements
    for (int i = 0; i < K; i++) {
        if (appeared[arr[i]] == 0) {
            numOfUnique++;
        }
        appeared[arr[i]]++;
    }
    if (numOfUnique == K) {
        answer++;
    }

    // rest of elements, idx: K ~ N - 1
    for (int i = K; i < N; i++) {
        // remove element
        appeared[arr[i - K]]--;
        if (appeared[arr[i - K]] == 0) {
            numOfUnique--;
        }

        // add element
        if (appeared[arr[i]] == 0) {
            numOfUnique++;
        }
        appeared[arr[i]]++;

        if (numOfUnique == K) {
            answer++;
        }
    }

    printf("%d\n", answer);

    return 0;
}

