#include <stdio.h>

void insertSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int tmp = arr[i], j = 1;
        while (j > 0 && arr[j - 1] > tmp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tmp;
    }
}

int main() {
    int arr[] = {3,5,7,2,9,0,6,1,8,4};
    
    bubbleSort(arr, 10);
    
    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
    return 0;
}