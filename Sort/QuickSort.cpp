#include <stdio.h>

// 用第一个元素将待排序序列划分成左右两个部分
int Partition(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {     //第一个元素作为枢纽
        while (low < high && A[high] >= pivot)  //用low，high搜索枢纽的最终位置
            high--;
        A[low] = A[high];   //比枢纽小的移动到左端
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];   //比枢纽大的移动到右端
    }
    A[low] = pivot; //枢纽存放到最终位置
    return low; //返回存放枢纽的位置
}

// 快速排序
void QuickSort(int A[], int low, int high) {
    if (low < high) {   //递归跳出的条件
        int pivotPos = Partition(A, low, high); //划分
        QuickSort(A, low, pivotPos - 1);    //划分左子表
        QuickSort(A, pivotPos + 1, high);   //划分右子表
    }
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    //输出初始数组
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    QuickSort(arr, 0, n - 1);

    //输出排序后的数组
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
