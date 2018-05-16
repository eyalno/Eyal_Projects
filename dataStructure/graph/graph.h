#include <string.h>
#include "ADTDefs.h"
#ifndef GRAPH
#define GRAPH


typedef struct Graph Graph;

Graph * GraphCreate(Vector* _vec,int _mode);

void GraphDestroy(Graph * _graph);

ADTERR GraphConnect(Graph* _graph,int _from ,int _to);

ADTERR GraphDisconnect(Graph* _graph,int _from ,int _to);

int GraphIsAdjacent(Graph* _graph,int _from ,int _to);

ADTERR GraphJoinWt(Graph* _graph,int _from ,int _to,int _weight);

ADTERR GraphChangeWT(Graph* _graph,int _from ,int _to,int* _oldWT,int _newWT);


int GraphGetWT(Graph* _graph,int _from ,int _to);

int GraphIsPath(Graph* _graph,int _from ,int _to);

int GraphIsPathDFS(Graph* _graph,int _from ,int _to);
	
int GraphIsPathBFS(Graph* _graph,int _from ,int _to);

int* GraphIsDijkstra(Graph* _graph,int _from ,int _to);

void printGraph(Graph* _graph);

#endif
