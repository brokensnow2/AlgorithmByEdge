#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stackByarray stack;

//栈的四种类型:满增栈、满减栈、空增栈、空减栈
//王道书
struct stackByarray
{
	int data[50];
	int top; //数组下标表示栈頂
};

//用两个栈模拟队列
//入就放到s1,s1就相当于尾
//出从s2出，s2就相当于头
//保持s1总空，s2最新
void enQueue(stack* s1,stack* s2,int x)
{
	//真空
	if(s2->top == -1)
	{
		push(s2,x);	
	}
	else
	{
		//s2有最新的元素
		while(s2->top != -1) //while(!StackEmpty(s2))
		{
			int temp = pop(s2);
			push(s1,temp);
			//x放到队尾
			push(s1,x);
		}
		//全放到s2
		while(s1->top != -1)
		{
			int temp = pop(s1);
			push(s2,temp);
		}
	}
}

int deQueue(stack* s1,stack* s2)
{
	//这是真空了
	if(s2->top == -1) //while(StackEmpty(s2))
	{
		return -9999;
	}
	else
	{
		return pop(s2);
	}
}

int main()
{

}