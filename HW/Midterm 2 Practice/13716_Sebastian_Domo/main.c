#include <stdio.h>

typedef struct {
    int row;
    int col;
    int time;
} Competitor;

int N, M;
char grid[22][22]; // NxM

int Q; // number of competitors
Competitor competitors[3];
Competitor domo;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};


void dfs(int row, int col, int time, Competitor *player) {

    if (grid[row][col] == '-') { // finish line
        // If not recorded yet or less time
        if (player->time == -1 || time < player->time) {
            player->time = time;
        }
        return;
    }
    else if (grid[row][col] == 'X') { // wall
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i]; // next row
        int nc = col + dc[i]; // next col
        if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
            grid[row][col] = 'X'; // block
            dfs(nr, nc, time + 1, player);
            grid[row][col] = '.';
        }
    }

}


int main()
{
    // Read inputs
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < M; j++) {
            scanf("%c", &grid[i][j]);
        }
    }
    scanf("%d %d", &domo.row, &domo.col);
    domo.time = -1;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &competitors[i].row, &competitors[i].col);
        competitors[i].time = -1;
    }

    // SOLVE:

    // Find each player's minimum time to finish race
    dfs(domo.row, domo.col, 0, &domo);
    for (int i = 0; i < Q; i++) {
        dfs(competitors[i].row, competitors[i].col, 0, &competitors[i]);
    }

    // Find the fastest competitor's time
    int min = -1;
    for (int i = 0; i < Q; i++) {
        if (min == -1 || competitors[i].time < min) {
            min = competitors[i].time;
        }
    }

    // Print output
    printf("%d", domo.time);
    for (int i = 0; i < Q; i++) {
        printf(" %d", competitors[i].time);
    }
    printf("\n%d\n", min - domo.time);

    return 0;
}
