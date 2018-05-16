#include "ADTDefs.h"
#include "vector.h"
#include "graph.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "linearQueue.h"

#define INFINITY 1000
#define UNDEFINED -1
	
struct Graph
{
	int   m_Mode;
	int** m_Matrix;
	int   m_NumOfNodes;
	int** m_WeightMatrix; 
};

enum {DiR,UNDiR};
enum {WHITE,GREY,BLACK};

/* creates the graph */
Graph * GraphCreate(Vector* _vec,int _mode)
{
	int size,i,num;
	
	/*crate and initilize graph struct */
	Graph* tmp=(Graph*)malloc(sizeof(Graph));
	vectorItemsNum(_vec,&size);	
	
	if(!tmp)
	{
		return NULL;
	}
	
	tmp->m_Mode=_mode;
	tmp->m_NumOfNodes=size;
	
	/*create Matrix and weight matrix */
	tmp->m_Matrix=(int**)malloc(sizeof(int*)*(size+1));
	tmp->m_WeightMatrix=(int**)malloc(sizeof(int*)*(size+1));
	if(!tmp->m_Matrix || !tmp->m_WeightMatrix)
	{
		return NULL;
	}
	
	for (i=0;i<size +1;++i)
	{
		tmp->m_Matrix[i]=(int*)calloc(sizeof(int),(size+1));	
		tmp->m_WeightMatrix[i]=(int*)calloc(sizeof(int),(size+1));
		if(!tmp->m_Matrix[i] || !tmp->m_WeightMatrix)
		{
			return NULL;
		}
	}
	
	/*fills the matrix with the nodes*/
	for (i=1; i<size+1 ;++i)
	{
		vectorGet(_vec,i-1,&num);
		tmp->m_Matrix[0][i]=num;
		tmp->m_Matrix[i][0]=num;
		tmp->m_WeightMatrix[0][i]=num;
		tmp->m_WeightMatrix[i][0]=num;
	}
	return tmp;

}

/*destroy graph array of pointers*/
void GraphDestroy(Graph * _graph)
{
	int i;
	for (i=0; i<_graph->m_NumOfNodes+1;++i)
	{
		free(_graph->m_Matrix[i]);
	}
	
	free(_graph);

}

/*connects athe nodes accroding to the mode */
ADTERR GraphConnect(Graph* _graph,int _from ,int _to)
{
	if(_graph->m_Mode)
	{
		_graph->m_Matrix[_from][_to]=1;
		_graph->m_Matrix[_to][_from]=1;
	}
	else
	{	
		_graph->m_Matrix[_from][_to]=1;
	}
return ERR_OK;
}

/*disconnect the nodes accroding to the mode */
ADTERR GraphDisconnect(Graph* _graph,int _from ,int _to)
{
	if(_graph->m_Mode)
	{
		_graph->m_Matrix[_from][_to]=0;
		_graph->m_Matrix[_to][_from]=0;
	}
	else
	{	
		_graph->m_Matrix[_from][_to]=0;
	}
	return ERR_OK;
}
/*checks is connection*/
int GraphIsAdjacent(Graph* _graph,int _from ,int _to)
{
	return (_graph->m_Matrix[_from][_to]==1)?1:0;	
	
}	

/*add weight to a connection according to mode*/
ADTERR GraphJoinWt(Graph* _graph,int _from ,int _to,int _weight)
{
	if(_graph->m_Mode)
	{
		_graph->m_WeightMatrix[_from][_to]=_weight;
		_graph->m_WeightMatrix[_to][_from]=_weight;
	}
	else
	{	
		_graph->m_WeightMatrix[_from][_to]=_weight;
	}
return ERR_OK;
}


/*change weight to a connection according to mode*/
ADTERR GraphChangeWT(Graph* _graph,int _from ,int _to,int* _oldWT,int _newWT)
{

	*_oldWT=_graph->m_WeightMatrix[_from][_to];
	
	if(_graph->m_Mode)
	{
		_graph->m_WeightMatrix[_from][_to]=_newWT;
		_graph->m_WeightMatrix[_to][_from]=_newWT;
	}
	else
	{	
		_graph->m_WeightMatrix[_from][_to]=_newWT;
	}
return ERR_OK;
}

