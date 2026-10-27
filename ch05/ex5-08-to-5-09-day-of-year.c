#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday,int *pmonth, int *pday);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()  {

    int x = day_of_year(2010, 3, 14);
    printf("DayOfYear conversion: %d\n", x);

    int month, day;
    month_day(2008, 10, &month, &day);
    printf("MonthDay conversion, month: %d, day: %d\n", month, day);

return 0;
}

int day_of_year(int year, int month, int day) {

    int i, leap;
    leap = year%4 == 0 && year%100 != 0||year%400 == 0;
    char *p = daytab[leap];

    if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= *(p+month)) {
        for (p = daytab[leap], i = 1; i < month; i++)
            day += *(p+i);
        return day;
    } else
        return -1;
}

    int month_day(int year, int yearday,int *pmonth, int *pday) {

        int i, leap, maxday;
        leap = year%4 == 0 && year%100 != 0||year%400 == 0;
        char *p = daytab[leap];

        if (leap == 1)
            maxday = 366;
        else
            maxday = 365;

        if (year >= 0 && yearday >= 1 && yearday <= maxday) {
            for (p = daytab[leap], i = 1; yearday > *(p+i); i++)
                yearday -= *(p+i);
        *pmonth = i;
        *pday = yearday;
        return 0;
        } else {
            return -1;
        }
    }

// Exercise 5-8: There is no error checking in day_of_year or month_day. Remedy this defect.
// Exercise 5-9: Rewrite the routines day_of_year and month_day with pointers instead of indexing.
