/**
在上述示例中，我们定义了一个Graph结构体，使用邻接表表示图。
initializeGraph函数用于初始化图，addEdge函数用于添加边到邻接表中。
hasCycleUtil函数是递归函数，用于判断从给定顶点开始的子图是否包含环。
它通过维护两个数组 visited 和 recursionStack，
来记录已访问的顶点和递归调用栈上的顶点。
在每次递归调用时，我们检查相邻的顶点是否已经被访问过或者存在于递归调用栈中，
如果是，则说明存在环。
hasCycle函数是用来遍历所有顶点，并调用 hasCycleUtil 函数判断是否存在环
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int numNodes;
    Node* adjList[MAX_NODES];
} Graph;

void initializeGraph(Graph* graph, int numNodes) {
    graph->numNodes = numNodes;
    
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
    }
}

void addEdge(Graph* graph, int source, int destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = destination;
    newNode->next = NULL;

    newNode->next = graph->adjList[source];
    graph->adjList[source] = newNode;
}

bool hasCycleUtil(Graph* graph, int vertex, bool visited[], bool recursionStack[]) {
    visited[vertex] = true;
    recursionStack[vertex] = true;

    Node* curr = graph->adjList[vertex];
    while (curr != NULL) {
        int adjacentVertex = curr->vertex;
        if (!visited[adjacentVertex] && 
        hasCycleUtil(graph, adjacentVertex, visited, recursionStack)) {
            return true;
        } else if (recursionStack[adjacentVertex]) {
            return true;
        }
        curr = curr->next;
    }

    recursionStack[vertex] = false;
    return false;
}

bool hasCycle(Graph* graph) {
    int numNodes = graph->numNodes;
    bool visited[MAX_NODES];
    bool recursionStack[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
        recursionStack[i] = false;
    }

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i] && hasCycleUtil(graph, i, visited, recursionStack)) {
            return true;
        }
    }

    return false;
}

int main() {
    Graph graph;
    int numNodes = 4;

    initializeGraph(&graph, numNodes);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 1);

    bool hasCycleFlag = hasCycle(&graph);
    if (hasCycleFlag) {
        printf("Graph contains a cycle.\n");
    } else {
        printf("Graph does not contain a cycle.\n");
    }

    return 0;
}
