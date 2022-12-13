#include <stdio.h>

int middle[8] = {0,1};
int cumulative[8] = {0,1};
int snowflake[407][407] = {0}; // order 7 size: 407x407

void initialize_size(void)
{
    for(int i = 2; i <= 7; i++) {
        middle[i] = 4 * cumulative[i-2] - middle[i-2] + 2;
        cumulative[i] = cumulative[i-1] + middle[i];
    }

}

int snowflake_size(int order)
{
    return cumulative[order] + cumulative[order - 1];
}

void draw_snowflake(int n, int row, int col)
{
    if (n == 0) {
        return;
    } else if (n == 1) {
        snowflake[row][col] = 1;
        return;
    }

    int mid = middle[n];
    for (int r = row; r < row + mid; r++) {
        for (int c = col; c < col + mid; c++) {
            snowflake[r][c] = 1;
        }
    }

    // corners
    int mid_1 = middle[n - 1];
    draw_snowflake(n - 1, row - mid_1, col - mid_1);
    draw_snowflake(n - 1, row - mid_1, col + mid);
    draw_snowflake(n - 1, row + mid, col - mid_1);
    draw_snowflake(n - 1, row + mid, col + mid);

    // edges
    int mid_2 = middle[n - 2];
    draw_snowflake(n - 2, row - mid_2, col + mid_1);
    draw_snowflake(n - 2, row + mid_1, col - mid_2);
    draw_snowflake(n - 2, row + mid_1, col + mid);
    draw_snowflake(n - 2, row + mid, col + mid_1);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    initialize_size();

    draw_snowflake(n, cumulative[n - 1], cumulative[n - 1]);

    int size = snowflake_size(n);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", (snowflake[i][j] ? '#' : ' '));
        }
        printf("\n");
    }

    return 0;
}
