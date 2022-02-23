#include <stdio.h>
#define MAXSIZE 100

int my_getline(char s[], int i);
void squeeze(char s1[], char s2[]);

int main()
{
  char s[MAXSIZE], v[MAXSIZE];

  my_getline(s, MAXSIZE);
  my_getline(v, MAXSIZE);
  squeeze(s, v);
  printf("%s", s);

  return 0;
}

int my_getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i++] = '\n';
  }
  s[i] = '\0';

  return i;
}

void squeeze(char s1[], char s2[])
{
  int h, i, j;

  for (h = 0; s1[h] != '\0'; h++)
  {
    for (i = j = 0; s1[i] != '\0'; i++)
    {
      if (s1[i] != s2[h])
      {
        s1[j++] = s1[i];
      }
    }
  }
  s1[j] = '\0';
}
