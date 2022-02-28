#include <ctype.h>
#include <stdio.h>

int  getfloat(float *);
int  getch();
void ungetch(char);

int main()
{
	float f;

	getfloat(&f);
	printf("%f\n", f);

	return 0;
}

int getfloat(float *f)
{
	int   c;
	float sign, pow;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
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
	for (*f = 0.0; isdigit(c); c = getch())
	{
		*f = 10.0 * *f + (c - '0');
	}
	if (c == '.')
	{
		c = getch();
	}
	for (pow = 1.0; isdigit(c); pow *= 10.0, c = getch())
	{
		*f = 10.0 * *f + (c - '0');
	}
	*f = *f * sign / pow;
	if (c == EOF)
	{
		ungetch(c);
	}

	return 0;
}

#define BUFSIZE 100

int bp = 0;
int buf[BUFSIZE];

int getch(void)
{
	return (bp > 0) ? buf[--bp] : getchar();
}

void ungetch(char c)
{
	if (bp >= BUFSIZE)
	{
		printf("Buffer over\n");
	}
	else
	{
		buf[bp++] = c;
	}
}
