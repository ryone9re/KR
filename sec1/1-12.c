#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
  int c, now = OUT;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      if (now == IN)
      {
        printf("\n");
        now = OUT;
      }
    }
    else
    {
      now = IN;
      putchar(c);
    }
  }

  return 0;
}
