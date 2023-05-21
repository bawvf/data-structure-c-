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

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

/* ���ڹ��������********************************** */
//int index=1;
//typedef char String[24]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */
//String str;

typedef char TElemType;
TElemType Nil=' '; /* �ַ����Կո��Ϊ�� */

//�ṹ
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//ǰ�����
void PreOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//�������
void InOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

//�������
void PostOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

//����������
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
