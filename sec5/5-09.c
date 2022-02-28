#include <stdio.h>
#define YEARDAY 365

int  day_of_year(int, int, int);
void month_day(int, int, int *, int *);

static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(void)
{
	int month;
	int day;

	month_day(2000, 70, &month, &day);
	printf("%d\n", day_of_year(2000, 3, 10));
	printf("%dm%dd\n", month, day);

	return 0;
}

int day_of_year(int year, int month, int day)
{
	int leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
	{
		printf("error: invalid\n");
		return -1;
	}
	while (month >= 1)
	{
		day += *(*(daytab + leap) + (--month));
	}

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pda)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (yearday < 1 || yearday > YEARDAY + leap)
	{
		printf("error: invalid\n");
		return;
	}
	for (i = 1; yearday > *(*(daytab + leap) + i); i++)
	{
		yearday -= *(*(daytab + leap) + i);
	}
	*pmonth = i;
	*pda = yearday;
}
