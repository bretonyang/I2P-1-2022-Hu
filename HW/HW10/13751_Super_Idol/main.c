#include <stdio.h>

int main()
{
    unsigned int start, end;
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%u %u", &start, &end);

        // If two numbers cross the boundary of 2^n,
        // i.e. start < 2^n < end, this means there is no common 1s
        // exist in all the number. so the real question is to
        // find the left-most common 1s, if any.
        unsigned int result = 0;
        while (start != end) {
            start = start >> 1; // modified destructively
            end = end >> 1; // modified destructively
            result++;
        }

        printf("%u\n", end << result); // NOTE: start is modified
    }

    return 0;
}

/*

 1100101  01000 -> start
 1100101  ...
 1100101  10101 -> end

 1100101  00000 -> answer

 after while loop, `start`: 1100101, `result`: 5
 `start << result`: 1100101 00000

 ------------------------------------------------

 001001011 0.... -> start
 001001011 1.... -> end

*/










