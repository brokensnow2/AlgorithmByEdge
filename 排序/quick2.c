#include <stdio.h>

// 交换两个数
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//MOOC
// 使用 low 作为 pivot，返回分割点的索引
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // 选第一个元素作为 pivot
    int i = low, j = high;
    while (i < j) {
        //左边是<=,i < high防止越界
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        // >pivot 来防止越界,可以少写j > low
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

// 以 low 作为 pivot 的快速排序
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 , 6, 10};
    int arr1[] = {1, 2, 3, 5 ,6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    quicksort(arr1, 0, 5);
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    return 0;
}
