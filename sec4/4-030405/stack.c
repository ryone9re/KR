#include <stdio.h>
#define MAXSIZE 100

int    sp = 0;
double stack[MAXSIZE];

void push(double t)
{
	if (sp < MAXSIZE)
	{
		stack[sp++] = t;
	}
	else
	{
		printf("error: stack full, can't push %g\n", t);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return stack[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}
