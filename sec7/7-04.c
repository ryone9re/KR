#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000

int myscanf(char *fmt, ...);

int main(void)
{
	int    count;
	int    i, j;
	char   k[MAXSIZE], l[MAXSIZE];
	double m, n;

	// count = myscanf("%d %d", &i, &j);
	// printf("%d count: %d %d\n", i, count, j);
	// count = scanf("%s", k);
	// count = myscanf("%s %s", k, l);
	// printf("%s count: %d %s\n", k, count, l);
	count = myscanf("%e %f", &m, &n);
	printf("%lf %lf\n", m, n);

	return 0;
}

int  getch(void);
void ungetch(int);

int  bp = 0;
char buf[BUFSIZ];
char word[MAXSIZE];

int myscanf(char *fmt, ...)
{
	int       count;
	va_list   ap;
	char     *p;
	int       c;
	char     *w;
	int      *ivar, ivar_sign = 1;
	unsigned *uvar;
	char     *svar;
	double   *dvar, dvar_sign = 1.0, dvar_count = 1.0;

	va_start(ap, fmt);
	for (count = 0, p = fmt; *p; count++, p++)
	{
		while (isblank(*p))
		{
			p++;
		}
		if (*p != '%')
		{
			break;
		}
		switch (*++p)
		{
		case 'd':
			w = word;
			while (isblank(c = getch()))
				;
			if (c == '-')
			{
				ivar_sign = -1;
			}
			if (c == '-' || c == '+')
			{
				c = getch();
			}
			while (isdigit(c))
			{
				*w = c;
				w++;
				c = getch();
			}
			*w = '\0';
			ivar = va_arg(ap, int *);
			*ivar = ivar_sign * atoi(word);
			break;
		case 'u':
			w = word;
			while (isblank(c = getch()))
				;
			while (isdigit(c))
			{
				*w = c;
				w++;
				c = getch();
			}
			*w = '\0';
			uvar = va_arg(ap, unsigned *);
			*uvar = atoi(word);
			break;
		case 's':
			w = word;
			while (isblank(c = getch()))
				;
			while (!iscntrl(c) && !isspace(c))
			{
				*w = c;
				w++;
				c = getch();
			}
			*w = '\0';
			svar = va_arg(ap, char *);
			strcpy(svar, word);
			break;
		case 'e':
		case 'f':
		case 'g':
			w = word;
			while (isblank(c = getch()))
				;
			if (c == '-')
			{
				dvar_sign = -1.0;
			}
			if (c == '-' || c == '+')
			{
				c = getch();
			}
			while (isdigit(c))
			{
				*w = c;
				w++;
				c = getch();
			}
			if (iscntrl(c) || isspace(c))
			{
				*w = '\0';
				dvar = va_arg(ap, double *);
				*dvar = atof(word) / dvar_count;
				break;
			}
			else if (c == '.')
			{
				while (isdigit(c = getch()))
				{
					*w = c;
					dvar_count *= 10.0;
					w++;
				}
				*w = '\0';
				dvar = va_arg(ap, double *);
				*dvar = atof(word) / dvar_count;
				dvar_count = 1.0;
			}
			else
			{
				return 0;
			}
			break;
		default:
			return 0;
		}
	}
	va_end(ap);

	return count;
}

int getch(void)
{
	if (bp > 0)
	{
		return buf[--bp];
	}
	else
	{
		getchar();
	}
}

void ungetch(int c)
{
	if (bp >= BUFSIZ)
	{
		printf("Buffer over\n");
	}
	else
	{
		buf[bp++] = c;
	}
}
