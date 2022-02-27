#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
#define BUFSIZE 100

int  mgetline(char s[], int lim);
int  getch(void);
void ungetch(int);
void ungets(char s[]);

int bp = 0;
int buf[BUFSIZE];

int main()
{
	char c, s[MAXSIZE];

	mgetline(s, MAXSIZE);

	ungets(s);

	while ((c = getch()) != EOF)
	{
		putchar(c);
	}
	printf("\n");

	return 0;
}

int mgetline(char s[], int lim)
{
	int c, i;

	for (c = 0, i = 0; i < lim - 1 && (c = getch()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';

	return i;
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

void ungets(char s[])
{
	int i;

	i = strlen(s);

	while (i > 0)
	{
		ungetch(s[--i]);
	}
}
