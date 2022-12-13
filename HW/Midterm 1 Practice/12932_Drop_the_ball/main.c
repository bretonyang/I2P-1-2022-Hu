#include <stdio.h>

int main(void)
{
    int n, m, q;
    char board[501][501];

    // Read input
    scanf("%d %d", &n, &m);
    getchar(); // read and discard '\n'
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &board[i][j]);
        }
        getchar(); // read and discard '\n'
    }

    // Read queries
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int start_col;
        scanf("%d", &start_col);

        // SOLVE
        int row = 1;
        int col = start_col;
        int is_stuck = 0;

        // Drop the ball
        while (row <= n) {
            // drop the ball for one layer
            if (board[row][col] == '\\') {
                if (col + 1 > m) {
                    // falls outside
                    col++;
                    break;
                }
                else if (board[row][col + 1] == '/') {
                    // layer: "\/"
                    is_stuck = 1;
                    break;
                }
                else {
                    // layer: "\\"
                    row++;
                    col++;
                }
            }
            else {
                if (col - 1 < 1) {
                    // falls outside
                    col--;
                    break;
                }
                else if (board[row][col - 1] == '\\') {
                    // layer: "\/
                    is_stuck = 1;
                    break;
                }
                else {
                    // layer: "//"
                    row++;
                    col--;
                }
            }
        }

        // Output
        if (col > m) {
            printf("Right!\n");
        }
        else if (col < 1) {
            printf("Left!\n");
        }
        else if (is_stuck) {
            printf("Stuck QQ\n");
        }
        else {
            printf("Position: %d\n", col);
        }
    }

    return 0;
}

