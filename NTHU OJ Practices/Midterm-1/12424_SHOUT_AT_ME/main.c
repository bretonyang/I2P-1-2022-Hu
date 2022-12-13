#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 101

int main(void)
{
    char str[LEN];
    scanf("%s", str);

    // CONVERTING
    for (int i = 0, n = strlen(str); i < n; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }

    printf("%s\n", str);

    return 0;
}
