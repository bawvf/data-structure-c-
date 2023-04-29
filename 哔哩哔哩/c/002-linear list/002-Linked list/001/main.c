#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

//ͷ���
//struct LinkedList {
//    Node head;
//};

//��ʼ������
void initList(Node node) {
    node->next = NULL;
}

//��������
_Bool insertList(Node head, E element, int index) {
    if (index < 1)
        return 0;
    while (--index) {
        head = head->next;
        if (head == NULL)
            return 0;
    }

    Node node = malloc(sizeof(struct ListNode));
    if(node == NULL)
        return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;

    return 1;
}

//ɾ������
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
    head->next = head->next->next;
    free(tmp);

    return 1;
}

//��ȡ��Ӧλ���ϵ�Ԫ��
E * getList(Node head, int index) {
    if (index < 1)
        return 0;
    do {
        head = head->next;
        if (head == NULL)
            return 0;
    } while (--index);

    return &head->element;
}

//���Ҷ�ӦԪ�ص�λ��
int findList(Node head, E element) {
    head = head->next;
    int i = 1;
    while (head) {
        if (head->element == element)
            return i;
        head = head->next;
        i++;
    }
    return -1;
}

//��ӡ��
void printList(Node head) {   //ͷ��㲻������
    while (head->next) {
        head = head->next;
        printf("%d ", head->element);
    }
}

//������ĳ���
int sizeList(Node head) {
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}

int main() {
//    ͷ���
    struct ListNode head;
    initList(&head);

    for (int i = 1; i <= 3; ++i)
        insertList(&head, i * 100, i);
//    deleteList(&head, 3);
    printList(&head);

//    printf("%d", *getList(&head, 3));

    printf("%d ", findList(&head,100));

    printf("%d ", sizeList(&head));

    return 0;
}
