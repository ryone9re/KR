#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMMIT 1000

int mgetline(char *, int, FILE *);
int searchword(char *, char *);

int main(int argc, char *argv[])
{
	char *line;
	FILE *fp;

	line = (char *) malloc(sizeof(char) * LIMMIT);

	if (argc > 2)
	{
		if ((fp = fopen(argv[2], "r")) == NULL)
		{
			printf("file open error\n");
			exit(1);
		}
		while (1)
		{
			if ((mgetline(line, LIMMIT, fp)) == 0)
			{
				break;
			}
			if ((strstr(line, argv[1])) > 0)
			{
				printf("%s\n", line);
			}
		}
	}
	else if (argc > 1)
	{
		while (1)
		{
			if ((mgetline(line, LIMMIT, stdin)) == 0)
			{
				break;
			}
			if ((strstr(line, argv[1])) > 0)
			{
				printf("%s\n", line);
			}
		}
	}
	else
	{
		printf("arguments sukunai\n");
	}
}

void lntrim(char *);

int mgetline(char *line, int lim, FILE *fp)
{
	if (fgets(line, lim, fp) == NULL)
	{
		return 0;
	}
	else
	{
		lntrim(line);
		return strlen(line);
	}
}

void lntrim(char *line)
{
	char *p;
	p = strchr(line, '\n');
	if (p != NULL)
	{
		*p = '\0';
	}
}
