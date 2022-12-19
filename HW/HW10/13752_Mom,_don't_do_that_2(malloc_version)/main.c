#include <stdio.h>
#include <stdlib.h>

char *arr[21];
int len = 1;

void fill(int N) {
    for (int idx = 1; idx <= N; idx++) {
        // malloc
        arr[idx] = (char*)malloc(sizeof(char) * (2 * len + 1));
        int i = 0;

        // S_i-1
        for (; i < len; i++) {
            arr[idx][i] = arr[idx - 1][i];
        }

        // '1'
        arr[idx][i] = '1';
        i++;

        // reverse(inverse(S_i-1))
        for (int j = len - 1; j >= 0; j--) {
            arr[idx][i] = (arr[idx - 1][j] == '1' ? '0' : '1');
            i++;
        }

        len = i;
    }
}

int main() {
    int N, T, idx;
    scanf("%d %d", &N, &T);

    arr[0] = (char*)malloc(sizeof(char) * 1);
    arr[0][0] = '0';
    fill(N);
//    printf("\n--------------------\n");
//    for (int i = 0; i < len; i++) {
//        printf("%c ", arr[N][i]);
//    }
//    printf("\n-------------------\n");

    while (T--) {
        scanf("%d", &idx);
        printf("%c\n", arr[N][idx]);
    }

    for (int i = 0; i <= N; i++) {
        free(arr[i]);
    }

    return 0;
}
