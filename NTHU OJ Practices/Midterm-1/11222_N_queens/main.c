#include <stdio.h>

void place_queen(int row);
int valid(int row, int col);

int N;
int counter = 0;
int queen_pos[10]; // queen's position at each row

int main(void)
{
    scanf("%d", &N);

    place_queen(0);

    printf("%d", counter);

    return 0;
}

/**
 * Place the queen on the board by iterating through each
 * col in the current row, and test whether each position
 * is possible by recursively placing the queen in the
 * next row.
 */
void place_queen(int row)
{
    // Basis Step: If row reaches outside of the board,
    // then that means we've successfully placed N queens.
    if (row == N) {
        counter++;
        return;
    }

    // Recursive Step: Check whether we can place queen at
    // each col in current row. If we can, then we try to
    // place the queen in the next row.
    for (int col = 0; col < N; col++) {
        if (valid(row, col)) {
            queen_pos[row] = col;
            place_queen(row + 1);
        }
    }
}

int valid(int row, int col)
{
    // check upward and diagonal direction. (no need to check left side)
    for (int i = 0; i < row; i++) {
        int pos = queen_pos[i];
        if (pos == col || pos == col - (row - i) || pos == col + (row - i)) {
            return 0;
        }
    }
    return 1;
}
