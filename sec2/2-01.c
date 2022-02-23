#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
  printf("MAX char %d\n", (char)((unsigned char)~0 >> 1));
  printf("MIN char %d\n", (char)(-((unsigned char)~0 >> 1) - 1));

  printf("MIN short %d\n", (short int)((unsigned short int)~0 >> 1));
  printf("MIN short %d\n", (short int)-((unsigned short int)~0 >> 1) - 1);

  printf("MIN int %d\n", (int)((unsigned int)~0 >> 1));
  printf("MIN int %d\n", (int)-((unsigned int)~0 >> 1) - 1);

  printf("MIN long %ld\n", (long)((unsigned long)~0 >> 1));
  printf("MIN long %ld\n", (long)-((unsigned long)~0 >> 1) - 1);

  return 0;
}
