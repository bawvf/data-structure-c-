#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

//���Ա�ĵ�����洢�ṹ
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

//������Ķ�ȡ
Status GetElem(LinkList L, ElemType *e) {
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while (p && j < 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > 1)
        return ERROR;
    *e = p->data;
    
    return OK;
}

//������Ĳ���
Status ListInsert(LinkList *L, int i, ElemType e) {
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > 1)
        return ERROR;
    
    s = (LinkList) malloc(sizeof (Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}

//�������ɾ��
Status ListDelete(LinkList *L, int i, ElemType *e) {
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i)
        return ERROR;
    
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    
    return OK;
}

//������Ĵ���-ͷ����
void CreateListHead(LinkList *L, int n) {
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList) malloc(sizeof (Node));
    (*L)->next = NULL;
    
    for (i = 0; i < n; i++) {
        p = (LinkList) malloc(sizeof (Node));
        p->data = rand()%100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

//������Ĵ���-β����
void CreateListTail(LinkList *L, int n) {
    LinkList p, r;
    int i;
    srand(time(0));
    *L = (LinkList) malloc(sizeof (Node));
    r = *L;
    for (i = 0; i < n; i++) {
        p = (Node *) malloc(sizeof (Node));
        p->data = rand()%100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

//�����������ɾ��
Status ClearList(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
