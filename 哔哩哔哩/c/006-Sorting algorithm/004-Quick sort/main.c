#include <stdio.h>

void quickSort(int arr[], int start, int end) {
    if (start >= end)
        return;
    int left = start, right = end, pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot)
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot)
            left++;
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    quickSort(arr, start, left - 1);
    quickSort(arr, left + 1, end);
    
    
}

int main() {
    int arr[] = {3,5,7,2,9,0,6,1,8,4};
    
    quickSort(arr, 0 , 10);
    
    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
    return 0;
}
