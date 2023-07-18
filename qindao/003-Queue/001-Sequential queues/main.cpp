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


//����
#define MAXQSIZE 100
typedef struct {
    ElemType *base;
    int front;
    int rear;
} SqQueue;

//��ʼ��
Status InitQueue(SqQueue &Q) {
    Q.base = (ElemType*) malloc(MAXQSIZE*sizeof(ElemType));
    if (!Q.base)
        return OVERFLOW;
    Q.front = Q.rear = 0;
    return OK;
}

//����еĳ���
int QueueLength(SqQueue Q) {
    return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//ѭ���������
Status EnQueue(SqQueue &Q, ElemType e) {
    if ((Q.rear+1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}

//ѭ�����г���
Status DeQueue(SqQueue &Q, ElemType &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;
    return OK;
}

//ȡ��ͷԪ��
ElemType GetHead(SqQueue Q) {
    if (Q.front = Q.rear)
        return Q.base[Q.front];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
