#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100
#define NUMBER '0'

int  getch(void);
void ungetch(int);

int  bp = 0;
char buf[BUFSIZE];

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
