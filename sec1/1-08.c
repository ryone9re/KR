#include <stdio.h>

int main()
{
  int c, space = 0, tab = 0, indent = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      ++space;
    }
    else if (c == '\t')
    {
      ++tab;
    }
    else if (c == '\n')
    {
      ++indent;
    }
  }

  printf("space: %d tab: %d indent: %d\n", space, tab, indent);

  return 0;
}
