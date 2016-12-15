#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread(void *threadid)
{
	int tid;
	tid = (int)threadid;
	printf("Hello world ! It`s me,thread #%d\n",tid);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t id;
	void *ret;
	int i,retv;
	int t = 123;
	retv = pthread_create(&id,NULL,(void *)thread,(void *)t);
	if(retv != 0)
	{
		printf("Create pthread error !\n");
		return 1;
	}

	for(i = 0;i < 3; i++)
		printf("This is the main process . \n");
	pthread_join(id,&ret);
	printf("The thread return value is %d\n",(int)ret);

	return 0;

}
