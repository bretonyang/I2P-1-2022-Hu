#include <stdio.h>

int used[6] = {0};
char str[6] = {0};

void permute(int cnt, int n)
{
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            printf("%c ", str[i]);
        }
        putchar('\n');
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            str[cnt] = 'a' + i;

            permute(cnt + 1, n);

            used[i] = 0;
        }
    }
}

int main(void)
{
    char ch;
    scanf("%c", &ch);

    permute(0, ch - 'a' + 1);

    return 0;
}
