#include <stdio.h>

float convert_f_to_c(float);

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper)
  {
    celsius = convert_f_to_c(fahr);
    printf("%3.0f, %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}

float convert_f_to_c(float fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}
