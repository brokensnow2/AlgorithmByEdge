#include "graph.h"
#include "graph.c"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    G* graph = (G*)malloc(sizeof(G));
    initializeGraph(graph,10);
    printGraph(graph);
}