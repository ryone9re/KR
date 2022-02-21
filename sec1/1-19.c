#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void reverse(char s[], char r[]);

int main()
{
  char line[MAXLINE];
  char r_line[MAXLINE];

  while (my_getline(line, MAXLINE) > 0)
  {
    reverse(line, r_line);
    printf("%s\n", r_line);
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
  if (c == '\n')
  {
    line[i] = c;
  }
  line[(i + 1)] = '\0';

  return i;
}

void reverse(char line[], char r_line[])
{
  int i;

  i = 0;
  while (line[i] != '\0')
  {
    ++i;
  }
  while (line[--i] == '\n')
    ;
  for (int j = 0; 0 <= i; --i, ++j)
  {
    r_line[j] = line[i];
  }
}
