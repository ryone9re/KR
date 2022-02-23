#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int lim);
int my_any(char s1[], char s2[]);

int main()
{
  char s1[MAXLINE], s2[MAXLINE];
  int i;

  my_getline(s1, MAXLINE);
  my_getline(s2, MAXLINE);
  i = my_any(s1, s2);

  printf("%d\n", i);

  return 0;
}

int my_getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i++] = c;
  }
  s[i] = '\0';

  return i;
}

int my_any(char s1[], char s2[])
{
  int h, i;

  for (h = 0; s2[h] != '\0'; h++)
  {
    for (i = 0; s1[i] != '\0'; i++)
    {
      if (s1[i] == s2[h] && s2[h] != '\n')
      {
        return i;
      }
    }
  }

  return -1;
}
