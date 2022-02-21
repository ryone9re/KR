#include <stdio.h>
#define tab_width 8

int main()
{
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      ++i;
      if (i >= tab_width)
      {
        putchar('\t');
        i = 0;
      }
    }
    else
    {
      if (0 < i && i < tab_width)
      {
        while (0 < i)
        {
          putchar(' ');
          --i;
        }
        i = 0;
      }
      putchar(c);
    }
  }

  return 0;
}
