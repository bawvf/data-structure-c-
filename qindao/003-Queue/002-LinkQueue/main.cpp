#include <iostream>
#include <commctrl.h>

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
#define MAXSIZE 100
typedef struct Qnode {
    ElemType data;
    struct Qnode *next;
} QNode, *QuenePtr;

typedef struct {
    QuenePtr front;
    QuenePtr rear;
} LinkQueue;

//��ʼ��
Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QuenePtr) malloc(sizeof (QNode));
    if (!Q.front)
        return OVERFLOW;
    Q.front->next = NULL;
    return OK;
}

//����������
Status DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        QuenePtr p = Q.front->next;
        free(Q.front);
        Q.front = p;
    }
    return OK;
}

//��Ԫ��e���
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

//�����г���
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

//�������еĶ�ͷԪ��
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
