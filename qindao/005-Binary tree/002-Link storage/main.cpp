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

//二叉链表存储结构
typedef struct BiNode {
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *Bitree;

//先序遍历
Status PreOrderTraverse(Bitree T) {
    if (T == NULL)
        return OK;
    else {
        printf("%d\t", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//中序遍历
Status InOrderTraverse(Bitree T) {
    if (T == NULL)
        return OK;
    else {
        InOrderTraverse(T->lchild);
        printf("%d\t", T->data);
        InOrderTraverse(T->rchild);
    }
}

//后序遍历
Status PostOrderTraverse(Bitree T) {
    if (T == NULL)
        return OK;
    else {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d\t", T->data);
    }
}

//顺序栈的表示
#define MAXSIZE 100
typedef struct {
    Bitree *base;
    Bitree *top;
    int stacksize;
} SqStack;

//顺序栈的初始化
Status InitStack(SqStack &S) {
    S.base = (Bitree*) malloc(MAXSIZE*sizeof(Bitree));
    if (!S.base)
        return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//顺序栈的入栈
Status Push(SqStack &S, Bitree e) {
if (S.top - S.base == S.stacksize)
return ERROR;
*S.top++ = e;
return OK;
}

//顺序栈的出栈
Status Pop(SqStack &S, Bitree &e) {
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}

//顺序栈判断栈是否为空
Status SqStackEmpty(SqStack S) {
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

//中序遍历非递归算法
Status InOrderTraverse_1(Bitree T) {
    Bitree p;
    Bitree q;
    SqStack s;
    InitStack(s);
    p = T;
    while (p || SqStackEmpty(s)) {
        if (p) {
            Push(s, p);
            p = p->lchild;
        } else {
            Pop(s, q);
            printf("%c", q->data);
            p = q->rchild;
        }
    }
    return OK;
}

//顺序循环队列定义
#define MAXQSIZE 100
typedef struct {
    BiNode data[MAXSIZE];
    int front, rear;
} SqQueue;

//初始化
Status InitQueue(SqQueue &Q) {
    if (!Q.data)
        return OVERFLOW;
    Q.front = Q.rear = 0;
    return OK;
}

//循环队列入队
Status EnQueue(SqQueue &Q, BiNode &e) {
    if ((Q.rear+1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}

//循环队列出队
Status DeQueue(SqQueue &Q, BiNode &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.data[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;
    return OK;
}

//判断是否为空
Status QueueEmpty(SqQueue e) {
    if (e.rear == e.front)
        return ERROR;
    else
        return OK;
}

//二叉树的层次遍历
void LevelOrder(BiNode *b) {
    BiNode *p;
    SqQueue *qu;
    InitQueue(*qu);
    EnQueue(*qu,*b);
    while (!QueueEmpty(*qu)) {
        DeQueue(*qu, *p);
        printf("%c ", p->data);
        if (p->lchild != NULL)
            EnQueue(*qu, *p->lchild);
        if (p->rchild != NULL)
            EnQueue(*qu, *p->rchild);
        
    }
}

//按先序遍历序列建立二叉树的二叉链表
Status CreateBitree(Bitree &T) {
    ElemType ch;
    scanf(&ch);
    if (ch == '#')
        T = NULL;
    else {
        if (!(T = (BiNode*) malloc(sizeof (BiNode))))
            return OVERFLOW;
        T->data = ch;
        CreateBitree(T->lchild);
        CreateBitree(T->rchild);
    }
    return OK;
}

//复制二叉树
int Copy(Bitree T, Bitree &NewT) {
    if (T == NULL) {
        NewT = NULL;
        return 0;
    } else {
        NewT = new BiNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}

//计算二叉树深度
int Depth(Bitree T) {
    if (T == NULL)
        return 0;
    else {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if (m>n)
            return (m+1);
        else
            return (n+1);
    }
}

//计算二叉树结点总数
int NodeCount(Bitree T) {
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild)+1;
}

//线索二叉树
//结构
typedef struct BiThrNode {
    int data;
    int ltag, rtag;
    struct BiThrNode *lchild, *rchild;
} BiThrNode, *BiThrTree;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
