#include <stdio.h>
#include <ctype.h>

int main(void) {
    int length = 5;
    char word[length+1], encrypted[length+1];

    scanf("%s", word);

    for (int i = 0; i < length; i++) {
        encrypted[i] = 'Z' - (toupper(word[i]) - 'A');
    }

    encrypted[length] = '\0';

    printf("%s\n", encrypted);

    return 0;
}


