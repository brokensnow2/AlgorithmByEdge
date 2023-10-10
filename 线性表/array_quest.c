#include<stdio.h>
#include<stdlib.h>
#include"linear_ADT.c"

//逆序思想，排序思想，如何合并表

//QUEST1
int deleteMinValue(List* list)
{
    int min,index;
    if(list -> length == 0)
    {
        printf("error\n");
        return -9999;
    }
    else
    {
        min = list->data[0];
		for(int i=0;i<list->length;i++)
        {
            int a = list->data[i];
            if(min > a)
            {
				min = a;
                index = i;
            }
        }
        list->data[index] = list->data[list->length-1];
        return min;
    }
}

//QUEST2
void Reverse(List* list)
{
    
}

//QUEST3
void Del_All_X(List* list,int x)
{
    int k=0;
    for(int i=0;i<list->length;i++)
    {
        if(list->data[i] != x)
        {
            list->data[k] = list->data[i];        
            k++;
        }
    }
    list->length = k;
}

//QUEST6
void DelRepeatElement(List* list)
{
    if(list == NULL)
    	return;
	int flag = list->data[0];
    int k = 0;
    for(int i = 1;i<list->length;)
    {
		if(flag == list->data[i])
        {
			k++;
            for(int j = i+1;j<list->length;j++)
            {
                list->data[j-1] = list->data[j];
            }
            list->length--;
        }
        else
        {
            flag = list->data[i];
            i++;
        }
    }
}


//QUEST11
//思想同题7,适用于有序表，如果无序可以先排序再调用FindMid
int FindMid(List* list1,List* list2)
{
    int x = 0;
    int y = 0; //两个指针
    int mid;//存中位数的
    //A,B 等长
    for(int i = 0;i<list1->length;i++)
    {
		if(list1->data[x] <= list2->data[y])
        {
			mid = list1->data[x];
            x++;
        }
        else
        {
            mid = list2->data[y];
            y++;
        }
    }
    return mid;
}



//QUEST13
//时间复杂度nlogn，空间复杂度logn。。。
void FindMinestNumNotInList(List* list)
{
	//quickSort1(list->data,0,list->length-1);
    for(int i = 0;i<list->length; i++)
    {
        //if()
    }
}

//天勤QUEST5
void ByHeadValueSort(List* list)
{
    int temp;
    int i = 1,n = list->length-1;
    while (i < list->length/2 && n > list->length/2)
    {
        if(list->data[i] < list->data[0])
        {
			i++;
        }
        else
        {
            temp = list->data[i];
            list->data[i] = list->data[n];
            list->data[n] = temp;
            n--;
        }
    }
}

//天勤Ch.5 Q1
//将所有非0元素移到数组前端
void sortArray(int a[])
{
	int i = 0,count = 0;
    int n = length(a);
    while(i<length(a) && count < length(a))
    {
        if (a[i] == 0)
        {
			a[i] = a[--n];
            a[n] = 0;
        }
        else
        {
            i++;
        }
        count++;
    }
    
}

int main()
{
    //initialize
    List* l = (List*)malloc(sizeof(List));
    l->data = create();
    for(int i=0;i<10;i++)
    {
        l->data[i]=i;
        l->length++;
    }

	List* l2 = (List*)malloc(sizeof(List));
    l2->data = create();
    for(int i=0;i<10;i++)
    {
        l2->data[i]=i+1;
        l2->length++;
    }

	//
    //Del_All_X(l,3);
    //print(l);
	//printf("\n");
    //
	
    //Insert(l,2,2);
    //print(l);
	//printf("\n");
    //

    //
    //DelRepeatElement(l);

    print(l);

	printf("%d\n",FindMid(l,l2));

    printf("%d\n",deleteMinValue(l));


}