/*******************************************************************
 *   > File Name: 06-define.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 26 15:21:44 2017
 ******************************************************************/

#include <stdio.h>

#define LENGTH  10
#define WIDTH   5
#define NEWLINE '\n'

int main(int argc, char* argv[])
{
    int area;

    area = LENGTH *WIDTH;

    printf("Value of area : %d\n", area);
    printf("%c", NEWLINE);

    return 0;
}