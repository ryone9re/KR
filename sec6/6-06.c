#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
#define WORDSIZE 1000
#define TRUE 1
#define FALSE 0
#define DEFINE "define"

struct nlist
{
	struct nlist *next;
	char	     *name;
	char	     *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned      hash(char *);
struct nlist *lookup(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
struct nlist *undef(char *);
int           mgetword(char *, int, int *);
int           getwordstring(char *, int);

int main(void)
{
	int  c, i, isdefine = FALSE;
	char word[WORDSIZE], name[WORDSIZE], defn[WORDSIZE];

	while ((c = mgetword(word, WORDSIZE, &isdefine)) != EOF)
	{
		if (isdefine == TRUE)
		{
			if (getwordstring(name, WORDSIZE) != EOF && getwordstring(defn, WORDSIZE) != EOF)
			{
				install(name, defn);
				isdefine = FALSE;
			}
		}
	}

	struct nlist *p;

	p = lookup("SIZE");

	printf("%s %s\n", p->name, p->defn);

	return 0;
}

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
	{
		hashval = *s + 31 * hashval;
	}

	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
	{
		if (strcmp(s, np->name) == 0)
		{
			return np;
		}
	}

	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned      hashval;

	if ((np = lookup(name)) == NULL)
	{
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
		{
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
	{
		free((void *) np->defn);
	}
	if ((np->defn = strdup(defn)) == NULL)
	{
		return NULL;
	}

	return np;
}

struct nlist *undef(char *name)
{
	struct nlist *np;

	np = lookup(name);
	if (np == NULL)
	{
		return NULL;
	}
	else
	{
		if (np->next != NULL)
		{
			np->next = np->next->next;
			np = np->next;
		}
		else
		{
			hashtab[hash(name)] = NULL;
			free((void *) np);
		}
	}

	return np;
}

#define IN 1
#define OUT 0
#define BUFSIZE 100

char buf[BUFSIZE];
int  bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
	return;
}

int mgetword(char *word, int lim, int *isdefine)
{
	int   c, d, getch(void), comment, string, directive, def;
	void  ungetch(int);
	char *w = word;

	comment = string = directive = OUT;

	while (isspace(c = getch()))
		;

	if (c == '/')
	{
		if ((d = getch()) == '*')
		{
			comment = IN;
		}
		else
		{
			comment = OUT;
			ungetch(d);
		}
	}

	if (c == '\"')
	{
		string = IN;
	}

	if (c == '#')
	{
		directive = IN;
	}

	if (c == '\\')
	{
		c = getch();
	}

	if (comment == OUT && string == OUT && directive == OUT)
	{
		if (c != EOF)
			*w++ = c;

		if (!isalnum(c) && c != '_')
		{
			*w = '\0';
			return c;
		}

		for (; --lim > 0; w++)
		{
			*w = getch();
			if (!isalnum(*w) && *w != '_')
			{
				ungetch(*w);
				break;
			}
		}
		*w = '\0';
		return word[0];
	}
	else if (comment == IN)
	{
		*w++ = c;
		*w++ = d;

		while ((*w++ = c = getch()))
		{
			if (c == '*')
			{
				if ((c = getch()) == '/')
				{
					*w++ = c;
					comment = OUT;
					break;
				}
				else
				{
					ungetch(c);
				}
			}
		}
		*w = '\0';
	}
	else if (string == IN)
	{
		*w++ = c;
		while ((*w++ = getch()) != '\"')
		{
			if (*w == '\\')
				*w++ = getch();
		}
		string = OUT;
		*w = '\0';
	}
	else if (directive == IN)
	{
		for (; --lim > 0; w++)
		{
			if ((c = getch()) == EOF)
			{
				return EOF;
			}
			*w = c;
			if (!isalnum(*w) && *w != '_')
			{
				ungetch(*w);
				break;
			}
		}
		*w = '\0';
		if (strcmp(word, DEFINE) == 0)
		{
			*isdefine = TRUE;
		}
		directive = OUT;
		return word[0];
	}

	return c;
}

int getwordstring(char *word, int lim)
{
	int   c;
	char *w = word;

	while (isspace(c = getch()))
		;

	if (c != EOF)
		*w++ = c;

	if (!isalnum(c) && c != '_')
	{
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++)
	{
		*w = getch();
		if (!isalnum(*w) && *w != '_')
		{
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
