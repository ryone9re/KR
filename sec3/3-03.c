#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

int mgetline(char s[], int lim);
void expand(char s1[], char s2[]);

int main()
{
  char s1[MAXLINE], s2[MAXLINE] = {'\0'};

  mgetline(s1, MAXLINE);
  expand(s1, s2);
  printf("%s", s2);

  return 0;
}

int mgetline(char s[], int lim)
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i++] = '\n';
  }
  s[i] = '\0';

  return i;
}

void expand(char s1[], char s2[])
{
  int s1set, s2set, c;

  s1set = s2set = 0;
  while ((c = s1[s1set++]) != '\0')
  {
    if (s1[s1set] == '-' && s1[s1set + 1] >= c)
    {
      s1set++;
      while (c < s1[s1set])
      {
        s2[s2set++] = c++;
      }
    }
    else
    {
      s2[s2set++] = c;
    }
  }
  s2[s2set] = '\0';
}
