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

//˳�������
#define MAXSIZE 100

typedef struct {
    ElemType *elem;
    int length;
}SqList;

//���Ա�L�ĳ�ʼ��
Status InitList_Sq(SqList &L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) exit(OVERFLOW);    //�洢����ʧ��
    L.length = 0;
    return OK;
}

//�������Ա�
void DestroyList(SqList &L) {
    if (L.elem)
        delete L.elem;      //�ͷŴ洢�ռ�
}

//������Ա�
void ClearList(SqList &L) {
    L.length = 0;
}

//�����Ա�ĳ���
int GetLength(SqList L) {
    return (L.length);
}

//�ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList L) {
    if (L.length == 0)
        return 1;
    else
        return 0;
}

//˳����ȡֵ(����λ��i��ȡ��Ӧλ������Ԫ�ص�����)
int GetElem(SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i-1];
    
    return OK;
}

//˳���Ĳ���
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i+1;
    return 0;
}

//˳���Ĳ���
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length == MAXSIZE)
        return ERROR;
    for (int j = L.length = 1; j >= i - 1; j--)
        L.elem[j+1] = L.elem[j];
    L.elem[i-1] = e;
    L.length++;
    return OK;
}

//˳����ɾ��
Status ListDelete_Sq(SqList &L, int i) {
    if ((i<1)||(i>L.length))
        return ERROR;
    for (int j = i; j <= L.length-1; j++)
        L.elem[j-1] = L.elem[j];
    L.length--;
    return OK;
}

//�����ĺϲ�
void MergeList_Sq(SqList LA, SqList LB, SqList &LC) {
    ElemType *pa = LA.elem;
    ElemType *pb = LB.elem;
    LC.length = LA.length + LB.length;
    LC.elem = new ElemType[LC.length];
    ElemType *pc = LC.elem;
    ElemType *pa_last = LA.elem + LA.length-1;
    ElemType *pb_last = LB.elem + LB.length-1;
    
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while (pa <= pa_last)
        *pc++ = *pa++;
    while (pb <= pb_last)
        *pc++ = *pb++;
}


int main() {

//    SqList *L;
//    L->elem = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
