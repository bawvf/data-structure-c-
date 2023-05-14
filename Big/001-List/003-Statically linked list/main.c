#include "string.h"
#include "ctype.h"

#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* 存储空间初始分配量 */

typedef int Status;           /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char ElemType;        /* ElemType类型根据实际情况而定，这里假设为char */

//静态链表的描述方法
typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

//初始化数组
Status InitList(StaticLinkList space) {
    int i;
    for (i = 0; i < MAXSIZE; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
    
    return OK;
}

//静态链表的插入操作
int Malloc_SSL(StaticLinkList space) {
    int i = space[0].cur;
    
    if (space[0].cur)
        space[0].cur = space[1].cur;
    
    return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e) {
    int j, k, l;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(L) + 1)
        return ERROR;
    j = Malloc_SSL(L);
    if (j) {
        L[j].data = e;
        for (l = 1; l <= i - 1; l++)
            k = L[k].cur;
        L[j].cur = L[k].cur;
        L[k].cur = j;
        
        return OK;
    }
    return ERROR;
}

//删除操作

void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;    /* 把第一个元素的cur值赋给要删除的分量cur */
    space[0].cur = k;               /* 把要删除的分量下标赋值给第一个元素的cur */
}

int ListLength(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}

Status ListDelete(StaticLinkList L, int i) {
    int j, k;
    if (i < 1 || i > ListLength(L))
        return ERROR;
    k = MAXSIZE - 1;
    for (j = 1; j <= i - 1; j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    
    return OK;
}




int main() {
    printf("Hello, World!\n");
    return 0;
}
