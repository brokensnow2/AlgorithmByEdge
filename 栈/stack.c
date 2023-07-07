#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define INIT_SIZE 100
#define CREMENT 20
#define ERROR -1
#define OK 1

//数据结构书
typedef struct {
    int *base;//栈底指针
    int *top;//栈頂指针
    int stacksize;
}SqStack;

SqStack *init()
{
    //堆中开辟一块连续的空间，其实就是data[SIZE]
    int *a = (int *)malloc(INIT_SIZE * sizeof(int));
    //注意先开辟再使用指针
    SqStack *s = (SqStack *)malloc(sizeof(SqStack));
    s->base = a;
    s->top = s->base;
    s->stacksize = INIT_SIZE;
    return s;
}

int InitStack(SqStack *s)
{
    printf(".....");
    s->base = (int *)malloc(INIT_SIZE * sizeof(int));
    printf("%p\n",s->base);
    if(!s->base)
    {
        return ERROR;
    }
    else
    {
		s->top = s->base;//栈空标志
        s->stacksize = INIT_SIZE;
        return OK;
    }
}
int GetTop(SqStack *s)
{
	if(s->top == s->base)
    {
        return ERROR;
    }
    else
    {
        return *(s->top-1);
    }
}
int Pop(SqStack *s)
{
	if(s->top == s->base)
    {
        return ERROR;
    }
    else
    {
        int a = *(s->top-1);
        s->top = s->top-1;
        /*
        int e = * --s.top;一句解决
        */
        return a;
    }
}
int Push(SqStack *s, int e)
{
    if(s->top - s->base >= s->stacksize-1)//防止top指针越界
    {
		s->base = (int *)realloc(s->base,
        			 (INIT_SIZE + CREMENT)*sizeof(int));
        if(!s->base)
        {
            return ERROR;
        }
		s->top = s->base + s->stacksize - 1;
        s->stacksize += CREMENT;
    }
    printf("%d\n",e);
	*s->top = e;
    s->top++;
    /*
    *s->top++ = e; 一句解决
    */
    return OK;
}
void Clear(SqStack *s)
{
    s->top = s->base;
}
int IsEmpty(SqStack *s)
{
	if(s->top == s->base)
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
    SqStack *stack = init();
    scanf("%d",&a);
    while(a)
    {
        Push(stack,a % 8);
        a = a / 8;
    }
    while(!IsEmpty(stack)) //注意！！！不是IsEmpty,IsEmpty是地址
    {
        a = Pop(stack);
        printf("%d",a);
    }
}