#include <stdio.h>

// 二分查找函数
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止整数溢出

        if (arr[mid] == target) {
            return mid; // 找到目标元素，返回索引
        } else if (arr[mid] < target) {
            left = mid + 1; // 目标在右半部分
        } else {
            right = mid - 1; // 目标在左半部分
        }
    }

    return -1; // 目标元素不存在
}
//test
int mytest(int arr[],int size,int target)
{
    int low=0;
    int high=size-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (target==arr[mid])
        {
            return mid;
        }
        else if (target<arr[mid])
        {
            high=mid-1;
        }
        else low=mid+1;
        
    }
    
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("元素 %d 找到于索引 %d\n", target, result);
    } else {
        printf("元素 %d 不存在于数组中\n", target);
    }
    
    target=16;
    int test=mytest(arr,size,target);
    printf("元素 %d 找到于索引 %d\n", target, test);
    return 0;
}
