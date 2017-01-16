/*******************************************************************
 *   > File Name: 02-thread_mutex.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 15 Jan 2017 05:56:27 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define THREAD_NUM  3   /*线程数*/
#define REPEAT_NUM  3   /*每个线程循环的次数*/
#define DELAY_TIME_LEVELS   6.0 /*循环之间的最大时间间隔*/

pthread_mutex_t mutex;

void* thrd_func(void* arg)
{
    int thrd_num = (int)arg;
    int delay_time = 0,count = 0;
    int res;

    /*互斥锁上锁*/
    res = pthread_mutex_lock(&mutex);
    if(res)
    {
        printf("Thread %d lock failed\n",thrd_num);
        pthread_exit(NULL);
    }

    printf("Thread %d is starting\n",thrd_num);
    for(count = 0; count < REPEAT_NUM; count++)
    {
        delay_time = (int)(rand() * DELAY_TIME_LEVELS / (RAND_MAX)) + 1;
        sleep(delay_time);
        printf("\tThread %d : job %d delay = %d\n",thrd_num, count, delay_time);
    }
    printf("Thread %d finished\n",thrd_num);
    /*互斥锁解锁*/
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    pthread_t  thread[THREAD_NUM];
    int no = 0, res;
    void* thrd_ret;

    srand(time(NULL));
    /*互斥锁初始化*/
    pthread_mutex_init(&mutex, NULL);
    for(no = 0; no < THREAD_NUM; no++)
    {
        res = pthread_create(&thread[no], NULL, thrd_func, (void*)no);
        if(res != 0)
        {
            printf("Create thread %d failed\n",no);
            exit(res);
        }
    }
    printf("Create threads success\nWaiting for thread to finish...\n");
    for(no = 0; no < THREAD_NUM; no++)
    {
        res = pthread_join(thread[no],&thrd_ret);
        if(!res)
        {
            printf("Thread %d joined\n",no);
        }
        else
        {
            printf("Thread %d join failed\n", no);
        }
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
