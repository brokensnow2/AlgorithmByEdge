#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stu ss;

//结构体类型的定义
struct stu
{
	char name[50];
	int age;
};

int main()
{
	ss *p = NULL;

	p = (ss *)malloc(sizeof(ss));
	//如果是指针变量，通过->操作结构体成员
	strcpy(p->name, "test");
	p->age = 22;

	printf("p->name = %s, p->age=%d\n", p->name, p->age);
	printf("(*p).name = %s, (*p).age=%d\n", (*p).name,  (*p).age);

	free(p);
	p = NULL;

	return 0;
}