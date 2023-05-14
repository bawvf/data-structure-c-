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

#define MAXSIZE 1000 /* 存储空间初始分配量 */

typedef int Status;           /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char ElemType;        /* ElemType类型根据实际情况而定，这里假设为char */

//存储结构
typedef struct DulNode {
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
} DulNode, *DuLinkList;



int main() {
    printf("Hello, World!\n");
    return 0;
}
