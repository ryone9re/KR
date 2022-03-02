#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 1000
#define DEFAULT_COMP_LEN 8

struct tnode
{
	char              *word;
	int                count;
	struct linenumber *linenumbers;
	struct tnode      *left;
	struct tnode      *right;
};

struct linenumber
{
	int                linenumber;
	struct linenumber *nextnumber;
};

struct simroot
{
	struct simword *firstword;
	struct simroot *nextroot;
};

struct simword
{
	char           *word;
	int             count;
	int             linenumber;
	struct simword *nextword;
};

struct tnode      *addtree(struct tnode *, char *, int);
void               treeprint(const struct tnode *);
int                mgetword(char *, int, int *);
struct linenumber *lnumberalloc(void);
struct linenumber *addlinenumber(struct linenumber *, int);

int main(int argc, char *argv[])
{
	struct tnode *root;
	char          word[MAXWORD];
	int           len;
	int           lineno = 0;

	/* get all the words */
	root = NULL;
	while (mgetword(word, MAXWORD, &lineno) != 'x')
		if (isalpha(word[0]))
			root = addtree(root, word, lineno);

	if (argc == 1)
		len = DEFAULT_COMP_LEN;
	else if (argc == 2)
		len = atoi(argv[1]);
	else
	{
		printf("Incorrect number of arguments.\n");
		return 1;
	}

	printf("Words with line numbers\n");

	treeprint(root); /* prints all the words */

	printf("\n");

	return 0;
} /* end of main() */

struct tnode *talloc(void);
char         *mstrdup(char *);

/* mgetword from Ex6.1 */

#define IN 1
#define OUT 0

int mgetword(char *word, int lim, int *lineno_addr)
{
	int   c, d, getch(void), comment, string, directive;
	void  ungetch(int);
	char *w = word;

	comment = string = directive = OUT;

	while (isspace(c = getch()))
	{
		if (c == '\n')
		{
			*lineno_addr = *lineno_addr + 1;
		}
	}

	/* Check if inside a comment */

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

	/* Check if inside a quote */

	if (c == '\"')
	{
		string = IN;
	}

	/* Check if inside a directive */

	if (c == '#')
	{
		directive = IN;
	}

	if (c == '\\')
	{
		c = getch(); /* ignore the \\ character */
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
			if (*w == '\\') /* Take care of escaped quotes */
				*w++ = getch();
		}
		string = OUT;
		*w = '\0';
	}
	else if (directive == IN)
	{
		*w++ = c;
		while ((*w++ = getch()) != '\n')
		{
			if (c == '\\')
			{ /* Take care of continuation line escape */
				*w++ = getch();
			}
		}
		directive = OUT;
		*w = '\0';
	}

	return c;
}

/***************************************************************************
 *                    All code below here is from K&R2.                    *
 ***************************************************************************/
struct tnode *addtree(struct tnode *p, char *w, int linenumber)
{
	int cond;

	if (p == NULL)
	{ /* new word */
		p = talloc();
		p->word = mstrdup(w);
		p->count = 1;
		p->linenumbers = NULL;
		p->linenumbers = addlinenumber(p->linenumbers, linenumber);
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
	{
		p->count++;
		p->linenumbers = addlinenumber(p->linenumbers, linenumber);
	}
	else if (cond < 0)
		p->left = addtree(p->left, w, linenumber);
	else
		p->right = addtree(p->right, w, linenumber);
	return p;
}

struct linenumber *addlinenumber(struct linenumber *p, int linenumber)
{
	if (p == NULL)
	{
		p = lnumberalloc();
		p->linenumber = linenumber;
		p->nextnumber = NULL;
	}
	else
	{
		p->nextnumber = addlinenumber(p->nextnumber, linenumber);
	}

	return p;
}

struct linenumber *lnumberalloc(void)
{
	return (struct linenumber *) malloc(sizeof(struct linenumber));
}

void printnumbers(const struct linenumber *);

/* treeprint: From K&R2 page 142. Prints tree p in-order. */
void treeprint(const struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("\n%s :", p->word);
		printnumbers(p->linenumbers);
		treeprint(p->right);
	}
}

void printnumbers(const struct linenumber *p)
{
	if (p != NULL)
	{
		printf("%d,", p->linenumber);
		printnumbers(p->nextnumber);
	}
}

/* talloc: From K&R2 page 142. Makes a tnode. */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: From K&R2 page 143. Makes a duplicate of s. */
char *mstrdup(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

/*
 * getch and ungetch are from K&R2, page 79
 */
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch() */
int  bufp = 0;     /* next free position in buf */

int getch(void)
{ /* get a (possibly pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{ /* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
	return;
}
