#include <stdio.h>

#define SIZE 1000

void find_shortest_path(int row, int col, int count);

char farm[SIZE][SIZE];
int length, width;
int min = SIZE * SIZE;

int main(void)
{
    int row_S, col_S;

    // Read input
    scanf("%d %d", &length, &width);

    for (int i = 0; i < length; i++) {
        // discard everything before ' '
        while (getchar() != ' ') continue;

        for (int j = 0; j < width; j++) {
            farm[i][j] = getchar();
            getchar(); // discard the ' ' or '\n' after.

            if (farm[i][j] == 'S') {
                row_S = i;
                col_S = j;
            }
        }
    }

    // find shortest path and record it in min.
    find_shortest_path(row_S, col_S, 0);
    printf("%d\n", min);

    return 0;
}

void find_shortest_path(int row, int col, int count)
{
    // Basis step
    if (farm[row][col] == 'M') {
        if (count < min) {
            min = count;
        }
        return;
    }

    // Recursive step
    farm[row][col] = 'o'; // block our current position

    if (valid(row, col - 1)) {
        // left
        find_shortest_path(row, col - 1, count + 1);
    }
    if (valid(row, col + 1)) {
        // right
        find_shortest_path(row, col + 1, count + 1);
    }
    if (valid(row + 1, col)) {
        // down
        find_shortest_path(row + 1, col, count + 1);
    }
    if (valid(row - 1, col)) {
        // top
        find_shortest_path(row - 1, col, count + 1);
    }

    farm[row][col] = '.'; // unblock our current position
}

int valid(int row, int col)
{
    return row >= 0 && row < length && col >= 0 && col < width &&
        farm[row][col] != 'o' && farm[row][col] != '^';
}
