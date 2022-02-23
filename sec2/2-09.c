#include <stdio.h>

int bitcount(unsigned);

int main()
{
  int i;

  i = bitcount((unsigned)34);
  printf("%u\n", i);

  return 0;
}

int bitcount(unsigned x)
{
  int i;

  for (i = 0; x != 0; x &= x - 1)
  {
    ++i;
  }

  return i;
}
