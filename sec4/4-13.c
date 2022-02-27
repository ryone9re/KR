#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void rv(char s[], int, int);

int main()
{
	char s[] = "Hello";

	reverse(s);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[])
{
	int i;
	int j;

	i = 0;
	j = strlen(s) - 1;
	rv(s, i, j);
}

void rv(char s[], int i, int j)
{
	int c;

	if (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		rv(s, ++i, --j);
	}
}
