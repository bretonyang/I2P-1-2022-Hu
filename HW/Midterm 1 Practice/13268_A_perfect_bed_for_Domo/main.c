#include <stdio.h>

int main(void)
{
    int N, L;
    int a[1000];

    // Read input
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    // Solve
    int has_perfect_bed = 0;

    for (int i = 0; i <= N - L; i++) {
        int is_perfect = 1;
        int left = a[i];
        int right = a[i + L - 1];

        for (int j = i + 1; j < i + L - 1; j++) {
            if (a[j] <= left || a[j] <= right) {
                is_perfect = 0;
                break;
            }
        }

        if (is_perfect) {
            has_perfect_bed = 1;
            for (int j = i; j < i + L; j++) {
                printf("%d", a[j]);
                printf("%c", (j < i + L - 1) ? ' ' : '\n');
            }
        }
    }

    if (!has_perfect_bed) {
        printf("Domo\n");
    }

    return 0;
}
