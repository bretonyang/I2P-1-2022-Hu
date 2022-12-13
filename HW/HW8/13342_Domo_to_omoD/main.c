#include <stdio.h>
#include <ctype.h>
#include <string.h>

char expression[1000];
char result[500];

int idx = 0;

void get_prefix_operand(void)
{
    int curIdx = idx; // record current index

    if (isdigit(expression[curIdx])) {
        sprintf(result + strlen(result), "%c", expression[curIdx]);
        return;
    } else {
        idx += 2; // skip space
        get_prefix_operand();
        idx += 2; // skip space
        get_prefix_operand();

        sprintf(result + strlen(result), "%c", expression[curIdx]);
    }
}

int main()
{
    gets(expression); // get whole line without trailing '\n'

    get_prefix_operand();

    for (int i = 0, n = strlen(result); i < n; i++) {
        printf("%c%s", result[i], (i < n - 1) ? " " : "");
    }

    return 0;
}
