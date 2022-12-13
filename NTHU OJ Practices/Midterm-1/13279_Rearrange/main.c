#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int i, a, b;
    int n, m;
    scanf("%d %d", &n, &m);

    int seat[n], student[n];
    for (i = 0; i < n; i++)
    {
        seat[i] = i; // student number for ith seat
        student[i] = i; // seat number for ith student
    }

    // solve
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        swap(&student[seat[a]], &student[seat[b]]);
        swap(&seat[a], &seat[b]);
    }

    // display
    for (i = 0; i < n - 1; i++)
    {
        printf("%d ", student[i] + 1);
    }
    printf("%d\n", student[i] + 1);

    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
