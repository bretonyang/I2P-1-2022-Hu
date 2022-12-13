#include <stdio.h>
#include <math.h>

int is_special(int n);

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        if (is_special(n))
        {
            printf("Yes it is.\n");
        }
        else
        {
            printf("No it is not.\n");
        }
    }

    return 0;
}

int is_special(int n)
{
    // special number: sum of its digits powered to the # of its digits equals itself.
    int num = n;
    int special_sum = 0;
    int num_digits = 0;

    // count number of digits
    while (num > 0)
    {
        num_digits++;
        num /= 10;
    }

    // sum of digit powered to num_digits
    num = n;
    while (num > 0)
    {
        special_sum += pow(num % 10, num_digits);
        num /= 10;
    }

    if (special_sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
