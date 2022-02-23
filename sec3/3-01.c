#include <stdio.h>

int binsearch(int x, int v[], int n);
int onetime_binsearch(int x, int v[], int n);
int rec_binsearch(int x, int v[], int n, int low, int high);

int main()
{
  int i, x;
  int v[] = {0, 3, 4, 5, 8, 9, 10, 13, 17};

  x = 8;
  // i = binsearch(10, v, 9);
  i = onetime_binsearch(10, v, 9);
  printf("%d\n", i);

  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, mid, high;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (x > v[mid])
    {
      low = mid + 1;
    }
    else if (x < v[mid])
    {
      high = mid - 1;
    }
    else
    {
      return mid;
    }
  }

  return -1;
}

int onetime_binsearch(int x, int v[], int n)
{
  int low, mid, high;

  for (low = 0, high = n - 1, mid = (low + high) / 2; low < high && x != v[mid]; mid = (low + high) / 2)
  {
    if (x > v[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  if (x == v[mid])
  {
    return mid;
  }
  else
  {
    return -1;
  }
}

int rec_binsearch(int x, int v[], int n, int low, int high)
{
  int mid;

  if (low >= high)
  {
    return -1;
  }
  mid = (low + high) / 2;
  if (x > v[mid])
  {
    rec_binsearch(x, v, n, mid + 1, high);
  }
  else if (x < v[mid])
  {
    rec_binsearch(x, v, n, low, mid - 1);
  }
  else
  {
    return mid;
  }

  return -1;
}
