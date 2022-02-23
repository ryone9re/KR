#include <stdio.h>
#define MAXSIZE 1000

int main()
{
  int c, i, lim = MAXSIZE;
  char s[MAXSIZE];

  for (i = 0; i < lim - 1; ++i)
  {
    if ((c = getchar()) == '\n')
    {
      break;
    }
    if (c == EOF)
    {
      break;
    }
    s[i] = c;
  }
  printf("%s\n", s);

  return 0;
}
