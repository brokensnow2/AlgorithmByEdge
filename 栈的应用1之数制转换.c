#include<stdio.h>
#include<stdlib.h>
#define INIT_SIZE 100
#define CREMENT 20
#define ERROR -1
#define OK 1

typedef struct {
    int *base;//栈底指针
    int *top;//栈頂指针
    int stacksize;
}SqStack;
int InitStack(SqStack s)
{
    s.base = (int *)malloc(INIT_SIZE * sizeof(int));
    if(!s.base)
    {
        return ERROR;
    }
    else
    {
		s.top = s.base;//栈空标志
        s.stacksize = INIT_SIZE;
        return OK;
    }
}
int GetTop(SqStack s)
{
	if(s.top == s.base)
    {
        return ERROR;
    }
    else
    {
        return *(s.top-1);
    }
}
int Pop(SqStack s)
{
	if(s.top == s.base)
    {
        return ERROR;
    }
    else
    {
        int a = *(s.top-1);
        s.top = s.top-1;
        /*
        int e = * --s.top;一句解决
        */
        return a;
    }
}
int Push(SqStack s, int e)
{
    if(s.top - s.base >= s.stacksize-1)//防止top指针越界
    {
		s.base = (int *)realloc(s.base,
        			 (INIT_SIZE + CREMENT)*sizeof(int));
        if(!s.base)
        {
            return ERROR;
        }
		s.top = s.base + s.stacksize - 1;
        s.stacksize += CREMENT;
    }
	*s.top = e;
    s.top++;
    /*
    *s.top++ = e; 一句解决
    */
    return OK;
}
void Clear(SqStack s)
{
    s.top = s.base;
}
int IsEmpty(SqStack s)
{
	if(s.top == s.base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int a;
    //SqStack *S= (SqStack *)malloc(sizeof(SqStack));
    struct SqStack stack;
	InitStack(stack);
    scanf("%d",&a);
    while(a)
    {
        Push(stack,a % 8);
        a = a / 8;
    }
    while(!IsEmpty)
    {
        a = Pop(stack);
        printf("%d",a);
    }
}