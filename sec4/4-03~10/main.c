#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define NUMBER '0'

void   push(double t);
double pop(void);
int    getop(char s[]);

int main(void)
{
	int    type;
	double op2;
	char   s[MAXSIZE];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 > 0)
			{
				push(pop() - op2);
			}
			else
			{
				printf("error: zero divisor\n");
			}
			break;
		case '%':
			op2 = pop();
			if (op2 > 0)
			{
				push((int) pop() % (int) op2);
			}
			else
			{
				printf("error: zero divisor\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
}
