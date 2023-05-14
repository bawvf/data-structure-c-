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

#define MAXSIZE 1000 /* �洢�ռ��ʼ������ */

typedef int Status;           /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char ElemType;        /* ElemType���͸���ʵ������������������Ϊchar */

//��̬�������������
typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

//��ʼ������
Status InitList(StaticLinkList space) {
    int i;
    for (i = 0; i < MAXSIZE; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
    
    return OK;
}

//��̬����Ĳ������
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

//ɾ������

void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;    /* �ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ���cur */
    space[0].cur = k;               /* ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur */
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
