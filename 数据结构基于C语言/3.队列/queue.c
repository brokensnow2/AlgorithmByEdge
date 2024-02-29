#include<stdio.h> // 引入标准输入输出库
#include<stdlib.h> // 引入标准库，包含了一些通用的函数，如malloc和free
#define INIT_SIZE 30 // 定义一个宏，表示队列的初始大小
#define bool int // 定义一个宏，将bool替换为int，因为C语言中没有bool类型

// 定义一个循环队列的结构体
typedef struct queue
{
	int data[INIT_SIZE]; // 队列的数据，用一个固定大小的数组来存储
    int front,rear; // 队列的头部和尾部的索引
}Queue;

// 创建一个队列的函数
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue)); // 使用malloc函数分配一块内存，大小为一个Queue结构体的大小
    return q; // 返回创建的队列的指针
}

// 初始化队列的函数
void init(Queue* q)
{
	q->front = 0; // 将队列的头部索引设置为0
    q->rear = 0; // 将队列的尾部索引设置为0
}

// 检查队列是否为空的函数
bool isEmpty(Queue* q)
{
	if(q->front ==q->rear) // 如果头部索引和尾部索引相等，那么队列就是空的
    {
        return 1; // 返回1，表示队列是空的
    }
    else
    {
        return 0; // 返回0，表示队列不是空的
    }
}

// 入队操作的函数
bool enQueue(Queue* q,int x)
{
	if((q->rear+1)%INIT_SIZE == q->front) // 如果尾部索引加1后等于头部索引，那么队列就是满的
    {
        return 0; // 返回0，表示入队操作失败
    }
    else
    {
        q->data[q->rear] = x; // 将新元素添加到队列的尾部
        q->rear = (q->rear + 1)%INIT_SIZE; // 更新尾部索引
        return 1; // 返回1，表示入队操作成功
    }
}

// 出队操作的函数
int deQueue(Queue *q)
{
	if(q->front == q->rear) // 如果头部索引等于尾部索引，那么队列就是空的
    {
        return 0; // 返回0，表示出队操作失败
        printf("error\n"); // 输出错误信息
    }
    else
    {
        int x = q->data[q->front]; // 获取队列头部的元素
        q->front = (q->front + 1)%INIT_SIZE; // 更新头部索引
        return x; // 返回出队的元素
    }
}


