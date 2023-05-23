#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct LNode {
    int key;
    struct LNode * next;
} * Node;

typedef struct HashTable {
    struct LNode * table;
} * HashTable;

void init(HashTable hashTable) {
    hashTable->table = malloc(sizeof (struct LNode) * SIZE);
    for (int i = 0; i < SIZE; ++i) {
        hashTable->table[i].key = -1;
        hashTable->table[i].next = NULL;
    }
}

int hash(int key) {
    return key % SIZE;
}

Node createNode(int key) {
    Node node = malloc(sizeof (struct LNode));
    node->key = key;
    node->next = NULL;
    return node;
}

void insert(HashTable hashTable, int key) {
    int hashCode = hash(key);
    Node head = hashTable->table + hashCode;
    while (head->next != NULL)
        head = head->next;
    head->next = createNode(key);
}

_Bool find(HashTable hashTable, int key) {
    int hashCode = hash(key);
    Node head = hashTable->table + hashCode;
    while (head->next && head->key != key)
        head = head->next;
    return head->key == key;
}

int main() {
    struct HashTable table;
    init(&table);
    return 0;
}
