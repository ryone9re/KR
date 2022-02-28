#include <stdio.h>

void mstrncpy(char *, char *, int);
void mstrncat(char *, char *, int);
int  mstrncmp(char *, char *, int);

int main()
{
	int  i;
	char r[5], s[] = "Hello", t[] = "world", u[] = "world", v[] = "Hello";

	mstrncpy(r, s, 2);
	printf("%s\n", r); // assert "He"
	mstrncat(s, t, 3);
	printf("%s\n", s); // assert "Hellowor"
	i = mstrncmp(t, u, 3);
	printf("%d\n", i); // assert 0
	i = mstrncmp(u, v, 4);
	printf("%d\n", i); // assert 47

	return 0;
}

void mstrncpy(char *s, char *t, int n)
{
	int i;

	for (i = 0; i < n && *t != '\0'; i++, s++, t++)
	{
		*s = *t;
	}
}

void mstrncat(char *s, char *t, int n)
{
	int i;

	while (*s != '\0')
	{
		s++;
	}
	for (i = 0; i < n && *t != '\0'; i++, s++, t++)
	{
		*s = *t;
	}
}

int mstrncmp(char *s, char *t, int n)
{
	int i;

	for (i = 0; i < n && *t != '\0' && *s == *t; i++, s++, t++)
	{
		if (*s == '\0')
		{
			return 0;
		}
	}

	return *s - *t;
}
