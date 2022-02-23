#include <stdio.h>
#define MAXSIZE 100
#define YES 1
#define NO 0

int my_getline(char s[], int i);
int htoi(char hex[]);

int main()
{
  char s_hex[MAXSIZE];
  int i;

  my_getline(s_hex, MAXSIZE);
  i = htoi(s_hex);
  printf("%d\n", i);

  return 0;
}

int my_getline(char line[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  return i;
}

int htoi(char s[])
{
  int hexdigit, inhex, i = 0, n = 0;

  if (s[i] == '0')
  {
    ++i;
    if (s[i] == 'x' || s[i] == 'X')
    {
      ++i;
    }
  }

  inhex = YES;
  while (inhex == YES)
  {
    if (s[i] >= '0' && s[i] <= '9')
    {
      hexdigit = s[i] - '0';
    }
    else if (s[i] >= 'a' && s[i] <= 'f')
    {
      hexdigit = s[i] - 'a' + 10;
    }
    else if (s[i] >= 'A' && s[i] <= 'F')
    {
      hexdigit = s[i] - 'A' + 10;
    }
    else
    {
      inhex = NO;
    }

    if (inhex == YES)
    {
      n = 16 * n + hexdigit;
    }

    ++i;
  }

  return n;
}
