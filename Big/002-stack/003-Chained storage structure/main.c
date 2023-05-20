#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */

//��ջ�ṹ
typedef struct StackNode {
    SElemType data;
    struct StackNode * next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;

//��ջ����
Status Push(LinkStack *S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof (StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    
    return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(LinkStack S)
{
    if (S.count==0)
        return TRUE;
    else
        return FALSE;
}

//��ջ����
Status Pop(LinkStack *S, SElemType *e) {
    LinkStackPtr p;
    if (StackEmpty(*S))
        return ERROR;
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;;
    free(p);
    S->count--;
    
    return OK;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
