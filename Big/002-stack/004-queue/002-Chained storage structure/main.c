#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;

typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
}LinkQueue;

//入队
Status EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr s = (QueuePtr) malloc(sizeof (QNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    
    return OK;
}

//出队
Status DeQueue(LinkQueue *Q, QElemType *e) {
    QueuePtr p;
    if (Q->front == Q->rear)
        return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    
    return OK
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
