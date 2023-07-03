#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
	struct LNode *next;
}LNode;

LNode *List_TailInsert(LNode* l)
{
    int x;
    LNode *s,*r = l;
    scanf("%d",&x);
    while(x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        //头结点不放数据
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return l;
}

void PrintList(LNode* l)
{
    while(l->next != NULL)
    {
        l = l->next;
		printf("%d\n",l->data);
    }
}

//线性表的链式存储
//QUEST1
void Del_X(LNode *l,int x)
{
    LNode *p=l->next;
    if(p==NULL)
    {
        return;
    }
    if(p->data==x)
    {
        l->next=p->next;//防止断链
        free(p);
        Del_X(l,x); //不能是l->next,防止2，3，3，这种情况
    }
    else{
        Del_X(l,x);
    }
}


//QUEST2
//Reverse函数要放在Ignore前面哦
void Reverse_printf(LNode* list)
{
	if(list->next != NULL)
    {
        Reverse_printf(list->next);
    }
    printf("%d\t",list->data);
}
void IgnoreHead(LNode *list)
{
    if(list->next != NULL)
    {
        Reverse_printf(list->next);
    }
}

//QUEST4
void DeleteMinValue(LNode *list)
{
    if( list->next != NULL)
    {
        LNode* pre = list;
        LNode* p = list->next;

        LNode* min_pre = list;
        LNode* min_p = list->next;
		while(p->next != NULL)
    	{
        	//注意先后
        	pre = p;
        	p = p->next;

        	if(min_p->data > p->data)
        	{
            	min_p = p;
            	min_pre = pre;
        	}
    	}
    	if(min_p->next != NULL)
    	{
        	min_pre->next = min_p->next;
        	free(min_p);
    	}
    	else{
        	min_pre->next = NULL;
        	free(min_p);
    	}
    }
    else{
        printf("NULL");
    }
}


int main()
{
    //头指针            分配的堆内存:头结点
	LNode *head = (LNode*)malloc(sizeof(LNode));
    head = List_TailInsert(head);
    DeleteMinValue(head);
    PrintList(head);
}

