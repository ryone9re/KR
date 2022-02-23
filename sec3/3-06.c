#include <stdio.h>

void itoa(int n, char s[], int w);
void reverse(char c[]);
int abs(int n);

int main()
{
  char s[100] = {'\0'};

  itoa(10, s, 10);
  printf("%s\n", s);

  return 0;
}

void itoa(int n, char s[], int w)
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
  while (i < w - 1)
  {
    s[i++] = ' ';
  }
  reverse(s);
  s[i] = '\0';
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
  if (n < 0)
  {
    return -n;
  }
  else
  {
    return n;
  }
}
