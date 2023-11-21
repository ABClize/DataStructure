#include <stdio.h>

// ���ֲ��Һ���
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // ��ֹ�������

        if (arr[mid] == target) {
            return mid; // �ҵ�Ŀ��Ԫ�أ���������
        } else if (arr[mid] < target) {
            left = mid + 1; // Ŀ�����Ұ벿��
        } else {
            right = mid - 1; // Ŀ������벿��
        }
    }

    return -1; // Ŀ��Ԫ�ز�����
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
        printf("Ԫ�� %d �ҵ������� %d\n", target, result);
    } else {
        printf("Ԫ�� %d ��������������\n", target);
    }
    
    target=16;
    int test=mytest(arr,size,target);
    printf("Ԫ�� %d �ҵ������� %d\n", target, test);
    return 0;
}
