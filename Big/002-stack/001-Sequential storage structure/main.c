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

//结构定义
typedef int Status;
typedef int SElemType;

typedef struct {
    SElemType data[MAXSIZE];
    int top;
} SQStack;

//进栈操作
Status Push(SQStack *S, SElemType e) {
//    栈满
    if (S->top == MAXSIZE - 1)
        return ERROR;
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status Pop(SQStack *S, SElemType *e) {
    if (S->top == 1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}

//出栈操作

int main() {
    printf("Hello, World!\n");
    return 0;
}
