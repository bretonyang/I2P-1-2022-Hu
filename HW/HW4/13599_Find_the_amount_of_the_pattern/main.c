#include <stdio.h>

int main(void)
{
    // Reading inputs
    int n;
    scanf("%d", &n);

    int b_matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b_matrix[i][j]);
        }
    }

    int m;
    scanf("%d", &m);

    int p_matrix[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &p_matrix[i][j]);
        }
    }

    // Counting amount of pattern
    int cnt = 0;

    for (int b_row = 0; b_row <= n - m; b_row++) {
        for (int b_col = 0; b_col <= n - m; b_col++) {
            // check for pattern at (b_row, b_col)
            int has_pattern = 1;

            for (int p_row = 0; p_row < m; p_row++) {
                for (int p_col = 0; p_col < m; p_col++) {
                    if (p_matrix[p_row][p_col] == 1 && b_matrix[b_row + p_row][b_col + p_col] != 1) {
                        has_pattern = 0;
                        break;
                    }
                }
                if (!has_pattern) break;
            }

            if (has_pattern) {
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}

