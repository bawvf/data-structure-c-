#include <stdio.h>

void selectSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i; j < size; ++j)
            if (arr[j] < arr[min])
                min = j;
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

int main() {
    int arr[] = {3,5,7,2,9,0,6,1,8,4};
    
    selectSort(arr, 10);
    
    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
    return 0;
}