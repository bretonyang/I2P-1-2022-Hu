#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

char **split_(char* str, char* pattern, int* split_num) {
    char** arr_of_strings = NULL; // initialize to NULL
    char* ptr_to_substr = str; // pointer to the substring we'd like to store
    char* ptr_to_pattern; // pointer to each occurence of pattern
    int size = 0;
    int substr_len;
    int pattern_len = strlen(pattern);

    // strstr() returns a pointer to the start of the pattern in the string.
    ptr_to_pattern = strstr(ptr_to_substr, pattern);

    while (ptr_to_pattern != NULL) {
        if (ptr_to_pattern <= ptr_to_substr) {
            // when multiple patterns are next to each other
            ptr_to_substr = ptr_to_pattern + pattern_len;
            ptr_to_pattern = strstr(ptr_to_substr, pattern);
            continue;
        }

        size++;
        substr_len = ptr_to_pattern - ptr_to_substr;

        arr_of_strings = (char**)realloc(arr_of_strings, sizeof(char*) * size);
        arr_of_strings[size - 1] = (char*)malloc(sizeof(char) * (substr_len + 1));

        memcpy(arr_of_strings[size - 1], ptr_to_substr, sizeof(char) * substr_len);
        arr_of_strings[size - 1][substr_len] = '\0';

        ptr_to_substr = ptr_to_pattern + pattern_len;
        ptr_to_pattern = strstr(ptr_to_substr, pattern);
    }

    // Why need the following if condition?
    // eg1: aa2a2aaa
    // eg2: aa2a2aaa22

    // Check if there is any character in the remaining string
    if (*ptr_to_substr != '\0') {
        // Record the last substring if there are still characters
        size++;
        substr_len = strlen(ptr_to_substr);

        arr_of_strings = (char**)realloc(arr_of_strings, sizeof(char*) * size);
        arr_of_strings[size - 1] = (char*)malloc(sizeof(char) * (substr_len + 1));

        memcpy(arr_of_strings[size - 1], ptr_to_substr, sizeof(char) * substr_len);
        arr_of_strings[size - 1][substr_len] = '\0';
    }

    // return and store information
    *split_num = size;
    return arr_of_strings;
}

void free_(char **result, int split_num) {
    for (int i = 0; i < split_num; i++) {
        free(result[i]);
    }
    free(result);
}

