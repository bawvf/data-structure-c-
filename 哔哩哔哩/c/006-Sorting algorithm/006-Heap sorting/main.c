#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct MinHeap {
    E * arr;
    int size;
    int capacity;
} * Heap;

_Bool initHeap(Heap heap) {
    heap->size = 0;
    heap->capacity = 11;
    heap->arr = malloc(sizeof (E) * heap->capacity);
    
    return heap->arr != NULL;
}

_Bool insert(Heap heap, E element) {
    if (heap->size == heap->capacity)
        return 0;
    int index = ++heap->size;
    while (index > 1 && element < heap->arr[index / 2]) {
        heap->arr[index] = heap->arr[index / 2];
        index /= 2;
    }
    heap->arr[index] = element;
    return 1;
}

E delete(Heap heap) {
    E max = heap->arr[1], e= heap->arr[heap->size--];
    int index = 1;
    while (index * 2 <= heap->size) {
        int child = index * 2;
        if (child < heap->size && heap->arr[child] > heap->arr[child + 1])
            child += 1;
        if (e <= heap->arr[child])
            break;
        else
            heap->arr[index] = heap->arr[child];
        index = child;
    }
    heap->arr[index] = e;
    
    return max;
}

void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void makeHeap(int* arr, int start, int end) {
    while (start * 2 + 1 <= end) {
        int child = start * 2 + 1;
        if (child + 1 <= end && arr[child] < arr[child + 1])
            child++;
        if (arr[child] > arr[start])
            swap(&arr[child], &arr[start]);
        start = child;
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        makeHeap(arr, i, size - 1);
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[i], &arr[0]);
        makeHeap(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = {3,5,7,2,9,0,6,1,8,4};
    
    struct MinHeap heap;
    initHeap(&heap);
    for (int i = 0; i < 10; ++i)
        insert(&heap, arr[i]);
    for (int i = 0; i < 10; ++i)
        arr[i] = delete(&heap);
    
    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
    return 0;
}
