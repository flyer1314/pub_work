#ifndef __DVR_UART__H__
#define __DVR_UART__H__

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>

#define     UART_ERR_OPEN_FAIL      -1	//设备打开失败
#define     UART_ERR_CONFIG_FAIL    -2	//设备配置失败

#define BUFFER_SIZE     128		//BUF大小
#define HOST_COM_PORT   2       //主com口
#define MAX_COM_NUM     3		//最大com数
#define GENERAL         1
#define USBTTY          0
#define COM_TYPE        1

#define Wtime           5
#define SD_DATA_DEFAULT_DIR     "/mnt/sd01/DVR/DATA/"
#define SD_DATA_DEFAULT_FILE    "/mnt/sd01/DVR/DATA/OBD"


typedef enum{
    UART_0  =   0,  //串口0
    UART_1,         //串口1
    UART_2,         //串口2
    UART_NUM
}UART_ID;

typedef struct{
    int UartID;     //串口编号 
    int BaudRate;   //波特率
    int DataBite;   //数据位
    char Parity;    //奇偶校验位
    int StopBite;   //停止位
}UART_CONFIG;

int open_port(int com_port);    /*打开设备*/
int set_com_config(int fd,int baud_rate,int data_bits,char parity,int stop_bits);/*配置设备*/

signed int gk_open_com_port(UART_CONFIG uart_config);/*打开并配置设备*/
signed int gk_close_com_port(int fd);   /*关闭设备*/
signed int gk_read_com_port(signed int fd,char *read_buf,int read_size);    /*读设备*/
signed int gk_write_com_port(signed int fd,char* write_buf,int write_size); /*写设备*/

int uart_fd_init(void);/*配置并打开串口ttySGK1，返回fd*/

int SetPthreadStackSize(pthread_attr_t *attr, size_t stacksize);/*初始化一个线程属性，并设置栈的大小*/

#endif
