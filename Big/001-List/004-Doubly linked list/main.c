#include "string.h"
#include "ctype.h"

#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* �洢�ռ��ʼ������ */

typedef int Status;           /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char ElemType;        /* ElemType���͸���ʵ������������������Ϊchar */

//�洢�ṹ
typedef struct DulNode {
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
} DulNode, *DuLinkList;



int main() {
    printf("Hello, World!\n");
    return 0;
}
