/*******************************************************************
 *   > File Name: 02-extern.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jul 14 21:42:38 2017
 ******************************************************************/

#include <stdio.h>

//变量声明
extern int a, b;
extern int c;
extern float f;

int main(int argc, char* argv[])
{
    /*变量定义*/
    int a,b;
    int c;
    float f;

    /*初始化*/
    a = 10;
    b = 20;

    c = a+b;
    printf("value of c: %d\n",c);

    f = 70.0 / 3.0;
    printf("value of f :%f\n", f);

    return 0;
}
