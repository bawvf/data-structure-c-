#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct Element {   //������һ��Element��ֵ��װһ��
    int key;    //����Ԫ���趨Ϊint
} * E;

typedef struct HashTable{   //����������װΪһ����ϣ��
    E * table;
} * HashTable;

int hash(int key){   //��ϣ����
    return key % SIZE;
}

void init(HashTable hashTable){   //��ʼ������
    hashTable->table = malloc(sizeof(struct Element) * SIZE);
    for (int i = 0; i < SIZE; ++i)
        hashTable->table[i] = NULL;
}

void insert(HashTable hashTable, E element){   //���������Ϊ�˷���Ͳ�����װ���������
    int hashCode = hash(element->key), count = 0;   //���ȼ���Ԫ�صĹ�ϣֵ
    while (hashTable->table[hashCode]) {
        hashCode = hash(element->key + ++count);
    }
    hashTable->table[hashCode] = element;   //�Ժ�����
}

_Bool find(HashTable hashTable, int key){
    int hashCode = hash(key), count = 0;   //���ȼ���Ԫ�صĹ�ϣֵ
    const int startIndex = hashCode;
    do {
        if (hashTable->table[hashCode]->key == key)
            return 1;
        hashCode = hash(key + ++count);
    } while (startIndex != hashCode && hashTable->table[hashCode]);
    return 0;
}

E create(int key){    //����һ���µ�Ԫ��
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
