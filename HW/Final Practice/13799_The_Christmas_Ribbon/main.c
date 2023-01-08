#include <stdio.h>
#include <stdlib.h>

int array[1000005]; // 4,000,000
int appeared[1000005]; // whether the number has appeared
int numOfAppeared = 0; // when this == K, then found target subarray

int solve(int N, int K) {
    int answer = 0;

    // setup the first 0~K-1 numbers (K numbers)
    for (int i = 0; i < K; i++) {
        // if has NOT appeared before, then update numOfAppeared
        if (appeared[array[i]] == 0) {
            numOfAppeared++;
        }
        // Record that the number has appeared
        appeared[array[i]]++;
    }
    // Check whether the first 0~K-1 subarray is a target subarray
    if (numOfAppeared == K) {
        answer++;
    }

    // loop through K~N-1 numbers
    for (int i = K; i < N; i++) {
        // Unregister the first element in the K subarray
        appeared[array[i - K]]--;
        if (appeared[array[i - K]] == 0) {
            // numOfAppeared decreases if the removed number
            // is the only appearance of the number
            numOfAppeared--;
        }

        // Add the new element to the K subarray
        // Check if the number has appeared before
        if (appeared[array[i]] == 0) {
            numOfAppeared++;
        }
        appeared[array[i]]++;

        // Check whether the subarray is a target subarray
        if (numOfAppeared == K) {
            answer++;
        }
    }

    return answer;
}

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int answer = solve(N, K);
    printf("%d\n", answer);

    return 0;
}
