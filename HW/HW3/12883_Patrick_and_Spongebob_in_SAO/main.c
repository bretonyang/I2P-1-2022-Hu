#include <stdio.h>

#define NUM_DISHES 500

int most_ordered(int ordered_dishes[], int start, int end);
int idx_of_max(int arr[], int size);

int main(void)
{
    int i, n, q, l, r;

    // Read inputs
    scanf("%d", &n);
    int a[n];

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &q);
    int ans[q];

    for (i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        ans[i] = most_ordered(a, l - 1, r - 1);
    }

    // print answer
    for (i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}


int most_ordered(int ordered_dishes[], int start, int end)
{
    // array to count vote
    int occurence_of_dishes[NUM_DISHES] = {0};

    // Vote for their dish number
    for (int i = start; i <= end; i++) {
        occurence_of_dishes[ordered_dishes[i] - 1]++;
    }

    // NOTE: dish number = 1 + index_of_max_occurence
    return 1 + idx_of_max(occurence_of_dishes, NUM_DISHES);
}

/**
 * Returns the index of the first appearance of the max num in arr[].
 * (since the first index is also the smallest)
 */
int idx_of_max(int arr[], int size)
{
    int max = arr[0];
    int idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            idx = i;
        }
    }

    return idx;
}
