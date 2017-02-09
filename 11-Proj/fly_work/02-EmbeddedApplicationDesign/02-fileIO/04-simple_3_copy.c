/*******************************************************************
 *   > File Name: 04-simple_3_copy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 03:33:19 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int copy_file(const char *src_file, const char *dst_file)
{
    int fds,fdd;
    unsigned char buf[BUF_SIZE];
    int read_len;

    if((fds = open(src_file, O_RDONLY)) < 0)
    {
        perror("fail to open src_file");
        return (-1);
    }

    if((fdd = open(dst_file, O_RDWR|O_CREAT|O_TRUNC, 0664)) < 0)
    {
        perror("fail to open dst_file");
        return (-1);
    }

    while((read_len = read(fds, buf, sizeof(buf))) > 0)
    {
        write(fdd, buf, read_len);
    }

    close(fds);
    close(fdd);
    return 0;
}

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Usage :%s src_file dst_file\n",argv[0]);
        return 0;
    }

    copy_file(argv[1],argv[2]);

    return 0;
}
