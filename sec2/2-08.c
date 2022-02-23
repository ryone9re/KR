#include <stdio.h>

unsigned rightrot(unsigned, int);
int wordlength(void);

int main()
{
  printf("%u\n", (unsigned)rightrot((unsigned)51, 5));

  return 0;
}

unsigned rightrot(unsigned x, int n)
{
  unsigned rbit;

  rbit = x << (wordlength() - n);
  x = x >> n;

  return rbit | x;
}

int wordlength()
{
  int i;
  unsigned v = (unsigned)~0;

  i = 0;
  while ((v = v >> 1) > 0)
  {
    i++;
  }

  return i;
}
