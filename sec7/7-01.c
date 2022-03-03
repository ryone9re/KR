#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define UPPER "./upper"
#define LOWER "./lower"

int main(int argc, char *argv[])
{
	int c;

	if (strcmp(argv[0], UPPER) == 0)
	{
		while ((c = getchar()) != EOF)
		{
			putchar(toupper(c));
		}
	}
	else if (strcmp(argv[0], LOWER) == 0)
	{
		while ((c = getchar()) != EOF)
		{
			putchar(tolower(c));
		}
	}
	else
	{
		printf("Please called ./upper or ./lower\n");
	}

	return 0;
}
