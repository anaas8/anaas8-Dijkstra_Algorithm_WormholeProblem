#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <stdlib.h>
#include<string.h>
#define maxvertex 10000
#define IN 9999
typedef char graphentry[25];


typedef struct edge{
int endpoint;
int cost;
struct edge *nextedge;
}Edge;

typedef struct vertex{
graphentry entry;
Edge * firstedge;
}Vertex;

typedef struct graph{
 int n;
 int E;
 Vertex entry[maxvertex];
}Graph;



void creategraph(Graph *);
int dijkstra(Graph *,graphentry ,graphentry );
void AddEdge(Graph*,int,int,int);
void removeEdge(Graph * , graphentry, graphentry );
void AddVertex(Graph * , int ,graphentry);
void removeVertex(Graph * , graphentry);

#endif // GRAPH_H_INCLUDED
