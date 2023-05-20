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

//循环队列的顺序结构
typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

//初始化结构
Status InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    
    return OK;
}

//队列的长度
int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//入栈
Status EnQueue(SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    
    return OK;
}

//出栈
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
