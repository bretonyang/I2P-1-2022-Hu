#include <stdio.h>

#define SIZE 1000
#define START 'D'
#define DESTINATION 'S'

void find_path(int row, int col);

char maze[SIZE][SIZE];
int length, width;
int can_escape;

int main(void)
{
    int row_S, col_S, T;

    // Read input
    scanf("%d%d", &length, &width);
    scanf("%d", &T);

    while (T-- > 0) {

        for (int i = 0; i < length; i++) {
            // discard everything before ' '
            while (getchar() != ' ') continue;

            for (int j = 0; j < width; j++) {
                maze[i][j] = getchar();
                getchar(); // discard the ' ' or '\n' after.

                if (maze[i][j] == DESTINATION) {
                    row_S = i;
                    col_S = j;
                }
            }
        }

        // find shortest path and record it in min.
        can_escape = 0;
        find_path(row_S, col_S);

        if (can_escape) {
            printf("ESCAPE!\n");
        }
        else {
            printf("QQ\n");
        }
    }

    return 0;
}

void find_path(int row, int col)
{
    // Basis step
    if (maze[row][col] == START || can_escape) {
        can_escape = 1;
        return;
    }
    else if (maze[row][col] == 'x') {
        return;
    }

    // Recursive step
    maze[row][col] = 'x'; // block our current position

    if (col - 1 >= 0) {
        // left
        find_path(row, col - 1);
    }
    if (col + 1 < width) {
        // right
        find_path(row, col + 1);
    }
    if (row + 1 < length) {
        // down
        find_path(row + 1, col);
    }
    if (row - 1 >= 0) {
        // top
        find_path(row - 1, col);
    }

    /* Do NOT unblock, since if a path didn't lead to destination,
       then it will NOT for other paths too. */

//    maze[row][col] = '.'; // unblock our current position

}
