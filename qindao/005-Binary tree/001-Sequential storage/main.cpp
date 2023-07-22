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

//二叉树顺序存储表示
#define MAXTSIZE 100
typedef ElemType SqBiTree[MAXTSIZE];
SqBiTree bt;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
