#include <stdio.h>

int show_parentheses(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("=%d\n", show_parentheses(n));

    return 0;
}

int show_parentheses(int n)
{
    int prev_ans;
    if (n > 1) {
        // Recursive step:
        if (n % 2 == 1) {
            printf("(");
            prev_ans = show_parentheses(n - 1);
            printf(")*%d", n);
            return prev_ans * n;
        }
        else {
            prev_ans = show_parentheses(n - 1);
            printf("+%d", n);
            return prev_ans + n;
        }
    }
    else {
        // Basis step:
        printf("1");
        return 1;
    }
}
