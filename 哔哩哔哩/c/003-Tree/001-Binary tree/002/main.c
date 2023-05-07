#include <stdio.h>
#include <stdlib.h>

typedef char E;

struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef struct TreeNode * Node;

//------------- ջ -------------------
typedef Node T;   //����ջ��Ԫ�����Ͷ���Ϊ�����Node��Ҳ���Ƕ��������ָ��

struct StackNode {
    T element;
    struct StackNode * next;
};

typedef struct StackNode * SNode;  //���������ΪSNode����Ȼ�������ͻ�˾Ͳ�����

void initStack(SNode head){
    head->next = NULL;
}

_Bool pushStack(SNode head, T element){
    SNode node = malloc(sizeof(struct StackNode));
    if(node == NULL) return 0;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;
}

_Bool isEmpty(SNode head){
    return head->next == NULL;
}

T popStack(SNode head){
    SNode top = head->next;
    head->next = head->next->next;
    T e = top->element;
    free(top);
    return e;
}

//-------------------------------------

void preOrder(Node root){
    struct StackNode stack;  //ջ�ȸ����
    initStack(&stack);
    while (root || !isEmpty(&stack)){   //����������ֻ�е�ջ�ղ��ҽڵ�ΪNULLʱ����ֹѭ��
        while (root) {    //�������ǵ�˼·���Ȳ��ϱ�����������ֱ��û��Ϊֹ
            pushStack(&stack, root);   //;��ÿ����һ����㣬�ͽ���㶪��ջ��
            printf("%c", root->element);   //Ȼ���ӡ��ǰ���Ԫ��ֵ
            root = root->left;  //����������һ�����ӽ��
        }
        root = popStack(&stack);  //����ǰ���ѭ������ȷ������ȫ�������ˣ����ž�����������
        root = root->right;  //�õ��Һ��ӣ�������Һ��ӣ���һ�ֻ��ظ�����Ĳ��裻���û���Һ�����ô�����root�ͱ���ֵΪNULL�ˣ���һ�ֿ�ʼ��ֱ�����������while��������ջ��һ���������������
    }
}

void inOrder(Node root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%c", root->element);
    inOrder(root->right);
}

void postOrder(Node root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->element);
}

int main() {
    
    Node a = malloc(sizeof (struct TreeNode));
    Node b = malloc(sizeof (struct TreeNode));
    Node c = malloc(sizeof (struct TreeNode));
    Node d = malloc(sizeof (struct TreeNode));
    Node e = malloc(sizeof (struct TreeNode));
    Node f = malloc(sizeof (struct TreeNode));
    
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = NULL;
    d->left = d->right = NULL;
    e->left = e->right = NULL;
    f->left = f->right = NULL;
    
//    inOrder(a);
    
    postOrder(a);
    
    return 0;
}