/*get weight to a connection */
int GraphGetWT(Graph* _graph,int _from ,int _to)
{
	return _graph->m_WeightMatrix[_from][_to];
}

int GraphIsPathBFS(Graph* _graph,int _from ,int _to)
{
	/*creates queue and color array to indicated visited node*/
	int node,i;
	int* color=(int*)calloc(sizeof(int),_graph->m_NumOfNodes);
	Queue * tmp= queueCreate(8,8);
	queueInsert(tmp,_from);	
	color [_from-1]=1;	
	
	/* main loop if queue is empty we finished the graph*/
	while (!queueIsEmpty(tmp))
	{
		/*node found*/
		queueRemove(tmp,&node);
		
		if (_to==node)
		{
			return 1;
		}
		/*check all child if visited add new child to queue with color change*/
		for(i=1;i <= _graph->m_NumOfNodes ; ++i)
		{
			if (_graph->m_Matrix[node][i] && !color[i-1])
			{
					color[i-1]=1;
					queueInsert(tmp,i);	
					
			}		
		}
	}	
return 0;	
}

int GraphIsPathDFS(Graph* _graph,int _from ,int _to)
{
	/*creates stack and color array to indicated visited node*/
	int node,i;
	int* color=(int*)calloc(sizeof(int),_graph->m_NumOfNodes);
	Stack * tmp= stackCreate(8,8);
	if (!color ||!tmp)
	{
		return 0;
	}
	stackPush(tmp,_from);	
	
	/* main loop if stack is empty we finished the graph*/
	while (stackIsEmpty(tmp))
	{
		/*node found*/
		stackPop(tmp,&node);
		color[node-1]=GREY;
		
		if (_to==node)
		{
			free (tmp);
			free (color);
			return 1;
		}
		
		/*check all child if visited add new child to queue with color change*/
		for(i=1;i <= _graph->m_NumOfNodes ; ++i)
		{
			if (_graph->m_Matrix[node][i] && !color[i-1])
			{
					stackPush(tmp,i);	
					
			}		
		}
		color[node-1]=BLACK;
	}
	/*release memmory*/
	free (tmp);
	free (color);
return 0;	
}

int* GraphIsDijkstra(Graph* _graph,int _from ,int _to)
{

	int *dist,*visited;
	int i,k,minimum;
	int size=_graph->m_NumOfNodes;	

	/*creates array of distances from source initilize to infinity */
	if(!(dist=(int*)malloc(sizeof(int)*size)) || !(visited=(int*)malloc(sizeof(int)*size)))
	{
		return 0;
	}
	
	for (i=0;i<size;++i)
	{
		dist[i]=INFINITY;	
		visited[i]=UNDEFINED;
	}
	dist[_from-1]=0;

	for (k=0; k<size; ++k)
	{
		minimum=-1;
		for (i=0; i<size; ++i)
		{
			if((!visited[i] && minimum==-1) || dist[i] < dist[minimum])
			{
				minimum=-1;		
			}	
		
			visited[minimum]=1;
		}
	
		for (i=0; i<size; ++i)
		{
			if (_graph->m_WeightMatrix[minimum][i])
			{
				if(dist[minimum] + _graph->m_WeightMatrix[minimum][i]< dist[i])	
				{
					dist[i]=dist[minimum] +_graph->m_WeightMatrix[minimum][i];
				}
			}	
		}	
	}

return dist;
}

void printGraph(Graph* _graph)	
{
	int i,j;
	
	puts("The matrix:");
	for (i=0;i<_graph->m_NumOfNodes+1;++i)
	{
		for (j=0;j<_graph->m_NumOfNodes+1;++j)
		{
			printf("%d ",_graph->m_Matrix[i][j]);
		}
		puts("");
			
	}
	puts("");
	
	puts("The Weight matrix:");
	for (i=0;i<_graph->m_NumOfNodes+1;++i)
	{
		for (j=0;j<_graph->m_NumOfNodes+1;++j)
		{
			printf("%d ",_graph->m_WeightMatrix[i][j]);
		}
		puts("");
			
	}
	puts("");


}



