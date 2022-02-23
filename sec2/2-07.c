#include <stdio.h>

unsigned invert(unsigned, int, int);

int main()
{
  unsigned x;
  int p, n, i;

  x = (unsigned)30;
  p = 4;
  n = 3;
  i = invert((unsigned)x, p, n);
  printf("%d\n", i);

  return 0;
}

unsigned invert(unsigned x, int p, int n)
{
  int i, j;

  i = x >> (p + 1 - n);
  j = x >> (p + 1);
  j = j << n;

  return (~i & ~(~0 << n) | j) << (p + 1 - n) | ~(~0 << (p + 1 - n)) & x;
}
