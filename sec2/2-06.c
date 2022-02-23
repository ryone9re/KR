#include <stdio.h>

unsigned setbits(unsigned, int, int, unsigned);

int main()
{
  unsigned x, y, i;

  i = setbits((unsigned)90, 4, 3, (unsigned)43);
  printf("%d\n", i);

  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  int c, d, e, f;

  c = y & ~(~0 << n);
  d = x & ~(~0 << (p + 1 - n));
  e = x >> (p + 1);
  f = (e << n) | c;

  return (f << (p + 1 - n)) | d;
}
