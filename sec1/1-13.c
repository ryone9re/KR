#include <stdio.h>

int main()
{
  int c, i, wc = 0, wa[1000];

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n')
    {
      wa[i++] = wc;
      wc = 0;
    }
    else
    {
      ++wc;
    }
  }
  wa[i] = '\0';

  for (int j = 0; j < i; ++j)
  {
    for (int q = 0; q < wa[j]; ++q)
    {
      printf("O");
    }
    printf("\n");
  }

  return 0;
}
