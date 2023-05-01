#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct LNode {
    E element;
    struct LNode * next;
};

typedef struct LNode * Node;

//��ʼ��
void initStack(Node head) {
    head->next = NULL;
}

//��ջ
_Bool pushStack(Node head, E element) {
    Node node = malloc(sizeof (struct LNode));
    if (node == NULL)
        return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

//�ж�
_Bool isEmpty(Node head) {
    return head->next == NULL;
}

//��ջ
E popStack(Node head) {
    Node tmp = head->next;
    E e = tmp->element;
    head->next = head->next->next;
    free(tmp);
    return e;
}

//��ӡ
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
