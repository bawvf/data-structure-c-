#include <iostream>

//预定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//记录序列以顺序表存储
#define MAXSIZE 20
typedef int KeyType;

//定义每个记录(数据元素)的结构
typedef struct {
    KeyType key;
} RedType;

typedef struct {
    RedType r[MAXSIZE+1];
    int length;
} SqList;

//插入排序

//1.直接插入排序
void InsertSort(SqList &L) {
    int i, j;
    for (i = 2; i <= L.length; ++i) {
        if (L.r[i].key < L.r[i-1].key) {
            L.r[0] = L.r[i];
            for (j = i-1; L.r[0].key < L.r[j].key; --j) {
                L.r[j+1] = L.r[j];
            }
            L.r[j+1] = L.r[0];
        }
    }
}

//2.折半插入排序
void BInsertSort(SqList &L) {
    int i, j, low, mid, high;
    for (i = 2; i <= L.length; ++i) {
        L.r[0] = L.r[i];
        low = 1, high = i-1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (L.r[0].key < L.r[mid].key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j=i-1; j>=high+1; --j)
            L.r[j+1] = L.r[j];
        L.r[high+1] = L.r[0];
    }
}

//3.希尔排序
void ShellInsert(SqList &L, int dk) {
    int i, j;
    for (i = dk+1; i < L.length; ++i) {
        if (L.r[i].key < L.r[i-dk].key) {
            L.r[0] = L.r[i];
            for (j = i-dk; j > 0 && (L.r[0].key<L.r[j].key); j=j-dk)
                L.r[j+dk] = L.r[j];
            L.r[j+dk] = L.r[0];
        }
        
    }
}

//交换排序
//1.冒泡排序
void bubble_sort(SqList &L) {
    int m, n, i, j;
    RedType x;
    for (m = 1; m <= n-1; m++) {
        for (j = 1; j <= n-m; j++)
            if (L.r[j].key > L.r[j+1].key) {
                x = L.r[j];
                L.r[j] = L.r[j+1];
                L.r[j+1] = x;
            }
    }
}

//1.冒泡排序_改
void bubble_sort_1(SqList &L) {
    int m, n, i, j, flag=1;
    RedType x;
    for (m = 1; m <= n-1 && flag==1; m++) {
        flag = 0;
        for (j = 1; j <= n-m; j++)
            if (L.r[j].key > L.r[j+1].key) {
                flag = 1;
                x = L.r[j];
                L.r[j] = L.r[j+1];
                L.r[j+1] = x;
            }
    }
}

//2.快速排序
int Partition(SqList &L, int low, int high) {
    int pivotkey;
    L.r[0] = L.r[low];
    pivotkey = L.r[low].key;
    while (low < high) {
        while (low < high && L.r[high].key >= pivotkey)
            --high;
        while (low < high && L.r[low].key <= pivotkey)
            ++low;
    }
    L.r[low] = L.r[0];
    return low;
}

void QSort(SqList &L, int low, int high) {
    if (low < high) {
        int pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc-1);
        QSort(L, pivotloc+1, high);
    }
}

//3.简单选择排序
void SelectSort(SqList &L) {
    int t;
    for (int i = 1; i < L.length; ++i) {
        int k = i;
        for (int j = i+1; j < L.length; ++j)
            if (L.r[j].key < L.r[k].key)
                k = j;
        if (k != i) {
            t = L.r[i].key;
            L.r[i].key = L.r[k].key;
            L.r[k].key = t;
        }
    }
}

//4.归并排序


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
