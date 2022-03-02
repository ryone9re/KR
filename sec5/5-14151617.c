// 飛 (14の答えみたら全部載ってたから忘れる)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int  readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qqsort(void *lineptr[], int left, int right, int (*)(const void *, const void *));
int  numcmp(const char *, const char *);

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
	{
		numeric = 1;
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qqsort((void **) lineptr, 0, nlines - 1, (int (*)(const void *, const void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);

		return 0;
	}
	else
	{
		printf("input too big to sort\n");

		return 1;
	}
}

#define MAXLEN 1000
#define MAXSTOR 5000

int   mgetline(char *, int);
char *alloc(int n);

int readlines(char *lineptr[], int maxlines)
{
	int   len, nlines;
	char  line[MAXLEN];
	char *p;

	nlines = 0;

	while ((len = mgetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
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

#define ALLOCSIZE 10000

static char  allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
	{
		return 0;
	}
}

void swap(void *v[], int, int);

void qqsort(void *v[], int left, int right, int (*comp)(const void *, const void *))
{
	int i, last;

	if (left >= right)
	{
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if ((*comp)(v[i], v[left]) < 0)
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qqsort(v, left, last - 1, comp);
	qqsort(v, last + 1, right, comp);
}

int numcmp(const char *s1, const char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
	{
		return -1;
	}
	else if (v1 > v2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
