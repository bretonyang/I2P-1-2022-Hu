#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[10000];
    char guess[100000];
    int ch; // To store EOF
    int temper;
    int success_letters = 0;
    int guess_idx = 0;
    int name_idx = 0;

    scanf("%s", name);
    scanf("%d", &temper);
    getchar(); // discard extra '\n'

    while ((ch = getchar()) != EOF) {
        if (ch == '/') {
            temper--;

            if (guess_idx <= 0) {
                // Nothing to delete
                continue;
            }
            else if (guess_idx == name_idx && guess[guess_idx - 1] == name[name_idx - 1]) {
                // delete a success letter
                success_letters--;
                name_idx--;
                guess_idx--;
            }
            else {
                // delete a wrong letter
                guess_idx--;
            }
        }
        else if (ch == '!') {
            temper -= 2;

            success_letters = 0;
            guess_idx = 0;
            name_idx = 0;
        }
        else if (ch == name[name_idx] && guess_idx == name_idx) {
            // correct guess (so far)
            guess[guess_idx] = ch;

            success_letters++;
            guess_idx++;
            name_idx++;
            printf("%d\n", success_letters);
        }
        else {
            // wrong guess
            guess[guess_idx] = ch;
            guess_idx++;
            printf("no\n");
        }

        if (success_letters == strlen(name) && temper > 0) {
            printf("DAISUKI!\n");
            break;
        }
        else if (temper <= 0) {
            printf("SAYONARA\n");
            break;
        }
    }

    return 0;
}


/*

Read 1 char at a time. (ch)
keep track of the number of letters correctly answered so far.

ch cases:

If ch == '/':
        delete last letter guessed
        temper = temper - 1

If ch == '!':
        restart
        temper = temper - 1

If ch != correct char
        print("no") until ch == correct char.

If ch == correct char
        fd

If:
1. name correct && temper > 0
   --> print("DAISUKI!")

2. Otherwise
   --> print("SAYONARA")

*/



/*
Special cases:

input:
RUSHIA
3
RUSHISA

expected output:
1
2
3
4
5
no
no


input:
RUSHIA
3
RUSS/HIA

expected output:
1
2
3
no
4
5
6
DAISUKI

*/


