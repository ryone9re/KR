#include "mfcntrl.h"

int main(void)
{
	int   c;
	FILE *fp, *fp2;

	fp = mfopen("../../input", "r");
	fp2 = mfopen("../../output", "w");
	while ((c = getc(fp)) != EOF)
	{
		putc(c, fp2);
	}
	mfclose(fp);
	mfclose(fp2);
}
