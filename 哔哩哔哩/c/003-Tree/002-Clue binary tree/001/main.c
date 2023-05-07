#include <stdio.h>
#include <stdlib.h>

typedef char E;

typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int leftTag, rightTag;
} * Node;

Node creatNode(E element) {
    Node node = malloc(sizeof (struct TreeNode));
    node->left = node->right = NULL;
    node->leftTag = node->rightTag = 0;
    node->element = element;
    return node;
}

//中序遍历
Node pre = NULL;
void inOrderTheaded(Node root) {
    if (root == NULL)
        return;
    if (root->leftTag  == 0)
        inOrderTheaded(root->left);
    
    if (root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    
    pre = root;
    
    if (root->rightTag == 0)
    inOrderTheaded(root->right);
}

//前序遍历
void inOrder(Node root) {
    while (root) {
        printf("%c", root->element);
        if (root->leftTag == 0)
            root = root->left;
        else
            root = root->right;
    }
}

int main() {
    Node a = creatNode('A');
    Node b = creatNode('B');
    Node c = creatNode('C');
    Node d = creatNode('D');
    Node e = creatNode('E');
    
    a->left = b;
    b->left = d;
    a->right = c;
    b->right = e;
    
    preOrderTheaded(a);
    inOrder(a);
    
    return 0;
}
