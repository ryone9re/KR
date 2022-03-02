#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

struct key
{
	char *word;
	int   count;
} keytab[] = {{"auto", 0},     {"break", 0},    {"case", 0},
              {"char", 0},     {"const", 0},    {"continue", 0},
              {"default", 0},  {"do", 0},       {"double", 0},
              {"else", 0},     {"enum", 0},     {"extern", 0},
              {"float", 0},    {"for", 0},      {"goto", 0},
              {"if", 0},       {"int", 0},      {"long", 0},
              {"register", 0}, {"return", 0},   {"signed", 0},
              {"sizeof", 0},   {"short", 0},    {"static", 0},
              {"struct", 0},   {"switch", 0},   {"typedef", 0},
              {"union", 0},    {"unsigned", 0}, {"void", 0},
              {"volatile", 0}, {"while", 0},    NULL};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(void)
{
	int  n;
	char word[MAXWORD];
	int  NKEYS, i;

	for (i = 0; keytab[i].word != 0x0; i++)
		;

	NKEYS = i;

	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
		{
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
			{
				keytab[n].count++;
			}
		}
	}
	for (n = 0; n < NKEYS; n++)
	{
		if (keytab[n].count > 0)
		{
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}
	}

	return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
		{
			high = mid - 1;
		}
		else if (cond > 0)
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int getword(char *word, int lim)
{
	int   c, d, getch(void);
	void  ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c == '/' && (c = getch()) == '*')
	{
		c = getch();
		while (d != '*' || c != '/')
		{
			d = c;
			c = getch();
			if (c == EOF)
			{
				return EOF;
			}
		}
		return 0;
	}
	if (c == '#')
	{
		while ((c = getch()) != '\n')
		{
			if (c == EOF)
			{
				return EOF;
			}
		}
		return 0;
	}
	if (c != EOF)
	{
		*w++ = c;
	}
	if (!isalpha(c) && c != '_')
	{
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
	{
		if (!isalnum(*w = getch()) && *w != '_')
		{
			ungetch(*w);
			break;
		}
	}
	*w = '\0';

	return word[0];
}

#define BUFSIZE 10000

char buf[BUFSIZE];
int  bp = 0;

int getch(void)
{
	if (bp > 0)
	{
		return buf[--bp];
	}
	else
	{
		return getchar();
	}
}

void ungetch(int c)
{
	if (bp > BUFSIZE)
	{
		printf("buffer over flow\n");
	}
	else
	{
		buf[bp++] = c;
	}
}

/* Pointer version */
// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// #define MAXWORD 100

// struct key
// {
// 	char *word;
// 	int   count;
// } keytab[] = {{"auto", 0},     {"break", 0},    {"case", 0},
//               {"char", 0},     {"const", 0},    {"continue", 0},
//               {"default", 0},  {"do", 0},       {"double", 0},
//               {"else", 0},     {"enum", 0},     {"extern", 0},
//               {"float", 0},    {"for", 0},      {"goto", 0},
//               {"if", 0},       {"int", 0},      {"long", 0},
//               {"register", 0}, {"return", 0},   {"signed", 0},
//               {"sizeof", 0},   {"short", 0},    {"static", 0},
//               {"struct", 0},   {"switch", 0},   {"typedef", 0},
//               {"union", 0},    {"unsigned", 0}, {"void", 0},
//               {"volatile", 0}, {"while", 0},    NULL};

// int         getword(char *, int);
// struct key *binsearch(char *, struct key *, int);

// int main(void)
// {
// 	struct key *n;
// 	char        word[MAXWORD];
// 	int         NKEYS, i;

// 	for (i = 0; keytab[i].word != 0x0; i++)
// 		;

// 	NKEYS = i;

// 	while (getword(word, MAXWORD) != EOF)
// 	{
// 		if (isalpha(word[0]))
// 		{
// 			if ((n = binsearch(word, keytab, NKEYS)) != NULL)
// 			{
// 				n->count++;
// 			}
// 		}
// 	}
// 	for (n = keytab; n < keytab + NKEYS; n++)
// 	{
// 		if (n->count > 0)
// 		{
// 			printf("%4d %s\n", n->count, n->word);
// 		}
// 	}

// 	return 0;
// }

// struct key *binsearch(char *word, struct key *tab, int n)
// {
// 	int         cond;
// 	struct key *low = &tab[0];
// 	struct key *high = &tab[n];
// 	struct key *mid;

// 	while (low < high)
// 	{
// 		mid = low + (high - low) / 2;
// 		if ((cond = strcmp(word, mid->word)) < 0)
// 		{
// 			high = mid;
// 		}
// 		else if (cond > 0)
// 		{
// 			low = mid + 1;
// 		}
// 		else
// 		{
// 			return mid;
// 		}
// 	}
// 	return NULL;
// }

// int getword(char *word, int lim)
// {
// 	int   c, d, getch(void);
// 	void  ungetch(int);
// 	char *w = word;

// 	while (isspace(c = getch()))
// 		;
// 	if (c == '/' && (c = getch()) == '*')
// 	{
// 		c = getch();
// 		while (d != '*' || c != '/')
// 		{
// 			d = c;
// 			c = getch();
// 			if (c == EOF)
// 			{
// 				return EOF;
// 			}
// 		}
// 		return 0;
// 	}
// 	if (c == '#')
// 	{
// 		while ((c = getch()) != '\n')
// 		{
// 			if (c == EOF)
// 			{
// 				return EOF;
// 			}
// 		}
// 		return 0;
// 	}
// 	if (c != EOF)
// 	{
// 		*w++ = c;
// 	}
// 	if (!isalpha(c) && c != '_')
// 	{
// 		*w = '\0';
// 		return c;
// 	}
// 	for (; --lim > 0; w++)
// 	{
// 		if (!isalnum(*w = getch()) && *w != '_')
// 		{
// 			ungetch(*w);
// 			break;
// 		}
// 	}
// 	*w = '\0';

// 	return word[0];
// }

// #define BUFSIZE 10000

// char buf[BUFSIZE];
// int  bp = 0;

// int getch(void)
// {
// 	if (bp > 0)
// 	{
// 		return buf[--bp];
// 	}
// 	else
// 	{
// 		return getchar();
// 	}
// }

// void ungetch(int c)
// {
// 	if (bp > BUFSIZE)
// 	{
// 		printf("buffer over flow\n");
// 	}
// 	else
// 	{
// 		buf[bp++] = c;
// 	}
// }
