#include <stdio.h>
#include <stdlib.h>
#define LIM 100

void itoaa(int, char s[]);

int main()
{
	char s[LIM];
	int  i = 2299;

	itoaa(i, s);
	printf("%s\n", s);

	return 0;
}

void itoaa(int i, char s[])
{
	static int j;

	if (i / 10)
	{
		itoaa(i / 10, s);
	}
	else
	{
		j = 0;
		if (i < 0)
		{
			s[j++] = '-';
		}
	}
	s[j++] = abs(i) % 10 + '0';
	s[j] = '\0';
}
