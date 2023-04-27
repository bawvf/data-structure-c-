#include <stdio.h>

//递归二分法方式
int binarySearch(int * nums, int target, int left, int right ) {
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (nums[mid] == target)
        return mid;
    if (nums[mid] < target)
        return binarySearch(nums, target, mid + 1, right);
    else
        return binarySearch(nums, target, left, mid - 1);
}

int search(int * nums, int numSize, int target) {
    return binarySearch(nums, target, 0,numSize - 1);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
