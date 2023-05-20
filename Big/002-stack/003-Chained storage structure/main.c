#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

//链栈结构
typedef struct StackNode {
    SElemType data;
    struct StackNode * next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;

//进栈操作
Status Push(LinkStack *S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof (StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack S)
{
    if (S.count==0)
        return TRUE;
    else
        return FALSE;
}

//出栈操作
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
