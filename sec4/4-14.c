#include <stdio.h>
#define swap(t, x, y) \
	{                 \
		t z;          \
		z = x;        \
		x = y;        \
		y = z;        \
	}

int main()
{
	int x, y;

	x = 10;
	y = 99;
	printf("%d  %d\n", x, y);
	swap(int, x, y);
	printf("%d  %d\n", x, y);

	return 0;
}
