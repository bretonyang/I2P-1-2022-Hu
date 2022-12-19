#include <stdio.h>

char arr_of_bin[20][1000000]; // ~20MB (might want to try malloc)
int len = 1;

void fill_arr(int N) {
    // S_0
    arr_of_bin[0][0] = '0';

    // Fill binary strings from S_1 to S_N
    for (int i = 1; i <= N; i++) {
        int idx = 0;

        // S_i-1
        for (int prev_idx = 0; prev_idx < len; prev_idx++) {
            arr_of_bin[i][idx] = arr_of_bin[i - 1][prev_idx];
            idx++;
        }

        // '1'
        arr_of_bin[i][idx] = '1';
        idx++;

        // reverse(invernt(S_i-1))
        for (int prev_idx = len - 1; prev_idx >= 0; prev_idx--) {
            char prev_ch = arr_of_bin[i - 1][prev_idx];
            arr_of_bin[i][idx] = (prev_ch == '1') ? '0' : '1';
            idx++;
        }

        // Update length
        len = 2 * len + 1;
    }
}

int main() {

    int index, N, T;
    scanf("%d %d", &N, &T);

    fill_arr(N);

    while (T--) {
        scanf("%d", &index);

        printf("%c\n", arr_of_bin[N][index]);
    }

    return 0;
}
