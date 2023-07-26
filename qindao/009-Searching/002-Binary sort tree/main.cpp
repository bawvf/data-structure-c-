#include <iostream>

//Ԥ����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
//typedef char ElemType;
typedef char KeyType;
//�����������Ĵ洢�ṹ
typedef struct {
    KeyType key;
} ElemType;

typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTree T;

//�����������ĵݹ����
BSTree SearchBST(BSTree T, KeyType key) {
    if ((!T) || key == T->data.key )
        return T;
    else if (key < T->data.key)
        return SearchBST(T->lchild, key);
    else
        return SearchBST(T->rchild, key);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
