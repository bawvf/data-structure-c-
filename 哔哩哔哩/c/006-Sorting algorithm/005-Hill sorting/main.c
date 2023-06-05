#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int size) {
    int delta = size / 2;
    while (delta >= 1) {
        for (int i = delta; i < size; ++i) {
            int j = i, tmp = arr[i];
            while (j >= delta && arr[j - delta] > tmp) {
                arr[j] = arr[j - delta];
                j -= delta;
            }
            arr[j] = tmp;
        }
        delta /= 2;
    }
}

int main() {
    int arr[] = {3,5,7,2,9,0,6,1,8,4};
    
    shellSort(arr, 10);
    
    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
    return 0;
}
