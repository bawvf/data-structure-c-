#include <iostream>

//Ԥ����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

//˳��ջ�ı�ʾ
#define MAXSIZE 100
typedef struct {
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S) {
    S.base = (ElemType*) malloc(MAXSIZE*sizeof(ElemType));
    if (!S.base)
        return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//˳��ջ�ж�ջ�Ƿ�Ϊ��
Status SqStackEmpty(SqStack S) {
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

//��˳��ջ����
int StackLength(SqStack S) {
    return S.top - S.base;
}

//���˳��ջ
Status ClearStack(SqStack S) {
    if (S.base)
        S.top = S.base;
    return OK;
}

//����˳��ջ
Status DestryStack(SqStack &S) {
    if (S.base) {
        free(S.base);
        S.stacksize = 0;
        S.base = S.top = NULL;
    }
    return OK;
}

//˳��ջ����ջ
Status Push(SqStack &S, ElemType e) {
    if (S.top - S.base == S.stacksize)
        return ERROR;
    *S.top++ = e;
    return OK;
}

//˳��ջ�ĳ�ջ
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
