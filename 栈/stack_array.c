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

int main()
{

}