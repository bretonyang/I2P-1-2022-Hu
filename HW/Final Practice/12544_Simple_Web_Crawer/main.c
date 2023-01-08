#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1500]; // at most 1000 chars per line
    char delim[] = "<>";
    char* token;
    int numOfLinks = 0;

    while (fgets(str, 1500, stdin) != NULL) {
        // split each line
        token = strtok(str, delim);
        while (token != NULL) {
            // <title>
            if (strcmp(token, "title") == 0) {
                token = strtok(NULL, delim);
                printf("%s\n", token);
            }
            // </a>
            else if (strcmp(token, "/a") == 0) {
                numOfLinks++;
            }

            token = strtok(NULL, delim);
        }
    }

    printf("%d\n", numOfLinks);

    return 0;
}

