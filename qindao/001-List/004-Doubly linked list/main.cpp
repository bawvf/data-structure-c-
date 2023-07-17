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

//�ṹ
typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

//ȡֵһȡ�������е�i��Ԫ�ص�����
DuLNode * GetElemp_DuL(DuLinkList &L, int i) {
    DuLinkList p = L->next;
    int j = 1;
    while (p&&j<i) {
        p = p->next;
        ++j;
    }
    if (!p||j>i)
        return ERROR;
}

//˫������Ĳ���
int ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
    DuLinkList p;
    if(!(p = GetElemp_DuL(L,i)))
        return ERROR;
    DuLinkList s = (DuLinkList) malloc(sizeof (DuLNode));
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

//˫�������ɾ��
int ListDelete_Dul(DuLinkList &L, int i, ElemType &e) {
    DuLinkList p;
    if (!(p = GetElemp_DuL(L,i)))
        return ERROR;
    e = p ->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
