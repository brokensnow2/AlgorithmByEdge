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

void Del_X(LNode *l,int x)
{
    LNode *h = l;
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
        Del_X(l->next,x);
    }
}
/**
int main()
{
	LNode *head = (LNode*)malloc(sizeof(LNode));
    head = List_TailInsert(head);
    Del_X(head,3);
    PrintList(head);
}
*/
