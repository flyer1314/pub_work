#include <stdio.h>

#define TEST (1)

void Exchg3(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
	printf("x = %d, y = %d \n",x,y);
}

#if TEST
int main(void)
{
	int a = 4, b = 6;
	Exchg3(a,b);
	printf("After : a = %d, b = %d \n",a,b);

	return 0;
}
#endif
