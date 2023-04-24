#include<stdlib.h>
#include<stdio.h>
/**
void InsertSort_New(int a[], int n)
{
    int i,j,temp,low,high,mid;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        low=0;
        high=i-1;
        while( low<=high )
        {
            mid = (low + high )/2;
            if(a[mid]>temp)
                high = mid - 1;
            if(a[mid]<temp)
            	low = mid + 1;
        }
        printf("%d;",mid);
        if(a[mid]>temp)
        {
        	for(j=i-1;j>=mid;j--)
        		a[j+1] = a[j];
            a[mid] = temp;
        }
        if(a[mid]<=temp)
        {
            for(j=i-1;j>mid;j--)
        		a[j+1] = a[j];
            a[mid+1] = temp;    
        }
    }
}
*/
void InsertSort_New(int a[], int n)
{
    int i,j,temp,low,high,mid;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        low=0;
        high=i-1;
        while( low<=high )
        {
            mid = (low + high )/2;
            if(a[mid]>temp)
                high = mid - 1;
            else if(a[mid]<temp)
                low = mid + 1;
            else
                break;
        }
        if(a[mid]>temp)
        {
            for(j=i-1;j>=mid;j--)
                a[j+1] = a[j];
            a[mid] = temp;
        }
        else
        {
            for(j=i-1;j>=mid+1;j--)
                a[j+1] = a[j];
            a[mid+1] = temp;    
        }
    }
}


void InsertSort(int a[], int n)
{
    int i,j,temp;//i是代插入；j是已排序的从后往前；temp保留代插入值
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<a[j])
            {
				a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1] = temp;
    }
}

void shellSort(int arr[], int n) {
    // 定义间隔序列
    int gap = n/2;
  
    // 迭代间隔序列，每次减小一半
    while (gap > 0) {
        // 对每个间隔进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}


int main()
{
    int i;
    int a[] = {1,3,5,7,2,4,8,5,9};
    //InsertSort(a,9);
    InsertSort_New(a,9);
    printf("\n");
    for(i=0;i<9;i++)
    {
        printf("%d,",a[i]);
    }
}