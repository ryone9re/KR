#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

int  getint(int *pn);
int  getch(void);
void ungetch(int);

int  bp = 0;
char buf[BUFSIZE];

int main(void)
{
	int a, i;

	getint(&i);
	printf("%d\n", i);

	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		c = getch();
		if (!isdigit(c))
		{
			ungetch(c);
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
	{
		*pn = *pn * 10 + (c - '0');
	}
	*pn *= sign;
	if (c != EOF)
	{
		ungetch(c);
	}

	return c;
}

int getch(void)
{
	if (bp > 0)
	{
		return buf[--bp];
	}
	else
	{
		return getchar();
	}
}

void ungetch(int c)
{
	if (bp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bp++] = c;
	}
}
