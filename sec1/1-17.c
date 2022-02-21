#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0)
  {
    if (len >= 80)
    {
      printf("%s", line);
    }
  }

  return 0;
}

int my_getline(char line[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }
  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  --i;

  return i;
}
