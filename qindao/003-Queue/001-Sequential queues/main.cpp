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


//定义
#define MAXQSIZE 100
typedef struct {
    ElemType *base;
    int front;
    int rear;
} SqQueue;

//初始化
Status InitQueue(SqQueue &Q) {
    Q.base = (ElemType*) malloc(MAXQSIZE*sizeof(ElemType));
    if (!Q.base)
        return OVERFLOW;
    Q.front = Q.rear = 0;
    return OK;
}

//求队列的长度
int QueueLength(SqQueue Q) {
    return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//循环队列入队
Status EnQueue(SqQueue &Q, ElemType e) {
    if ((Q.rear+1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}

//循环队列出队
Status DeQueue(SqQueue &Q, ElemType &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;
    return OK;
}

//取队头元素
ElemType GetHead(SqQueue Q) {
    if (Q.front = Q.rear)
        return Q.base[Q.front];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
