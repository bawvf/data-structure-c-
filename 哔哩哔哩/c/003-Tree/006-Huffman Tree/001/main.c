#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char E;

typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int value;
} * Node;

typedef Node T;

typedef struct LNode {
    T element;
    struct LNode * next;
} * LNode;

struct Queue {
    LNode front, rear;
};

typedef struct Queue * LinkedQueue;

//初始化
_Bool initQueue(LinkedQueue queue) {
    LNode node = malloc(sizeof (struct LNode));
    if (node == NULL)
        return 0;
    queue->front = queue->rear = node;
    node->next = NULL;
    return 1;
}

_Bool offerQueue(LinkedQueue queue, T element) {
    LNode node = malloc(sizeof (struct LNode));
    if (node == NULL)
        return 0;
    node->element = element;
    node->next = NULL;
    LNode pre = queue->front;
    while (pre->next && pre->next->element->value <= element->value)
        pre = pre->next;
    if (pre == queue->rear) {
        queue->rear->next = node;
        queue->rear = node;
    } else {
        node->next = pre->next;
        pre->next = node;
    }
    return 1;
}

T pollQueue(LinkedQueue queue) {
    T e = queue->front->next->element;
    LNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if (queue->rear == node)
        queue->rear = queue->front;
    free(node);
    return e;
    
}

void printQueue(LinkedQueue queue) {
    printf("<<<");
    LNode node = queue->front->next;
    while (node) {
        printf("%c ", node->element->element);
        node = node->next;
    }
    printf("<<<\n");
}

//创建结点
Node createNode(E element, int value) {
    Node node = malloc(sizeof (struct TreeNode));
    node->element = element;
    node->left = node->right = NULL;
    node->value = value;
    return node;
}

char * encode(Node root, E e) {
    if (root == NULL)
        return NULL;
    if (root->element == e)
        return "";
    char * str = encode(root->left, e);
    char * s = malloc(sizeof (char) * 10);
    if (str != NULL) {
        s[0] = '0';
        str = strcat(s, str);
    } else {
        str = encode(root->right, e);
        if (str != NULL) {
            s[0] = '1';
            str = strcat(s, str);
        }
    }
    return str;
}

void printEncode(Node root, E e) {
    printf("%c 的编码为: %s", e, encode(root, e));
    putchar('\n');
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    
    offerQueue(&queue, createNode('A', 5));
    offerQueue(&queue, createNode('B', 16));
    offerQueue(&queue, createNode('C', 8));
    offerQueue(&queue, createNode('D', 13));

    while (queue.front->next != queue.rear) {
        Node left = pollQueue(&queue);
        Node right = pollQueue(&queue);
        Node node = createNode(' ', left->value + right->value);
        node->left = left;
        node->right = right;
        offerQueue(&queue, node);
    }

    Node root = pollQueue(&queue);

    printEncode(root, 'A');
    printEncode(root, 'B');
    printEncode(root, 'C');
    printEncode(root, 'D');

    return 0;
}
