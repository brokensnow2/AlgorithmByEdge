#include<stdio.h>
#include<stdlib.h>
#include"linear_ADT.c"

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

	//
    Del_All_X(l,3);
    for(int i=0;i<l->length;i++)
    {
    	printf("%d\t",l->data[i]);        
    }
	printf("\n");
    //
	
    Insert(l,2,2);
    for(int i=0;i<l->length;i++)
    {
    	printf("%d\t",l->data[i]);        
    }
    printf("\n");

    //
    DelRepeatElement(l);
    for(int i=0;i<l->length;i++)
    {
    	printf("%d\t",l->data[i]);        
    } 
    printf("\n");

    //  
    printf("%d\n",deleteMinValue(l));


}