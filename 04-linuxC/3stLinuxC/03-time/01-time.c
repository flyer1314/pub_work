#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t tm;
	
	//time(&tm);
	printf("%ld\n",time(&tm));
	printf("%ld\n",tm);

	return 0;
}
