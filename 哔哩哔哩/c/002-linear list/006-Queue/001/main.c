#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Queue {
    E * array;
    int capacity;
    int front, rear;
};

typedef struct Queue * ArrayQueue;

_Bool initqueue(ArrayQueue queue) {
    queue->array = malloc(sizeof (E) * 10);
    if (queue->array == NULL)
        return 0;
    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return 1;
}

//����
_Bool offerQueue(ArrayQueue queue, E element) {
    int pos = (queue->rear + 1) % queue->capacity;
    if (pos == queue->front)
        return 0;
    queue->rear = pos;
    queue->array[queue->rear] = element;
    return 1;
}

_Bool isEmpty(ArrayQueue queue) {
    return queue->rear == queue->front;
}

//ɾ��
E pollQueue(ArrayQueue queue) {
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

//��ӡ
void printQueue(ArrayQueue queue) {
    printf("<<<");
    int i = queue->front;
    do {
        i = (i + 1) % queue->capacity;
        printf("%d ", queue->array[i]);
    } while (i != queue->rear);
    printf("<<<\n");
}

int main() {
    struct Queue queue;
    initqueue(&queue);
    
    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue, i * 100);
    }
    
    printQueue(&queue);
    
    while (!isEmpty(&queue)) {
        printf("%d ", pollQueue(&queue));
    }
    
    return 0;
}
