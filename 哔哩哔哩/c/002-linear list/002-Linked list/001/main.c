#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

//头结点
//struct LinkedList {
//    Node head;
//};

//初始化函数
void initList(Node node) {
    node->next = NULL;
}

//插入数据
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

//删除数据
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

//获取对应位置上的元素
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

//查找对应元素的位置
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

//打印表
void printList(Node head) {   //头结点不存数据
    while (head->next) {
        head = head->next;
        printf("%d ", head->element);
    }
}

//求链表的长度
int sizeList(Node head) {
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}

int main() {
//    头结点
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
