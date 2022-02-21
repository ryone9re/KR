#include <stdio.h>

int l, m, b;

void incomment();
void inquote(int c);
void search(int c);

int main(void)
{
  int c;

  extern int l, m, b;

  while ((c = getchar()) != EOF)
  {
    if (c == '/')
    {
      if ((c = getchar()) == '*')
      {
        incomment();
      }
      else
      {
        search(c);
      }
    }
    else if (c == '\'' || c == '"')
    {
      inquote(c);
    }
    else
    {
      search(c);
    }
  }

  if (l != 0 || m != 0 || b != 0)
  {
    printf("Error!\n");
  }
  else
  {
    printf("No Error\n");
  }

  return 0;
}

void incomment()
{
  int c, d;

  c = getchar();
  d = getchar();

  while (c != '*' || d != '/')
  {
    c = d;
    d = getchar();
  }
}

void inquote(int c)
{
  int d;

  putchar(c);
  while ((d = getchar()) != c)
  {
    if (d == '\\')
    {
      getchar();
    }
  }
}

void search(int c)
{
  extern int l, m, b;

  if (c == '(')
  {
    ++l;
  }
  else if (c == ')')
  {
    --l;
  }
  else if (c == '{')
  {
    ++m;
  }
  else if (c == '}')
  {
    --m;
  }
  else if (c == '[')
  {
    ++b;
  }
  else if (c == ']')
  {
    --b;
  }
}
