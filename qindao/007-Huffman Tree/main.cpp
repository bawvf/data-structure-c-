#include <iostream>
#include <cstring>

//预定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//结点类型定义
typedef struct {
    int weight;
    int parent, lch, rch;
} HTNode, *HuffmanTree;

//实现
void Select(HuffmanTree HT, int i, int *s1, int *s2) {
    for (int j = 1; j <= i; ++j) {
        if (HT[j].parent == 0) {
            if (HT[j].weight < *s1) {
                *s1 = HT[j].weight;
                *s2 = *s1;
            }
            if (*s2 == 99) {
                for (int k = 1; k <= i; ++k) {
                    if (HT[k].parent == 0 && HT[k].weight != *s1) {
                        if (HT[j].weight < *s2) {
                            *s2 = HT[j].weight;
                            *s2 = *s1;
                        }
                    }
                }
            }
        }
    }
}


void CreatHuffmanTree(HuffmanTree HT, int n) {
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    HT = (HTNode *) malloc(sizeof(HTNode));
    for (int i = 1; i < m; ++i) {
        HT[i].lch = 0;
        HT[i].rch = 0;
        HT[i].parent = 0;
    }
    for (int i = 1; i < n; ++i) {
        printf("%d\t", HT[i].weight);
    }
    
    for (int i = n + 1; i <= m; ++i) {
        int s1 = 99;
        int s2 = 99;
        Select(HT, i - 1, &s1, &s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lch = s1;
        HT[i].rch = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

//编码
void CreatHuffmanCode(HuffmanTree HT, int n) {
    char HC[n+1];
    char *cd = new char [n];
    cd[n-1] = '\0';
    for (int i = 1; i <= n; ++i) {
        int start = n-1;
        int c = i;
        int f = HT[i].parent;
        while (f != 0) {
            --start;
            if (HT[f].lch == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char [n-start];
        strcpy(HC[i], &cd[start]);
    }
    delete cd;
    
    
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}