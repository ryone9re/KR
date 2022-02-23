#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int lim);
void escape(char s[], char t[]);

int main()
{
  char s[MAXLINE], t[MAXLINE];

  mgetline(s, MAXLINE);
  escape(s, t);
  printf("%s\n", t);

  return 0;
}

int mgetline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }
  if (c == '\n')
  {
    s[i++] = '\n';
  }
  s[i] = '\0';

  return i;
}

void escape(char s[], char t[])
{
  int sset, tset;

  for (sset = 0, tset = 0; s[sset] != '\0'; ++sset, ++tset)
  {
    switch (s[sset])
    {
    case '\n':
      t[tset++] = '\\';
      t[tset] = 'n';
      break;
    case '\t':
      t[tset++] = '\\';
      t[tset] = 't';
      break;
    default:
      t[tset] = s[sset];
      break;
    }
  }
  t[tset] = '\0';
}
