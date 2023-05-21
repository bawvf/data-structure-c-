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

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0��ʾָ�����Һ���ָ��, */
/* Thread==1��ʾָ��ǰ�����̵����� */

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiTree;

//�������
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

//����
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
