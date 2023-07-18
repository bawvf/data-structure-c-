#include <iostream>

//预定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

//顺序栈的表示
#define MAXSIZE 100
typedef struct {
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

//顺序栈的初始化
Status InitStack(SqStack &S) {
    S.base = (ElemType*) malloc(MAXSIZE*sizeof(ElemType));
    if (!S.base)
        return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//顺序栈判断栈是否为空
Status SqStackEmpty(SqStack S) {
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

//求顺序栈长度
int StackLength(SqStack S) {
    return S.top - S.base;
}

//清空顺序栈
Status ClearStack(SqStack S) {
    if (S.base)
        S.top = S.base;
    return OK;
}

//销毁顺序栈
Status DestryStack(SqStack &S) {
    if (S.base) {
        free(S.base);
        S.stacksize = 0;
        S.base = S.top = NULL;
    }
    return OK;
}

//顺序栈的入栈
Status Push(SqStack &S, ElemType e) {
    if (S.top - S.base == S.stacksize)
        return ERROR;
    *S.top++ = e;
    return OK;
}

//顺序栈的出栈
Status Pop(SqStack &S, ElemType &e) {
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
