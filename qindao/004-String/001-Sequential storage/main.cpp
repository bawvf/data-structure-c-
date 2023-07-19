#include <iostream>

//预定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

//串的顺序存储结构
#define MAXLEN 255
typedef struct {
    char ch[MAXLEN+1];
    int length;
} SString;

//BF算法描述
int Index_BF(SString S, SString T, int pos) {
    int i=pos, j=1;
    while (i<=S.length && j<=T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i-j+2;
            j = 1;
        }
    }
    if (j >= T.length)
        return i-T.length;
    else
        return 0;
}

//KMP算法
int Index_KMP(SString S, SString T, int pos) {
    int i=pos, j=1;
    while (i<=S.length && j<=T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j >= T.length)
        return i-T.length;
    else
        return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
