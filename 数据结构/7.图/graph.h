#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int numNodes;
    int vertexInfo[MAX_NODES];
    int matrix[MAX_NODES][MAX_NODES];
} G;

void initializeGraph(G* graph, int numNodes);

void addEdge(G* graph, int source, int destination);

void removeEdge(G* graph, int source, int destination);

bool hasEdge(G* graph, int source, int destination);

void setVertexInfo(G* graph, int vertex, int info);

int getVertexInfo(G* graph, int vertex);

int FirstNeighbor(G* graph, int vertex);

int NextNeighbor(G* graph, int x, int y);

void insertVertex(G* graph, int x);

void printGraph(G* graph);

int calculateInDegree(G* graph, int vertex);

int calculateOutDegree(G* graph, int vertex);

void addWeightedEdge(G* graph, int source,
					int destination, int weight);

#endif  // GRAPH_H