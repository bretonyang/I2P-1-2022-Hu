#include <stdio.h>
#include <string.h>

#define SIZE_RESULT 10000
#define SIZE_STR 101

int calc_worth(char *str);

int main(void)
{
    int result[SIZE_RESULT];
    char str[SIZE];
    scanf ("%[^\n]%*c", str);

    // Read each line and store its worth into result array
    int i = 0;
    while (strcmp(str, "0") != 0)
    {
        result[i] = calc_worth(str);
        scanf("%[^\n]%*c", str);
        i++;
    }
    result[i] = -1;

    // print result
    for (int i = 0; result[i] != -1; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

int calc_worth(char *str)
{
    // 'a'=1, 'b'=2, ..., 'z'=26, others are 0
    int worth = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            worth += str[i] - 'a' + 1;
        }
    }

    return worth;
}

