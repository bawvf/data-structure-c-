#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int tmp[], int left, int leftEnd, int right, int rightEnd) {
    int i = left, size = rightEnd - left + 1;
    while (left <= leftEnd && right <= rightEnd) {
        if (arr[left] <= arr[right])
            tmp[i++] = arr[left++];
        else
            tmp[i++] = arr[right++];
    }
    while (left <= leftEnd)
        tmp[i++] = arr[left++];
    while (right <= rightEnd)
        tmp[i++] = arr[right++];
    for (int j = 0; j < size; ++j, rightEnd--)
        arr[rightEnd] = tmp[rightEnd];
}

void mergeSort(int arr[], int tmp[], int start, int end) {
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, tmp, start, mid);
    mergeSort(arr, tmp, mid + 1, end);
    merge(arr, tmp, start, mid, mid + 1, end);
}

int main() {
    int arr[] = {3,5,7,2,9,0,6,1,8,4};
    int tmp[10];
    
    mergeSort(arr, tmp, 0, 9);
    
    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
    return 0;
}