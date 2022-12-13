#include <stdio.h>
#include <string.h>

int count = 0;

int is_palindrome(int start, int len, char *str)
{
    for (int i = start, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

void partition(int start, int len, char *str)
{
    if (start >= len - 1) {
        count++;
        return;
    }
    else {
        for (int i = start + 1; i <= len; i++) {
            if (is_palindrome(start, i, str)) {
                partition(i, len, str);
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        char str[42];
        scanf("%s", str);

        count = 0;
        partition(0, strlen(str), str);

        printf("%d\n", count);
    }

    return 0;
}
