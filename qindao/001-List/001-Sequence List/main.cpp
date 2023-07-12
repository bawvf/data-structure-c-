#include <iostream>

//预定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

//顺序表类型
#define MAXSIZE 100

typedef struct {
    ElemType *elem;
    int length;
}SqList;

//线性表L的初始化
Status InitList_Sq(SqList &L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) exit(OVERFLOW);    //存储分配失败
    L.length = 0;
    return OK;
}

//销毁线性表
void DestroyList(SqList &L) {
    if (L.elem)
        delete L.elem;      //释放存储空间
}

//清空线性表
void ClearList(SqList &L) {
    L.length = 0;
}

//求线性表的长度
int GetLength(SqList L) {
    return (L.length);
}

//判断线性表L是否为空
int IsEmpty(SqList L) {
    if (L.length == 0)
        return 1;
    else
        return 0;
}

//顺序表的取值(根据位置i获取相应位置数据元素的内容)
int GetElem(SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i-1];
    
    return OK;
}

//顺序表的查找
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i+1;
    return 0;
}

//顺序表的插入
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

//顺序表的删除
Status ListDelete_Sq(SqList &L, int i) {
    if ((i<1)||(i>L.length))
        return ERROR;
    for (int j = i; j <= L.length-1; j++)
        L.elem[j-1] = L.elem[j];
    L.length--;
    return OK;
}


int main() {
    
//    SqList *L;
//    L->elem = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
