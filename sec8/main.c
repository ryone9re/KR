#include "mfcntrl.h"

int main(void)
{
	int   c;
	FILE *fp;

	fp = mfopen("input", "r");
	if ((fseek(fp, (long) 1, 0)) == 0)
	{
		while ((c = getc(fp)) != EOF)
		{
			putc(c, stdout);
		}
	}
}
