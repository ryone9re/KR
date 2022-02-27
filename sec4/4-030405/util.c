#include <math.h>
#include <stdio.h>

extern int sp;

void   push(double);
double pop();

void printstack(void)
{
	double t;

	t = pop();
	printf("%lf\n", t);
	push(t);
}

void cpstack(void)
{
	double t;

	t = pop();
	push(t);
	push(t);
}

void exchangestack(void)
{
	double i, j;

	if (sp > 1)
	{
		i = pop();
		j = pop();
		push(i);
		push(j);
	}
	else
	{
		printf("error: need more than 2 number in stack");
	}
}

void sinstack()
{
	double x;

	x = pop();
	push(sin(x));
}

void expstack()
{
	double x;

	x = pop();
	push(exp(x));
}

void powstack()
{
	double x, y;

	y = pop();
	x = pop();
	push(pow(x, y));
}
