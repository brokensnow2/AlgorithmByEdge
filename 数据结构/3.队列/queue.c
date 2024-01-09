#include<stdio.h>
#include<stdlib.h>
#define INIT_SIZE 30
#define bool int
//循环队列
typedef struct queue
{
	int data[INIT_SIZE];
    int front,rear;
}Queue;

Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    return q;
}

void init(Queue* q)
{
	q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue* q)
{
	if(q->front ==q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool enQueue(Queue* q,int x)
{
	if((q->rear+1)%INIT_SIZE == q->front)
    {
        return 0;
    }
    else
    {
        q->data[q->rear] = x;
        q->rear = (q->rear + 1)%INIT_SIZE;
        return 1;
    }
}

int deQueue(Queue *q)
{
	if(q->front == q->rear)
    {
        return 0;
        printf("error\n");
    }
    else
    {
        int x = q->data[q->front];
        q->front = (q->front + 1)%INIT_SIZE;
        return x;
    }
}

