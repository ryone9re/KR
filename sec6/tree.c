#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct tnode
{
	char	     *word;
	int           count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void          treeprint(struct tnode *);
int           getword(char *, int);

int main(void)
{
	struct tnode *root;
	char          word[MAXWORD];

	root = ((void *) 0);
	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
		{
			root = addtree(root, word);
		}
	}
	treeprint(root);

	return 0;
}

struct tnode *talloc(void);
char         *mstrdup(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == ((void *) 0))
	{
		p = talloc();
		p->word = mstrdup(w);
		p->count = 1;
		p->left = p->right = ((void *) 0);
	}
	else if ((cond = strcmp(p->word, w)) == 0)
	{
		p->count++;
	}
	else if (0 > cond)
	{
		p->right = addtree(p->right, w);
	}
	else
	{
		p->left = addtree(p->left, w);
	}

	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

int  getch(void);
void ungetch(int c);

int getword(char *word, int lim)
{
	int   c, d, getch(void);
	void  ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
	{
		*w++ = c;
	}
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
	{
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	}
	*w = '\0';

	return word[0];
}

int  bp = 0;
char buf[BUFSIZ];

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
	if (bp > BUFSIZ)
	{
		printf("buffer over flow\n");
	}
	else
	{
		buf[bp++] = c;
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mstrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
	{
		strcpy(p, s);
	}

	return p;
}
