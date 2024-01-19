#include <stdio.h>
#include <stdbool.h>
#include "graph.h"
#define MAX_NODES 100

void initializeGraph(G* graph, int numNodes) {
    graph->numNodes = numNodes;
    
    // 初始化顶点信息数组
    for (int i = 0; i < numNodes; i++) {
        graph->vertexInfo[i] = 0;  // 可根据需求进行初始化
    }

    // 初始化邻接矩阵，所有元素设为0表示无边
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}

void addEdge(G* graph, int source, int destination) {
    // 在邻接矩阵中将指定位置的值设为1，表示存在边
    graph->matrix[source][destination] = 1;

    // 如果是无向图，还需将对应位置的值设为1
    // graph->matrix[destination][source] = 1;
}

void removeEdge(G* graph, int source, int destination) {
    // 在邻接矩阵中将指定位置的值设为0，表示删除边
    graph->matrix[source][destination] = 0;

    // 如果是无向图，还需将对应位置的值设为0
    // graph->matrix[destination][source] = 0;
}

bool hasEdge(G* graph, int source, int destination) {
    // 返回邻接矩阵中指定位置的值，表示是否存在边
    return graph->matrix[source][destination] == 1;
}

void setVertexInfo(G* graph, int vertex, int info) {
    // 设置指定顶点的信息
    graph->vertexInfo[vertex] = info;
}

int getVertexInfo(G* graph, int vertex) {
    // 获取指定顶点的信息
    return graph->vertexInfo[vertex];
}

int FirstNeighbor(G* graph, int vertex) {
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->matrix[vertex][i] == 1) {
            return i;
        }
    }
    return -1;  // 如果没有邻接节点，返回-1表示不存在
}

int NextNeighbor(G* graph, int x, int y) {
    for (int i = y + 1; i < graph->numNodes; i++) {
        if (graph->matrix[x][i] == 1) {
            return i;
        }
    }
    return -1;  // 如果没有下一个邻接节点，返回-1表示不存在
}

void insertVertex(G* graph, int x) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Graph is already full. Cannot insert more vertices.\n");
        return;
    }
    
    // 更新顶点数量
    graph->numNodes++;
    
    // 更新新顶点的信息
    graph->vertexInfo[graph->numNodes - 1] = x;
    
    // 初始化新顶点与其他顶点之间的边关系
    for (int i = 0; i < graph->numNodes - 1; i++) {
        graph->matrix[i][graph->numNodes - 1] = 0;
        graph->matrix[graph->numNodes - 1][i] = 0;
    }
}

int calculateInDegree(G* graph, int vertex) {
    int inDegree = 0;
    
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->matrix[i][vertex] == 1) {
            inDegree++;
        }
    }
    
    return inDegree;
}

int calculateOutDegree(G* graph, int vertex) {
    int outDegree = 0;
    
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->matrix[vertex][i] == 1) {
            outDegree++;
        }
    }
    
    return outDegree;
}

void addWeightedEdge(G* graph, int source, int destination, int weight) {
    graph->matrix[source][destination] = weight;
    // 如果是无向图，还需将对应位置的值设为权值
    // graph->matrix[destination][source] = weight;
}


void printGraph(G* graph) {
    printf("Number of nodes: %d\n", graph->numNodes);
    printf("Vertex Information:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        printf("Vertex %d: %d\n", i, graph->vertexInfo[i]);
    }
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        for (int j = 0; j < graph->numNodes; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
