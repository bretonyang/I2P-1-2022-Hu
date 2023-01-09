#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[1005];
    char* token;
    int numOfLinks = 0;

    while (gets(line) != NULL) {
        token = strtok(line, "<");
        while (token != NULL) {
            // <title>
            if (token[0] == 't') {
                printf("%s\n", token + 6);
            }
            else if (token[0] == 'a') {
                numOfLinks++;
            }

            token = strtok(NULL, "<");
        }
    }

    printf("%d\n", numOfLinks);

    return 0;
}
