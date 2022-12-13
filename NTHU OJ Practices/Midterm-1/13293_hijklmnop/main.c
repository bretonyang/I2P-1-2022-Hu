#include <stdio.h>

int main(void)
{
    char str_map[26], int_map[9], str[10], word[5];
    scanf("%s", str);
    scanf("%s", word);

    for (int i = 0; i < 9; i++)
    {
        str_map[str[i] - 'a'] = i + '1';
        int_map[i] = str[i];
    }

    // transform the word
    for (int i = 0; i < 4; i++)
    {
        if (word[i] >= '1' && word[i] <= '9')
        {
            word[i] = int_map[word[i] - '1'];
        }
        else
        {
            word[i] = str_map[word[i] - 'a'];
        }
    }

    printf("%s", word);

    return 0;
}
