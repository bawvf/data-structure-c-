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

//˫�ױ�ʾ��
typedef struct PTNode {
    ElemType data;
    int parent;
} PTNode;

//���ṹ
#define MAX_TREE_SIEZ 100
typedef struct {
    PTNode nodes[MAX_READ_LOCKS];
    int r, n;   //���ڵ��λ�úͽ�����
} PTree;

//���ӱ�ʾ��

//���ӽ��ṹ
typedef struct CTNode {
    int child;
    struct CTNode *next;
} *ChildPtr;

//˫�׽��ṹ
typedef struct {
    ElemType data;
    ChildPtr firstchild;
} CTBox;

//���ṹ
typedef struct {
    CTBox nodes[MAX_READ_LOCKS];
    int n, r;   //������͸�����λ��
} CTree;

//�����ֵܱ�ʾ��
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
