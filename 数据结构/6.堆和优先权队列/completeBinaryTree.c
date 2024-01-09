#include<stdio.h>
#include<stdlib.h>
typedef struct completeBinaryTree{
    int* heap;
    int length;
}CBT;

void AdjustDown(int heap[],int lastParentIndex,int borderIndex)
{
	int p,minChild,temp;
    p = lastParentIndex;
    //有左孩子
	while( 2*p+1 <= borderIndex )
    {
        //有右孩子
		if( 2*p+2 <= borderIndex && heap[2*p+2] < heap[2*p+1])
        {
			minChild = 2*p+2;
        }
        else
        {
            minChild = 2*p+1;
        }
        //最小堆
        if(heap[p] < heap[minChild])
        {
            break;
        }
        else
        {
            temp = heap[p];
            heap[p] = heap[minChild];
            heap[minChild] = temp;
            p = minChild;//下轮考察位置
        }
    }
}

//创建堆
void CreateHeap(int heap[],int length)
{

    for(int i = (length-2)/2;i > -1;i--)
    {
        //i,length-1为下标
        AdjustDown(heap,i,length-1);
    }
}

//取出堆顶最小元素放置数组最后
void Sort(int heap[], int length)
{
    //n是下标
    int n = length - 1;
    while(n > 0)
    {
        int temp = heap[0];
    	heap[0] = heap[n];
    	heap[n] = temp;
        n = n - 1;
        //CreateHeap要的是长度
    	//CreateHeap(heap, n+1);
        /**
        在 Sort 函数中，每次调用 CreateHeap 函数都会重新建堆，
        这会使时间复杂度变为 O(n^2*logn)。实际上，
        可以只对堆顶元素所在的子树进行调整，
        即将堆顶元素与最后一个叶子节点交换后，
        只需要对新的堆顶元素进行一次 AdjustDown 操作即可，
        这样时间复杂度就能保持在 $O(nlogn)$
        */
        AdjustDown(heap, 0, n);
    }

}

void CreateCBT(CBT* cbt,int a[])
{
    cbt->heap = a;
    /**
    在函数内部使用 sizeof(a) / sizeof(a[0])
    计算数组长度，实际上是计算指针大小，而不是数组长度
    */
    cbt->length = sizeof(a) / sizeof(a[0]);
    printf("%d\n",cbt->length);
}

int main()
{
    int a[] = {2,1,5,2,7,8,9,10};
    int n = sizeof(a) / sizeof(a[0]);
    printf("%d\n",n);
    CBT* cbt = (CBT*)malloc(sizeof(CBT));
    CreateCBT(cbt, a);
    CreateHeap(a, n);
    for(int i = 0; i<n; i++)
    {
        printf("%d;",a[i]);
    }    
    printf("\n");
    Sort(a, n);
    for(int i = 0; i<n; i++)
    {
        printf("%d;",a[i]);
    }
}