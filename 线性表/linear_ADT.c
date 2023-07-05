#include<stdio.h>
#include<stdlib.h>
#define InitSize 100
#define Ture 1
#define False 0


/*
顺序存储
*/
typedef struct{
    int *data;
    int Max;
    int length;
}List;


int *create()
{
	return (int*)malloc(sizeof(int)*InitSize);
}

List* expand(List *l)
{
    l->Max = l->Max + 50;
    return realloc(l->data,sizeof(int)*(l->Max));//caution!!
}

int Insert(List *list,int i,int e)
{
	if(i<1 || i>list->length)
    	return False;
    if(list->length>list->Max)
    {
        list=expand(list);
    }
    for(int j=list->length;j>=i;j--)
    {
        list->data[j] = list->data[j-1];
    }
    list->data[i-1] = e;
    list->length++;
    return Ture;
}

int Delete(List* l, int i)
{
    for(int j = i;j<l->length;j++)
    {
        l->data[j-1]=l->data[j];
    }
    l->length--;
    return Ture;
}
/**
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
        printf("%d",l->data[i]);
    }
    Delete(l,3);
    printf("\n");
    for(int i=0;i<l->length;i++)
    {
        printf("%d",l->data[i]);
    }  
    printf("\nThe Length is %d\n",l->length);
}
*/
