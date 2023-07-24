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

//�ڽӾ���Ĵ洢��ʾ
#define MaxInt 32767;
#define MVNum 100
typedef char VerTexType;    //�����ַ���
typedef int ArcType;        //�ߵ�����

typedef struct {
    VerTexType vexs[MVNum];   //�����
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;         //��ǰ������ͱ���
} AMGraph;

//�����ڽӾ����ʾ������������
int LocateVex(AMGraph G, VerTexType u) {
    for (int i = 0; i < G.vexnum; ++i)
        if (u == G.vexs[i])
            return i;
    return -1;
}

Status CreatUDN(AMGraph &G) {
    char v1, v2;
    int w, i, j;
    scanf("����:", &G.vexnum);
    scanf("����:", &G.arcnum);
    for (int i = 0; i < G.vexnum; ++i)
        scanf("", &G.vexs);
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;
    for (int k = 0; k < G.arcnum; ++k) {
        scanf(&v1);
        scanf(&v2);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}

//�����ڽӾ����ʾͼ�����������������
void DFS(AMGraph G, int v) {
    bool visited[MVNum];
    printf("%c", v);
    visited[v] = true;
    for (int i = 0; i < G.vexnum; ++i) {
        if ((G.arcs[v][i] != 0) && (!visited[w]))
            DFS(G, i);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
