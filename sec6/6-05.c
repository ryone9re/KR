#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist
{
	struct nlist *next;
	char	     *name;
	char	     *defn;
};

static struct nlist *hashtab[HASHSIZE];

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

int main(void)
{
	struct nlist *p;
	struct nlist *q;
	struct nlist *result;

	p = install("GO", "GOOO");
	q = install("GO", "FFFF");
	result = lookup("GO");

	printf("p: %p result: %p\n", p, result);

	undef("GO");

	printf("p: %p q: %p result: %p\n", p, q, lookup("GO"));

	return 0;
}
