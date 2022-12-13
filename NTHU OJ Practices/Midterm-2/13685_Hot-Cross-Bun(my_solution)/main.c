#include <stdio.h>

int n, m;
long long min = -1;
int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, -1, 1};

char grid[20][20];

void flip(int row, int col) {
    for (int i = 0; i < 5; i++) {
        int r = row + dr[i];
        int c = col + dc[i];
        if (r >= 0 && r < n && c >= 0 && c < m) {
            grid[r][c] = (grid[r][c] == 'o' ? 'x' : 'o');
        }
    }
}

void cross(int cnt, long long num) {
    if (cnt == n * m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'o') {
                    return;
                }
            }
        }

        // solved
        if (min == -1 || num < min) {
            min = num;
        }
        return;
    }

    /** NOTE: both uses m */
    // Get current row, col
    int row = cnt / m;
    int col = cnt % m;

    // case 1: flip current position, and try cross next pos
    flip(row, col);
    cross(cnt + 1, num + 1);
    flip(row, col); // undo the flip

    // case 2: do NOT flip current position
    cross(cnt + 1, num);
}


int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    // SOLVE
    cross(0, 0);

    if (min == -1) {
        printf("no solution\n");
    }
    else {
        printf("%lld\n", min);
    }

    return 0;
}

