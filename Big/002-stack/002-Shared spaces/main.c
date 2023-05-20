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

//结构定义
typedef struct {
    SElemType data[MAXSIZE];
    int top1;
    int top2;
} SqDoubleStack;

//进栈
Status Push(SqDoubleStack *S, SElemType e, int stackNumber) {
    if (S->top1 + 1 == S->top2)
        return ERROR;
    if (stackNumber == 1)
        S->data[++S->top1] = e;
    else if (stackNumber == 2)
        S->data[--S->top2] = e;
    
    return OK;
}

//出栈
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber) {
    if (stackNumber == 1) {
        if (S->top1 == -1)
            return ERROR;
        *e = S->data[S->top1--1];
    } else if (stackNumber == 2) {
        if (S->top2 == MAXSIZE)
            return ERROR;
        *e = S->data[S->top2++];
    }
    return OK;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
