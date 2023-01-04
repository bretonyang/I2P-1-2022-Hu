/* Fina a way out for Domo */
#include <stdio.h>
#include <stdlib.h>

int N_rows, M_cols, K_ops;
int answer = 0;
char domos_key[105][105];
char target_key[105][105];

int dr[4] = {-1, -1, 1, 1};
int dc[4] = {-1, 1, -1, 1};

int valid(int row, int col) {
    return row >= 0 && row < N_rows && col >= 0 && col < M_cols;
}

void dfs(int row, int col, int ops) {
    // basis case
    if (ops == K_ops) {
        for (int i = 0; i < N_rows; i++) {
            for (int j = 0; j < M_cols; j++) {
                if (domos_key[i][j] != target_key[i][j])
                    return;
            }
        }

        // possible
        answer++;
        return;
    }

    // recursive case
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (valid(nr, nc)) {
            // swap
            domos_key[row][col] = domos_key[nr][nc];
            domos_key[nr][nc] = 'x';

            // search
            dfs(nr, nc, ops + 1);

            // undo swap
            domos_key[nr][nc] = domos_key[row][col];
            domos_key[row][col] = 'x';
        }
    }
}

int main(void) {
    int row, col;

    // Read input
    scanf("%d%d%d", &N_rows, &M_cols, &K_ops);
    for (int i = 0; i < N_rows; i++) {
        for (int j = 0; j < M_cols; j++) {
            scanf(" %c", &domos_key[i][j]);
            if (domos_key[i][j] == 'x') {
                row = i, col = j;
            }
        }
    }
    for (int i = 0; i < N_rows; i++) {
        for (int j = 0; j < M_cols; j++) {
            scanf(" %c", &target_key[i][j]);
        }
    }

    // search
    dfs(row, col, 0);

    printf("%d\n", answer);

    return 0;
}
