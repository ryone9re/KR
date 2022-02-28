#include <stdio.h>

int strend(char *, char *);

int main()
{
	char s[] = "Helloworld", t[] = "world";
	int  i;

	i = strend(s, t);
	printf("w1 %s w2 %s res %d\n", s, t, i);

	return 0;
}

int strend(char *s, char *t)
{
	char *ts = t;

	while (*s != '\0')
	{
		s++;
	}
	while (*t != '\0')
	{
		t++;
	}
	for (s--, t--; *s == *t; s--, t--)
		;
	if (++t == ts)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
