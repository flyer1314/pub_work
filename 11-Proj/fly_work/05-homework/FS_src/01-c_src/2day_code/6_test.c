#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	char a = 5, b = 3;

	printf("a = %hhd\n",a);
	printf("~a = %hhd\n",~a);
	printf("a | b = %hhd\n",a | b);
	printf("a & b = %hhd\n",a & b);
	printf("a<< 2 = %hhd\n",a<<2);
	printf("-a<< 2 = %hhd\n",-a<<2);
	printf("a>> 2 = %hhd\n",a>>2);
	printf("-a>> 2 = %hhd\n",-a>>2);
	printf("a ^ b = %hhd\n",a ^ b);
	return 0;
}
