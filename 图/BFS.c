#include<stdio.h>
#include"graph.h"
#include"graph.c"
#include<stdlib.h>
#define INIT_SIZE 30
#define bool int

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


static Queue *q;
bool visited[MAX_NODES];
void BFSTraverse(G g)
{
    //初始化访问数组
    for(int i=0;i<g.numNodes;i++)
    	visited[i] = 0;
    Queue *q = createQueue();
    init(q);
    for(int i =0;i<g.numNodes;i++)
    {
        if(!visited[i])
        	BFS(g,i);
    }
}

void BFS(G g,int v)
{
	printf("%d\n",g.vertexInfo[v]);
    visited[v] = 1;
    enqueue(q,v);
    while(!isEmpty(q))
    {
        Dequeue(q,v);
        for(int w = FirstNeighbor(&g,v);w>= 0;w = NextNeighbor(&g,v,w))
        {
            if(!visited[w])
            {
                visited[w] = 1;
                printf("%d\n",g.vertexInfo[w]);
                enqueue(w);
            }
        }
    }
}