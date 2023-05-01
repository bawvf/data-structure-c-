#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode * Node;

//��ʼ��ͷ���
void initList(Node head) {
    head->next = head->prev = NULL;
}

//����Ԫ��
_Bool insertList(Node head, E element, int index) {
    if (index < 1)
        return 0;
    while (--index) {
        head = head->next;
        if (head == NULL)
            return 0;
    }
    Node  node = malloc(sizeof (struct ListNode));
    if (node == NULL)
        return 0;

    node->element = element;
    if (head->next != NULL) {
        //    �������
        node->next = head->next;
        head->next->prev = node;
    } else {
        node->next = NULL;
    }

//    ǰ�����
    head->next = node;
    node->prev = head;

    return 1;
}

//ɾ��Ԫ��
_Bool deleteList(Node head, int index) {
    if (index < 1)
        return 0;
    while (--index) {
        head = head->next;
        if (head == NULL)
            return 0;
    }
    if (head->next == NULL)
        return 0;
    
    Node tmp = head->next;
    if (head->next->next) {
        head->next = head->next->next;
        head->next->next->prev = head;
    } else {
        head->next = NULL;
    }
    
    free(tmp);
}

int main() {
    struct ListNode head;
    initList(&head);

//    �������Ԫ��
    for (int i = 1; i <= 5; ++i)
        insertList(&head, i * 100, i);
    
    deleteList(&head, 1);
    
//    �������
    Node node = &head;
    do {
        node = node->next;
        printf("%d-> ", node->element);
    } while (node->next != NULL);
    
    printf("\n");
//    �������
    do {
        printf("%d-> ", node->element);
        node = node->prev;
        
    } while (node->prev != NULL);
    return 0;
}
