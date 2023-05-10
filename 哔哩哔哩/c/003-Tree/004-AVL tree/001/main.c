#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int height;
} * Node;

Node createNode(E element) {
    Node node = malloc(sizeof (struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    node->height = 1;
    return node;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(Node root) {
    if (root == NULL)
        return 0;
    return root->height;
}

//左旋
Node leftRotation(Node root) {  //传入原本根节点 传出新的根结点
    Node newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    
    return newRoot;
}
//右旋
Node rightRotation(Node root) {  //传入原本根节点 传出新的根结点
    Node newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    
    return newRoot;
}

//L-R
Node leftRightRoation(Node root) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

//R-L
Node rightLeftRoation(Node root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

//插入
Node insert(Node root, E element) {
    if (root == NULL) {
        root = createNode(element);
    } else if (root->element > element) {
        root->left = insert(root->left, element);
        if (getHeight(root->left) - getHeight(root->right) > 1) {
            if (root->left->element > element)
                root = rightRotation(root);
            else
                root = leftRightRoation(root);
        }
    } else if (root->element < element) {
        root->right = insert(root->right, element);
        if (getHeight(root->left) - getHeight(root->right) < -1) {
            if (root->right->element < element)
                root = leftRotation(root);
            else
                root = rightRotation(root);
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

int main() {
    Node root = NULL;
    while (1) {
        E e;
        scanf("%d", &e);
        root = insert(root, e);
        printf("");
    }
    return 0;
}
