#include <stdio.h>

void hanoi(int n, char from, char tmp, char to)
{
    if (n == 0) return;

    // move n - 1 disks from "from" to "tmp", use "to" as temp.
    hanoi(n - 1, from, to, tmp);

    // move top disk at "from" to "to"
    printf("move disk %d from rod %c to rod %c\n", n, from, to);

    // move n - 1 disks from "tmp" to "to", use "from" as temp.
    hanoi(n - 1, tmp, from, to);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}
