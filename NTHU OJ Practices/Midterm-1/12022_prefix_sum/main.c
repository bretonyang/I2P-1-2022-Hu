#include <stdio.h>

void fill_prefix_sums(long long int result[], int n, long long int arr[]);

int main(void)
{
    int n;
    scanf("%d", &n);

    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    // Getting prefix sum array
    long long int prefix_sums[n];
    fill_prefix_sums(prefix_sums, n, arr);

    int m;
    scanf("%d", &m);

    long long int ans[m];
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        if (l == 1) {
            ans[i] = prefix_sums[r - 1];
        }
        else {
            ans[i] = prefix_sums[r - 1] - prefix_sums[l - 2];
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}

void fill_prefix_sums(long long int result[], int n, long long int arr[])
{
    result[0] = arr[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + arr[i];
    }
}
