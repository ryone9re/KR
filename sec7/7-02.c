#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LINECHAR 10
#define MAXSIZE 1000

int mgetword(char *);
int mconvertothex(int);

int main()
{
	int  c, i = 0;
	char word[MAXSIZE];

	for (i = 0; (c = mgetword(word)) != EOF; i += strlen(word))
	{
		if (i >= LINECHAR)
		{
			putchar('\n');
			i = 0;
		}
		printf("%s", word);
	}
	printf("\n");

	return 0;
}

int mgetword(char *word)
{
	int   c;
	char  a[MAXSIZE];
	char *w = word;

	c = getchar();
	if (c == EOF)
	{
		return EOF;
	}
	*a = c;
	if (iscntrl(c) || isspace(c))
	{
		sprintf(w, "%x", a);
	}
	else
	{
		sprintf(w, "%c", c);
	}

	return c;
}
