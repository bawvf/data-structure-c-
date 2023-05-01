#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode * node = head;
    while (node->next != NULL) {
        if (node->val == node->next->val) {
            node->next = node->next->next;
        } else {
            node = node->next;
        }
    }
    return head;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
