#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct LNode {
    E element;
    struct LNode * next;
};

typedef struct LNode * Node;

//初始化
void initStack(Node head) {
    head->next = NULL;
}

//入栈
_Bool pushStack(Node head, E element) {
    Node node = malloc(sizeof (struct LNode));
    if (node == NULL)
        return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

//判断
_Bool isEmpty(Node head) {
    return head->next == NULL;
}

//出栈
E popStack(Node head) {
    Node tmp = head->next;
    E e = tmp->element;
    head->next = head->next->next;
    free(tmp);
    return e;
}

//打印
void printStack(Node head) {
    head = head->next;
    while (head) {
        printf("%d ", head->element);
        head = head->next;
    }
    printf("|\n");
}

int main() {
    struct LNode head;
    initStack(&head);
    
    for (int i = 0; i < 3; ++i)
        pushStack(&head, i * 100);
    
    printStack(&head);
    
    while (!isEmpty(&head)) {
        printf("%d ", popStack(&head));
    }
    return 0;
}
