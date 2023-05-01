#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Stack {
    E * array;
    int capacity;
    int top;
};

typedef struct Stack * ArrayStack;

//初始化
_Bool initStack(ArrayStack stack) {
    stack->array = malloc(sizeof (E) * 10);
    if (stack->array == NULL)
        return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}

//入栈
_Bool pushStack(ArrayStack stack, E element) {
//    判断满栈
    if (stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        E * newArray = realloc(stack->array, newCapacity * sizeof (E));
        if (newArray == NULL)
            return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[++stack->top] = element;
    return 1;
}

_Bool isEmpty(ArrayStack stack) {
    return stack->top == -1;
}

E popStack(ArrayStack stack) {
    return stack->array[stack->top--];
}

//打印
void printStack(ArrayStack stack) {
    printf("|");
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    //初始化
    struct Stack stack;
    initStack(&stack);
    
    for (int i = 0; i < 10; i++)
        pushStack(&stack, i * 100);
    
    printStack(&stack);
    
    while (!isEmpty(&stack)) {
        printf("%d ", popStack(&stack));
    }
    return 0;
}
