#include <iostream>

//Ԥ����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

typedef struct Londe {
    ElemType data;
    struct Londe *next;
}LNode, *LinkList;

//������ĳ�ʼ��
Status InitList_L(LinkList &L) {
    L = (LinkList) malloc(sizeof (LNode));
    L->next = NULL;
    return OK;
}

//�ж������Ƿ�Ϊ��
int ListEmpty(LinkList L) {
    if (L->next)
        return 0;
    else
        return 1;
}

//�����������
Status DestroyList_L(LinkList &L) {
    Londe *p;
    while (L) {
        p = L;
        L = L->next;
    }
    return OK;
}

//�������
Status ClearList(LinkList &L) {
    Londe *p, *q;
    p = L->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    return OK;
}

//������ı�
int ListLength_L(LinkList L) {
    LinkList p;
    p = L->next;
    int i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

//ȡֵһȡ�������е�i��Ԫ�ص�����
Status GetElem_L(LinkList L, int i, ElemType &e) {
    LinkList p = L->next;
    int j = 1;
    while (p&&j<i) {
        p = p->next;
        ++j;
    }
    if (!p||j>i)
        return ERROR;
    e = p->data;
    return OK;
}

//��ֵ����-����ָ�����ݻ�ȡ���������ڵ�λ��(��ַ)
LNode *LocateElem_L(LinkList L, ElemType e) {
    LinkList p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

int LocateElem_L_2(LinkList L, ElemType e) {
    LinkList p;
    p = L->next;
    int j = 1;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    if (p)
        return j;
    else
        return 0;
}

//����-�ڵ�i�����ǰ����ֵΪe���½��
Status ListInsert_L(LinkList &L, int i, ElemType e) {
    LinkList p = L;
    int j = 0;
    while (p && j<i-1) {
        p = p->next;
        ++j;
    }
    if (!p || j>i-1)
        return ERROR;
    LinkList S = (LinkList) malloc(sizeof (LNode));
    S->data = e;
    S->next = p->next;
    p->next = S;
    return OK;
}

//ɾ��-ɾ����i�����
Status ListDelete_L(LinkList &L, int i, ElemType &e) {
    LinkList p = L;
    int j = 0;
    while (p->next && j<i-1) {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j>i-1)
        return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

//ͷ�巨
void CreateList_H(LinkList &L, int n) {
    L = (LinkList)malloc(sizeof (LNode));
    L->next = NULL;
    for (int i = n; i > 0; --i) {
        LinkList P = (LNode*) malloc(sizeof (LNode));
        scanf(&P->data);
        P->next = L->next;
        L->next = P;
    }
}

//β�巨
void CreateList_R(LinkList &L, int n) {
    L = (LinkList)malloc(sizeof (LNode));
    L->next = NULL;
    LinkList r = L;
    for (int i = 0; i < n; ++i) {
        LinkList P = (LNode*) malloc(sizeof (LNode));
        scanf(&P->data);
        P->next = NULL;
        r->next = P;
        r = P;
    }
    
}

void union_(LinkList &La, LinkList &Lb, &e) {
    int La_len = ListLength_L(La);
    int Lb_len = ListLength_L(Lb);
    
    for (int i=1; i<=Lb_len; i++) {
        GetElem_L(Lb, i, e);
        if(!LocateElem_L(La, e))
            ListInsert_L(&La, ++La_len, e);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
