#include <stdio.h>
#define WRAP_COUNT 10

int main()
{
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      putchar(c);
      i = 0;
    }
    else if (c == ' ')
    {
      while ((c = getchar()) != EOF && c == ' ')
        ;
      if (c != '\n')
      {
        putchar(c);
        putchar('\n');
        i = 0;
      }
      else
      {
        putchar(c);
        i = 0;
      }
    }
    else
    {
      if (i > WRAP_COUNT)
      {
        putchar('\n');
        i = 0;
      }
      putchar(c);
      ++i;
    }
  }

  return 0;
}
