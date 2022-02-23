#include <stdio.h>

int lower(char c);

int main()
{
  char c = 'A';

  c = lower(c);
  printf("%c\n", c);

  return 0;
}

int lower(char c)
{
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
