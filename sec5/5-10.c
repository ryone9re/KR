#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int    checkd(char);
void   push(double);
double pop(void);

int main(int argc, char *argv[])
{
	int    type, var = 0;
	double op2, v;
	char   s[MAXOP];
	double variable[26];
	int    i;

	i = 1;
	while (--argc > 0)
	{
		type = checkd(**++argv);
		switch (type)
		{
		case NUMBER:
			push((double) (**argv - '0'));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error:zero divisor\n");
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	v = pop();
	printf("\t%.8g\n", v);

	return 0;
}

#define MAXVAL 100

int    sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:stack full, cant push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int checkd(char s)
{
	if (isdigit(s))
	{
		return NUMBER;
	}
	else
	{
		return s;
	}
}
