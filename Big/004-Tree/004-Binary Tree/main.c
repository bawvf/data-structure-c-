#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

/* 用于构造二叉树********************************** */
//int index=1;
//typedef char String[24]; /*  0号单元存放串的长度 */
//String str;

typedef char TElemType;
TElemType Nil=' '; /* 字符型以空格符为空 */

//结构
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//前序遍历
void PreOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//中序遍历
void InOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

//后序遍历
void PostOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

//建立二叉数
void CreateBiTree(BiTree *T) {
    TElemType ch;
    
    scanf("%c", &ch);
    
    if (ch == '#')
        *T = NULL;
    else {
        *T = (BiTree) malloc(sizeof (BiTNode));
        if (!*T)
            exit(OVERFLOW);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
