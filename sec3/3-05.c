#include <stdio.h>
#define MAXSIZE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
  char s[MAXSIZE] = {'\0'};

  itob(20220, s, 16);
  printf("%s\n", s);

  return 0;
}

void itob(int n, char s[], int b)
{
  int c = 0, i = 0;

  while (n > b)
  {
    if ((c = n % b) > 9)
    {
      s[i++] = c - 10 + 'a';
    }
    else
    {
      s[i++] = c + '0';
    }
    n /= b;
  }
  if (n > 9)
  {
    s[i] = n - 10 + 'a';
  }
  else
  {
    s[i] = n + '0';
  }
  reverse(s);
  s[++i] = '\0';
}

void reverse(char s[])
{
  int i, j, k;

  for (j = 0; s[j] != '\0'; j++)
    ;
  for (i = 0, j--; i < j; i++, j--)
  {
    k = s[i];
    s[i] = s[j];
    s[j] = k;
  }
}
