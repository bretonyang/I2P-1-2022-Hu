#include <stdio.h>

int is_invalid(int mon, int day);
int calc_days(int mon, int day);

int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
    int month, day;
    scanf("%d/%d", &month, &day);

    // SOLVE
    if (is_invalid(month, day)) {
        printf("Input Error\n");
    }
    else {
        int days = calc_days(month, day);

        if (days == 1) {
            printf("There is 1 day\n");
        }
        else {
            printf("There are %d days\n", days);
        }
    }

    return 0;
}

int is_invalid(int mon, int day)
{
    if (day > days_in_month[mon - 1] || day < 1) {
        return 1;
    }
    return 0;
}

int calc_days(int mon, int day)
{
    int day_sum = 0;
    for (int i = 0; i < mon - 1; i++) {
        day_sum += days_in_month[i];
    }
    day_sum += day;

    return day_sum;

}


