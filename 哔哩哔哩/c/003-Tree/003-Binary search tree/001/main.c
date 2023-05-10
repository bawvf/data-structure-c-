#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
} * Node;

Node createNode(E element) {
    Node node = malloc(sizeof (struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    return node;
}

//����Ԫ��
Node insert(Node root, E element) {
    if (root) {
        if (root->element > element)
            root->left = insert(root->left, element);
        else if (root->element < element)
            root->right = insert(root->right, element);
    } else
        root = createNode(element);
    
    return root;
}

//����Ԫ��
Node find(Node root, E target) {
    while (root) {
        if (root->element > target)
            root->left;
        else if (root->element < target)
            root->right;
        else
            return root;
    }
    return NULL;
}

//�������ֵ
Node findMax(Node root) {
    while (root && root->right)
        root = root->right;
    return root;
}

//ɾ��ֵ
Node delete(Node root, E target) {
    if (root == NULL)
        return NULL;
    if (root->element > target)
        root->left = delete(root->left, target);
    else if (root->element < target)
        root->right = delete(root->right, target);
    else {
        if (root->left && root->right) {
            Node max = findMax(root->left);
            root->element = max->element;
            root->left = delete(root->left, root->element);
        } else {
            Node tmp = root;
            if (root->right) {
                root = root->right;
            } else {
                root = root->left;
            }
            free(tmp);
        }
    }
    return root;
}

//�������
void inOrder(Node root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d", root->element);
    inOrder(root->right);
}

int main() {
    Node root = insert(NULL,18);
    
    insert(root, 10);
    insert(root, 20);
    insert(root, 7);
    insert(root, 5);
    insert(root, 22);
    insert(root, 9);
    inOrder(root);
    return 0;
}
