#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT 10
#define N(n) (n) ? n : DEFAULT
#define MAXLINES 5000

char *lineptr[MAXLINES];
char  linestor[MAXLINES];

int  readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines, int wlines);

int main(int argc, char *argv[])
{
	int c, d, i;

	switch (argc)
	{
	case 1:
		if ((i = readlines(lineptr, linestor, MAXLINES)) >= N(c))
		{
			writelines(lineptr, i, N(c));
			return 0;
		}
		else
		{
			printf("error: input too shorter than number \n");
			return 1;
		}
		break;
	case 2:
		if (**++argv == '-')
		{
			c = 0;
			while (isdigit(d = *(++(*argv))))
			{
				c = c * 10 + d - '0';
			}
			if (d == '\0')
			{
				if ((i = readlines(lineptr, linestor, MAXLINES)) >= N(c))
				{
					writelines(lineptr, i, N(c));
					return 0;
				}
				else
				{
					printf("error: input too shorter than number \n");
					return 1;
				}
			}
			else
			{
				printf("error: arguments invalid\n");
			}
		}
		else
		{
			printf("error: arguments invalid\n");
		}
		break;
	default:
		printf("error: too many arguments\n");
		return 1;
	}
}

#define MAXLEN 1000
#define MAXSTOR 5000

int mgetline(char *, int);

int readlines(char *lineptr[], char *linestor, int maxlines)
{
	int   len, nlines;
	char  line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;

	nlines = 0;

	while ((len = mgetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || p + len > linestop)
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines, int wlines)
{
	int i;
	lineptr += nlines - wlines;
	for (i = 0; i < wlines; i++)
		printf("%s\n", *(lineptr++));
}

int mgetline(char *s, int lim)
{
	int   c;
	char *t = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;

	*s = '\0';

	return s - t;
}
