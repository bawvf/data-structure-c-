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

//��������洢�ṹ
typedef struct BiNode {
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *Bitree;

//�������
Status PreOrderTraverse(Bitree T) {
    if (T == NULL)
        return OK;
    else {
        printf("%d\t", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//�������
Status InOrderTraverse(Bitree T) {
    if (T == NULL)
        return OK;
    else {
        InOrderTraverse(T->lchild);
        printf("%d\t", T->data);
        InOrderTraverse(T->rchild);
    }
}

//�������
Status PostOrderTraverse(Bitree T) {
    if (T == NULL)
        return OK;
    else {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d\t", T->data);
    }
}

//˳��ջ�ı�ʾ
#define MAXSIZE 100
typedef struct {
    Bitree *base;
    Bitree *top;
    int stacksize;
} SqStack;

//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S) {
    S.base = (Bitree*) malloc(MAXSIZE*sizeof(Bitree));
    if (!S.base)
        return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//˳��ջ����ջ
Status Push(SqStack &S, Bitree e) {
if (S.top - S.base == S.stacksize)
return ERROR;
*S.top++ = e;
return OK;
}

//˳��ջ�ĳ�ջ
Status Pop(SqStack &S, Bitree &e) {
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}

//˳��ջ�ж�ջ�Ƿ�Ϊ��
Status SqStackEmpty(SqStack S) {
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

//��������ǵݹ��㷨
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

//˳��ѭ�����ж���
#define MAXQSIZE 100
typedef struct {
    BiNode data[MAXSIZE];
    int front, rear;
} SqQueue;

//��ʼ��
Status InitQueue(SqQueue &Q) {
    if (!Q.data)
        return OVERFLOW;
    Q.front = Q.rear = 0;
    return OK;
}

//ѭ���������
Status EnQueue(SqQueue &Q, BiNode &e) {
    if ((Q.rear+1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}

//ѭ�����г���
Status DeQueue(SqQueue &Q, BiNode &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.data[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;
    return OK;
}

//�ж��Ƿ�Ϊ��
Status QueueEmpty(SqQueue e) {
    if (e.rear == e.front)
        return ERROR;
    else
        return OK;
}

//�������Ĳ�α���
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

//������������н����������Ķ�������
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

//���ƶ�����
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

//������������
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

//����������������
int NodeCount(Bitree T) {
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild)+1;
}

//����������
//�ṹ
typedef struct BiThrNode {
    int data;
    int ltag, rtag;
    struct BiThrNode *lchild, *rchild;
} BiThrNode, *BiThrTree;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
