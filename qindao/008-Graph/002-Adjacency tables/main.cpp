#include <iostream>
#include <commctrl.h>

//预定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

#define MaxInt 32767;
#define MVNum 100
typedef char VerTexType;    //顶点字符型
typedef int ArcType;        //边的类型

//边结构
#define MVNum 100
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    int info;   //存储其他信息
} ArcNode;

//图的邻接表存储表示
typedef struct VNode {
    VerTexType data;
    ArcNode *firstarc;
} VNode, AdjList[MVNum];

//图结构
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

//采用邻接表表示法创建无向网
Status CreateUDG(ALGraph &G) {
    int v1, v2, i, j;
    scanf("", &G.vexnum);
    scanf("", &G.arcnum);
    for (i = 0; i < G.vexnum; ++i) {
        scanf(&G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    for (j = 0; j < G.arcnum; ++j) {
        scanf("", &v1, &v2);
//        i = LocateVex(G, v1);
//        j = LocateVex(G, v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
    }
    return OK;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
