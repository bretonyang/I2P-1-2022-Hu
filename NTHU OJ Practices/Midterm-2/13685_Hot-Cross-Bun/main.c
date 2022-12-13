#include <stdio.h>

int n, m;
char grid[20][20];

int min = -1;
int dr[5] = {0, -1, 1, 0, 0}; // o, up, down, left, right
int dc[5] = {0, 0, 0, -1, 1};

int valid(int row, int col)
{
    return row >= 0 && col >= 0 && row < n && col < m;
}

void cross(int row, int col, int count)
{
    /* base case */
    if (row == n) {
        // check whether all crossed out
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'o') {
                    return;
                }
            }
        }

        // All crossed out, record count if not recorded yet or count < min
        if (min == -1 || count < min) {
            min = count;
        }
        return;
    }

    /* inductive case */
    int next_row = row;
    int next_col = col + 1;
    if (next_col == m) {
        next_row++;
        next_col = 0;
    }

    // case 1: cross out the current grid[row][col]
    for (int i = 0; i < 5; i++) {
        int t_row = row + dr[i];
        int t_col = col + dc[i];
        if (valid(t_row, t_col) && grid[t_row][t_col] == 'o') {
            grid[t_row][t_col] = 'x';
        } else if (valid(t_row, t_col) && grid[t_row][t_col] == 'x') {
            grid[t_row][t_col] = 'o';
        }
    }

    cross(next_row, next_col, count + 1); // try cross next position

    // unmake the changes
    for (int i = 0; i < 5; i++) {
        int t_row = row + dr[i];
        int t_col = col + dc[i];
        if (valid(t_row, t_col) && grid[t_row][t_col] == 'o') {
            grid[t_row][t_col] = 'x';
        } else if (valid(t_row, t_col) && grid[t_row][t_col] == 'x') {
            grid[t_row][t_col] = 'o';
        }
    }

    // case 2: don't cross out the current grid[row][col]
    cross(next_row, next_col, count); // try cross next position

    /// NOTE: we can interchange the position of case 1&2, the result is the same

}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    cross(0, 0, 0);

    if (min == -1) {
        printf("no solution\n");
    } else {
        printf("%d\n", min);
    }

    return 0;
}
