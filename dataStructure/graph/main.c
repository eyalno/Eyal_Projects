/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "vector.h"
#include "graph.h"
#include "ADTDefs.h"

/*sdgsdgsd*/

int main(){

Vector *tmp;
Graph * tmpG;
/*Unitest create add add set get destroy */
tmp=vectorCreate(8,8);
vectorAdd(tmp,1);
vectorAdd(tmp,2);
vectorAdd(tmp,3);
vectorAdd(tmp,4);
vectorAdd(tmp,5);
vectorAdd(tmp,6);
vectorAdd(tmp,7);
vectorAdd(tmp,8);

tmpG=GraphCreate(tmp,0);

GraphConnect(tmpG,1,3);
GraphJoinWt(tmpG,1,3,1);
GraphConnect(tmpG,1,6);
GraphJoinWt(tmpG,1,6,3);
GraphConnect(tmpG,1,7);
GraphJoinWt(tmpG,1,7,4);
GraphConnect(tmpG,3,2);
GraphJoinWt(tmpG,3,2,2);
GraphConnect(tmpG,3,4);
GraphJoinWt(tmpG,3,4,2);
GraphConnect(tmpG,2,5);
GraphJoinWt(tmpG,2,5,2);
GraphConnect(tmpG,4,8);
GraphJoinWt(tmpG,4,8,3);
GraphConnect(tmpG,5,6);
GraphJoinWt(tmpG,5,6,2);
GraphConnect(tmpG,7,8);
GraphJoinWt(tmpG,7,8,5);

puts("1->3->2->5->6");
puts("1->3->4->8");
puts("1->7");

printGraph(tmpG);

#ifdef _BFS
puts("BFS");
if (GraphIsPathBFS(tmpG,3,6))
	puts("found");
else
	puts("not found");


if (GraphIsPathBFS(tmpG,3,8))
	puts("found");
else
	puts("not found");

if (GraphIsPathBFS(tmpG,6,5))
	puts("found");
else
	puts("not found");

if (GraphIsPathBFS(tmpG,4,7))
	puts("found");
else
	puts("not found");
#endif

#ifdef _DFS 
puts("DFS");
if (GraphIsPathDFS(tmpG,3,6))
	puts("found 3-> 6");
else
	puts("not found 3->6");

if (GraphIsPathDFS(tmpG,3,8))
	puts("found 3->8");
else
	puts("not found 3->8");

if (GraphIsPathDFS(tmpG,6,5))
	puts("found 6->5 ");
else
	puts("not found 6->5");

if (GraphIsPathDFS(tmpG,4,7))
	puts("found 4->7");
else
	puts("not found 4->7");
#endif




return 0;
}
