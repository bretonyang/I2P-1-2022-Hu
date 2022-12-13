#include <stdio.h>

#define SIZE 10 // But this will work, since it's replaced with 10 in preprocessing

void print_pascal(void);

int main(void)
{
    printf("Printing pascal left -> right, top -> bottom......\n\n");
    print_pascal();

    printf("\n\nPrinting pascal right -> left, top -> bottom......\n\n");

    return 0;
}

void print_pascal(void)
{
    // this will NOT work, since variable sized array can NOT be initialized
    // int SIZE = 10;
    // const int SIZE = 10;
    int a[SIZE][SIZE] = {1};

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }

    // print actual array
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = 0; j < SIZE; j++)
//        {
//            printf("%3d ", a[i][j]);
//        }
//        printf("\n");
//    }
//
//    printf("\n");

    // print pascal
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}
