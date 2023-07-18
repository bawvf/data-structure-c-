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

//��ջ�ı�ʾ
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

//��ջ�ĳ�ʼ��
Status InitStack(LinkStack &S) {
    S = NULL;
    return OK;
}

//�ж���ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S) {
    if (S == NULL)
        return TRUE;
    else return FALSE;
}

//��ջ����ջ
Status Push(LinkStack &S, ElemType e) {
    LinkStack p = (LinkStack) malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

//��ջ�ĳ�ջ
Status Pop(LinkStack &S, ElemType &e) {
    if (S == NULL)
        return ERROR;
    e = S->data;
    LinkStack p = S;
    S = S->next;
    free(p);
    return OK;
}

//ȡջ��Ԫ��
ElemType GetTop(LinkStack S) {
    if (S != NULL)
        return S->data;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
