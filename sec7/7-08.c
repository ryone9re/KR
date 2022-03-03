#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int   page_count = 1;
	char *file_name;
	FILE *fp;
	int   c;

	while (argc-- > 1)
	{
		file_name = *++argv;
		if ((fp = fopen(file_name, "r")) == NULL)
		{
			fprintf(stderr, "file open error\n");
			exit(1);
		}
		printf("---%s---\n", file_name);
		while ((c = getc(fp)) != EOF)
		{
			putc(c, stdout);
		}
		printf("---%d---\n", page_count);
		page_count++;
		fclose(fp);
	}

	return 0;
}
