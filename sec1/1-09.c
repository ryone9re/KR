#include <stdio.h>

int main()
{
  int c, sc = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      putchar(c);
      while ((c = getchar()) != EOF && c == ' ')
        ;
      putchar(c);
    }
    else
    {
      putchar(c);
    }
  }

  printf("\n");

  return 0;
}
