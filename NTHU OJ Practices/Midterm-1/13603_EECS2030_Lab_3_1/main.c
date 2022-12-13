#include <stdio.h>

int main(void)
{
    int i, j;
    int n;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // print space
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // print numbers
        for (j = 0; j < i; j++) {
            printf("%d ", i + 1);
        }

        // print last number of a row
        printf("%d\n", i + 1);
    }

    return 0;
}

// 6

/*

      1
     2 2
    3 3 3
   4 4 4 4
  5 5 5 5 5
 6 6 6 6 6 6
7 7 7 7 7 7 7

       1
      2 2
     3 3 3
    4 4 4 4
   5 5 5 5 5
  6 6 6 6 6 6
 7 7 7 7 7 7 7
8 8 8 8 8 8 8 8

*/
