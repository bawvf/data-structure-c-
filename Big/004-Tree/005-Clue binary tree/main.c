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

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0表示指向左右孩子指针, */
/* Thread==1表示指向前驱或后继的线索 */

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiTree;

//中序遍历
BiTree pre;

void InThreading(BiTree p) {
    if (p) {
        InThreading(p->lchild);
        if (!p->lchild) {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild) {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

//遍历
Status InOrderTraverse_Thr(BiTree T) {
    BiTree p;
    p = T->lchild;
    while (p != T) {
        while (p->LTag == Link)
            p = p->lchild;
        printf("%c", p->data);
        while (p->RTag == Thread && p->rchild != T) {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    return OK;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
