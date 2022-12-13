#include <stdio.h>

int garden[10][10];
int stars[10]; // stars' positions in each row
int n;
long long max = (long long) -1e10;
int no_solution = 1;

/* Each row and col can have only 1 star, and none can be in diagonal. */
void place(int row, long long points)
{
    if (row == n) {
        if (points > max) {
            max = points;
        }
        no_solution = 0;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (valid(row, col)) {
            stars[row] = col;
            place(row + 1, points + garden[row][col]);
        }
    }
}

int valid(int row, int col)
{
    for (int i = 0; i < row; i++) {
        int pos = stars[i];
        if (pos == col - (row - i) || pos == col || pos == col + (row - i)) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &garden[i][j]);
        }
    }

    // Similar to the N queens problem.
    place(0, 0);

    if (no_solution) {
        printf("no solution\n");
    }
    else {
        printf("%lld\n", max);
    }

    return 0;
}
