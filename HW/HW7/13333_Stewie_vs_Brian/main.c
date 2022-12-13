#include <stdio.h>

#define SIZE 9

int no_solution = 1;
int sudoku[SIZE][SIZE] = {0};
int row_filled[SIZE][SIZE + 1] = {0}; // record filled numbers
int col_filled[SIZE][SIZE + 1] = {0}; // record filled numbers
int square_filled[SIZE][SIZE + 1] = {0}; // record filled numbers

int valid(int row, int col, int num)
{
    return !row_filled[row][num] && !col_filled[col][num] &&
           !square_filled[(row / 3) * 3 + col / 3][num];
}

void place(int cnt)
{
    if (cnt == SIZE * SIZE) {
        no_solution = 0;
        return;
    }

    int row = cnt / 9;
    int col = cnt % 9;

    if (sudoku[row][col] != 0) {
        place(cnt + 1); // place next number
    } else {
        // fill in valid number
        for (int i = 1; i <= SIZE; i++) {
            if (valid(row, col, i)) {
                // record number
                sudoku[row][col] = i;
                row_filled[row][i] = 1;
                col_filled[col][i] = 1;
                square_filled[(row / 3) * 3 + col / 3][i] = 1;

                // place next number
                place(cnt + 1);

                // return if solution found
                // (note: why are we returning here unlike in N queens problem,
                //  where we did not return? Because here we want to return as
                //  soon as we've found a solution, and in N queens problem we're
                //  asked to count all the solutions.)
                if (!no_solution) return;

                // else unfill the number
                sudoku[row][col] = 0;
                row_filled[row][i] = 0;
                col_filled[col][i] = 0;
                square_filled[(row / 3) * 3 + col / 3][i] = 0;
            }
        }
    }
}

int main(void)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] != 0) {
                row_filled[i][sudoku[i][j]] = 1;
                col_filled[j][sudoku[i][j]] = 1;
                square_filled[(i / 3) * 3 + j / 3][sudoku[i][j]] = 1;
            }
        }
    }

    place(0);

    if (no_solution) {
        printf("no solution\n");
    } else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d", sudoku[i][j]);
                putchar(j < SIZE - 1 ? ' ' : '\n');
            }
        }
    }

    return 0;
}
