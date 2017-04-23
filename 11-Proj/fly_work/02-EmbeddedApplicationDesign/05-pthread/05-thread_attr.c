/*******************************************************************
 *   > File Name: 05-thread_attr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 26 Feb 2017 08:43:53 PM CST
 ******************************************************************/

/*头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
/*宏定义*/
#define REPEAT_NUM  3   /*线程中的小任务*/
#define DELAY_TIME_LEVELS   6.0 /*小任务之间的最大时间间隔*/
int finish_flag = 0;

/*线程执行函数*/
void *thrd_func(void* arg){
    int delay_time = 0;
    int count = 0;

    printf("Thread is starting\n");
    for(count = 0; count < REPEAT_NUM; count ++){
        delay_time = (int)(rand() * DELAY_TIME_LEVELS/(RAND_MAX)) + 1;
        sleep(delay_time);
        printf("\tThread : job %d delay = %d\n",count, delay_time);
    }

    printf("Thread finished\n");
    finish_flag = 1;
    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    pthread_t thread;
    pthread_attr_t attr;
    int no = 0,res;
    void * thrd_ret;

    srand(time(NULL));
    /*初始化线程属性对象*/
    res = pthread_attr_init(&attr);
    if(res != 0){
        printf("Create attribute failed\n");
        exit(res);
    }

    /*设置线程分离属性*/
    res = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    if(res != 0){
        printf("Setting attrbute failed\n");  
        exit(res);
    }

    res = pthread_create(&thread, &attr, thrd_func, NULL);
    if( res != 0){
        printf("Create thread failed\n");
        exit(res);
    }

    /*释放线程属性对象*/
    pthread_attr_destroy(&attr);
    printf("Create thread success\n");

    while(finish_flag){
        printf("Waiting for thread to finish...\n");
        sleep(2);
    }

    return 0;
}
