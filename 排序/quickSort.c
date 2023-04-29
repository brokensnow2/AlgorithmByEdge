#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//书上
int partition1(int arr[], int low, int high) {
    int pivot = arr[low];
    while(low<high)
    {
        while(low<high && arr[high]>=pivot)
        	--high;
        arr[low] = arr[high];
        while(low<high && arr[low] <= pivot)
        	++low;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}


void quickSort1(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition1(arr, low, high);
        quickSort1(arr, low, pi - 1);
        quickSort1(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr, n);
    quickSort1(arr, 0, n - 1);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}
