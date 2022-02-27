#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100
#define NUMBER '0'

int  getch(void);
void ungetch(int);

int  bp = 0;
char buf[BUFSIZE];

int getop(char s[])
{
	int c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	{
		return c;
	}
	i = 0;
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
		{
			ungetch(c);
		}
	}

	return NUMBER;
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
