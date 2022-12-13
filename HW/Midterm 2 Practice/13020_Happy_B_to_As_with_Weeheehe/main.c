#include <stdio.h>

int N, K;
char Ai[100005][3][3];
char B[3][3];
short Ai_x_pos[100005][2];

// Stores the history of [hash_value of matrix][operations already made]
// 1 means possible, -1 means impossiblse, 0 means undefined yet
int history[20000][15] = {0}; // 3^9 ~ 20000,

int ans = 0;
int cur_Ai = 0;
int found = 0;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

/* example:
    0 1 2
    0 3 6
    0 1 2 4 5 7 8
    0 3 6 12 15 21 24
*/
int hash() {
    // hash the current matrix
    int value = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            value = value * 3 + (Ai[cur_Ai][i][j] == 'x' ? 2 : Ai[cur_Ai][i][j] - '0');
        }
    }
    return value;
}

int valid(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3;
}

void exchange(int row, int col, int operations) {

    // get hash value of the current matrix form and operations number
    int hash_value = hash();

    if (history[hash_value][operations] == 1) {
        // if matrix form with the same operations have been found success
        found = 1;
        ans++;
        return;
    }

    if (history[hash_value][operations] == -1 || operations > K) {
        return;
    }

    // Check whether A equals B
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
        ans++;
        found = 1;
        history[hash_value][operations] = 1;
        return;
    }


    /// PROBLEM: Why don't we exclude the case i == prev_direction
    // Exchange
    for (int i = 0; i < 4; i++) {
        if (valid(row + dr[i], col + dc[i])) {
            int next_r = row + dr[i];
            int next_c = col + dc[i];

            // exchange
            Ai[cur_Ai][row][col] = Ai[cur_Ai][next_r][next_c];
            Ai[cur_Ai][next_r][next_c] = 'x';

            exchange(next_r, next_c, operations + 1);

            // Unmake exchange
            Ai[cur_Ai][next_r][next_c] = Ai[cur_Ai][row][col];
            Ai[cur_Ai][row][col] = 'x';

            if (found) {
                history[hash_value][operations] = 1;
                return;
            }
        }
    }

    // After all exchanges, still not found
    history[hash_value][operations] = -1;
}

int main() {
//    freopen("input.txt", "r", stdin);

    scanf("%d %d", &N, &K);

    // Read Ai for i in 0~N-1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            getchar();
            for (int k = 0; k < 3; k++) {
                scanf("%c", &Ai[i][j][k]);
                if (Ai[i][j][k] == 'x') {
                    Ai_x_pos[i][0] = j;
                    Ai_x_pos[i][1] = k;
                }
            }
        }
    }

    // Read B
    for (int j = 0; j < 3; j++) {
        getchar();
        for (int k = 0; k < 3; k++) {
            scanf("%c", &B[j][k]);
        }
    }

    // SOLVE:
    for (int i = 0; i < N; i++) {

        // Set up not found
        found = 0;

        // Exchange
        exchange(Ai_x_pos[i][0], Ai_x_pos[i][1], 0);

        // Update cur_Ai index
        cur_Ai++;
    }

    printf("%d\n", ans);

    return 0;
}











//#include <stdio.h>
//
//int N, K;
//char Ai[100005][3][3]; // 0.9MB
//char B[3][3];
//short Ai_x_pos[100005][2]; // 0.4MB
//
//// Stores the history of [hash_value of matrix][operations already made]
//// 1 means possible, -1 means impossiblse, 0 means undefined yet
//
//int ans = 0;
//int cur_Ai = 0;
//int found = 0;
//
//int dr[4] = {-1, 0, 1, 0};
//int dc[4] = {0, 1, 0, -1};
//
//int valid(int row, int col) {
//    return row >= 0 && row < 3 && col >= 0 && col < 3;
//}
//
//void exchange(int row, int col, int operations, int prev_d) {
//
//    if (found || operations > K) {
//        return;
//    }
//
//    // Check whether A equals B
//    int A_equals_B = 1;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            if (Ai[cur_Ai][i][j] != B[i][j]) {
//                A_equals_B = 0;
//                break;
//            }
//        }
//        if (!A_equals_B) break;
//    }
//    if (A_equals_B) {
//        ans++;
//        found = 1;
//        return;
//    }
//
//    // Exchange
//    for (int i = 0; i < 4; i++) {
//        if (i != prev_d && valid(row + dr[i], col + dc[i])) {
//            int next_r = row + dr[i];
//            int next_c = col + dc[i];
//
//            // exchange
//            Ai[cur_Ai][row][col] = Ai[cur_Ai][next_r][next_c];
//            Ai[cur_Ai][next_r][next_c] = 'x';
//
//            exchange(next_r, next_c, operations + 1, (i + 2) % 4);
//
//            // Unmake exchange
//            Ai[cur_Ai][next_r][next_c] = Ai[cur_Ai][row][col];
//            Ai[cur_Ai][row][col] = 'x';
//        }
//    }
//}
//
//int main() {
//    freopen("input2.txt", "r", stdin);
//
//    scanf("%d %d", &N, &K);
//
//    // Read Ai for i in 0~N-1
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < 3; j++) {
//            getchar();
//            for (int k = 0; k < 3; k++) {
//                scanf("%c", &Ai[i][j][k]);
//                if (Ai[i][j][k] == 'x') {
//                    Ai_x_pos[i][0] = j;
//                    Ai_x_pos[i][1] = k;
//                }
//            }
//        }
//    }
//
//    // Read B
//    for (int j = 0; j < 3; j++) {
//        getchar();
//        for (int k = 0; k < 3; k++) {
//            scanf("%c", &B[j][k]);
//        }
//    }
//
//    // SOLVE:
//    for (int i = 0; i < N; i++) {
//
//        // Set up not found
//        found = 0;
//
//        // Exchange
//        exchange(Ai_x_pos[i][0], Ai_x_pos[i][1], 0, -1);
//
//        // Update cur_Ai index
//        cur_Ai++;
//    }
//
//    printf("%d\n", ans);
//
//    return 0;
//}
//
//
