/*******************************************************************
 *   > File Name: 12-pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年05月07日 星期一 13时31分58秒
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int  var = 20;   /* 实际变量的声明 */
    int  *ip;        /* 指针变量的声明 */

    ip = &var;  /* 在指针变量中存储 var 的地址 */

    printf("Address of var variable: %p\n", &var  );

    /* 在指针变量中存储的地址 */
    printf("Address stored in ip variable: %p\n", ip );

    /* 使用指针访问值 */
    printf("Value of *ip variable: %d\n", *ip );

    return 0;
}
