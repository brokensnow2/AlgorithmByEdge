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

int main()
{
	LNode *head = (LNode*)malloc(sizeof(LNode));
    head = List_TailInsert(head);
    PrintList(head);
}