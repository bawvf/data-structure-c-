#include <iostream>
#include <commctrl.h>

//Ԥ����
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
typedef char VerTexType;    //�����ַ���
typedef int ArcType;        //�ߵ�����

//�߽ṹ
#define MVNum 100
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    int info;   //�洢������Ϣ
} ArcNode;

//ͼ���ڽӱ�洢��ʾ
typedef struct VNode {
    VerTexType data;
    ArcNode *firstarc;
} VNode, AdjList[MVNum];

//ͼ�ṹ
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

//�����ڽӱ��ʾ������������
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
