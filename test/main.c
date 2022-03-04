#include <stdio.h>

int main(void)
{
	int   c;
	FILE *fp;

	fp = fopen("input", "r");
	while ((c = getc(fp)) > 0)
	{
		if (putc(c, stdout) != c)
		{
			printf("error\n");
		}
	}
}
