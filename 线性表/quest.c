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

int main()
{
    List* l = (List*)malloc(sizeof(List));
    l->data = create();
    for(int i=0;i<10;i++)
    {
        l->data[i]=i;
        l->length++;
    }
    for(int i=0;i<10;i++)
    {
    	printf("%d\t",l->data[i]);        
    }
    printf("\n");
    printf("%d\n",deleteMinValue(l));

}