#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int    mgetline(char s[], int lim);
double pop(void);
void   push(double);

int    sp = 0;
double stack[MAXSIZE];

int main(void)
{
	int    i;
	char   s[MAXSIZE];
	double op;

	mgetline(s, MAXSIZE);

	for (i = 0; s[i] != '\0'; i++)
	{
		switch (s[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			push((double) (s[i] - '0'));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op = pop();
			push(pop() - op);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op = pop();
			push(pop() / op);
			break;
		case '\n':
			printf("%lf\n", pop());
			break;
		case ' ':
		case '\t':
			break;
		default:
			printf("NaN");
			break;
		}
	}
}

int mgetline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
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

double pop(void)
{
	if (sp > 0)
	{
		return stack[--sp];
	}
	else
	{
		printf("stack empty");
		return 0.0;
	}
}

void push(double c)
{
	if (sp >= MAXSIZE)
	{
		printf("stack overflow");
	}
	else
	{
		stack[sp++] = c;
	}
}
