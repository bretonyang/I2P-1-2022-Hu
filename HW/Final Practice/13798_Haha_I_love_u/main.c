#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

char my_str[3105];
char her_str[3105];

int table[3105][3105]; // 9,000,000 * 4 = 36 MB
//short table[3105][3105]; // 9,000,000 * 2 = 18 MB

// Solution using dp.
// Calculate the length of the longest common subsequence of the two strings.
int LCS_length(int my_str_len, int her_str_len) {

    // fill in the table
    for (int my_len = 0; my_len <= my_str_len; my_len++) {
        for (int her_len = 0; her_len <= her_str_len; her_len++) {
            // if either of the strings are empty, then LCS is 0
            if (my_len == 0 || her_len == 0) {
                table[my_len][her_len] = 0;
            }
            // if the last characters of the substrings match
            else if (my_str[my_len - 1] == her_str[her_len - 1]) {
                table[my_len][her_len] = 1 + table[my_len - 1][her_len - 1];
            }
            // if the characters does NOT match
            else {
                table[my_len][her_len] = MAX(table[my_len - 1][her_len],
                                             table[my_len][her_len - 1]);
            }
        }
    }
    return table[my_str_len][her_str_len];
}

int main() {
    scanf("%s%s", my_str, her_str);

    int answer = LCS_length(strlen(my_str), strlen(her_str));

    printf("%d\n", answer);

    return 0;
}

//// calculate the length of the longest common subsequence of the two strings.
//int LCS_length(int my_str_len, int her_str_len) {
//    if (my_str_len == 0 || her_str_len == 0) {
//        return 0;
//    }
//
//    // if last character is the same
//    if (my_str[my_str_len - 1] == her_str[her_str_len - 1]) {
//        return 1 + LCS_length(my_str_len - 1, her_str_len - 1);
//    }
//
//    // else len of LCS must be maximum of
//    int a = LCS_length(my_str_len - 1, her_str_len);
//    int b = LCS_length(my_str_len, her_str_len - 1);
//    return MAX(a, b);
//}

