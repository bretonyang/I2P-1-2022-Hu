#include <stdio.h>

#define SIZE 1000001

int main(void)
{
    char s[SIZE];
    int Q;
    scanf("%s", s);
    scanf("%d", &Q);

    char A[Q], B[Q];
    int a_to_z[26] = {0};
    for (int i = 0; i < Q; i++) {
        getchar(); // clean the left '\n' from last line
        scanf("%c %c", A+i, B+i);
        a_to_z[A[i] - 'a']++;
    }

    // SOLVE
    for (int i = 0; s[i] != '\0'; i++) {
        int count[26] = {0};
        for (int j = 0; j < Q; j++) {
            if (s[i] == A[j]) {
                s[i] = B[j];
                count[A[j] - 'a']++;
                if (count[B[j] - 'a'] == a_to_z[B[j] - 'a']) {
                    break;
                }
            }
        }
    }

    printf("%s\n", s);

    return 0;
}
