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

//链栈的表示
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

//链栈的初始化
Status InitStack(LinkStack &S) {
    S = NULL;
    return OK;
}

//判断链栈是否为空
Status StackEmpty(LinkStack S) {
    if (S == NULL)
        return TRUE;
    else return FALSE;
}

//链栈的入栈
Status Push(LinkStack &S, ElemType e) {
    LinkStack p = (LinkStack) malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

//链栈的出栈
Status Pop(LinkStack &S, ElemType &e) {
    if (S == NULL)
        return ERROR;
    e = S->data;
    LinkStack p = S;
    S = S->next;
    free(p);
    return OK;
}

//取栈顶元素
ElemType GetTop(LinkStack S) {
    if (S != NULL)
        return S->data;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
