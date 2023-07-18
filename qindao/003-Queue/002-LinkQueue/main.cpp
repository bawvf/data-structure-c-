#include <iostream>
#include <commctrl.h>

//预定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

//定义
#define MAXSIZE 100
typedef struct Qnode {
    ElemType data;
    struct Qnode *next;
} QNode, *QuenePtr;

typedef struct {
    QuenePtr front;
    QuenePtr rear;
} LinkQueue;

//初始化
Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QuenePtr) malloc(sizeof (QNode));
    if (!Q.front)
        return OVERFLOW;
    Q.front->next = NULL;
    return OK;
}

//销毁链队列
Status DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        QuenePtr p = Q.front->next;
        free(Q.front);
        Q.front = p;
    }
    return OK;
}

//将元素e入队
Status EnQueue(LinkQueue &Q, ElemType e) {
    QuenePtr p = (QuenePtr) malloc(sizeof(QNode));
    if (!p)
        return OVERFLOW;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

//链队列出队
Status DeQueue(LinkQueue &Q, ElemType &e) {
    if(Q.front == Q.rear)
        return ERROR;
    Qnode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return OK;
}

//求链队列的队头元素
Status GetHead(LinkQueue Q, ElemType &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.front->next->data;
    return OK;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
