#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode head) {
    struct ListNode * newHead = NULL, * tmp;
    while (head) {
        tmp = head.next;
        head.next = newHead;
        newHead = head;
        head = tmp;
    }
    return newHead;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
