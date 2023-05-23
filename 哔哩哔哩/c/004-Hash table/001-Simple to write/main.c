#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct Element {   //这里用一个Element将值包装一下
    int key;    //这里元素设定为int
} * E;

typedef struct HashTable{   //这里把数组封装为一个哈希表
    E * table;
} * HashTable;

int hash(int key){   //哈希函数
    return key % SIZE;
}

void init(HashTable hashTable){   //初始化函数
    hashTable->table = malloc(sizeof(struct Element) * SIZE);
    for (int i = 0; i < SIZE; ++i)
        hashTable->table[i] = NULL;
}

void insert(HashTable hashTable, E element){   //插入操作，为了方便就不考虑装满的情况了
    int hashCode = hash(element->key), count = 0;   //首先计算元素的哈希值
    while (hashTable->table[hashCode]) {
        hashCode = hash(element->key + ++count);
    }
    hashTable->table[hashCode] = element;   //对号入座
}

_Bool find(HashTable hashTable, int key){
    int hashCode = hash(key), count = 0;   //首先计算元素的哈希值
    const int startIndex = hashCode;
    do {
        if (hashTable->table[hashCode]->key == key)
            return 1;
        hashCode = hash(key + ++count);
    } while (startIndex != hashCode && hashTable->table[hashCode]);
    return 0;
}

E create(int key){    //创建一个新的元素
    E e = malloc(sizeof(struct Element));
    e->key = key;
    return e;
}

int main() {
    struct HashTable hashTable;
    init(&hashTable);
    insert(&hashTable, create(10));
    insert(&hashTable, create(7));
    insert(&hashTable, create(13));
    insert(&hashTable, create(29));
    
    printf("%d\n", find(&hashTable, 1));
    printf("%d\n", find(&hashTable, 13));
}
