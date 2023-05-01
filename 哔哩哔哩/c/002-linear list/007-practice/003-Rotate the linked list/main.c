#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * rotateRight(struct ListNode * head, int k) {
    if (head == NULL || k == 0)
        return head;
    int len = 1;
    struct ListNode * node = head;
    while (node->next) {
        node = node->next;
        len++;
    }
    
    if (len == k)
        return head;
    
    node->next = head;
    int i = len - k % len;
    
    while (--i)
        head = head->next;
    struct ListNode * res = head->next;
    head->next = NULL;
    return res;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
