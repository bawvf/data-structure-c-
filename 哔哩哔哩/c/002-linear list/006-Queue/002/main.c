#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct LNode {
    E element;
    struct LNode * next;
};

typedef struct LNode * Node;

struct Queue {
    Node front, rear;
};

typedef struct Queue * LinkedQueue;

//初始化
bool initQueue(LinkedQueue queue) {
    Node node = malloc(sizeof (struct LNode));
    if (node == NULL)
        return false;
    queue->rear = queue->front = node;
    return true;
}

//入栈
bool offerQueue(LinkedQueue queue, E element) {
    Node node = malloc(sizeof (struct LNode));
    if (node == NULL)
        return false;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return true;
}

//打印
void printQueue(LinkedQueue queue) {
    printf("<<< ");
    Node node = queue->front->next;
    while (node) {
        printf("%d ", node->element);
        node = node->next;
    }
    printf("<<<\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    
    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue, i * 100);
    }
    
    printQueue(&queue);
    return 0;
}
