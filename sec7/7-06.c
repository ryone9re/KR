#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

void  filecmp(FILE *, FILE *);
char *mfgets(char *, int, FILE *);

int main(int argc, char *argv[])
{
	char *prog = argv[0];
	FILE *fp1, *fp2;
	int   c1, c2;
	int   count;

	if (argc != 3)
	{
		printf("require two arguments\n");
		exit(1);
	}
	else
	{
		if ((fp1 = fopen(argv[1], "r")) == NULL)
		{
			printf("WOW!\n");
			exit(1);
		}
		if ((fp2 = fopen(argv[2], "r")) == NULL)
		{
			printf("WOW!\n");
			exit(1);
		}
		for (count = 1; ((c1 = getc(fp1)) != EOF) && ((c2 = getc(fp2)) != EOF);)
		{
			if (c1 != c2)
			{
				printf("row %d is different", count);
				exit(0);
			}
			if (c1 == '\n')
			{
				count++;
			}
		}
		printf("same\n");
		exit(0);
	}
}
