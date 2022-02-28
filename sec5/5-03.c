#include <stdio.h>

void mstrcat(char *, char *);

int main()
{
	char s[] = "Hello", t[] = "world";

	mstrcat(s, t);
	printf("%s\n", s);
	printf("%s\n", t);

	return 0;
}

void mstrcat(char *s, char *t)
{
	while (*s != '\0')
	{
		s++;
	}
	while ((*s++ = *t++) != '\0')
		;
}
