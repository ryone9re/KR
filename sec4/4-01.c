#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int lim);
int strindex(char source[], char searchfor[]);
int rstrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
  char line[MAXLINE];
  int found = 0;
  int c;

  while (mgetline(line, MAXLINE) > 0)
  {
    if ((c = rstrindex(line, pattern)) >= 0)
    {
      printf("%s", line);
      printf("%d\n", c);
      found++;
    }
  }

  return found;
}

int mgetline(char line[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }
  if (c == '\n')
  {
    line[i++] = c;
  }
  line[i] = '\0';

  return i;
}

int strindex(char s[], char t[])
{
  int i, j, k;

  i = 0;
  while (s[i] != '\0')
  {
    j = 0;
    if (s[i] == t[j])
    {
      k = i;
      while (s[++i] == t[++j])
        ;
      if (k > 0 && t[j] == '\0')
      {
        return k;
      }
    }
    ++i;
  }

  return -1;
}

int rstrindex(char s[], char t[])
{
  int i, j, k, l;

  l = -1;
  for (i = 0; s[i] != '\0'; i++)
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
    {
      l = i;
    }
  }

  return l;
}
