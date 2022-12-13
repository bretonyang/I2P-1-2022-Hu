#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int my_rand(void);

int main()
{
    my_srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", my_rand() % 6 + 1);
    }

    return 0;
}
