#include <stdio.h>

int not_overlapping(int a1, int a2, int b1, int b2);
int is_overlapping(int a1, int a2, int b1, int b2);

int main(void)
{
    int n;
    scanf("%d", &n);

    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // SOLVE
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!not_overlapping(intervals[i][0], intervals[i][1], intervals[j][0], intervals[j][1])) {
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}

int not_overlapping(int a1, int a2, int b1, int b2)
{
    return b2 <= a1 || b1 >= a2;
}

int is_overlapping(int a1, int a2, int b1, int b2)
{
    if ((a1 <= b1 && b1 < a2) || (a1 < b2 && b2 <= a2)) {
        return 1;
    }
    else if ((b1 <= a1 && a1 < b2) || (b1 < a2 && a2 <= b2)) {
        return 1;
    }

    return 0;
}
