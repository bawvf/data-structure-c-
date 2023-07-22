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

//双亲表示法
typedef struct PTNode {
    ElemType data;
    int parent;
} PTNode;

//树结构
#define MAX_TREE_SIEZ 100
typedef struct {
    PTNode nodes[MAX_READ_LOCKS];
    int r, n;   //根节点的位置和结点个数
} PTree;

//孩子表示法

//孩子结点结构
typedef struct CTNode {
    int child;
    struct CTNode *next;
} *ChildPtr;

//双亲结点结构
typedef struct {
    ElemType data;
    ChildPtr firstchild;
} CTBox;

//树结构
typedef struct {
    CTBox nodes[MAX_READ_LOCKS];
    int n, r;   //结点数和根结点的位置
} CTree;

//孩子兄弟表示法
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
