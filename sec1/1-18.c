#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0)
  {
    printf("len:%d line:%s", len, line);
  }

  return 0;
}

int my_getline(char line[], int maxline)
{
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }
  while (line[(i - 1)] == ' ' || line[(i - 1)] == '\t')
  {
    --i;
  }
  if (c == '\n')
  {
    line[i] = c;
  }
  line[(i + 1)] = '\0';

  return i;
}
