/*
*   4、用双向循环链表实顺序递增存储若干自然数，比如输入一个整数10，
*   则建立一个双向循环链表，里面的每个节点分别存放1，2，3，4，5，6，7，8，9，10，
*   然后通过某些操作，将其重新排列成1，3，5，7，9，10，8，6，4，2，即奇数升序偶数降序，
*   并在屏幕上打印出来。
 */

#include "doublelist.h"

int main(void)
{
    double_pnode h;

    init_doublelist(&h);   //初始化空链表
    create_doublelist(h);
    sort_doublelist(h);   //对链表中的数据逆转

    return 0;
}
