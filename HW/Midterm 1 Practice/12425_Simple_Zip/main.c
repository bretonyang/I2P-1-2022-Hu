#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LEN 1000

int calc_len(int n)
{
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int main(void)
{
    char str[LEN];

    while (scanf("%s", str) != EOF) {
        int str_len = strlen(str);
        int zip_len = 0;

        for (int i = 0; i < str_len; ) {
            char data = str[i];
            int count = 0;

            for (; str[i] == data; i++) count++;

            if (isalpha(data)) {
                printf("%d%c", count, data);
                zip_len += calc_len(count) + 1;
            }
            else if (isdigit(data)) {
                printf("%d'%c'", count, data);
                zip_len += calc_len(count) + 3;
            }
        }
        printf("\n");

        float compression_rate = (float)zip_len / (float)str_len;

        if (zip_len < str_len) {
            printf("compress rate:%6.3f\n", compression_rate);
        }
        else {
            printf("the string can't zip\n");
        }
    }

    return 0;
}


