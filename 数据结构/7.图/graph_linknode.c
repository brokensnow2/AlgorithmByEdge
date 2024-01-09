#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int numNodes;
    int vertexInfo[MAX_NODES];
    Node* adjList[MAX_NODES];
} G;

void initializeGraph(G* graph, int numNodes) {
    graph->numNodes = numNodes;
    
    for (int i = 0; i < numNodes; i++) {
        graph->vertexInfo[i] = 0;  // 可根据需求进行初始化
        graph->adjList[i] = NULL;
    }
}

void addEdge(G* graph, int source, int destination) {
    // 创建新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = destination;
    newNode->next = NULL;

    // 将新节点插入到邻接表的头部
    newNode->next = graph->adjList[source];
    graph->adjList[source] = newNode;
}

void removeEdge(G* graph, int source, int destination) {
    Node* curr = graph->adjList[source];
    Node* prev = NULL;

    // 遍历邻接表，查找目标节点并删除
    while (curr != NULL) {
        if (curr->vertex == destination) {
            if (prev == NULL) {
                graph->adjList[source] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

bool hasEdge(G* graph, int source, int destination) {
    Node* curr = graph->adjList[source];

    // 遍历邻接表，查找目标节点
    while (curr != NULL) {
        if (curr->vertex == destination) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int getVertexInfo(G* graph, int vertex) {
    return graph->vertexInfo[vertex];
}

void setVertexInfo(G* graph, int vertex, int info) {
    graph->vertexInfo[vertex] = info;
}

int FirstNeighbor(G* graph, int vertex) {
    if (graph->adjList[vertex] != NULL) {
        return graph->adjList[vertex]->vertex;
    }
    return -1;
}

int NextNeighbor(G* graph, int vertex, int prevNeighbor) {
    Node* curr = graph->adjList[vertex];
    while (curr != NULL) {
        if (curr->vertex > prevNeighbor) {
            return curr->vertex;
        }
        curr = curr->next;
    }
    return -1;
}

void insertVertex(G* graph, int vertex) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Graph is already full. Cannot insert more vertices.\n");
        return;
    }

    graph->numNodes++;

    graph->vertexInfo[graph->numNodes - 1] = vertex;
    graph->adjList[graph->numNodes - 1] = NULL;
}

void printGraph(G* graph) {
    printf("Number of nodes: %d\n", graph->numNodes);
    printf("Vertex Information:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        printf("Vertex %d: %d\n", i, graph->vertexInfo[i]);
    }
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        printf("Vertex %d: ", i);
        Node* curr = graph->adjList[i];
        while (curr != NULL) {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}
