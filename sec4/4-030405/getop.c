#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100
#define NUMBER '0'

int  getch(void);
void ungetch(int);

extern int  bp;
extern char buf[];

int getop(char s[])
{
	int c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;
	}
	if (c == '-' && isdigit(c = getch()))
	{
		ungetch(c);
		s[++i] = '-';
	}
	i = 0;
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
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
	}

	return NUMBER;
}
