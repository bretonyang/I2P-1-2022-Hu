#include <stdio.h>


int N, K;
char Ai[100000][3][3];
char B[3][3];

int Ai_x_pos[100000][2];
int cur_Ai = 0;

int ans = 0;
int possible_Ai = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int history[20000][15] = {0};


void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}


int hash() {
    int value = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char ch = Ai[cur_Ai][i][j];
            value = value * 3 + (ch == 'x' ? 2 : ch - '0');
        }
    }
    return value;
}


void exchange(int row, int col, int operations) {

    int hash_value = hash();

    if (history[hash_value][operations] == 1) {
        // will success
        possible_Ai = 1;
        ans++;
        return;
    }
    else if (operations > K || history[hash_value][operations] == -1 || possible_Ai) {
        // return to try other options
        return;
    }

    // Check whether Ai == B
    int A_equals_B = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Ai[cur_Ai][i][j] != B[i][j]) {
                A_equals_B = 0;
                break;
            }
        }
        if (!A_equals_B) break;
    }
    if (A_equals_B) {
        possible_Ai = 1;
        ans++;
        history[hash_value][operations] = 1;
        return;
    }

    // Exchange with adjacent
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {

            // Exchange
            swap(&Ai[cur_Ai][row][col], &Ai[cur_Ai][nr][nc]);

            exchange(nr, nc, operations + 1);

            // Un-exchange
            swap(&Ai[cur_Ai][row][col], &Ai[cur_Ai][nr][nc]);

            if (possible_Ai) {
                history[hash_value][operations] = 1;
                return;
            }

        }
    }

    // all directions fail
    history[hash_value][operations] = -1;

}


int main() {

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scanf(" %c", &Ai[i][j][k]);
                if (Ai[i][j][k] == 'x') {
                    Ai_x_pos[i][0] = j;
                    Ai_x_pos[i][1] = k;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf(" %c", &B[i][j]);
        }
    }

    // SOLVE:
    for (int i = 0; i < N; i++) {

        // initialize
        possible_Ai = 0;

        exchange(Ai_x_pos[i][0], Ai_x_pos[i][1], 0);

        cur_Ai++;

    }

    printf("%d\n", ans);

    return 0;
}

