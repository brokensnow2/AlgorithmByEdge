#include <stdio.h>

/**
 * 解决元素不相同且为有序表，使其奇数排在偶数前
 * 该算法思想有点类似于插入排序
*/
void oddHeadEven(int a[])
{
    int oddNum = 0,EvenNum = 0;
    for(int i = 0; i < length(a); i++)
    {
        if(a[i]%2 == 1)
        {
            ++oddNum;
            //当前奇数前有偶数,且下标oddNum-1前的全为奇数且有序。
            if(i > oddNum-1)
            {
				int temp = a[i];
                for (int j = i; j >= oddNum; j--)
                {
                    /* code */
					swap(a[j-1],a[j]);
                }
                a[oddNum-1] = temp;
                
            }
        }
        else
        {
            ++EvenNum;
        }
    }
}