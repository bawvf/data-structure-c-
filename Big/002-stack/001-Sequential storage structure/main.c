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

//�ṹ����
typedef int Status;
typedef int SElemType;

typedef struct {
    SElemType data[MAXSIZE];
    int top;
} SQStack;

//��ջ����
Status Push(SQStack *S, SElemType e) {
//    ջ��
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

//��ջ����

int main() {
    printf("Hello, World!\n");
    return 0;
}
