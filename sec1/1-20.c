#include <stdio.h>
#define not_cc_start 32
#define not_cc_end 126
#define tab_width 8

int main()
{
  int c, i, w;

  while ((c = getchar()) != EOF)
  {
    if (c != '\t')
    {
      putchar(c);
      if (not_cc_start <= c && c <= not_cc_end)
      {
        ++i;
      }
      if (c == '\n')
      {
        i = 0;
      }
    }
    else
    {
      w = tab_width - i % tab_width;
      while (0 < w)
      {
        putchar(' ');
        --w;
      }
      i = 0;
    }
  }

  return 0;
}
