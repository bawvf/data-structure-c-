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

typedef int Status;
typedef int QElemType; /* QElemType���͸���ʵ������������������Ϊint */

//ѭ�����е�˳��ṹ
typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

//��ʼ���ṹ
Status InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    
    return OK;
}

//���еĳ���
int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//��ջ
Status EnQueue(SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    
    return OK;
}

//��ջ
Status DeQueue(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    
    return OK;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
