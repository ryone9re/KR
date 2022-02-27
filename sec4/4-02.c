#include <ctype.h>
#include <stdio.h>
#define MAXSIZE 1000

int    mgetline(char line[], int lim);
double atof(char s[]);

int main(void)
{
	char   s[MAXSIZE];
	double d;

	mgetline(s, MAXSIZE);
	d = atof(s);
	printf("%10.15lf\n", d);
	return (0);
}

int mgetline(char line[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;
	}
	if (c == '\n')
	{
		line[i++] = c;
	}
	line[i] = '\0';
	return (i);
}

double atof(char s[])
{
	double val, val2, power, power2;
	int    i, j, sign, esign;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = s[i] == '-' ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
	}
	for (val = 0; isdigit(s[i]); i++)
	{
		val = 10 * val + (s[i] - '0');
	}
	if (s[i] == '.')
	{
		i++;
	}
	for (power = 1; isdigit(s[i]); i++)
	{
		val = 10 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
	}
	if (s[i] == '-')
	{
		esign = -1;
		i++;
	}
	for (val2 = 0; isdigit(s[i]); i++)
	{
		val2 = 10 * val2 + (s[i] - '0');
	}
	for (j = 0, power2 = 1; j < val2; j++)
	{
		power2 *= 10;
	}
	if (esign >= 0)
	{
		return sign * val / power * power2;
	}
	else
	{
		return sign * val / power / power2;
	}
}
