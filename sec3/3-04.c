#include <stdio.h>
#define MAXSIZE 1000

void itoa(int n, char s[]);
void reverse(char s[]);
int abs(int n);

int main()
{
  int i;
  unsigned j;
  char s[MAXSIZE];

  i = -2147483648;
  itoa(i, s);
  printf("%s\n", s);

  return 0;
}

void itoa(int n, char s[])
{
  int i, sign;

  sign = n;
  i = 0;
  do
  {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0)
  {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char c[])
{
  int i = 0, j = 0;

  while (c[++i] != '\0')
    ;
  char buf[i--];
  while (i >= 0)
  {
    buf[j++] = c[i--];
  }
  for (int l = 0; c[l] != '\0'; ++l)
  {
    c[l] = buf[l];
  }
}

int abs(int n)
{
  return n < 0 ? -n : n;
}
