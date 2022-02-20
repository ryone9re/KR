#include <stdio.h>

int main()
{
  int input, array[26] = {0};

  while ((input = getchar()) != EOF)
  {
    if (input == ' ' || input == '\n' || input == '\t')
    {
    }
    else
    {
      array[input - 97]++;
    }
  }

  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < array[i]; j++)
    {
      printf("O");
    }
    printf("\n");
  }

  return 0;
}
