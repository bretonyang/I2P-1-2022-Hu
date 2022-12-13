#include <stdio.h>

int is_invalid(int mon, int day);
int calc_days(int mon, int day);

int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// array [] of strings (i.e. char*)
char *day_in_week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

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

        // -1 because we want days: 0 ~ 6
        // + 4 because we 1/1/2021 is Friday, and Friday correspond to week day 4.
        printf("%s\n", day_in_week[((days - 1) % 7 + 4) % 7]);
    }

    return 0;
}

int is_invalid(int mon, int day)
{
    if (mon > 12 || mon < 1 || day > days_in_month[mon - 1] || day < 1) {
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


