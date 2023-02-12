#include<stdio.h>
/*
对单链表的逆置存储，逆置存储是指将元素线性关系逆置后的链表存储，
例如（a0,a1,a2），关系逆置后为（a2,a1,a0).
*/
typedef struct node

{
	int element;
    struct node *link;


}Node;

typedef struct singlelist
{

    Node *first;
    int n;

}SingleList;//头结点

//头插法
void invert(SingleList *L)
{
	Node *p= L->first;
    Node *q,*temp;
    while(p)
    {
		q = p->link;
		p->link = L->first;
        L->first = p;
        p = q;
    }
}