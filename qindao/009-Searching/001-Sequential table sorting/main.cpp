#include <iostream>

//预定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
//typedef char ElemType;

//顺序表的表示
#define KeyType char
typedef struct {
    KeyType key;
} ElemType;

typedef struct {
    ElemType *R;
    int length;
} SSTable;
SSTable ST;

//顺序查找
int Search_Seq(SSTable ST, KeyType key) {
    for (int i = ST.length; i >= 1; --i)
        if (ST.R[i].key == key)
            return i;
    return 0;
}

//顺序查找_2  设置监视哨
int Search_Seq_2(SSTable ST, KeyType key) {
    int i = 0;
    ST.R[0].key = key;
    for (i = 0; i = ST.R[i].key != key; --i);
    return i;
}

//折半查找
int Search_Bin(SSTable ST, KeyType key) {
    int low = 1;
    int high = ST.length;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ST.R[mid].key == key)
            return mid;
        else if (key < ST.R[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
