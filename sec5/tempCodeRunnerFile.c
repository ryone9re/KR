void month_day(int year, int yearday, int *pmonth, int *pda)
// {
// 	int i, leap;

// 	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
// 	if (yearday < 1 || yearday > YEARDAY + leap)
// 	{
// 		printf("error: invalid\n");
// 		return;
// 	}
// 	while (yearday > daytab[leap])
// 	{
// 		yearday -= daytab[leap];
// 	}
// 	*pmonth = i;
// 	*pda = yearday;
// }
