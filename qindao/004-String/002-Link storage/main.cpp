#include <iostream>

//Ԥ����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//������ʽ�洢�ṹ---�����ṹ
#define CHUNKSIZE 80
typedef struct Chunk {
    char ch[CHUNKSIZE];
    struct Chunk *next;
} Chunk;

typedef struct {
    Chunk *head, *tail;
    int curlen;
} LString;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
